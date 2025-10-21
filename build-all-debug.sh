cmake   -S . -B build/debug         \
        -G "Ninja"                  \
        -DCMAKE_BUILD_TYPE=Debug    \
        -DPHH_BUILD_TEST=OFF    \
        -DPHH_BUILD_TOOL=OFF   ;

ln -sf build/debug/compile_commands.json;

cmake --build build/debug;
