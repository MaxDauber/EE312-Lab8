#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <queue>
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
        long long count =0;
        int numSeq; //number of items in each sequence
        //string dir = argv[1];//string("sm_doc_set");
        string dir = string("sm_doc_set");
        vector<string> files = vector<string>();

        getdir(dir, files);
        for (unsigned int i = 0; i < files.size(); i++) {
            cout << i << files[i] << endl;
        }
        numSeq = 2;
        ifstream myfile;
        for (int i = 2; i < files.size(); i++) {
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
                       string input;
                       for(int j=0; j<wordQueue.size();j++){
                           //cout<<wordQueue[j]<<" ";
                           input += wordQueue[j];
                           cout << input;
                           int k = hash(input);
                           cout << hash(hash);
                       }
                       wordQueue.erase(wordQueue.begin());
                       count++;
                       cout<< endl;
                   }

            } else {
                cout << "Files not found!";
                return 0;
            }
            cout << endl;
            myfile.close();
        }
        cout<<"count is "<<count;
}

