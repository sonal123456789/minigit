#include <iostream>
#include <dirent.h>
#include <fstream>
#include <cstdlib>
#include <sys/stat.h>
#include <sys/types.h>
#include <bits/stdc++.h>
#include <string>
#include<windows.h>
using namespace std;

int init()
{
    if (mkdir(".git") == -1)
    {
        cerr << "Error : Directory not created " << strerror(errno) << endl;
        return 0;
    }
    else
    {
        if (chdir(".git") == -1)
        {
            cerr << "Error :  " << strerror(errno) << endl;
            return 0;
        }
        else
        {
            if (mkdir("zero") == -1)
            {
                cerr << "Error : Directory not created " << strerror(errno) << endl;
                return 0;
            }
            else
           {
                fstream MainIndex;
                MainIndex.open("Main_Index.txt", ios::out);
                if (!MainIndex)
                {
                    return 0;
                }

                fstream Gitlog;
                Gitlog.open("log.txt", ios::out);
                if (!Gitlog)
                {
                    return 0;
                }
                if (chdir("zero") == -1)
                {
                cerr << "Error : " << strerror(errno) << endl;
                return 0;
                }
                else
                {
                  fstream Index;
                Index.open("index.txt", ios::out);
                if (!Index)
                {
                    return 0;
                }
                BOOL b = CopyFile("C:\\Users\\ps\\Documents\\Gitproject","C:\\Users\\ps\\Documents\\Gitproject\\.git\\zero",0);
if (!b) {
    cout << "Error: " << GetLastError() << endl;
} else {
    cout << "Okay " << endl;
}
                }

            }
        }
    }
    return 0;
}

int main(int argc,char *argv[])
{
    string s;
    s=argv[1];
    int newrepo;
    string s1;
    if(s=="init")
    {
        newrepo=init();
    }
    
    return 0;
}
 
		
