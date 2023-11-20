#ifndef MEDIASOUP_CLIENT_ANDROID_CONSUMER_JNI_H
#define MEDIASOUP_CLIENT_ANDROID_CONSUMER_JNI_H

#include "common_jni.h"
#include <Consumer.hpp>
#include <jni.h>
#include <sdk/android/native_api/jni/scoped_java_ref.h>
namespace mediasoupclient
{
class ConsumerListenerJni final : public Consumer::Listener
{
public:
	ConsumerListenerJni(JNIEnv* env, const webrtc::JavaRef<jobject>& j_listener);

	~ConsumerListenerJni()
	{
	}

	void OnTransportClose(Consumer* native_consumer) override;

public:
	void SetJConsumer(JNIEnv* env, const webrtc::JavaRef<jobject>& j_consumer)
	{
		j_consumer_ = j_consumer;
	}

private:
	const webrtc::ScopedJavaGlobalRef<jobject> j_listener_global_;
	webrtc::ScopedJavaGlobalRef<jobject> j_consumer_;
};

class OwnedConsumer
{
public:
	OwnedConsumer(Consumer* consumer, ConsumerListenerJni* listener)
	  : consumer_(consumer), listener_(listener)
	{
	}

	~OwnedConsumer()
	{
		delete listener_;
		delete consumer_;
	}

	Consumer* consumer() const
	{
		return consumer_;
	}

private:
	Consumer* consumer_;
	ConsumerListenerJni* listener_;
};

webrtc::ScopedJavaLocalRef<jobject> NativeToJavaConsumer(
  JNIEnv* env, Consumer* consumer, ConsumerListenerJni* listener);

} // namespace mediasoupclient

#endif // MEDIASOUP_CLIENT_ANDROID_CONSUMER_JNI_H
