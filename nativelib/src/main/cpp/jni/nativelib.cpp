#include <jni.h>
#include <string>
#include <assert.h>

#include "native_class.h"

extern "C" JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *jvm, void *) {
    printf("Initializing JNI\n");
    printf("Initialization completed\n");
    return JNI_VERSION_1_6;
}

extern "C"
JNIEXPORT jlong JNICALL
Java_top_dawenhing_nativelib_NativeClass_createNative(JNIEnv *env, jobject thiz) {
    auto *obj = new NativeClass();
    return (jlong) obj;
}
extern "C"
JNIEXPORT void JNICALL
Java_top_dawenhing_nativelib_NativeClass_destroyNative(JNIEnv *env, jobject thiz, jlong handle) {
    assert(handle);
    NativeClass *obj = (NativeClass *)handle;
    delete obj;
}

extern "C"
JNIEXPORT jint JNICALL
Java_top_dawenhing_nativelib_NativeClass_nativeFoo(JNIEnv *env, jobject thiz, jlong handle,
                                                   jbyteArray in_data,
                                                   jobjectArray out_data) {
    assert(handle);
    NativeClass *obj = (NativeClass *)handle;

    jsize in_data_len = env->GetArrayLength(in_data);
    jbyte *in_data_ptr = env->GetByteArrayElements(in_data, nullptr);
    std::vector<uint8_t> in_data_vec(in_data_ptr, in_data_ptr + in_data_len);
    std::vector<uint8_t> out_data_vec;
    int ret = obj->foo(in_data_vec, out_data_vec);
    env->ReleaseByteArrayElements(in_data, in_data_ptr, 0);

    jsize out_data_len = out_data_vec.size();
    // convert out_data_vec to jbyteArray, and store as out_data[0]
    jbyteArray out_data_array = env->NewByteArray(out_data_len);
    jbyte *out_data_array_ptr = env->GetByteArrayElements(out_data_array, nullptr);
    std::copy(out_data_vec.begin(), out_data_vec.end(), out_data_array_ptr);
    env->SetObjectArrayElement(out_data, 0, out_data_array);
    env->ReleaseByteArrayElements(out_data_array, out_data_array_ptr, 0);
    return ret;
}