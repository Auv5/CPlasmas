#ifndef EXPORT_UTIL_H_
#define EXPORT_UTIL_H_

#ifdef _WIN32
#define EXPORT __declspec(dllexport)
#else
#error Unsupported system...
#endif

#endif