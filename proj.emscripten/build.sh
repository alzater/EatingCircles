OXYGINE="/home/alzater/cpp-projects/My-games/oxygine/oxygine-framework"
export EMSCRIPTEN="/home/alzater/emsdk_portable/emscripten/1.35.0"
python $OXYGINE/tools/others/embed_folder_js.py -s ../data
set EMCC_DEBUG=1
mkdir build
cd build
cmake -DCMAKE_TOOLCHAIN_FILE="$EMSCRIPTEN/cmake/Modules/Platform/Emscripten.cmake" -G"Unix Makefiles" ..
make -j5
cd ..
#cp ../data/sounds/* build/data/sounds
