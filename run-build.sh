#!/usr/bin/sh
set -e;

# this is default build for debug
cmake -S . -B build/debug -G "Ninja" \
    -DCMAKE_BUILD_TYPE=Debug \
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

ln -sf ./build/debug/compile_commands.json ./;

cmake --build build/debug --target all --config Debug -- -j$(nproc);
