#include "utils.hpp"
#include <cstdio>

namespace test {

void causes_segv() {
    int *p = nullptr;
    *p = 0;
}

void divide_by_zero() {
    int v = 0;
    int r = 10 / v;
    std::printf("%d\n", r);
}

void causes_sigill() {
    // This will cause SIGILL (Illegal Instruction)
#ifdef __x86_64__
    __asm__("ud2"); // Undefined instruction on x86_64
#elif defined(__i386__)
    __asm__("ud2"); // Undefined instruction on x86
#elif defined(__ARM_ARCH)
    __asm__(".word 0xe7f000f0"); // Undefined instruction on ARM
#else
    // Fallback: try to execute invalid machine code
    void (*bad_func)() = (void (*)())0x1;
    bad_func();
#endif
}

} // namespace test
