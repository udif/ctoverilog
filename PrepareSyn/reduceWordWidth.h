/* Nadav Rotem  - C-to-Verilog.com */
#ifndef LLVM_REDUCE_WORDWIDTH_H
#define LLVM_REDUCE_WORDWIDTH_H

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
    class ReduceWordWidthPass : public FunctionPass {

        public:
            /// needed by LLVM
            static char ID;
            /** 
             * @brief C'tor in LLVM style
             */
            ReduceWordWidthPass() : FunctionPass((intptr_t)&ID) {}

            /** 
             * @brief Requires LoopInfo analysis and tells llvm that
             * we change nothing
             * 
             * @param AU llvm analysis usage internal object
             */
            virtual void getAnalysisUsage(AnalysisUsage &AU) const {
                AU.setPreservesCFG();
            }

            bool removeUnusedInstructions(Instruction* inst);
            bool reduceOperatorWordWidth(Instruction* inst);

            virtual bool runOnFunction(Function &F);

        private:

    }; // class



} //end of namespace
#endif // h guard
