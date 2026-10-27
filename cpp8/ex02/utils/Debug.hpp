#ifndef __DEBUG_HPP__
#define __DEBUG_HPP__

#include <iostream>

// Compile with `make debug` (adds -D DEBUG) to enable the traces.
#ifdef DEBUG
# define DEBUG_MSG(x) std::cout << x
#else
# define DEBUG_MSG(x) ((void)0)
#endif

#endif
