#include <napi.h>
#include "WrappedArithmetic.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports)
{
    return WrappedArithmetic::init(env, exports);
}

NODE_API_MODULE(testaddon, InitAll)
