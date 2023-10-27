# Graphics Utilities
These utilities are a set of applications to showcase graphics APIs and have a readily available example to showcase a system's GPU functionality. Some examples include extension support, YUV and other color format support, API support (OpenGL, Vulkan) and simple benchmark data.

## Build Instructions
Follows usual CMAKE instructions. My preference is a separate build directory:

mkdir build; cd build
cmake ../

If you wish to cross-compile, a sample toolchain file has been provided (cmake-arm64.toolchain.example). Fill it in with the path to your filesystem and your toolchain for compilation. To cross-compile, run:

cmake -DCMAKE_TOOLCHAIN_FILE=../cmake-arm64.toolchain ../

