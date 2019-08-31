#ifndef _FIRST_CHARATER_IN_STREAM_H
#define _FIRST_CHARATER_IN_STREAM_H

class char_statistics
{
    public:
        char_statistics();
        void insert(char ch);
        char first_appearing_once();

    private:
        int occurrence[256];
        int index;
};

#endif
