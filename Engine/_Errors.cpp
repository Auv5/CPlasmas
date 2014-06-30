#include "_Errors.h"

#include <iostream>
#include <cstdlib>

// Assumes a smell has already occurred. See smell macro for the functionality you were thinking of.
void _smell(const char *message, int line, char *file, char *function)
{
	std::cout << "Smell (" << file << ", ln " << line << ", func " << function << "): " << message << std::endl;
}

// Assumes an assert has already occurred. See smell macro for the functionality you were thinking of.
void _assert(const char *message, int line, char *file, char *function)
{
	std::cout << "Assert (" << file << ", ln " << line << ", func " << function << "): " << message << std::endl;

	std::cin.get();
	std::exit(1);
}