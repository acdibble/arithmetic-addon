#pragma once
#include <napi.h>
#include "Arithemtic.h"

class WrappedArithmetic : public Napi::ObjectWrap<WrappedArithmetic>
{
public:
    static Napi::Object init(Napi::Env env, Napi::Object exports);
    WrappedArithmetic(const Napi::CallbackInfo &info);

private:
    static Napi::FunctionReference constructor;
    Napi::Value getTotal(const Napi::CallbackInfo &info);
    Napi::Value add(const Napi::CallbackInfo &info);
    Napi::Value sub(const Napi::CallbackInfo &info);
    Napi::Value mul(const Napi::CallbackInfo &info);
    Napi::Value div(const Napi::CallbackInfo &info);
    Napi::Value performOp(const Napi::CallbackInfo &info, const char *method);

    std::unique_ptr<Arithmetic> arithmeticInstance;
};
