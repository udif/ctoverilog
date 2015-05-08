This is a fork of the code from www.c-to-verilog.com

The original code was written by Nadav Rotem.

Since the original code was not released under any form of source code control, and has not advanced for some time, I moved it to a public GIT repository in order to advance it further.
Near term goals are to update the code to the latest LLVM relase (currently the code requires LLVM 2.5).

This code is licensed under the GPL v3 license, according to the terms in www.c-to-verilog.com

In order to compile this code, please install gcc 4.2.4 (different versions may work, but I've tried only with 4.2.4)

Installing and compiling the code (This has been tried on 64-bit CentOS 7.1):

**You might require the following packages if you don't already have those:**

    sudo yum install git bison flex glibc-devel.i686 gcc-g++ cmake
    
**Here we start**

Get source code

    cd $HOME
    wget http://www.llvm.org/releases/2.5/llvm-2.5.tar.gz
    wget http://llvm.org/releases/2.5/llvm-gcc-4.2-2.5.source.tar.gz

Extract source code

    tar xvfz llvm-2.5.tar.gz
    cd llvm-2.5/lib/Target

Clone the ctoverilog repository. Notice the target directory name. This is important!

    git clone https://github.com/udif/ctoverilog.git Verilog
    cd $HOME/llvm-2.5

Prepare default configuration

    ./configure --enable-shared

Fix the configuration to add the Verilog directory

    sed -i -e 's/CppBackend/CppBackend Verilog/g' Makefile.config
    sed -i '/Sparc/a\  Verilog' CMakeLists.txt

Now build LLVM

    make

Follow instructions from llvm-gcc4.2-2.5.source/README.LLVM to install the gcc front end to LLVM:

    cd $HOME
    wget http://llvm.org/releases/2.5/llvm-gcc-4.2-2.5.source.tar.gz
    mkdir llvm-gcc
    cd llvm-gcc
    tar xvfz ../llvm-gcc-4.2-2.5.source.tar.gz
    mkdir obj install
    cd obj
    LLVMOBJDIR=~/llvm-2.5
    BUILDOPTIONS=LLVM_VERSION_INFO=2.5
    ../llvm-gcc4.2-2.5.source/configure --prefix=`pwd`/../install --program-prefix=llvm- --enable-llvm=$LLVMOBJDIR --enable-languages=c,c++ --disable-multilib
    make $BUILDOPTIONS
    make install



