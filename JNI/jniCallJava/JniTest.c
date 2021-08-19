//
// Created by hyk on 21-8-18.
//

#include "JniTest.h"

JNIEXPORT void JNICALL Java_JniTest_JniCallJavaMember
  (JNIEnv *env, jobject jobj){
     jclass jclazz = (*env)->GetObjectClass(env,jobj);
     jfieldID ageId = (*env)-> GetFieldID(env,jclazz,"age","I");
     jfieldID nameId = (*env)->GetFieldID(env,jclazz,"name","Ljava/lang/String;");

     jint age = (*env)->GetIntField(env,jobj,ageId);

     jstring nameJs = (jstring)((*env)->GetObjectField(env,jobj,nameId)); 

     const char* name = (*env)->GetStringUTFChars(env,nameJs,NULL); 

     printf("name is %s,age is %d\n",name,age);

      //避免内存泄露
      // (*env)->DeleteLocalRef(nameJs);
     (*env)->ReleaseStringUTFChars(env,nameJs,name);
     name = NULL;

  };

  JNIEXPORT void JNICALL Java_JniTest_JniCallJavaStaticMember
    (JNIEnv *env, jobject jobj){
        // jclass jclazz1 = (*env)->FindClass(env,"JniTest"); 
        jclass jclazz1 = (*env)->GetObjectClass(env,jobj); 
        jfieldID manId = (*env)->GetStaticFieldID(env,jclazz1,"man","Z"); 
        jboolean man = (*env)->GetStaticBooleanField(env,jclazz1,manId); 
       
        printf("sex is %s\n", (man?"man":"woman"));

        (*env)->DeleteLocalRef(env,jclazz1);
        jclazz1 = NULL;
    };

    JNIEXPORT void JNICALL Java_JniTest_JniCallJavaMethod
  (JNIEnv *env, jobject jobj){
      jclass jclazz = (*env)->GetObjectClass(env,jobj);
      jmethodID objCutMethodId = (*env)->GetMethodID(env,jclazz,"<init>","(ILjava/lang/String;)V");
      jstring name = (*env)->NewStringUTF(env,"native bobo");
      jobject newObj = (*env)->NewObject(env,jclazz,objCutMethodId,18,name);
      jmethodID addAgeMtdId = (*env)->GetMethodID(env,jclazz,"tenYearLaterAge","()I");
      jint changedAge = (*env)->CallIntMethod(env,newObj,addAgeMtdId);
      printf("changed age is %d\n",changedAge);

      (*env)->DeleteLocalRef(env,newObj);
      newObj = NULL;
      (*env)->DeleteLocalRef(env,jclazz);
      jclazz = NULL;
  };

  JNIEXPORT void JNICALL Java_JniTest_JniCallJavaStaticMethod
  (JNIEnv *env, jobject jobj){
      Java_JniTest_JniCallJavaStaticMember(env,jobj);
      jclass jclazz = (*env)->GetObjectClass(env,jobj);
      jmethodID changeSexMtdId = (*env)->GetStaticMethodID(env,jclazz,"changeSexToOther","()V");
      (*env)->CallStaticVoidMethod(env,jclazz,changeSexMtdId);
      printf("then change th sex to:%s\n");
      (*env)->DeleteLocalRef(env,jclazz);
      jclazz = NULL;
      Java_JniTest_JniCallJavaStaticMember(env,jobj);
  };
