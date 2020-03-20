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

Napi::Value WrappedArithmetic::performOp(const Napi::CallbackInfo &info, Op method)
{
    Napi::Env env{info.Env()};
    Napi::HandleScope scope{env};

    if (info.Length() != 1 || !info[0].IsNumber())
    {
        Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
        return env.Undefined();
    }

    auto value = info[0].As<Napi::Number>().Int64Value();

    if (method == Op::div && value == 0)
    {
        Napi::RangeError::New(env, "Cannot divide by zero").ThrowAsJavaScriptException();
        return env.Undefined();
    }

    switch (method)
    {
    case Op::add:
        arithmeticInstance->add(value);
        break;
    case Op::sub:
        arithmeticInstance->sub(value);
        break;
    case Op::mul:
        arithmeticInstance->mul(value);
        break;
    case Op::div:
        arithmeticInstance->div(value);
        break;
    }

    return env.Undefined();
};

Napi::Value WrappedArithmetic::add(const Napi::CallbackInfo &info)
{
    return performOp(info, Op::add);
};

Napi::Value WrappedArithmetic::sub(const Napi::CallbackInfo &info)
{
    return performOp(info, Op::sub);
};

Napi::Value WrappedArithmetic::mul(const Napi::CallbackInfo &info)
{
    return performOp(info, Op::mul);
};

Napi::Value WrappedArithmetic::div(const Napi::CallbackInfo &info)
{
    return performOp(info, Op::div);
};

Napi::Value WrappedArithmetic::getTotal(const Napi::CallbackInfo &info)
{
    Napi::Env env{info.Env()};
    Napi::HandleScope scope{env};

    return Napi::Number::New(env, static_cast<double>(arithmeticInstance->getTotal()));
};
