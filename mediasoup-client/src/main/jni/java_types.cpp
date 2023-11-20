#include "include/java_types.h"

namespace mediasoupclient
{
	webrtc::ScopedJavaLocalRef<jstring> NativeToJavaString(JNIEnv* jni, const std::string& str)
{
	auto j_str = webrtc::NativeToJavaString(jni, str);
	return webrtc::ScopedJavaLocalRef<jstring>(jni, j_str.Release());
}

	webrtc::ScopedJavaLocalRef<jstring> NativeToJavaString(JNIEnv* jni, const absl::optional<std::string>& str)
{
	auto j_str = webrtc::NativeToJavaString(jni, str);
	return webrtc::ScopedJavaLocalRef<jstring>(jni, j_str.Release());
}

std::string JavaToNativeString(JNIEnv* jni, const webrtc::JavaRef<jstring>& j_string)
{
	return webrtc::JavaToNativeString(jni, webrtc::JavaParamRef<jstring>(j_string.obj()));
}

void JavaToNativeOptions(
  JNIEnv* env, const webrtc::JavaRef<jobject>& configuration, jlong factory, PeerConnection::Options& options)
{
	if (configuration.is_null())
	{
		return;
	}

	if (!configuration.is_null())
	{
		webrtc::PeerConnectionInterface::RTCConfiguration rtc_config(
		  webrtc::PeerConnectionInterface::RTCConfigurationType::kAggressive);
		webrtc::jni::JavaToNativeRTCConfiguration(
		  env, webrtc::JavaParamRef<jobject>(configuration.obj()), &rtc_config);
		options.config = rtc_config;
	}
	options.factory = reinterpret_cast<webrtc::PeerConnectionFactoryInterface*>(factory);
}
} // namespace mediasoupclient
