#include <iostream>
#include "WrappedArithmetic.h"

Napi::FunctionReference WrappedArithmetic::constructor;

Napi::Object WrappedArithmetic::init(Napi::Env env, Napi::Object exports)
{
    Napi::HandleScope scope{env};

    Napi::Function func = DefineClass(
        env,
        "Arithmetic",
        {
            InstanceMethod("add", &WrappedArithmetic::add),
            InstanceMethod("sub", &WrappedArithmetic::sub),
            InstanceMethod("mul", &WrappedArithmetic::mul),
            InstanceMethod("div", &WrappedArithmetic::div),
            InstanceMethod("getTotal", &WrappedArithmetic::getTotal),
        });

    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();

    exports.Set("Arithmetic", func);
    return exports;
};

WrappedArithmetic::WrappedArithmetic(const Napi::CallbackInfo &info) : Napi::ObjectWrap<WrappedArithmetic>(info)
{
    Napi::Env env{info.Env()};
    Napi::HandleScope scope{env};

    arithmeticInstance = std::make_unique<Arithmetic>();
};

Napi::Value WrappedArithmetic::performOp(const Napi::CallbackInfo &info, const char *method)
{
    Napi::Env env{info.Env()};
    Napi::HandleScope scope{env};

    if (info.Length() != 1 || !info[0].IsNumber())
    {
        Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
    }

    auto value = info[0].As<Napi::Number>().Int64Value();

    if (strncmp(method, "add", 4) == 0)
    {
        arithmeticInstance->add(value);
    }
    if (strncmp(method, "sub", 4) == 0)
    {
        arithmeticInstance->sub(value);
    }
    if (strncmp(method, "mul", 4) == 0)
    {
        arithmeticInstance->mul(value);
    }
    if (strncmp(method, "div", 4) == 0)
    {
        arithmeticInstance->div(value);
    }
    return env.Undefined();
};

Napi::Value WrappedArithmetic::add(const Napi::CallbackInfo &info)
{
    return performOp(info, "add");
};

Napi::Value WrappedArithmetic::sub(const Napi::CallbackInfo &info)
{
    return performOp(info, "sub");
};

Napi::Value WrappedArithmetic::mul(const Napi::CallbackInfo &info)
{
    return performOp(info, "mul");
};

Napi::Value WrappedArithmetic::div(const Napi::CallbackInfo &info)
{
    return performOp(info, "div");
};

Napi::Value WrappedArithmetic::getTotal(const Napi::CallbackInfo &info)
{
    Napi::Env env{info.Env()};
    Napi::HandleScope scope{env};

    return Napi::Number::New(env, static_cast<double>(arithmeticInstance->getTotal()));
};
