#ifndef EXPORT_UTIL_H_
#define EXPORT_UTIL_H_

#if defined(_WIN32)
#if defined(ENGAPI_EXPORT)
#define ENGAPI __declspec(dllexport)
#else
#define ENGAPI __declspec(dllimport)
#endif // defined(ENGAPI_EXPORT)
#elif defined(__linux__)
#define ENGAPI
#else
#error Unsupported operating system...
#endif // defined(_WIN32)

#endif
