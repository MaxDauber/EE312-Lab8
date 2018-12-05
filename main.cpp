#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <queue>


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
void cleaner (string& helo) {//function created to clean up strings and make them all caps
    for (int i = 0; i < helo.length(); i++) {
        if (96 < helo[i] && helo[i] < 123) {
            helo[i] = helo[i] - 32;
        }
        if(helo[i]<64 || helo[i]>91){
            helo.erase(helo.begin()+i);
            i--;
        }
    }
}

int main(int argc, char* argv[]) {
        long long count =0;
        //string dir = argv[1];//string("sm_doc_set");
        string dir = string("sm_doc_set");
        vector<string> files = vector<string>();

        getdir(dir, files);
        for (unsigned int i = 0; i < files.size(); i++) {
            cout << i << files[i] << endl;
        }
        string Mystring;
        ifstream myfile;
        for (int i = 2; i < files.size(); i++) {
            string fileptr = "sm_doc_set/" + files[i];
//            string fileptr = dir + '/ + files[i];

            myfile.open(fileptr.c_str());
            if (myfile.good() && myfile.is_open()) {
                cout << "good job fam";
                string mess;
               // string mess2;
                vector<string> less;
                //for (int i = 0; i < 6; i++) {
                   while(!myfile.eof()) {
                       while (less.size()<=6 && !myfile.eof())// replace 6 with the n word sequence
                       {
                           myfile >> mess;
                           cleaner(mess);
                           if (mess.length() != 0) {
                               less.push_back(mess);
                           }
                       }
                       for(int j=0; j<less.size();j++){
                           cout<<less[j]<<" ";
                       }
                       less.erase(less.begin());
                       count++;
                       cout<< endl;
                   }
                //cleaner(mess2);
                //cout << mess2;
               /* while(!less.empty()){
                    cout<<*(less.begin())<<" ";
                    less.erase(less.begin());
                } */

            } else {
                cout << "usuc";
                return 0;
            }
            cout << endl;
            myfile.close();
        }
        cout<<"count is "<<count;
}

