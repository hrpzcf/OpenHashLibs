#ifndef XKCP_has_Sponge_Keccak
    #define XKCP_has_Sponge_Keccak
#endif

#ifndef XKCP_has_FIPS202
    #define XKCP_has_FIPS202
#endif

#ifndef XKCP_has_KeccakP1600
    #define XKCP_has_KeccakP1600
#endif

// 为 plain64 实现启用 Lane Complementing 优化
// 见 Keccak/XKCP/lib/LowLevel.build 的 K1600-plain-64bits-lcua
#ifndef KeccakP1600_plain64_implementation_config
    #define KeccakP1600_plain64_implementation_config "lane complementing, all rounds unrolled"
    #define KeccakP1600_plain64_fullUnrolling
    #define KeccakP1600_plain64_useLaneComplementing
#endif
