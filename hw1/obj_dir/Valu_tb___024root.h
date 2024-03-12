// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Valu_tb.h for the primary calling header

#ifndef VERILATED_VALU_TB___024ROOT_H_
#define VERILATED_VALU_TB___024ROOT_H_  // guard

#include "verilated.h"


class Valu_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Valu_tb___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_OUT8(finish,0,0);
    CData/*3:0*/ alu_tb__DOT__op;
    CData/*0:0*/ alu_tb__DOT__ans_zero;
    CData/*0:0*/ alu_tb__DOT__ans_overflow;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ alu_tb__DOT__rs1;
    IData/*31:0*/ alu_tb__DOT__rs2;
    IData/*31:0*/ alu_tb__DOT__rd;
    IData/*31:0*/ alu_tb__DOT__ans_rd;
    IData/*31:0*/ alu_tb__DOT__i;
    IData/*31:0*/ alu_tb__DOT__pattern;
    IData/*31:0*/ alu_tb__DOT__temp;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Valu_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Valu_tb___024root(Valu_tb__Syms* symsp, const char* v__name);
    ~Valu_tb___024root();
    VL_UNCOPYABLE(Valu_tb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
