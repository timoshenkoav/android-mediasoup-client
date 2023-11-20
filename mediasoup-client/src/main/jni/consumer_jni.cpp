#define MSC_CLASS "consumer_jni"

#include "consumer_jni.h"
#include "Logger.hpp"
#include "generated_mediasoupclient_jni/jni/Consumer_jni.h"
#include "include/java_types.h"
#include <jni.h>
#include <sdk/android/native_api/jni/java_types.h>

namespace mediasoupclient {
    ConsumerListenerJni::ConsumerListenerJni(JNIEnv *env,
                                             const webrtc::JavaRef<jobject> &j_listener)
            : j_listener_global_(env, j_listener) {
        MSC_TRACE();
    }

    void ConsumerListenerJni::OnTransportClose(Consumer * /* native_consumer */) {
        MSC_TRACE();

        JNIEnv *env = webrtc::AttachCurrentThreadIfNeeded();
        Java_Listener_onTransportClose(env, j_listener_global_, j_consumer_);
    }

    static webrtc::ScopedJavaLocalRef<jstring>
    JNI_Consumer_GetNativeId(JNIEnv *env, jlong j_consumer) {
        MSC_TRACE();

        auto result = reinterpret_cast<OwnedConsumer *>(j_consumer)->consumer()->GetId();
        return webrtc::NativeToJavaString(env, result);
    }

    static webrtc::ScopedJavaLocalRef<jstring>
    JNI_Consumer_GetProducerId(JNIEnv *env, jlong j_consumer) {
        MSC_TRACE();

        auto result = reinterpret_cast<OwnedConsumer *>(j_consumer)->consumer()->GetProducerId();
        return webrtc::NativeToJavaString(env, result);
    }

    static jboolean JNI_Consumer_IsClosed(JNIEnv *env, jlong j_consumer) {
        MSC_TRACE();

        auto result = reinterpret_cast<OwnedConsumer *>(j_consumer)->consumer()->IsClosed();
        return static_cast<jboolean>(result);
    }

    static jboolean JNI_Consumer_IsPaused(JNIEnv *env, jlong j_consumer) {
        MSC_TRACE();

        auto result = reinterpret_cast<OwnedConsumer *>(j_consumer)->consumer()->IsPaused();
        return static_cast<jboolean>(result);
    }

    static webrtc::ScopedJavaLocalRef<jstring> JNI_Consumer_GetKind(JNIEnv *env, jlong j_consumer) {
        MSC_TRACE();

        auto result = reinterpret_cast<OwnedConsumer *>(j_consumer)->consumer()->GetKind();
        return webrtc::NativeToJavaString(env, result);
    }

    static jlong JNI_Consumer_GetTrack(JNIEnv *env, jlong j_consumer) {
        MSC_TRACE();

        auto result = reinterpret_cast<OwnedConsumer *>(j_consumer)->consumer()->GetTrack();
        return NativeToJavaPointer(result);
    }

    static webrtc::ScopedJavaLocalRef<jstring>
    JNI_Consumer_GetRtpParameters(JNIEnv *env, jlong j_consumer) {
        MSC_TRACE();

        auto result = reinterpret_cast<OwnedConsumer *>(j_consumer)->consumer()->GetRtpParameters();

        return webrtc::NativeToJavaString(env, result.dump());
    }

    static webrtc::ScopedJavaLocalRef<jstring>
    JNI_Consumer_GetAppData(JNIEnv *env, jlong j_consumer) {
        MSC_TRACE();

        auto result = reinterpret_cast<OwnedConsumer *>(j_consumer)->consumer()->GetAppData();

        return webrtc::NativeToJavaString(env, result.dump());
    }

    static void JNI_Consumer_Resume(JNIEnv *env, jlong j_consumer) {
        MSC_TRACE();

        reinterpret_cast<OwnedConsumer *>(j_consumer)->consumer()->Resume();
    }

    static void JNI_Consumer_Pause(JNIEnv *env, jlong j_consumer) {
        MSC_TRACE();

        reinterpret_cast<OwnedConsumer *>(j_consumer)->consumer()->Pause();
    }

    static webrtc::ScopedJavaLocalRef<jstring>
    JNI_Consumer_GetStats(JNIEnv *env, jlong j_consumer) {
        MSC_TRACE();

        try {
            auto result = reinterpret_cast<OwnedConsumer *>(j_consumer)->consumer()->GetStats();
            return webrtc::NativeToJavaString(env, result.dump());
        }
        catch (const std::exception &e) {
            MSC_ERROR("%s", e.what());
            THROW_MEDIASOUP_CLIENT_EXCEPTION(env, e);
            return nullptr;
        }
    }

    static void JNI_Consumer_Close(JNIEnv *env, jlong j_consumer) {
        MSC_TRACE();

        reinterpret_cast<OwnedConsumer *>(j_consumer)->consumer()->Close();
    }

    webrtc::ScopedJavaLocalRef<jobject> NativeToJavaConsumer(
            JNIEnv *env, Consumer *consumer, ConsumerListenerJni *listener) {
        auto ownedConsumer = new OwnedConsumer(consumer, listener);
        auto j_consumer = Java_Consumer_Constructor(env,
                                                    webrtc::NativeToJavaPointer(ownedConsumer));
        listener->SetJConsumer(env, j_consumer);
        return webrtc::ScopedJavaLocalRef<jobject>(env, j_consumer.Release());
    }

} // namespace mediasoupclient
