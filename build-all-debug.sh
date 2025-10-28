cmake   -S . -B build/debug \
        -G "Ninja" \
        -DCMAKE_BUILD_TYPE=Debug \
        -DCMAKE_CXX_STANDARD=23 \
        -DCMAKE_CXX_FLAGS="-std=c++23" \
        -DCMAKE_EXPORT_COMPILE_COMMANDS=1 \
        -DPHH_BUILD_TEST=ON \
        -DPHH_BUILD_TOOL=ON;

ln -sf build/debug/compile_commands.json;

cmake --build build/debug;

