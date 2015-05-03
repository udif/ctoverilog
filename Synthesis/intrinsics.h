/* Nadav Rotem  - C-to-Verilog.com */
#ifndef LLVM_VERILOG_INTRINSICS_H
#define LLVM_VERILOG_INTRINSICS_H

#include "llvm/Pass.h"
#include "llvm/Function.h"
#include "llvm/Instructions.h"
#include "llvm/Constants.h"
#include "llvm/ADT/StringExtras.h"
#include "llvm/Support/Streams.h"
#include "llvm/Module.h"
#include "llvm/ADT/Statistic.h"
#include "llvm/ADT/SmallVector.h"
#include "llvm/Support/CFG.h"
#include "llvm/DerivedTypes.h"
#include "llvm/Analysis/LoopInfo.h"
#include "llvm/Support/InstIterator.h"

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>

using namespace llvm;
using std::string; 
using std::vector; 

namespace xVerilog {

    string getIntrinsicForInstruction(CallInst *intrin, vector<string> &params);


} //end of namespace
#endif // h guard
