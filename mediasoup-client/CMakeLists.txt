cmake_minimum_required(VERSION 3.19)

project(mediasoupclient_so LANGUAGES CXX)

set(CC_COMPILER "${ANDROID_TOOLCHAIN_ROOT}/bin/i686-linux-android${ANDROID_API_LEVEL}-clang")

set(SUBCOMMAND_OPTS "-DCMAKE_TOOLCHAIN_FILE=${CMAKE_ANDROID_NDK}/build/cmake/android.toolchain.cmake -DCMAKE_C_COMPILER=${CMAKE_C_COMPILER} -DHYDRA_PLATFORM=${HYDRA_PLATFORM} -DBUILD_TARGET=${BUILD_TARGET} -DBUILD_TYPE=${BUILD_TYPE} -Handroid -DCMAKE_SYSTEM_NAME=${CMAKE_SYSTEM_NAME} -DCMAKE_SYSTEM_VERSION=${CMAKE_SYSTEM_VERSION} -DANDROID_PLATFORM=${ANDROID_PLATFORM} -DANDROID_ABI=${ANDROID_ABI} -DCMAKE_ANDROID_ARCH_ABI=${CMAKE_ANDROID_ARCH_ABI}")

# build config string for external projects based on CMake
set(EXT_CMAKE_CFG              "CC=${CC_COMPILER}")
set(EXT_CMAKE_CFG              "${EXT_CMAKE_CFG} -DCMAKE_POSITION_INDEPENDENT_CODE=ON")

include_directories(${CMAKE_ANDROID_NDK}/sources/android/cpufeatures)


# Set version number.
set(mediasoup_client_so_VERSION_MAJOR 3)
set(mediasoup_client_so_VERSION_MINOR 0)
set(mediasoup_client_so_VERSION_PATCH 8)

# C++ standard requirements.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX11_EXTENSION_COMPILE_OPTION "-std=c++17")
set(
	SOURCE_DIR
	${mediasoupclient_so_SOURCE_DIR}/src/main/jni/
)

set(
	SOURCE_FILES
	${SOURCE_DIR}/jni_generator_helper.cpp
	${SOURCE_DIR}/jni_onload.cpp
	${SOURCE_DIR}/java_types.cpp
	${SOURCE_DIR}/consumer_jni.cpp
	${SOURCE_DIR}/device_jni.cpp
	${SOURCE_DIR}/logger_jni.cpp
	${SOURCE_DIR}/mediasoup_client_jni.cpp
	${SOURCE_DIR}/peerconnection_jni.cpp
	${SOURCE_DIR}/producer_jni.cpp
	${SOURCE_DIR}/transport_jni.cpp
)

# TODO(haiyang wu): add condition
list(APPEND SOURCE_FILES ${PROJECT_SOURCE_DIR}/src/androidTest/jni/parameters_jni.cpp)
list(APPEND SOURCE_FILES ${PROJECT_SOURCE_DIR}/deps/libmediasoupclient/test/src/fakeParameters.cpp)

# Create target.
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

if(${MEDIASOUPCLIENT_LOG_TRACE})
	target_compile_definitions(${PROJECT_NAME}
		PRIVATE MSC_LOG_TRACE=1
	)
endif()

if(${MEDIASOUPCLIENT_LOG_DEV})
	target_compile_definitions(${PROJECT_NAME}
		PRIVATE MSC_LOG_DEV=1
	)
endif()

# Source Dependencies. override LIBWEBRTC_BINARY_PATH
# TODO(HaiyangWu) add libwebrtc.a without change CMakeLists in libmediasoupclient
# set(LIBWEBRTC_BINARY_PATH ${LIBWEBRTC_BINARY_ANDROID_PATH}/${ANDROID_ABI} CACHE STRING "libwebrtc binary path" FORCE)
add_subdirectory("deps/libmediasoupclient")

# Add some compile flags to our source files.
set_source_files_properties(${SOURCE_FILES}
	PROPERTIES COMPILE_FLAGS -Wall -Wextra -Wpedantic)
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++21")
include_directories(
		SYSTEM
		"${LIBWEBRTC_INCLUDE_PATH}/"
		"${LIBWEBRTC_INCLUDE_PATH}/third_party/abseil-cpp/"
)

# Private (implementation) header files.
target_include_directories(${PROJECT_NAME} PUBLIC
	"${SOURCE_DIR}/"
	"${SOURCE_DIR}/include"
	"${PROJECT_SOURCE_DIR}/deps/libmediasoupclient/include"
	"${PROJECT_SOURCE_DIR}/deps/libmediasoupclient/test/include"
	"${PROJECT_SOURCE_DIR}/deps/libmediasoupclient/deps/libsdptransform/include"
	"${LIBWEBRTC_INCLUDE_PATH}"
	"${LIBWEBRTC_INCLUDE_PATH}/third_party/abseil-cpp"
)

# Compile definitions for libwebrtc.
target_compile_definitions(${PROJECT_NAME} PUBLIC
	$<$<NOT:$<PLATFORM_ID:Windows>>:WEBRTC_POSIX>
	$<$<PLATFORM_ID:Windows>:WEBRTC_WIN>
	$<$<PLATFORM_ID:Darwin>:WEBRTC_MAC>
)

# Public (interface) dependencies.
target_link_libraries(${PROJECT_NAME} PUBLIC
	android
	log
	OpenSLES
	mediasoupclient
)
