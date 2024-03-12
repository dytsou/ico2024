// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Valu_tb__Syms.h"


void Valu_tb___024root__trace_chg_0_sub_0(Valu_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Valu_tb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_tb___024root__trace_chg_0\n"); );
    // Init
    Valu_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Valu_tb___024root*>(voidSelf);
    Valu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Valu_tb___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Valu_tb___024root__trace_chg_0_sub_0(Valu_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Valu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_tb___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0U])) {
        bufp->chgIData(oldp+0,(vlSelf->alu_tb__DOT__pattern),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgCData(oldp+1,(vlSelf->alu_tb__DOT__op),4);
        bufp->chgIData(oldp+2,(vlSelf->alu_tb__DOT__rs1),32);
        bufp->chgIData(oldp+3,(vlSelf->alu_tb__DOT__rs2),32);
        bufp->chgIData(oldp+4,(vlSelf->alu_tb__DOT__rd),32);
        bufp->chgIData(oldp+5,(vlSelf->alu_tb__DOT__ans_rd),32);
        bufp->chgBit(oldp+6,((0U == vlSelf->alu_tb__DOT__rd)));
        bufp->chgBit(oldp+7,(vlSelf->alu_tb__DOT__ans_zero));
        bufp->chgBit(oldp+8,((1U & ((2U == (IData)(vlSelf->alu_tb__DOT__op))
                                     ? (((vlSelf->alu_tb__DOT__rs1 
                                          >> 0x1fU) 
                                         & ((~ (vlSelf->alu_tb__DOT__rd 
                                                >> 0x1fU)) 
                                            & (vlSelf->alu_tb__DOT__rs2 
                                               >> 0x1fU))) 
                                        | ((~ (vlSelf->alu_tb__DOT__rs1 
                                               >> 0x1fU)) 
                                           & ((~ (vlSelf->alu_tb__DOT__rs2 
                                                  >> 0x1fU)) 
                                              & (vlSelf->alu_tb__DOT__rd 
                                                 >> 0x1fU))))
                                     : ((6U == (IData)(vlSelf->alu_tb__DOT__op)) 
                                        & (((vlSelf->alu_tb__DOT__rs1 
                                             >> 0x1fU) 
                                            & ((~ (vlSelf->alu_tb__DOT__rs2 
                                                   >> 0x1fU)) 
                                               & (~ 
                                                  (vlSelf->alu_tb__DOT__rd 
                                                   >> 0x1fU)))) 
                                           | ((~ (vlSelf->alu_tb__DOT__rs1 
                                                  >> 0x1fU)) 
                                              & ((vlSelf->alu_tb__DOT__rs2 
                                                  & vlSelf->alu_tb__DOT__rd) 
                                                 >> 0x1fU))))))));
        bufp->chgBit(oldp+9,(vlSelf->alu_tb__DOT__ans_overflow));
        bufp->chgIData(oldp+10,(vlSelf->alu_tb__DOT__temp),32);
    }
    bufp->chgBit(oldp+11,(vlSelf->clk));
    bufp->chgBit(oldp+12,(vlSelf->finish));
    bufp->chgIData(oldp+13,(vlSelf->alu_tb__DOT__i),32);
}

void Valu_tb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_tb___024root__trace_cleanup\n"); );
    // Init
    Valu_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Valu_tb___024root*>(voidSelf);
    Valu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
