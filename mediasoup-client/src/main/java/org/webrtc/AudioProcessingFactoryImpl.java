package org.webrtc;

public class AudioProcessingFactoryImpl implements AudioProcessingFactory{
    native long createNativeProcessing();
    @Override
    public long createNative() {
        return createNativeProcessing();
    }
}
