#include "../src/disassembler.h"
#include <iostream>

//std::string ProtToString(vm_prot_t prot) {
//  std::string str = "";
//  if (prot & VM_PROT_READ)
//    str += "R";
//  if (prot & VM_PROT_WRITE)
//    str += "W";
//  if (prot & VM_PROT_EXECUTE)
//    str += "X";
//
//  return str;
//}

//int main(int argc, char **argv) {
//    x86ThreadState *state = new x86ThreadState(mach_thread_self());
//    state->Load();
//    
//    std::cout << state->Description() << std::endl;
//}


const uint8_t code[] = { 0x5D };

int main() {
    Disassembler ds = Disassembler(0x0, code, 1);
    ds.Setup();
    auto instr = ds.Disassemble();
    std::cout << instr.mnemonic() << std::endl << instr.operands() << std::endl;
}
