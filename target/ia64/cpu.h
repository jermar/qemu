#ifndef IA64_CPU_H
#define IA64_CPU_H

#define TARGET_LONG_BITS 64
#define TARGET_PAGE_BITS 12
#define TARGET_PHYS_ADDR_SPACE_BITS 64

#include "cpu-qom.h"
#include "exec/cpu-defs.h"

#define CPUArchState struct CPUIA64State

#include "exec/cpu-all.h"

#define CPU_RESOLVING_TYPE TYPE_IA64_CPU

#define NB_MMU_MODES 1

typedef struct CPUIA64State {
    CPU_COMMON
    uint64_t pc;
} CPUIA64State;

typedef struct IA64CPU {
    CPUIA64State env;
} IA64CPU;

#define ENV_OFFSET offsetof(IA64CPU, env)

static inline IA64CPU *ia64_env_get_cpu(CPUIA64State *env)
{
    return container_of(env, IA64CPU, env);
}

#define ENV_GET_CPU(e) CPU(ia64_env_get_cpu(e))


static inline int cpu_mmu_index(CPUIA64State *env, bool ifetch)
{
    return 0;
}

static inline void cpu_get_tb_cpu_state(CPUIA64State *env, target_ulong *pc,
                                        target_ulong *cs_base, uint32_t *pflags)
{
    *pc = 0;
    *cs_base = 0;
    *pflags = 0;
}

#endif
