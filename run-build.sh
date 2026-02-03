#!/usr/bin/sh
set -e;

cmake -S . -B build/debug -G "Ninja" \
    -DCMAKE_BUILD_TYPE=Debug \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=1;

ln -sf ./build/debug/compile_commands.json ./;

cmake --build build/debug --target all --config Debug -- -j$(nproc);
