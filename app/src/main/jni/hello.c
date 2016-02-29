#include "com_kim_android_study_ndk_MainActivity.h"

JNIEXPORT jstring JNICALL Java_com_kim_android_1study_1ndk_MainActivity_getStringFromJNI
  (JNIEnv * env, jclass jclass)
{
      return (*env)->NewStringUTF(env,"Hello From JNI!");
}