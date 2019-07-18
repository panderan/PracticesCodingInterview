#include "assignment_operator.h"
#include <cstring>

CMyString::CMyString(const char *pData)
{
    if (pData == NULL) {
        m_pData = new char[1];
        m_pData[0] = '\0';
    }
    else {
        m_pData = new char[strlen(pData)+1];
        strcpy(m_pData, pData);
    }
}

CMyString::CMyString(const CMyString &str)
{
    m_pData = new char[strlen(str.m_pData)+1];
    strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString()
{
    delete m_pData;
}

CMyString & CMyString::operator = (const CMyString &str)
{
    char *buffer = NULL;

    buffer = new char[strlen(str.m_pData)+1];
    strcpy(buffer, str.m_pData);

    if (m_pData != NULL) {
        delete m_pData;
        m_pData = NULL;
    }

    m_pData = buffer;
    buffer = NULL;

    return *this;
}

