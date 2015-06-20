//===-- VTargetInfo.cpp - Verilog Target Implementation -----------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "VTargetMachine.h"
#include "llvm/Module.h"
#include "llvm/Target/TargetRegistry.h"
using namespace llvm;

Target llvm::TheVerilogTarget;

extern "C" void LLVMInitializeVerilogTargetInfo() { 
  RegisterTarget<> X(TheVerilogTarget, "v", "Verilog backend");
}

