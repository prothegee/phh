#!/usr/bin/sh
set -e;

BUILD_PATH="build/debug";
BUILD_TYPE="Debug";

# this is default build for debug
cmake -S . -B $BUILD_PATH -G "Ninja" \
    -DCMAKE_BUILD_TYPE=$BUILD_TYPE \
    -DCMAKE_CXX_STANDARD=23 \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=1 \
    -DBUILD_TESTS=ON \
    -DBUILD_TOOLS=ON \
    -DBUILD_SHARED_LIBS=ON \
    -DPHH_USE_CURL=ON \
    -DPHH_USE_ARGON2=ON \
    -DPHH_USE_OPENSSL=ON \
    -DPHH_USE_JSONCPP=ON \
    -DPHH_USE_CRYPTOPP=ON \
    -DPHH_USE_RAPIDJSON=ON \
    -DPHH_USE_ZXINGCPP=ON;

ln -sf $BUILD_PATH/compile_commands.json ./;

cmake --build $BUILD_PATH --target all --config $BUILD_TYPE -- -j$(nproc);
