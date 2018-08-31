#include "qemu/osdep.h"
#include "cpu.h"
#include "exec/exec-all.h"

void restore_state_to_opc(CPUIA64State *env, TranslationBlock *tb,
                          target_ulong *data)
{
    env->pc = data[0];
}

/* generate intermediate code for basic block 'tb'. */
void gen_intermediate_code(CPUState *cs, struct TranslationBlock *tb)
{
}
