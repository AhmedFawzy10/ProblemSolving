#include <iostream>
#include <string>
#include <vector>
using namespace std;


vector<string> SplitString(string s , string space)
{
    short pos = 0;
    vector<string> vString;
    string newStrng = "";

    while((pos = s.find(space)) != string::npos)
    {
        newStrng = s.substr(0, pos);

        if(newStrng != "")
            if(isalpha(newStrng[newStrng.size() - 1]))// (Hi,) I am here.
                vString.push_back(newStrng);
            else
                vString.push_back(newStrng.substr(0,newStrng.size() - 1));// To handle case (Hi,)

        s.erase(0, pos + 1);
    }

    if(s != "")
        vString.push_back(s);

    return vString;
}

string ToLowwerAll(string s)
{
    for (size_t i = 0; i < s.size(); i++)
        s[i] = tolower(s[i]);
    return s;
}

string VectorToString(vector<string> vString)
{
    string word = "";
    for(string &s : vString)
        word += s + " ";
    return word.substr(0,word.size() - 1);
}

string ReplaceString(string s, string replaceFrom, string replaceTo, bool match = 1)
{
    vector<string> vString = SplitString(s, " ");
    for(string &s : vString)
    {
        if(match)
        {
            if(s == replaceFrom)
                s = replaceTo;
        }
        else
        {
            if(ToLowwerAll(s) == ToLowwerAll(replaceFrom))
                s = replaceTo;
        }
    }
    return VectorToString(vString);
}

string AllSMall(string s)
{
    string ss = "";
    for (size_t i = 0; i < s.size(); i++)
    {
        ss.push_back(tolower(s[i]));
    }
    return ss;
}

string Replace(string s, string replaceFrom, string replaceTo, bool match = 1)
{
    vector<string> vString = SplitString(s, " ");
    for(string &s : vString)
    {
        if(match)
        {
            if(s == replaceFrom)
                s = replaceTo;
        }
        else
        {
            // cout<<AllSMall(s)<<endl;        // To Check case sensitivity
            if(AllSMall(s) == AllSMall(replaceFrom))
                s = replaceTo;
        }
    }
    return VectorToString(vString);
}

int main()
{
    string  s;
    cout<<"Enter a string: ";
    getline(cin, s);
    cout<<"Enter a word to replace: ";
    string replaceFrom;
    cin>>replaceFrom;
    cout<<"Enter a word to replace it with: ";
    string replaceTo;
    cin>>replaceTo;
    // vector<string> vString = SplitString(s, " ");
    // for(string &s: vString)
    //     cout<<s<<' ';
    cout<<"String without changes: "<<endl;
    cout<<s<<endl;
    // cout<<ReplaceString(s,"Egypt", "Philastine")<<endl;
    cout<<"String with replaced word: (case sensitive)"<<endl;
    cout<<Replace(s,replaceFrom, replaceTo) << endl;// case insensitive
    cout<<"String with replaced word: (no case sensitive)"<<endl;
    cout<<Replace(s,replaceFrom, replaceTo, 0);// no case sensitive

}