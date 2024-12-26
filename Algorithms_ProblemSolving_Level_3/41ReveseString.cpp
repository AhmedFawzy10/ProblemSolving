#include <iostream>
#include <vector>
using namespace std;

vector<string> FillStringIntoVector(string s, string SP)
{
    vector<string> vString ;
    string sword = "";
    int Pos = 0;
    while((Pos = s.find(SP)) != string::npos)
    {
        sword = s.substr(0,Pos);
        if(sword != "")
            vString.push_back(sword);
        s.erase(0, Pos + SP.size());
    }
    if(s != "")
        vString.push_back(s);
    return vString;
}

string ReverseString(string  s)
{
    vector<string> vString = FillStringIntoVector(s, ",,");

    string res = "";

    vector<string>::iterator ite = vString.end();

    while(--ite != vString.begin())
        res += *ite + ' ';

    return res.substr(0,res.size()-1);
}

int main()
{
    string  s ("Ahmed,,Fawzy,,Aldosoky");
    cout<<s<<endl;
    cout<<ReverseString(s);
}