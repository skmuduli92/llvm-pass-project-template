#include "llvm/Pass.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"

#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Module.h"

#include "llvm/Support/raw_ostream.h"
#include "llvm/ADT/BitVector.h"

// #include "Liveness.hpp"

using namespace llvm;

namespace {

  struct DummyPass : public ModulePass {
    static char ID;
    DummyPass() : ModulePass(ID) {}

    bool runOnModule(Module& mod) override {
      errs() << "DummyPass: ";
      errs() << (mod.getName()) << '\n';

      // LivenessDFA livenessAnalysis;
      // livenessAnalysis.runAnalysis(F);
      return false; // not altering the IR
    }

    virtual StringRef getPassName() const { return "DummyPass Pass"; }

  }; // end of struct DummyPass
}  // end of anonymous namespace

char DummyPass::ID = 0;
static RegisterPass<DummyPass> X("livevar", "DummyPass Analysis Pass",
false /* Only looks at CFG */,
false /* Analysis Pass */);
