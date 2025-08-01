#pragma once



#ifndef NDEBUG
#define WUI_DEBUG
#endif


#ifdef WUI_DEBUG

#include <cassert>

#define WUI_ASSERT(condition, message) \
        do { \
            assert(condition && message); \
        } while (0)

#else 

#define  WUI_ASSERT(condition, message)

#endif 
