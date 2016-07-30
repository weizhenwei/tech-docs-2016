#!/bin/sh

set -e

echo "before run this script, please make sure it's under ./src dirctory"

softlinks="./base/third_party/libevent ./build ./buildtools ./mojo ./testing ./third_party/binutils ./third_party/boringssl ./third_party/colorama ./third_party/drmemory ./third_party/expat ./third_party/ffmpeg ./third_party/instrumented_libraries ./third_party/jsoncpp ./third_party/libc++-static ./third_party/libFuzzer ./third_party/libjpeg ./third_party/libjpeg_turbo ./third_party/libsrtp ./third_party/libvpx ./third_party/libyuv ./third_party/llvm-build ./third_party/nss ./third_party/ocmock ./third_party/openh264 ./third_party/openmax_dl ./third_party/opus ./third_party/proguard ./third_party/protobuf ./third_party/sqlite ./third_party/syzygy ./third_party/usrsctp ./third_party/WebKit ./third_party/yasm ./third_party/zlib ./tools/clang ./tools/generate_library_loader ./tools/generate_stubs ./tools/gn ./tools/gyp ./tools/luci-go ./tools/mb ./tools/memory ./tools/protoc_wrapper ./tools/python ./tools/swarming_client ./tools/valgrind ./tools/vim ./tools/win ./tools/xdisplaycheck"

for var in $softlinks
do
    target_dir=$var

    # removing the heading "./";
    len=${#target_dir}
    simple=`echo $target_dir | cut -c 3-$len`

    source_dir="./chromium/src/"$simple

    echo "Replacing softlink $target_dir with its destination $source_dir"
    # rm -rf $target_dir
    # cp -rf $source_dir $target_dir
done


# we don't need third_party/ffmpeg anymore, so just delete it.
echo "we don't need third_party/ffmpeg anymore, so just delete it."
# rm -rf third_party/ffmpeg

echo "Replacing softlink with destination DONE"

