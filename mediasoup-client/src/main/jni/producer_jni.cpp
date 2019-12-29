#define MSC_CLASS "producer_jni"

#include "producer_jni.h"
#include "Logger.hpp"
#include "sdk/android/jni/producer_jni.h"
#include <jni.h>

namespace mediasoupclient
{
ProducerListenerJni::ProducerListenerJni(JNIEnv* env, const JavaRef<jobject>& j_listener_)
  : j_listener_(env, j_listener_)
{
	MSC_TRACE();
}

void ProducerListenerJni::OnTransportClose(Producer* producer)
{
	MSC_TRACE();

	JNIEnv* env = webrtc::AttachCurrentThreadIfNeeded();
	Java_Mediasoup_Producer_Listener_onTransportClose(
	  env, j_listener_, JavaParamRef<jobject>(j_producer_));
}

extern "C" JNIEXPORT jstring JNICALL
Java_org_mediasoup_droid_Producer_getNativeId(JNIEnv* env, jclass /* j_type */, jlong j_producer)
{
	MSC_TRACE();

	auto result = reinterpret_cast<OwnedProducer*>(j_producer)->producer()->GetId();
	return NativeToJavaString(env, result).Release();
}

extern "C" JNIEXPORT jboolean JNICALL
Java_org_mediasoup_droid_Producer_isNativeClosed(JNIEnv* env, jclass /* j_type */, jlong j_producer)
{
	MSC_TRACE();

	auto result = reinterpret_cast<OwnedProducer*>(j_producer)->producer()->IsClosed();
	return static_cast<jboolean>(result);
}

extern "C" JNIEXPORT jstring JNICALL
Java_org_mediasoup_droid_Producer_getNativeKind(JNIEnv* env, jclass /* j_type */, jlong j_producer)
{
	MSC_TRACE();

	auto result = reinterpret_cast<OwnedProducer*>(j_producer)->producer()->GetKind();
	return NativeToJavaString(env, result).Release();
}

extern "C" JNIEXPORT jlong JNICALL
Java_org_mediasoup_droid_Producer_getNativeTrack(JNIEnv* env, jclass /* j_type */, jlong j_producer)
{
	MSC_TRACE();

	auto result = reinterpret_cast<OwnedProducer*>(j_producer)->producer()->GetTrack();
	return NativeToJavaPointer(result);
}

extern "C" JNIEXPORT jboolean JNICALL
Java_org_mediasoup_droid_Producer_isNativePaused(JNIEnv* env, jclass /* j_type */, jlong j_producer)
{
	MSC_TRACE();

	auto result = reinterpret_cast<OwnedProducer*>(j_producer)->producer()->IsPaused();
	return static_cast<jboolean>(result);
}

extern "C" JNIEXPORT jint JNICALL Java_org_mediasoup_droid_Producer_getNativeMaxSpatialLayer(
  JNIEnv* env, jclass /* j_type */, jlong j_producer)
{
	MSC_TRACE();

	auto result = reinterpret_cast<OwnedProducer*>(j_producer)->producer()->GetMaxSpatialLayer();
	return result;
}

extern "C" JNIEXPORT jstring JNICALL Java_org_mediasoup_droid_Producer_getNativeAppData(
  JNIEnv* env, jclass /* j_type */, jlong j_producer)
{
	MSC_TRACE();

	auto result = reinterpret_cast<OwnedProducer*>(j_producer)->producer()->GetAppData();
	return NativeToJavaString(env, result.dump()).Release();
}

extern "C" JNIEXPORT jstring JNICALL Java_org_mediasoup_droid_Producer_getNativeRtpParameters(
  JNIEnv* env, jclass /* j_type */, jlong j_producer)
{
	MSC_TRACE();

	auto result = reinterpret_cast<OwnedProducer*>(j_producer)->producer()->GetRtpParameters();
	return NativeToJavaString(env, result.dump()).Release();
}

extern "C" JNIEXPORT jstring JNICALL
Java_org_mediasoup_droid_Producer_getNativeStats(JNIEnv* env, jclass /* j_type */, jlong j_producer)
{
	MSC_TRACE();

	try
	{
		auto result = reinterpret_cast<OwnedProducer*>(j_producer)->producer()->GetStats();
		return NativeToJavaString(env, result.dump()).Release();
	}
	catch (const std::exception& e)
	{
		MSC_ERROR("%s", e.what());
		THROW_MEDIASOUP_CLIENT_EXCEPTION(env, e);
		return nullptr;
	}
}

extern "C" JNIEXPORT void JNICALL
Java_org_mediasoup_droid_Producer_nativeResume(JNIEnv* env, jclass /* j_type */, jlong j_producer)
{
	MSC_TRACE();

	reinterpret_cast<OwnedProducer*>(j_producer)->producer()->Resume();
}

extern "C" JNIEXPORT void JNICALL Java_org_mediasoup_droid_Producer_setNativeMaxSpatialLayer(
  JNIEnv* env, jclass /* j_type */, jlong j_producer, jint j_layer)
{
	MSC_TRACE();

	try
	{
		reinterpret_cast<OwnedProducer*>(j_producer)
		  ->producer()
		  ->SetMaxSpatialLayer(static_cast<uint8_t>(j_layer));
	}
	catch (const std::exception& e)
	{
		MSC_ERROR("%s", e.what());
		THROW_MEDIASOUP_CLIENT_EXCEPTION(env, e);
	}
}

extern "C" JNIEXPORT void JNICALL
Java_org_mediasoup_droid_Producer_nativePause(JNIEnv* env, jclass /* j_type */, jlong j_producer)
{
	MSC_TRACE();

	reinterpret_cast<OwnedProducer*>(j_producer)->producer()->Pause();
}

extern "C" JNIEXPORT void JNICALL Java_org_mediasoup_droid_Producer_nativeReplaceTrack(
  JNIEnv* env, jclass /* j_type */, jlong j_producer, jlong j_track)
{
	MSC_TRACE();

	try
	{
		auto track = reinterpret_cast<webrtc::MediaStreamTrackInterface*>(j_track);
		reinterpret_cast<OwnedProducer*>(j_producer)->producer()->ReplaceTrack(track);
	}
	catch (const std::exception& e)
	{
		MSC_ERROR("%s", e.what());
		THROW_MEDIASOUP_CLIENT_EXCEPTION(env, e);
	}
}

extern "C" JNIEXPORT void JNICALL
Java_org_mediasoup_droid_Producer_nativeClose(JNIEnv* env, jclass /* j_type */, jlong j_producer)
{
	MSC_TRACE();

	reinterpret_cast<OwnedProducer*>(j_producer)->producer()->Close();
}

} // namespace mediasoupclient
