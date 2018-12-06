#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "hash.h"

using namespace std;


/*function... might want it in some class?*/
int getdir (string dir, vector<string> &files)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}
//formats input strings for consistency
void cleaner (string& str) {
    for (int i = 0; i < str.length(); i++) {
        if (96 < str[i] && str[i] < 123) {
            str[i] = str[i] - 32;
        }
        if(str[i]<64 || str[i]>91){
            str.erase(str.begin()+i);
            i--;
        }
    }
}

int main(int argc, char* argv[]) {

        Hash * hashTable=new Hash;
        int numSeq; //number of items in each sequence
        int minCollisions = 200;
        //string dir = argv[1];//string("sm_doc_set");

        string dir = string("sm_doc_set");
        vector<string> files = vector<string>();

        getdir(dir, files);

        for(int i = 0; i < files.size(); i++){
            if(files[i].substr(0,1) == "."){
                files.erase(files.begin()+i);
                i--;
            }
        }

        numSeq = 6;
        ifstream myfile;
        for (int i = 0; i < files.size(); i++) {
            string fileptr = "sm_doc_set/" + files[i];
//            string fileptr = dir + '/' + files[i];

            myfile.open(fileptr.c_str());
            if (myfile.good() && myfile.is_open()) {
                string word;
                vector<string> wordQueue;
                   while(!myfile.eof()) {
                       while (wordQueue.size()<numSeq && !myfile.eof())// replace 6 with the n word sequence
                       {
                           myfile >> word;
                           cleaner(word);
                           if (word.length() != 0) {
                               wordQueue.push_back(word);
                           }
                       }
                       string mystring;
                       for(int j=0; j<wordQueue.size();j++){
                           mystring += wordQueue[j];
                       }
                       hashTable->hash(mystring,i);
                       wordQueue.erase(wordQueue.begin());
                       //cout<< endl;
                   }

            }
            else {
                cout << "Files not found!";
                return 0;
            }
            myfile.close();
        }
        hashTable->getcollisions(files.size(), files, minCollisions);
	delete(hashTable);
}

