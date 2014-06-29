#include "_ExportUtil.h"

void EXPORT _smell(char *message, int line, char *file, char *function);
void EXPORT _assert(char *message, int line, char *file, char *function);

#ifndef __func__
#define __func__ __FUNCTION__
#endif

#define smell(cond, msg) do {if (!( cond )) { _smell( msg , __LINE__, __FILE__, __func__); }} while (0)
#define assert(cond, msg) do {if (!( cond )) { _assert( msg , __LINE__, __FILE__, __func__); }} while (0)