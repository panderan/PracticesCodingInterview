#include "numeric_string.h"
#include <unistd.h>

bool scan_unsigned_integer(const char **str)
{
    const char *cur = NULL;

    if (str == NULL || *str == NULL) {
        return false;
    }

    cur = *str;
    for (cur=*str; *cur!='\0' && *cur>='0' && *cur<='9'; cur++);
    
    if (*str==cur) {
        return false;
    }
    else {
        *str=cur;
        return true;
    }
}

bool scan_integer(const char **str)
{
	const char *cur = NULL;
    
    if (str == NULL || *str == NULL) {
        return false;
    }
    
    cur = *str;
    if (*cur == '-' || *cur == '+') {
        cur++;
    }
    if (scan_unsigned_integer(&cur) == false) {
        *str = cur;
        return false;
    }

    *str = cur;
    return true;
}

bool is_numeric(const char *str)
{
    const char *cur = str;
    bool retval = true, has_a_part=false, has_b_part=false;
    	
	if (str == NULL) {
		return false;
	}    

    if (*cur != '.') {
        has_a_part = scan_integer(&cur);
    }
    if (*cur=='.') { 
        cur++;
        has_b_part = scan_unsigned_integer(&cur);
    }
    if (has_a_part==false && has_b_part==false) {
        return false;
    }

    if (*cur=='e' || *cur=='E') {
        cur++;
        retval = scan_integer(&cur);     
    }

    if (retval && *cur=='\0') {
        return true;
    }
    else {
        return false;
    }
}

