#include "generated_mediasoupclient_jni/jni/Parameters_jni.h"
#include "fakeParameters.hpp"
#include "json.hpp"
#include <include/java_types.h>
#include <jni.h>

using json = nlohmann::json;

namespace mediasoupclient {
    namespace test {
        static webrtc::ScopedJavaLocalRef<jstring>
        JNI_Parameters_GenRouterRtpCapabilities(JNIEnv *env) {
            json routerRtpCapabilities = generateRouterRtpCapabilities();
            return webrtc::NativeToJavaString(env, routerRtpCapabilities.dump());
        }

        static webrtc::ScopedJavaLocalRef<jstring> JNI_Parameters_GenRouterRtpCapabilitiesExclude(
                JNIEnv *env, const webrtc::JavaParamRef<jstring> &j_exclude) {
            std::string exclude = webrtc::JavaToNativeString(env, j_exclude);
            json routerRtpCapabilities = generateRouterRtpCapabilities();
            for (auto &codec: routerRtpCapabilities["codecs"])
                codec.erase(exclude);

            return webrtc::NativeToJavaString(env, routerRtpCapabilities.dump());
        }

        static webrtc::ScopedJavaLocalRef<jstring>
        JNI_Parameters_GenRtpParametersByKind(JNIEnv *env) {
            json rtpParametersByKind = generateRtpParametersByKind();
            return webrtc::NativeToJavaString(env, rtpParametersByKind.dump());
        }

        static webrtc::ScopedJavaLocalRef<jstring>
        JNI_Parameters_GenLocalDtlsParameters(JNIEnv *env) {
            json localDtlsParameters = generateLocalDtlsParameters();
            return webrtc::NativeToJavaString(env, localDtlsParameters.dump());
        }

        static webrtc::ScopedJavaLocalRef<jstring>
        JNI_Parameters_GenTransportRemoteParameters(JNIEnv *env) {
            json transportRemoteParameters = generateTransportRemoteParameters();
            return webrtc::NativeToJavaString(env, transportRemoteParameters.dump());
        }

        static webrtc::ScopedJavaLocalRef<jstring> JNI_Parameters_GenProducerRemoteId(JNIEnv *env) {
            std::string producerRemoteId = generateProducerRemoteId();
            return webrtc::NativeToJavaString(env, producerRemoteId);
        }

        static webrtc::ScopedJavaLocalRef<jstring> JNI_Parameters_GenConsumerRemoteParameters(
                JNIEnv *env, const webrtc::JavaParamRef<jstring> &j_codecMimeType) {
            std::string codecMimeType = webrtc::JavaToNativeString(env, j_codecMimeType);
            json consumerRemoteParameters = generateConsumerRemoteParameters(codecMimeType);
            return webrtc::NativeToJavaString(env, consumerRemoteParameters.dump());
        }

    } // namespace test
} // namespace mediasoupclient
