#include "first_charater_in_stream.h"
#include <limits>

using namespace std;

char_statistics::char_statistics() : index(0)
{
    for (int i=0; i<256; occurrence[i++]=-1);
}

void char_statistics::insert(char ch)
{
    if (occurrence[ch] >= 0) {
        occurrence[ch] = -2;
    }

    if (occurrence[ch] == -1) {
        occurrence[ch] = index++;
    }
}

char char_statistics::first_appearing_once()
{
    int min_idx = 0, i = 0;
    char ch = '\0';

    min_idx = numeric_limits<int>::max();
    for (i=0; i<256; i++) {
        if (occurrence[i] >=0 && occurrence[i] < min_idx) {
            ch = (char) i;
            min_idx = occurrence[i];
        }
    }

    return ch;
}

