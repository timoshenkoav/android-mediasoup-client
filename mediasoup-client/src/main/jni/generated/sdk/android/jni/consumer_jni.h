#ifndef GEN_MEDIASOUP_CLIENT_ANDROID_CONSUMER_JNI_H
#define GEN_MEDIASOUP_CLIENT_ANDROID_CONSUMER_JNI_H

#include <jni.h>
#include <sdk/android/src/jni/jni_generator_helper.h>

const char kClassPath_org_mediasoup_droid_Consumer[] = "org/mediasoup/droid/Consumer";
const char kClassPath_org_mediasoup_droid_Consumer_Listener[] =
  "org/mediasoup/droid/Consumer$Listener";

JNI_GENERATOR_EXPORT
std::atomic<jclass> g_org_mediasoup_droid_Consumer_clazz(nullptr);
// Leaking this jclass as we cannot use LazyInstance from some threads.
#ifndef org_mediasoup_droid_Consumer_clazz_defined
#define org_mediasoup_droid_Consumer_clazz_defined

inline jclass org_mediasoup_droid_Consumer_clazz(JNIEnv* env)
{
	return base::android::LazyGetClass(
	  env, kClassPath_org_mediasoup_droid_Consumer, &g_org_mediasoup_droid_Consumer_clazz);
}

#endif

JNI_GENERATOR_EXPORT
std::atomic<jclass> g_org_mediasoup_droid_Consumer_Listener_clazz(nullptr);
// Leaking this jclass as we cannot use LazyInstance from some threads.
#ifndef org_mediasoup_droid_Consumer_Listener_clazz_defined
#define org_mediasoup_droid_Consumer_Listener_clazz_defined

inline jclass org_mediasoup_droid_Consumer_Listener_clazz(JNIEnv* env)
{
	return base::android::LazyGetClass(
	  env,
	  kClassPath_org_mediasoup_droid_Consumer_Listener,
	  &g_org_mediasoup_droid_Consumer_Listener_clazz);
}

#endif

static std::atomic<jmethodID> g_org_mediasoup_droid_Consumer_Constructor(nullptr);

base::android::ScopedJavaLocalRef<jobject> Java_Mediasoup_Consumer_Constructor(
  JNIEnv* env, jlong nativeConsumer)
{
	jclass clazz = org_mediasoup_droid_Consumer_clazz(env);
	CHECK_CLAZZ(env, clazz, org_mediasoup_droid_Consumer_clazz(env), NULL);

	jni_generator::JniJavaCallContextChecked call_context;
	call_context.Init<base::android::MethodID::TYPE_INSTANCE>(
	  env, clazz, "<init>", "(J)V", &g_org_mediasoup_droid_Consumer_Constructor);

	jobject ret = env->NewObject(clazz, call_context.base.method_id, nativeConsumer);
	return base::android::ScopedJavaLocalRef<jobject>(env, ret);
}

static std::atomic<jmethodID> g_org_mediasoup_droid_Consumer_Listener_onTransportClose(nullptr);

static void Java_Mediasoup_Consumer_Listener_onTransportClose(
  JNIEnv* env,
  const base::android::JavaRef<jobject>& obj,
  const base::android::JavaRef<jobject>& producer)
{
	jclass clazz = org_mediasoup_droid_Consumer_Listener_clazz(env);
	CHECK_CLAZZ(env, obj.obj(), org_mediasoup_droid_Consumer_Listener_clazz(env), 0);

	jni_generator::JniJavaCallContextChecked call_context;
	call_context.Init<base::android::MethodID::TYPE_INSTANCE>(
	  env,
	  clazz,
	  "onTransportClose",
	  "(Lorg/mediasoup/droid/Consumer;)V",
	  &g_org_mediasoup_droid_Consumer_Listener_onTransportClose);

	env->CallVoidMethod(obj.obj(), call_context.base.method_id, producer.obj());
}

#endif // GEN_MEDIASOUP_CLIENT_ANDROID_CONSUMER_JNI_H
