#ifndef STRINGIZE
#define STRINGIZE_AUX(a) #a
#define STRINGIZE(a) STRINGIZE_AUX(a)
#endif

#include STRINGIZE(DEVICE/interrupts.h)
