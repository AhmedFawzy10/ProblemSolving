#include <iostream>
#include <vector>
#include <string>
using namespace std;

void SplitString(string str, string URL[5])
{
    string token;
    int pos;
    int i = 0;
    while((pos = str.find('=')) != string::npos)
    {
        token = str.substr(pos+1, str.find('&') - pos - 1);
        URL[i++] = token;
        str.erase(0, str.find('&') + 1);
    }
}

void PrintURL(string URL[5])
{
    cout<<"username: "<<URL[0]<<endl;
    cout<<"pwd: "<<URL[1]<<endl;
    cout<<"profile: "<<URL[2]<<endl;
    cout<<"role: "<<URL[3]<<endl;
    cout<<"key: "<<URL[4]<<endl;
}

int main()
{
    string s;
    cin>>s;
    string res[5];
    s.erase(0, s.find('?') + 1);
    SplitString(s,res);
    PrintURL(res);
    byte x = 122;
}