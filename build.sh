CLANG=~/void/prebuilts/clang/host/linux-x86/clang-sdclang/bin/
GCC32=~/void/prebuilts/gcc/linux-x86/arm-linux-androideabi-4.9/bin/
GCC64=~/void/prebuilts/gcc/linux-x86/aarch64-linux-android-4.9/bin/

PATH=$CLANG:$GCC64:$GCC32:$PATH

export PATH
export ARCH=arm64

export CLANG_TRIPLE
export CROSS_COMPILE
export CROSS_COMPILE_ARM32

CLANG_TRIPLE="aarch64-linux-gnu-"
CROSS_COMPILE="aarch64-linux-gnu-"
CROSS_COMPILE_ARM32="arm-linux-gnueabi-"

output_dir=out
make O="$output_dir" \
            alioth_defconfig

make -j $(nproc) \
            O="$output_dir" \
            CC="ccache clang" \
            HOSTCC=gcc \
            LD=ld.lld \
            AS=llvm-as \
            AR=llvm-ar \
            NM=llvm-nm \
            OBJCOPY=llvm-objcopy \
            OBJDUMP=llvm-objdump \
            STRIP=llvm-strip \
            LLVM=1 \
            LLVM_IAS=1
