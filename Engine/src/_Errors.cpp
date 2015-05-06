#include "_Errors.h"

#include <iostream>
#include <cstdarg>

// The maximum length of an (expanded) error message
static const size_t MAX_ERROR = 500;

// Assumes a smell has already occurred. See smell macro for the functionality you were thinking of.
void _smell(const char *message_fmt, int line, const char *file, const char *function, ...)
{
	char msg_buf[MAX_ERROR];

	va_list vl;
	va_start(vl, function);

	vsnprintf(msg_buf, MAX_ERROR, message_fmt, vl);

	va_end(vl);

	std::cout << "Smell (" << file << ", ln " << line << ", func " << function << "): " << msg_buf << std::endl;
}

// Assumes an assert has already occurred. See assert macro for the functionality you were thinking of.
void _assert(const char *message_fmt, int line, const char *file, const char *function, ...)
{
	char msg_buf[MAX_ERROR];

	va_list vl;
	va_start(vl, function);

	vsnprintf(msg_buf, MAX_ERROR, message_fmt, vl);

	va_end(vl);

	std::cout << "Assert (" << file << ", ln " << line << ", func " << function << "): " << msg_buf << std::endl;

	std::cin.get();
	std::exit(1);
}
