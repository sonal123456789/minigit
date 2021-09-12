#include <iostream>
#include <dirent.h>
#include <fstream>
#include <cstdlib>
#include <sys/stat.h>
#include <sys/types.h>
#include <bits/stdc++.h>
#include <string>
#include<vector>
using namespace std;
string getsha(string filename)
{
    string a= "certutil -hashfile " + filename + " SHA1" + " > temp.txt";
    char buf[100];
    system(a.c_str());
    fstream my_file;
	my_file.open("temp.txt", ios::in);
	if (!my_file) {
		cout << "No such file";
	}
	else {
        int i=0;
		while (i<100) {
			my_file >> buf[i];
			if (my_file.eof())
				break;
            i++;

		}

	}
    string input = buf;
    my_file.close();
string sha = input.substr(0,input.find('C'));
	int string_length = sha.length(), k=1,i=0,j=0;
	string shaf;
    while(string_length--) {
        if(sha[j] == 58 or k==1) {
            if(sha[j] == 58) {k=0;}
        }
        else {shaf = sha.substr(j, sha.length()-j+1); break;}
        j++;
    }
 int r = remove("temp.txt");
    if (r)
    {
        cout << "fail to delete file" << endl;
}
return shaf;
}
map <string,string> mp(vector<string> v)
{
    map <string,string> m;
    for(int i=0;i<v.size();i++)
	{
		string temp=v.at(i);
		string saa=getsha(temp);
		m.insert(pair<string,string>(temp,saa));
    }
return m;
}
vector<string> get_files_from(string path)
{
    vector<string> toret;
    struct dirent *entry;
    DIR *dir = opendir(path.c_str());
    if (dir == NULL)
    {
        cout << "Error in opening Directory";
        exit(EXIT_FAILURE);
    }
    while ((entry = readdir(dir)) != NULL)
    {
        //cout << entry->d_name << endl;
        string fname = entry->d_name;
        if (fname == ".git"||fname == "."||fname== "..")
        {
            continue;
        }
        else
        {
            toret.push_back(fname);
        }
    }
    closedir(dir);
    return toret;
}
void print(std::vector<string> const &v)
{   int i;
	for(i=0;i<v.size();i++)
	{
		std::cout<<v.at(i)<< " ";

	}
}
void printm(std::map<string,string> const &mm)
{
    int i;
   for(map<string,string>::const_iterator it = mm.begin();it != mm.end(); ++it)
{
    std::cout << it->first << " " << it->second << " " << "\n";
}
}
int main(int argc,char* argv[])
{
     vector<string> v;
	 v=get_files_from("C:\\Users\\ASUS\\OneDrive\\Documents\\git_project");
	 print(v);
	 cout<<"\n";
	 map<string,string> mm;
     mm=mp(v);
     printm(mm);
     return 0;
}
