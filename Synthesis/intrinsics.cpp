/* Nadav Rotem  - C-to-Verilog.com */
#include "intrinsics.h"
#include <sstream>
namespace xVerilog {


    string getIntrinsicForInstruction(CallInst *intrin, vector<string> &params) {
         std::stringstream ss;
         string macro_name =  intrin->getCalledFunction()->getNameStr(); 
         if (macro_name == "rotate_left") {
            assert(params.size()==3 && "rotate_left needs to have two params");
            string var = params[1];
            string offset = params[2];
            ss<<"{" << var<<"[31-"<<offset<<":0]"<< "," << var<<"[31:32-"<<offset<<"]}";
         }   
       return ss.str();
    }


} // namespace
