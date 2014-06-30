#ifndef EXPORT_UTIL_H_
#define EXPORT_UTIL_H_

#ifdef _WIN32
#if defined(ENGAPI_EXPORT)
#define ENGAPI __declspec(dllexport)
#else
#define ENGAPI __declspec(dllimport)
#endif
#else
#error Unsupported operating system...
#endif

#endif