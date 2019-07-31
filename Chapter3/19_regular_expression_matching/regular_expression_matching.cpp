#include "regular_expression_matching.h"
#include <unistd.h>

bool match_core(const char *str, const char *pattern)
{
    if (str == NULL || pattern == NULL) {
        return false;
    }
    /* if (*str == '\0' && *pattern == '\0') { */
    /*     return true;                        */
    /* }                                       */
    /* if (*str == '\0' || *pattern == '\0') { */
    /*     return false;                       */
    /* }                                       */
    if (*str == '\0') {
        if (*pattern=='\0' || (*(pattern+1)=='*' && *(pattern+2)=='\0')) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        if (*pattern == '\0') {
            return false;
        }
    }

    if (*(str) == *(pattern) && *(pattern) != '.' && *(pattern+1) != '*') {
        return match_core(str+1, pattern+1);
    }
    else if (*(pattern)=='.' && *(pattern+1) != '*') {
        return match_core(str+1, pattern+1);
    }
    else if (*(pattern+1)=='*') {
        if (*(str) != *(pattern) && *(pattern) != '.') {
            return match_core(str, pattern+2);
        }
        else {
            bool retval = false;
            retval = retval || match_core(str, pattern+2);
            retval = retval || match_core(str+1, pattern);
            retval = retval || match_core(str+1, pattern+2);
            return retval;
        }
    }
    else {
        return false;
    }
}

bool match(const char *str, const char *pattern)
{
    return match_core(str, pattern);    
}

