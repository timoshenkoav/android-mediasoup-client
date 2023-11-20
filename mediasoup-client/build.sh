API_LEVEL=28
ABI=$1
BUILD_TYPE=$2

export PATH="$PATH:${ANDROID_NDK}/toolchains/llvm/prebuilt/linux-x86_64/bin/"

~/Android/sdk/cmake/3.22.1/bin/cmake \
-DBUILD_TYPE=${BUILD_TYPE} \
-DBUILD_TARGET=android \
-DCMAKE_SYSTEM_VERSION=${API_LEVEL}  \
-DANDROID_API_LEVEL=${API_LEVEL} \
-DANDROID_PLATFORM=android-${API_LEVEL}  \
-DANDROID_ABI=${ABI}  \
-DCMAKE_ANDROID_ARCH_ABI=${ABI}  \
-DCMAKE_LIBRARY_OUTPUT_DIRECTORY=${PWD}/output/${ABI}  \
-DCMAKE_RUNTIME_OUTPUT_DIRECTORY=${PWD}/output/${ABI}  \
-DCMAKE_BUILD_TYPE=${BUILD_TYPE}  \
-B${PWD}/output/${ABI}  \
-DLIBWEBRTC_INCLUDE_PATH=/Users/alex/Projects/Engageli/mediasoup-client-android/mediasoup-client/deps/webrtc/src/ \
-DLIBWEBRTC_BINARY_PATH=/Users/alex/Projects/Engageli/mediasoup-client-android/mediasoup-client/deps/webrtc/lib \
-DMEDIASOUPCLIENT_BUILD_TESTS=false \
-DSDPTRANSFORM_BUILD_TESTS=OFF \
-DSDPTRANSFORM_BUILD_READMEHELPER=OFF \
-DMEDIASOUPCLIENT_LOG_TRACE=ON \
-DMEDIASOUPCLIENT_LOG_DEV=ON \
-DCMAKE_TOOLCHAIN_FILE=${ANDROID_NDK}/build/cmake/android.toolchain.cmake \
-H/android \
-DCMAKE_SYSTEM_NAME=Android  \
-DANDROID_STL=c++_static \
-DANDROID_NDK=$ANDROID_NDK  \
-DCMAKE_ANDROID_NDK=$ANDROID_NDK  \
.

~/Android/sdk/cmake/3.22.1/bin/cmake --build $PWD/output/${ABI}