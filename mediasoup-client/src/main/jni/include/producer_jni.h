#ifndef MEDIASOUP_CLIENT_ANDROID_PRODUCER_JNI_H
#define MEDIASOUP_CLIENT_ANDROID_PRODUCER_JNI_H

#include "Producer.hpp"
#include "common_jni.h"
#include <jni.h>
#include <sdk/android/native_api/jni/scoped_java_ref.h>
namespace mediasoupclient
{
class ProducerListenerJni final : public Producer::Listener
{
public:
	ProducerListenerJni(JNIEnv* env, const webrtc::JavaRef<jobject>& j_listener_);

	~ProducerListenerJni()
	{
	}

	void OnTransportClose(Producer* producer) override;

public:
	void SetJProducer(JNIEnv* env, const webrtc::JavaRef<jobject>& j_producer)
	{
		j_producer_ = j_producer;
	}

private:
	const webrtc::ScopedJavaGlobalRef<jobject> j_listener_;
	webrtc::ScopedJavaGlobalRef<jobject> j_producer_;
};

class OwnedProducer
{
public:
	OwnedProducer(Producer* producer, ProducerListenerJni* listener)
	  : producer_(producer), listener_(listener)
	{
	}

	~OwnedProducer()
	{
		delete listener_;
		delete producer_;
	}

	Producer* producer() const
	{
		return producer_;
	}

private:
	Producer* producer_;
	ProducerListenerJni* listener_;
};

	webrtc::ScopedJavaLocalRef<jobject> NativeToJavaProducer(
  JNIEnv* env, Producer* producer, ProducerListenerJni* listener);

} // namespace mediasoupclient

#endif // MEDIASOUP_CLIENT_ANDROID_PRODUCER_JNI_H
