#include <jni.h>
#include <string>
#include <cstdio>
#include "elk.h"
#include "js.h"
#include <android/log.h>

extern "C" JNIEXPORT jstring JNICALL
Java_com_fengshihao_jsengine_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "";
    int a = add(10, 20);
    __android_log_print(ANDROID_LOG_DEBUG, "TRACKERS", "%d", a);
    char mem[400];
    struct js *js = js_create(mem, sizeof(mem));  // Create JS instance
    jsval_t v = js_eval(js, "let a = 23432; let foo = function() {return a + 1111;}; foo()", ~0);     // Execute JS code
    int useage = js_usage(js);
    sprintf(mem, "result: %s use memory %d\n", js_str(js, v), useage);
    return env->NewStringUTF(mem);
}