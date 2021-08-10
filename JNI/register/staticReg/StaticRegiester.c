#include "StaticRegiester.h"
 
/*
 * Class:     StaticRegiester
 * Method:    printNativeMsg
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_StaticRegiester_printNativeMsg
  (JNIEnv  * env, jobject jobj){
     printf("hello native msg run ");
  };


JNIEXPORT jstring JNICALL Java_StaticRegiester_obtainNativeReturnMsg
  (JNIEnv *env, jobject jobj){
     return (*env)->NewStringUTF(env, "Hello Static Regiester Return Msg.");
  }
  