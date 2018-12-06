#ifndef _HASH_H
#define _HASH_H

#include <string>
#include <iostream>

using namespace std;


class Hash
{
private:
    static const int TABLE_SIZE = 512;
    struct HashNode
    {
        int data;
        HashNode *next;

    };

    HashNode * Table [TABLE_SIZE];

public:
    int hash (string &s);
    int * getcollisions(void);

};


#endif


