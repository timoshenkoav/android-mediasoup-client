#ifndef MEDIASOUP_CLIENT_ANDROID_TRANSPORT_JNI_H
#define MEDIASOUP_CLIENT_ANDROID_TRANSPORT_JNI_H

#include "Transport.hpp"
#include "common_jni.h"
#include <jni.h>
#include <sdk/android/src/jni/scoped_java_ref_counted.h>
namespace mediasoupclient
{
class SendTransportListenerJni final : public SendTransport::Listener
{
public:
	SendTransportListenerJni(JNIEnv* env, const webrtc::JavaRef<jobject>& j_listener)
	  : j_listener_(env, j_listener)
	{
	}

	std::future<void> OnConnect(Transport* transport, const json& dtlsParameters) override;

	void OnConnectionStateChange(Transport* transport, const std::string& connectionState) override;

	std::future<std::string> OnProduce(
	  SendTransport* transport, const std::string& kind, json rtpParameters, const json& appData) override;
	std::future<std::string> OnProduceData(
			SendTransport* transport,
			const json& sctpStreamParameters,
			const std::string& label,
			const std::string& protocol,
			const json& appData) override;

public:
	void SetJTransport(JNIEnv* env, const webrtc::JavaRef<jobject>& j_transport)
	{
		j_transport_ = j_transport;
	}

private:
	const webrtc::ScopedJavaGlobalRef<jobject> j_listener_;
	webrtc::ScopedJavaGlobalRef<jobject> j_transport_;
};

class RecvTransportListenerJni final : public RecvTransport::Listener
{
public:
	RecvTransportListenerJni(JNIEnv* env, const webrtc::JavaRef<jobject>& j_listener): j_listener_(env, j_listener)
	{
	}

	std::future<void> OnConnect(Transport* transport, const json& dtlsParameters) override;

	void OnConnectionStateChange(Transport* transport, const std::string& connectionState) override;

public:
	void SetJTransport(JNIEnv* env, const webrtc::JavaRef<jobject>& j_transport)
	{
		j_transport_ = j_transport;
	}

private:
	const webrtc::ScopedJavaGlobalRef<jobject> j_listener_;
	webrtc::ScopedJavaGlobalRef<jobject> j_transport_;
};

class OwnedSendTransport
{
public:
	OwnedSendTransport(SendTransport* transport, SendTransportListenerJni* listener)
	  : transport_(transport), listener_(listener)
	{
	}

	~OwnedSendTransport()
	{
		delete listener_;
		delete transport_;
	}

	SendTransport* transport() const
	{
		return transport_;
	}

private:
	SendTransport* transport_;
	SendTransportListenerJni* listener_;
};

class OwnedRecvTransport
{
public:
	OwnedRecvTransport(RecvTransport* transport, RecvTransportListenerJni* listener)
	  : transport_(transport), listener_(listener)
	{
	}

	~OwnedRecvTransport()
	{
		delete listener_;
		delete transport_;
	}

	RecvTransport* transport() const
	{
		return transport_;
	}

private:
	RecvTransport* transport_;
	RecvTransportListenerJni* listener_;
};

	webrtc::ScopedJavaLocalRef<jobject> NativeToJavaSendTransport(
  JNIEnv* env, SendTransport* transport, SendTransportListenerJni* listener);

	webrtc::ScopedJavaLocalRef<jobject> NativeToJavaRecvTransport(
  JNIEnv* env, RecvTransport* transport, RecvTransportListenerJni* listener);

} // namespace mediasoupclient

#endif // MEDIASOUP_CLIENT_ANDROID_TRANSPORT_JNI_H
