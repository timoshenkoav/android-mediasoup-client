// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.


// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     org/mediasoup/droid/PeerConnection

#ifndef org_mediasoup_droid_PeerConnection_JNI
#define org_mediasoup_droid_PeerConnection_JNI

#include <jni.h>

#include "../include/jni_generator_helper.h"


// Step 1: Forward declarations.

JNI_REGISTRATION_EXPORT extern const char kClassPath_org_mediasoup_droid_PeerConnection[];
const char kClassPath_org_mediasoup_droid_PeerConnection[] = "org/mediasoup/droid/PeerConnection";
// Leaking this jclass as we cannot use LazyInstance from some threads.
JNI_REGISTRATION_EXPORT std::atomic<jclass> g_org_mediasoup_droid_PeerConnection_clazz(nullptr);
#ifndef org_mediasoup_droid_PeerConnection_clazz_defined
#define org_mediasoup_droid_PeerConnection_clazz_defined
inline jclass org_mediasoup_droid_PeerConnection_clazz(JNIEnv* env) {
  return base::android::LazyGetClass(env, kClassPath_org_mediasoup_droid_PeerConnection,
      &g_org_mediasoup_droid_PeerConnection_clazz);
}
#endif


// Step 2: Constants (optional).


// Step 3: Method stubs.
namespace mediasoupclient {

static jlong JNI_PeerConnection_NewPeerConnection(JNIEnv* env, const
    base::android::JavaParamRef<jobject>& nativeListener,
    const base::android::JavaParamRef<jobject>& configuration,
    jlong peerConnectionFactory);

JNI_GENERATOR_EXPORT jlong Java_org_mediasoup_droid_PeerConnection_nativeNewPeerConnection(
    JNIEnv* env,
    jclass jcaller,
    jobject nativeListener,
    jobject configuration,
    jlong peerConnectionFactory) {
  return JNI_PeerConnection_NewPeerConnection(env, base::android::JavaParamRef<jobject>(env,
      nativeListener), base::android::JavaParamRef<jobject>(env, configuration),
      peerConnectionFactory);
}

static void JNI_PeerConnection_FreeOwnedPeerConnection(JNIEnv* env, jlong ownedPeerConnection);

JNI_GENERATOR_EXPORT void Java_org_mediasoup_droid_PeerConnection_nativeFreeOwnedPeerConnection(
    JNIEnv* env,
    jclass jcaller,
    jlong ownedPeerConnection) {
  return JNI_PeerConnection_FreeOwnedPeerConnection(env, ownedPeerConnection);
}

static jlong JNI_PeerConnection_GetNativePeerConnection(JNIEnv* env, const
    base::android::JavaParamRef<jobject>& jcaller);

JNI_GENERATOR_EXPORT jlong Java_org_mediasoup_droid_PeerConnection_nativeGetNativePeerConnection(
    JNIEnv* env,
    jobject jcaller) {
  return JNI_PeerConnection_GetNativePeerConnection(env, base::android::JavaParamRef<jobject>(env,
      jcaller));
}

static jboolean JNI_PeerConnection_SetConfiguration(JNIEnv* env, const
    base::android::JavaParamRef<jobject>& jcaller,
    const base::android::JavaParamRef<jobject>& rtcConfig);

JNI_GENERATOR_EXPORT jboolean Java_org_mediasoup_droid_PeerConnection_nativeSetConfiguration(
    JNIEnv* env,
    jobject jcaller,
    jobject rtcConfig) {
  return JNI_PeerConnection_SetConfiguration(env, base::android::JavaParamRef<jobject>(env,
      jcaller), base::android::JavaParamRef<jobject>(env, rtcConfig));
}

static base::android::ScopedJavaLocalRef<jstring> JNI_PeerConnection_CreateOffer(JNIEnv* env, const
    base::android::JavaParamRef<jobject>& jcaller,
    const base::android::JavaParamRef<jobject>& constraints);

JNI_GENERATOR_EXPORT jstring Java_org_mediasoup_droid_PeerConnection_nativeCreateOffer(
    JNIEnv* env,
    jobject jcaller,
    jobject constraints) {
  return JNI_PeerConnection_CreateOffer(env, base::android::JavaParamRef<jobject>(env, jcaller),
      base::android::JavaParamRef<jobject>(env, constraints)).Release();
}

static base::android::ScopedJavaLocalRef<jstring> JNI_PeerConnection_CreateAnswer(JNIEnv* env, const
    base::android::JavaParamRef<jobject>& jcaller,
    const base::android::JavaParamRef<jobject>& constraints);

JNI_GENERATOR_EXPORT jstring Java_org_mediasoup_droid_PeerConnection_nativeCreateAnswer(
    JNIEnv* env,
    jobject jcaller,
    jobject constraints) {
  return JNI_PeerConnection_CreateAnswer(env, base::android::JavaParamRef<jobject>(env, jcaller),
      base::android::JavaParamRef<jobject>(env, constraints)).Release();
}

static void JNI_PeerConnection_SetLocalDescription(JNIEnv* env, const
    base::android::JavaParamRef<jobject>& jcaller,
    const base::android::JavaParamRef<jstring>& type,
    const base::android::JavaParamRef<jstring>& description);

JNI_GENERATOR_EXPORT void Java_org_mediasoup_droid_PeerConnection_nativeSetLocalDescription(
    JNIEnv* env,
    jobject jcaller,
    jstring type,
    jstring description) {
  return JNI_PeerConnection_SetLocalDescription(env, base::android::JavaParamRef<jobject>(env,
      jcaller), base::android::JavaParamRef<jstring>(env, type),
      base::android::JavaParamRef<jstring>(env, description));
}

static void JNI_PeerConnection_SetRemoteDescription(JNIEnv* env, const
    base::android::JavaParamRef<jobject>& jcaller,
    const base::android::JavaParamRef<jstring>& type,
    const base::android::JavaParamRef<jstring>& description);

JNI_GENERATOR_EXPORT void Java_org_mediasoup_droid_PeerConnection_nativeSetRemoteDescription(
    JNIEnv* env,
    jobject jcaller,
    jstring type,
    jstring description) {
  return JNI_PeerConnection_SetRemoteDescription(env, base::android::JavaParamRef<jobject>(env,
      jcaller), base::android::JavaParamRef<jstring>(env, type),
      base::android::JavaParamRef<jstring>(env, description));
}

static base::android::ScopedJavaLocalRef<jstring> JNI_PeerConnection_GetLocalDescription(JNIEnv*
    env, const base::android::JavaParamRef<jobject>& jcaller);

JNI_GENERATOR_EXPORT jstring Java_org_mediasoup_droid_PeerConnection_nativeGetLocalDescription(
    JNIEnv* env,
    jobject jcaller) {
  return JNI_PeerConnection_GetLocalDescription(env, base::android::JavaParamRef<jobject>(env,
      jcaller)).Release();
}

static base::android::ScopedJavaLocalRef<jstring> JNI_PeerConnection_GetRemoteDescription(JNIEnv*
    env, const base::android::JavaParamRef<jobject>& jcaller);

JNI_GENERATOR_EXPORT jstring Java_org_mediasoup_droid_PeerConnection_nativeGetRemoteDescription(
    JNIEnv* env,
    jobject jcaller) {
  return JNI_PeerConnection_GetRemoteDescription(env, base::android::JavaParamRef<jobject>(env,
      jcaller)).Release();
}

static base::android::ScopedJavaLocalRef<jobject> JNI_PeerConnection_GetSenders(JNIEnv* env, const
    base::android::JavaParamRef<jobject>& jcaller);

JNI_GENERATOR_EXPORT jobject Java_org_mediasoup_droid_PeerConnection_nativeGetSenders(
    JNIEnv* env,
    jobject jcaller) {
  return JNI_PeerConnection_GetSenders(env, base::android::JavaParamRef<jobject>(env,
      jcaller)).Release();
}

static base::android::ScopedJavaLocalRef<jobject> JNI_PeerConnection_GetTransceivers(JNIEnv* env,
    const base::android::JavaParamRef<jobject>& jcaller);

JNI_GENERATOR_EXPORT jobject Java_org_mediasoup_droid_PeerConnection_nativeGetTransceivers(
    JNIEnv* env,
    jobject jcaller) {
  return JNI_PeerConnection_GetTransceivers(env, base::android::JavaParamRef<jobject>(env,
      jcaller)).Release();
}

static jboolean JNI_PeerConnection_RemoveTrack(JNIEnv* env, const
    base::android::JavaParamRef<jobject>& jcaller,
    jlong sender);

JNI_GENERATOR_EXPORT jboolean Java_org_mediasoup_droid_PeerConnection_nativeRemoveTrack(
    JNIEnv* env,
    jobject jcaller,
    jlong sender) {
  return JNI_PeerConnection_RemoveTrack(env, base::android::JavaParamRef<jobject>(env, jcaller),
      sender);
}

static base::android::ScopedJavaLocalRef<jobject> JNI_PeerConnection_AddTransceiverWithTrack(JNIEnv*
    env, const base::android::JavaParamRef<jobject>& jcaller,
    jlong track);

JNI_GENERATOR_EXPORT jobject Java_org_mediasoup_droid_PeerConnection_nativeAddTransceiverWithTrack(
    JNIEnv* env,
    jobject jcaller,
    jlong track) {
  return JNI_PeerConnection_AddTransceiverWithTrack(env, base::android::JavaParamRef<jobject>(env,
      jcaller), track).Release();
}

static base::android::ScopedJavaLocalRef<jobject> JNI_PeerConnection_AddTransceiverOfType(JNIEnv*
    env, const base::android::JavaParamRef<jobject>& jcaller,
    const base::android::JavaParamRef<jobject>& mediaType);

JNI_GENERATOR_EXPORT jobject Java_org_mediasoup_droid_PeerConnection_nativeAddTransceiverOfType(
    JNIEnv* env,
    jobject jcaller,
    jobject mediaType) {
  return JNI_PeerConnection_AddTransceiverOfType(env, base::android::JavaParamRef<jobject>(env,
      jcaller), base::android::JavaParamRef<jobject>(env, mediaType)).Release();
}

static void JNI_PeerConnection_Close(JNIEnv* env, const base::android::JavaParamRef<jobject>&
    jcaller);

JNI_GENERATOR_EXPORT void Java_org_mediasoup_droid_PeerConnection_nativeClose(
    JNIEnv* env,
    jobject jcaller) {
  return JNI_PeerConnection_Close(env, base::android::JavaParamRef<jobject>(env, jcaller));
}

static base::android::ScopedJavaLocalRef<jstring> JNI_PeerConnection_GetStats(JNIEnv* env, const
    base::android::JavaParamRef<jobject>& jcaller);

JNI_GENERATOR_EXPORT jstring Java_org_mediasoup_droid_PeerConnection_nativeGetStats(
    JNIEnv* env,
    jobject jcaller) {
  return JNI_PeerConnection_GetStats(env, base::android::JavaParamRef<jobject>(env,
      jcaller)).Release();
}

static base::android::ScopedJavaLocalRef<jstring> JNI_PeerConnection_GetStatsForRtpSender(JNIEnv*
    env, const base::android::JavaParamRef<jobject>& jcaller,
    jlong selector);

JNI_GENERATOR_EXPORT jstring Java_org_mediasoup_droid_PeerConnection_nativeGetStatsForRtpSender(
    JNIEnv* env,
    jobject jcaller,
    jlong selector) {
  return JNI_PeerConnection_GetStatsForRtpSender(env, base::android::JavaParamRef<jobject>(env,
      jcaller), selector).Release();
}

static base::android::ScopedJavaLocalRef<jstring> JNI_PeerConnection_GetStatsForRtpReceiver(JNIEnv*
    env, const base::android::JavaParamRef<jobject>& jcaller,
    jlong selector);

JNI_GENERATOR_EXPORT jstring Java_org_mediasoup_droid_PeerConnection_nativeGetStatsForRtpReceiver(
    JNIEnv* env,
    jobject jcaller,
    jlong selector) {
  return JNI_PeerConnection_GetStatsForRtpReceiver(env, base::android::JavaParamRef<jobject>(env,
      jcaller), selector).Release();
}


static std::atomic<jmethodID>
    g_org_mediasoup_droid_PeerConnection_getNativeOwnedPeerConnection(nullptr);
static jlong Java_PeerConnection_getNativeOwnedPeerConnection(JNIEnv* env, const
    base::android::JavaRef<jobject>& obj) {
  jclass clazz = org_mediasoup_droid_PeerConnection_clazz(env);
  CHECK_CLAZZ(env, obj.obj(),
      org_mediasoup_droid_PeerConnection_clazz(env), 0);

  jni_generator::JniJavaCallContextChecked call_context;
  call_context.Init<
      base::android::MethodID::TYPE_INSTANCE>(
          env,
          clazz,
          "getNativeOwnedPeerConnection",
          "()J",
          &g_org_mediasoup_droid_PeerConnection_getNativeOwnedPeerConnection);

  jlong ret =
      env->CallLongMethod(obj.obj(),
          call_context.base.method_id);
  return ret;
}

}  // namespace mediasoupclient

#endif  // org_mediasoup_droid_PeerConnection_JNI
