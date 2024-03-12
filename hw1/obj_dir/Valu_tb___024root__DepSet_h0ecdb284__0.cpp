// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Valu_tb.h for the primary calling header

#include "Valu_tb__pch.h"
#include "Valu_tb___024root.h"

void Valu_tb___024root___eval_act(Valu_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Valu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_tb___024root___eval_act\n"); );
}

VL_INLINE_OPT void Valu_tb___024root___nba_sequent__TOP__0(Valu_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Valu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_tb___024root___nba_sequent__TOP__0\n"); );
    // Body
    if (VL_UNLIKELY((((vlSelf->alu_tb__DOT__ans_rd 
                       != vlSelf->alu_tb__DOT__rd) 
                      | ((IData)(vlSelf->alu_tb__DOT__ans_zero) 
                         != (0U == vlSelf->alu_tb__DOT__rd))) 
                     | ((IData)(vlSelf->alu_tb__DOT__ans_overflow) 
                        != (1U & ((2U == (IData)(vlSelf->alu_tb__DOT__op))
                                   ? (((vlSelf->alu_tb__DOT__rs1 
                                        >> 0x1fU) & 
                                       ((~ (vlSelf->alu_tb__DOT__rd 
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
                                             & (~ (vlSelf->alu_tb__DOT__rd 
                                                   >> 0x1fU)))) 
                                         | ((~ (vlSelf->alu_tb__DOT__rs1 
                                                >> 0x1fU)) 
                                            & ((vlSelf->alu_tb__DOT__rs2 
                                                & vlSelf->alu_tb__DOT__rd) 
                                               >> 0x1fU)))))))))) {
        VL_WRITEF_NX("Fail Pattern %11d\n",0,32,vlSelf->alu_tb__DOT__i);
        VL_FINISH_MT("alu_tb.v", 51, "");
        VL_FINISH_MT("alu_tb.v", 51, "");
    } else {
        VL_WRITEF_NX("Pass Pattern %11d\n",0,32,vlSelf->alu_tb__DOT__i);
    }
    vlSelf->alu_tb__DOT__i = ((IData)(1U) + vlSelf->alu_tb__DOT__i);
}

VL_INLINE_OPT void Valu_tb___024root___nba_sequent__TOP__1(Valu_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Valu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_tb___024root___nba_sequent__TOP__1\n"); );
    // Init
    IData/*31:0*/ alu_tb__DOT__alu__DOT____VdfgTmp_h2300d0f6__0;
    alu_tb__DOT__alu__DOT____VdfgTmp_h2300d0f6__0 = 0;
    // Body
    if ((vlSelf->alu_tb__DOT__pattern ? feof(VL_CVT_I_FP(vlSelf->alu_tb__DOT__pattern)) : true)) {
        vlSelf->finish = 1U;
    } else {
        vlSelf->alu_tb__DOT__temp = VL_FSCANF_INX(vlSelf->alu_tb__DOT__pattern,"%#\n",0,
                                                  4,
                                                  &(vlSelf->alu_tb__DOT__op)) ;
        vlSelf->alu_tb__DOT__temp = VL_FSCANF_INX(vlSelf->alu_tb__DOT__pattern,"%#\n",0,
                                                  32,
                                                  &(vlSelf->alu_tb__DOT__rs1)) ;
        vlSelf->alu_tb__DOT__temp = VL_FSCANF_INX(vlSelf->alu_tb__DOT__pattern,"%#\n",0,
                                                  32,
                                                  &(vlSelf->alu_tb__DOT__rs2)) ;
        vlSelf->alu_tb__DOT__temp = VL_FSCANF_INX(vlSelf->alu_tb__DOT__pattern,"%#\n",0,
                                                  32,
                                                  &(vlSelf->alu_tb__DOT__ans_rd)) ;
        vlSelf->alu_tb__DOT__temp = VL_FSCANF_INX(vlSelf->alu_tb__DOT__pattern,"%#\n",0,
                                                  1,
                                                  &(vlSelf->alu_tb__DOT__ans_zero)) ;
        vlSelf->alu_tb__DOT__temp = VL_FSCANF_INX(vlSelf->alu_tb__DOT__pattern,"%#\n",0,
                                                  1,
                                                  &(vlSelf->alu_tb__DOT__ans_overflow)) ;
    }
    alu_tb__DOT__alu__DOT____VdfgTmp_h2300d0f6__0 = 
        (vlSelf->alu_tb__DOT__rs1 | vlSelf->alu_tb__DOT__rs2);
    vlSelf->alu_tb__DOT__rd = ((0U == (IData)(vlSelf->alu_tb__DOT__op))
                                ? (vlSelf->alu_tb__DOT__rs1 
                                   & vlSelf->alu_tb__DOT__rs2)
                                : ((1U == (IData)(vlSelf->alu_tb__DOT__op))
                                    ? alu_tb__DOT__alu__DOT____VdfgTmp_h2300d0f6__0
                                    : ((2U == (IData)(vlSelf->alu_tb__DOT__op))
                                        ? (vlSelf->alu_tb__DOT__rs1 
                                           + vlSelf->alu_tb__DOT__rs2)
                                        : ((6U == (IData)(vlSelf->alu_tb__DOT__op))
                                            ? (vlSelf->alu_tb__DOT__rs1 
                                               - vlSelf->alu_tb__DOT__rs2)
                                            : ((0xcU 
                                                == (IData)(vlSelf->alu_tb__DOT__op))
                                                ? (~ alu_tb__DOT__alu__DOT____VdfgTmp_h2300d0f6__0)
                                                : (
                                                   (7U 
                                                    == (IData)(vlSelf->alu_tb__DOT__op))
                                                    ? 
                                                   ((vlSelf->alu_tb__DOT__rs1 
                                                     < vlSelf->alu_tb__DOT__rs2)
                                                     ? 1U
                                                     : 0U)
                                                    : 0U))))));
}

void Valu_tb___024root___eval_nba(Valu_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Valu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_tb___024root___eval_nba\n"); );
    // Body
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Valu_tb___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Valu_tb___024root___nba_sequent__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void Valu_tb___024root___eval_triggers__act(Valu_tb___024root* vlSelf);

bool Valu_tb___024root___eval_phase__act(Valu_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Valu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_tb___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Valu_tb___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Valu_tb___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Valu_tb___024root___eval_phase__nba(Valu_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Valu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_tb___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Valu_tb___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Valu_tb___024root___dump_triggers__nba(Valu_tb___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Valu_tb___024root___dump_triggers__act(Valu_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Valu_tb___024root___eval(Valu_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Valu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_tb___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Valu_tb___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("alu_tb.v", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Valu_tb___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("alu_tb.v", 1, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Valu_tb___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Valu_tb___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Valu_tb___024root___eval_debug_assertions(Valu_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Valu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_tb___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
}
#endif  // VL_DEBUG
