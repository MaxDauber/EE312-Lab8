#ifndef _HASH_H
#define _HASH_H

#include <string>
#include <iostream>
#include <vector>

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
    Hash();
    void hash (string &s, int key);
    int * getcollisions(int numofdocs, vector<string> &files, int minCollisions);
    ~Hash();
};

#endif


