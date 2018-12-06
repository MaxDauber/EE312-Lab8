#include <string>
#include <iostream>
#include "hash.h"

int Hash::hash (string &input){
    return input[0];
};

int * Hash::getcollisions(){
    int collisions[][];

    for(int i = 0; i < TABLE_SIZE; i++){
        if(Table[i] != NULL){
            
        }
    }

    return NULL;

};
