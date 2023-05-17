#include <jni.h>
#include <iostream>

int main() {
    JavaVM* jvm;
    JNIEnv* env;
    JavaVMInitArgs vm_args;
    JavaVMOption options[1];

    // 设置Java虚拟机参数
    options[0].optionString = "-Djava.class.path=/home/xuda/CLionProjects/jni-example/c_call_java";
    vm_args.version = JNI_VERSION_1_6;
    vm_args.nOptions = 1;
    vm_args.options = options;
    vm_args.ignoreUnrecognized = JNI_TRUE;

    // 创建Java虚拟机
    jint res = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);
    if (res != JNI_OK) {
        printf("无法创建Java虚拟机\n");
        return 1;
    }

    // 加载类
    jclass cls = env->FindClass("MyJavaClass");
    if (cls == nullptr) {
        printf("无法找到类\n");
        return 1;
    }

    // 创建对象
    jmethodID constructor = env->GetMethodID(cls, "<init>", "()V");
    jobject obj = env->NewObject(cls, constructor);
    std::cout <<"obj: " <<obj << std::endl;


    // 调用方法
    jmethodID method = env->GetMethodID(cls, "checkWalletAndUser", "(Ljava/lang/String;Ljava/lang/String;)Z");
    std::cout <<"method: " <<method << std::endl;

    jstring address = env->NewStringUTF("0x1234543");
    jstring userId = env->NewStringUTF("123456789");
    jboolean result = env->CallBooleanMethod(obj, method, address,userId);

    //result的值打印为1或0，分别对应true和false。
    printf("方法返回值: %d\n", result);

    // 删除本地引用
    env->DeleteLocalRef(cls);
    env->DeleteLocalRef(obj);
    env->DeleteLocalRef(address);
    env->DeleteLocalRef(userId);

    // 销毁Java虚拟机
    jvm->DestroyJavaVM();

    return 0;
}
