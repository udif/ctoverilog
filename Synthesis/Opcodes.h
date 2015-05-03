/* Nadav Rotem  - C-to-Verilog.com */
#ifndef LLVM_OPCODE_OP_H
#define LLVM_OPCODE_OP_H

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

#include "../params.h"
#include "globalVarsRegistry.h"
using namespace llvm;

using std::set;
using std::map;
using std::vector;
using std::pair;
using std::string;

namespace xVerilog {

    class ExternamModule;

    /// @brief This class represents a static delay.
    class DelayInst : public CastInst {
        /// @brief Private copy constructor
        DelayInst(const DelayInst &CI)
            : CastInst(CI.getType(), ZExt, CI.getOperand(0)) {
            }
        public:
        /// @brief Constructor with insert-before-instruction semantics
        DelayInst(
                Value *S,                     ///< The value to be zero extended
                const Type *Ty,               ///< The type to zero extend to
                const std::string &Name = "", ///< A name for the new instruction
                Instruction *InsertBefore = 0 ///< Where to insert the new instruction
                );

        /// @brief Constructor with insert-at-end semantics.
        DelayInst(
                Value *S,                     ///< The value to be zero extended
                const Type *Ty,               ///< The type to zero extend to
                const std::string &Name,      ///< A name for the new instruction
                BasicBlock *InsertAtEnd       ///< The block to insert the instruction into
                );

        /// @brief Clone an identical DelayInst
        virtual CastInst *clone() const;

        /// @brief Methods for support type inquiry through isa, cast, and dyn_cast:
        static inline bool classof(const DelayInst *) { return true; }
        static inline bool classof(const Instruction *I) {
            // TODO: fixme
            return I->getOpcode() == ZExt;
        }
        static inline bool classof(const Value *V) {
            return isa<Instruction>(V) && classof(cast<Instruction>(V));
        }
    };




    class InInst: public Instruction {
        public:
            InInst(const Type *Ty, Value *value, ExternamModule *where);
            InInst(const InInst &In);
            virtual InInst *clone() const;

            const char *getOpcodeName() const { return "*end-of-list-inst*"; }
            const Type* getType() const { return m_type; }

            // Methods for support type inquiry through isa, cast, and dyn_cast...
            static inline bool classof(const InInst *) { return true; }
            static inline bool classof(const Instruction *I) {
                return I->getOpcode() == OtherOpsEnd;
            }
            static inline bool classof(const Value *V) {
                return isa<Instruction>(V) && classof(cast<Instruction>(V));
            }


        private:
            // link to externam module
            const Type* m_type;
            Value* m_toSave;
            ExternamModule* m_extern;
    }; // class



} //end of namespace
#endif // h guard
