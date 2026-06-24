#ifndef REGISTER_RISC_V_H_
#define REGISTER_RISC_V_H_

enum register_risc_v {
    // parameter / return registers
    // x10-11 function args / return values
    // x12-17 function arguments
    A0, A1, A2, A3, A4, A5, A6, A7,

    // temporary registers for computation
    T0, T1, T2, T3, T4, T5, T6,

    S0, S1, S2, S3, S4, S5, S6, S7, S8, S9, S10, S11,

    Unassigned,
};

#endif // REGISTER_RISC_V_H_