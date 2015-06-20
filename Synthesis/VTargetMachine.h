/* Nadav Rotem  - C-to-Verilog.com */
#ifndef VTARGETMACHINE_H
#define VTARGETMACHINE_H

#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetData.h"

namespace llvm {

//class formatted_raw_ostream;

struct VTargetMachine : public TargetMachine {
  const TargetData DataLayout;       // Calculates type size & alignment

  VTargetMachine(const Target &T, const std::string &TT,
                 const std::string &FS)
    : TargetMachine(T) {}

  virtual bool WantsWholeFile() const { return true; }
  virtual bool addPassesToEmitWholeFile(PassManager &PM,
                                        formatted_raw_ostream &Out,
                                        CodeGenFileType FileType,
                                        CodeGenOpt::Level level);

  virtual const TargetData *getTargetData() const { return 0; }
};

extern Target TheVerilogTarget;

} // End llvm namespace


#endif
