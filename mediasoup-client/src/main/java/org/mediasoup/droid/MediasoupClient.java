package org.mediasoup.droid;

import android.content.Context;

import org.webrtc.Loggable;
import org.webrtc.Logging;
import org.webrtc.PeerConnectionFactory;
import org.webrtc.PeerConnectionFactory.InitializationOptions;

public class MediasoupClient {

    static {
        System.loadLibrary("mediasoupclient_so");
    }

    public static void initialize(Context appContext) {
        initialize(appContext, null, null, null);
    }

    public static void initialize(Context appContext, String fieldTrials, Loggable loggable, Logging.Severity severity) {
        InitializationOptions options =
                InitializationOptions.builder(appContext)
                        .setFieldTrials(fieldTrials)
                        .setEnableInternalTracer(true)
                        .setNativeLibraryName("mediasoupclient_so")
                        .setInjectableLogger(loggable, severity)
                        .createInitializationOptions();
        PeerConnectionFactory.initialize(options);
    }

    public static String version() {
        return nativeVersion();
    }

    private static native String nativeVersion();
}
