/* Nadav Rotem  - C-to-Verilog.com */
#include "Opcodes.h"

namespace xVerilog{

    DelayInst::DelayInst(
            Value *S, const Type *Ty, const std::string &Name, Instruction *InsertBefore
            )  : CastInst(Ty, ZExt, S, Name, InsertBefore) { 
    }

    DelayInst::DelayInst(
            Value *S, const Type *Ty, const std::string &Name, BasicBlock *InsertAtEnd
            )  : CastInst(Ty, ZExt, S, Name, InsertAtEnd) { 
    }


    InInst::InInst(const InInst &In): 
        Instruction(In.getType(),0,0,0) {
        }

    InInst::InInst(const Type *Ty, Value *value, ExternamModule *where): 
        Instruction(Ty,OtherOpsEnd,0,0), m_type(Ty), m_toSave(value), m_extern(where){
        }

    InInst* InInst::clone() const {
        assert(0 && "Cannot clone EOL");abort();
        return 0;
    }

     CastInst   *DelayInst::clone()     const { return new DelayInst(*this); }

} // namespace
