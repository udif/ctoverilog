/* Nadav Rotem  - C-to-Verilog.com */
#ifndef REMOVE_ALLOCA_PASS_H
#define REMOVE_ALLOCA_PASS_H

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

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>

using namespace llvm;

using std::set;
using std::map;
using std::vector;
using std::pair;
using std::string;

namespace xVerilog {

    /* 
     */
    class RemoveAllocaPass : public ModulePass {

        public:
            /// needed by LLVM
            static char ID;
            /** 
             * @brief C'tor in LLVM style
             */
            RemoveAllocaPass() : ModulePass((intptr_t)&ID) {}

            /** 
             * @param AU llvm analysis usage internal object
             */
            virtual void getAnalysisUsage(AnalysisUsage &AU) const {
                //AU.setPreservesCFG();
            }

            virtual bool runOnModule(Module &M);
    }; // class



} //end of namespace
#endif // h guard
