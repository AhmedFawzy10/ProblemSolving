#include <iostream>
#include <vector>
using namespace std;


string RemovePun(string s)
{
    string sword = "";
    for (size_t i = 0; i < s.size(); i++)
    {
        if(!ispunct(s[i]))
            sword += s[i];
    }
    return sword;
}

int main()
{
    string  s ("Hello egypt, I'm From; Egypt. ");
    
    // vector<string> vString = SplitString(s, " ");
    // for(string &s: vString)
    //     cout<<s<<' ';
    cout<<s<<endl;
    cout<<RemovePun(s)<<endl;
    // cout<<ReplaceString(s,"Egy
}