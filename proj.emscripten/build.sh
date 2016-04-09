OXYGINE="/home/alzater/cpp-projects/My-games/oxygine/oxygine-framework"
export EMSCRIPTEN="/home/alzater/emsdk_portable/emscripten/master"
python $OXYGINE/tools/others/embed_folder_js.py -s ../data
set EMCC_DEBUG=1
mkdir build
cd build
cmake -DCMAKE_TOOLCHAIN_FILE="$EMSCRIPTEN/cmake/Modules/Platform/Emscripten.cmake" -G"Unix Makefiles" ..
make
cd ..
#cp ../data/sounds/* build/data/sounds
