#ifndef _STM32_TOOLS_H_

#define _STRINGIZE_AUX(a) #a
#define _STRINGIZE(a) _STRINGIZE_AUX(a)

#define _CAT_AUX(a, b) a##b
#define _CAT(a, b) _CAT_AUX(a, b)

#endif
