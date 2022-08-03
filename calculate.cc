// calculate.cc
#include <node.h>

// https://youtu.be/O4Rlq_NSkoM
// Create A C++ Addon For Node js
// * make sure Visual Studio with C++ (ms-build) installed
// * npm i -g node-gyp
// (No need for npm i windows-build-tools)
// (it comes with node.js installation)
// * in the project root folder:
// * node-gyp configure
// * node-gyp build

namespace calculate {
    using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Local;
    using v8::Object;
    using v8::Number;
    using v8::Value;


    void Method(const FunctionCallbackInfo<Value>&args) {
        Isolate* isolate = args.GetIsolate();

        int i;
        double x = 100.32462344, y = 200.333456533452;

        for(i = 0; i < 1'000'000'000; i++) {
            x += y;
        }

        auto total = Number::New(isolate, x);
        args.GetReturnValue().Set(total);

    }
    void Initialize(Local<Object> exports) {
        NODE_SET_METHOD(exports, "calc", Method);
    }

    NODE_MODULE(NOE_GYP_MODULE_NAME, Initialize);
}
