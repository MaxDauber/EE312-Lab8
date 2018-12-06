#ifndef _HASH_H
#define _HASH_H

#include <string>
#include <iostream>

using namespace std;


class Hash
{
private:
    static const int TABLE_SIZE = 1000003;
    struct HashNode
    {
        int data;
        HashNode *next;
    };
    HashNode * Table [TABLE_SIZE];
public:

    int hash (string &s);
    int * getcollisions(void);

    Hash();
    void hash (string &s, int key);
    int * getcollisions(int numofdocs);
    ~Hash();

};

#endif


