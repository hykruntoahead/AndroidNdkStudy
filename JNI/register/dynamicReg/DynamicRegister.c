#include "../staticReg/jni.h"

/*
 * Class:     DynamicRegiester
 * Method:    printNativeMsg
 * Signature: ()V
 */
void printNativeMsg(JNIEnv *env, jobject jobj)
{
  printf("native dynamic print msg");
}

/*
 * Class:     DynamicRegiester
 * Method:    returnNativeHandleMsg
 * Signature: (I)Ljava/lang/String;
 */
jstring returnNativeHandleMsg(JNIEnv *env, jobject jobj, jint count)
{
  // jstring js = (*env)->NewStringUTF(env, "Hello Dynamic Regiester Return Msg.");
  char strMsg[64];

  // 发送格式化输出到 str 所指向的字符串
  // str -- 这是指向一个字符数组的指针，该数组存储了 C 字符串。
 // format -- 这是字符串，包含了要被写入到字符串 str 的文本。它可以包含嵌入的 format 标签，format 标签可被随后的附加参数中指定的值替换，并按需求进行格式化。
  sprintf(strMsg, "Hello Dynamic Regiester Return Msg count: %d", count);

  return (*env)->NewStringUTF(env,strMsg);
}

static const JNINativeMethod mMethods[] = {
    {"printNativeMsg", "()V", (void *)printNativeMsg},
    {"returnNativeHandleMsg", "(I)Ljava/lang/String;", (jstring *)returnNativeHandleMsg}};

static const char *mClassName = "DynamicRegiester";
jint JNI_OnLoad(JavaVM *vm, void *reserved)
{
  JNIEnv *env = NULL;
  //获得 JniEnv
  int r = (*vm)->GetEnv(vm,(void **)&env, JNI_VERSION_1_4);
  if (r != JNI_OK)
  {
    return -1;
  }

  jclass mainCls = (*env)->FindClass(env,mClassName);

  r = (*env)->RegisterNatives(env,mainCls, mMethods, 2);
  if (r != JNI_OK)
  {
    return -1;
  }
  return JNI_VERSION_1_4;
}