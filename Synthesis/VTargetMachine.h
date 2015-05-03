/* Nadav Rotem  - C-to-Verilog.com */
#ifndef VTARGETMACHINE_H
#define VTARGETMACHINE_H

#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetData.h"

namespace llvm {

struct VTargetMachine : public TargetMachine {
  const TargetData DataLayout;       // Calculates type size & alignment

  VTargetMachine(const Module &M, const std::string &FS)
    : DataLayout(&M) {}

  virtual bool WantsWholeFile() const { return true; }
  virtual bool addPassesToEmitWholeFile(PassManager &PM, raw_ostream &Out,
                                        CodeGenFileType FileType, bool Fast);

  // This class always works, but shouldn't be the default in most cases.
  static unsigned getModuleMatchQuality(const Module &M) { return 1; }
  
  virtual const TargetData *getTargetData() const { return &DataLayout; }
};

} // End llvm namespace


#endif
