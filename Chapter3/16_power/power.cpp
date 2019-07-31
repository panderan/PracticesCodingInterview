#include "power.h"
#include <cmath>

bool g_power_error;

double power_with_unsigned_exp(double base, unsigned int exponent)
{
    double retval = 1.0;
    for (int i = 0; i < exponent; i++) {
        retval *= base;
    }
    return retval;
}

double power_with_unsigned_exp_fast(double base, int exponent)
{
    int retval = 1.0;

    if (exponent == 1) {
        return base;
    }
    if (exponent == 0) {
        return 1;
    }
    
    retval = power_with_unsigned_exp_fast(base, exponent>>1);
    if ((exponent & 0x1) == 1) {
        retval *= base;
    }
    return retval;
}

double power(double base, int exponent)
{
    g_power_error = false;
    if (exponent == 0) {
        return 1;
    }
    if (exponent == 1) {
        return base;
    }
    if (abs(base-0)<0.0000001) {
        if (exponent < 0) {
            g_power_error = true;
        }
        return 0;
    }
    
    unsigned int unsigned_exp = exponent>0 ? exponent : -exponent;
    double retval = 0;

    retval = power_with_unsigned_exp(base, unsigned_exp);

    return exponent>0 ? retval : 1/retval;
}

double power_fast(double base, int exponent)
{
    g_power_error = false;
    if (exponent == 0) {
        return 1;
    }
    if (exponent == 1) {
        return base;
    }
    if (abs(base-0)<0.0000001) {
        if (exponent < 0) {
            g_power_error = true;
        }
        return 0;
    }
    
    unsigned int unsigned_exp = exponent>0 ? exponent : -exponent;
    double retval = 0;

    retval = power_with_unsigned_exp_fast(base, unsigned_exp);
    if ((unsigned_exp & 0x1) == 1) {
        retval *= base;
    }

    return exponent>0 ? retval : 1/retval;
}

