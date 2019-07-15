#ifndef _CMyString_H
#define _CMyString_H

#include <cstdlib>

class CMyString {
    public:
        CMyString(const char *pData = NULL);
        CMyString(const CMyString& str);
        ~CMyString(void);

        CMyString & operator = (const CMyString &str);
        char * getData () const {return m_pData;}

    private:
        char *m_pData;
};

#endif
