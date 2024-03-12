// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Valu_tb.h for the primary calling header

#include "Valu_tb__pch.h"
#include "Valu_tb___024root.h"

VL_ATTR_COLD void Valu_tb___024root___eval_static__TOP(Valu_tb___024root* vlSelf);

VL_ATTR_COLD void Valu_tb___024root___eval_static(Valu_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Valu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_tb___024root___eval_static\n"); );
    // Body
    Valu_tb___024root___eval_static__TOP(vlSelf);
}

VL_ATTR_COLD void Valu_tb___024root___eval_static__TOP(Valu_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Valu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_tb___024root___eval_static__TOP\n"); );
    // Body
    vlSelf->alu_tb__DOT__i = 0U;
}

VL_ATTR_COLD void Valu_tb___024root___eval_initial__TOP(Valu_tb___024root* vlSelf);

VL_ATTR_COLD void Valu_tb___024root___eval_initial(Valu_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Valu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_tb___024root___eval_initial\n"); );
    // Body
    Valu_tb___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
}

VL_ATTR_COLD void Valu_tb___024root___eval_initial__TOP(Valu_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Valu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_tb___024root___eval_initial__TOP\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_1;
    // Body
    VL_WRITEF_NX("[HW1 Testbench]\n---------------\n",0);
    __Vtemp_1[0U] = 0x2e747874U;
    __Vtemp_1[1U] = 0x6e707574U;
    __Vtemp_1[2U] = 0x69U;
    vlSelf->alu_tb__DOT__pattern = VL_FOPEN_NN(VL_CVT_PACK_STR_NW(3, __Vtemp_1)
                                               , std::string{"r"});
    ;
    vlSelf->finish = 0U;
}

VL_ATTR_COLD void Valu_tb___024root___eval_final(Valu_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Valu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_tb___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Valu_tb___024root___dump_triggers__stl(Valu_tb___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Valu_tb___024root___eval_phase__stl(Valu_tb___024root* vlSelf);

VL_ATTR_COLD void Valu_tb___024root___eval_settle(Valu_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Valu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_tb___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Valu_tb___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("alu_tb.v", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Valu_tb___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Valu_tb___024root___dump_triggers__stl(Valu_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Valu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_tb___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ vlSelf->__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Valu_tb___024root___stl_sequent__TOP__0(Valu_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Valu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_tb___024root___stl_sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ alu_tb__DOT__alu__DOT____VdfgTmp_h2300d0f6__0;
    alu_tb__DOT__alu__DOT____VdfgTmp_h2300d0f6__0 = 0;
    // Body
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

VL_ATTR_COLD void Valu_tb___024root___eval_stl(Valu_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Valu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_tb___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Valu_tb___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

VL_ATTR_COLD void Valu_tb___024root___eval_triggers__stl(Valu_tb___024root* vlSelf);

VL_ATTR_COLD bool Valu_tb___024root___eval_phase__stl(Valu_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Valu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_tb___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Valu_tb___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Valu_tb___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Valu_tb___024root___dump_triggers__act(Valu_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Valu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_tb___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ vlSelf->__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Valu_tb___024root___dump_triggers__nba(Valu_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Valu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_tb___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ vlSelf->__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Valu_tb___024root___ctor_var_reset(Valu_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Valu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_tb___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->finish = VL_RAND_RESET_I(1);
    vlSelf->alu_tb__DOT__op = VL_RAND_RESET_I(4);
    vlSelf->alu_tb__DOT__rs1 = VL_RAND_RESET_I(32);
    vlSelf->alu_tb__DOT__rs2 = VL_RAND_RESET_I(32);
    vlSelf->alu_tb__DOT__rd = VL_RAND_RESET_I(32);
    vlSelf->alu_tb__DOT__ans_rd = VL_RAND_RESET_I(32);
    vlSelf->alu_tb__DOT__ans_zero = VL_RAND_RESET_I(1);
    vlSelf->alu_tb__DOT__ans_overflow = VL_RAND_RESET_I(1);
    vlSelf->alu_tb__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->alu_tb__DOT__pattern = 0;
    vlSelf->alu_tb__DOT__temp = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
