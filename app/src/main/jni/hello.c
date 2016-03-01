#include "com_kim_android_study_ndk_MainActivity.h"
#include <android/log.h>
#include <stdio.h>
#include <stdlib.h>

#define TAG "KIM"
#define LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, TAG, __VA_ARGS__)

JNIEXPORT void JNICALL Java_com_kim_android_1study_1ndk_MainActivity_updateFile(JNIEnv * env, jclass jclass, jstring path)
{
    //生成native的char的指针
    const char* file_path = (*env)->GetStringUTFChars(env,path,NULL);
    if (file_path != NULL){
        LOGV("From JNI : file_path is %s !",file_path);
        //打开文件
        FILE* file = fopen(file_path,"a+");
        if (file != NULL){
            LOGV("From JNI : open file success !");
        }
        char data[] = "I am KIM";
        //写入文件
        int count = fwrite(data,strlen(data),1,file);
        if (count > 0){
            LOGV("From JNI : write file success !");
        }
        //关闭文件
        if (file != NULL){
            fclose(file);
        }
        //释放资源
        (*env)->ReleaseStringUTFChars(env,path,file_path);
    }
}

JNIEXPORT jstring JNICALL Java_com_kim_android_1study_1ndk_MainActivity_getStringFromJNI(JNIEnv * env, jclass jclass)
{
    LOGV("Log from JNI");
    return (*env)->NewStringUTF(env,"Hello From JNI!");
}