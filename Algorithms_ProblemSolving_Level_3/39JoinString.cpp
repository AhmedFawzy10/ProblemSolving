#include <iostream>
#include <vector>

using namespace std;

vector<string>  AddStringSplitingToVector(string s, string SP)
{
    string sword;
    vector<string> vString;
    short pos = 0;

    while((pos = s.find(SP)) != string::npos)
    {
        sword = s.substr(0, pos);
        if(sword != "")
            vString.push_back(sword);
        s.erase(0, pos + SP.size());
    }
    if(s != "")
        vString.push_back(s);
    return vString;
}

string VectorToString(vector<string> vString, string SP)
{
    string word = "";
    bool flag = 0;
    for(string &i : vString)
    {
        if(flag)
            word += SP;
        word += i;
        flag = 1;
    }
    return word;
}

string VectorToString(string vString[], int Len, string SP)
{
    string word = "";
    
    for (size_t i = 0; i < Len; i++)
        word += vString[i] + SP;
    
    return word.substr(0, word.size() - SP.size());
}

int main()
{
    string s = "Ahmed Fawzy Aldosoky";
    string sS[] = {"Ahmed", "Fawzy", "Aldosoky"};
    vector<string> vString = AddStringSplitingToVector(s, " ");
    for(string &i : vString)
        cout<<i<<endl;
    string ss = VectorToString(vString, "#,,#");
    cout<<VectorToString(sS,3," ")<<endl;
    cout<<ss;
}
