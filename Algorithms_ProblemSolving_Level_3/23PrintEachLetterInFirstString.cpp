#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ReadString(string s)
{
    cout<<"Enter the string : ";
    getline(cin,s);
    return s;
}

string ToUpperCase(string s)
{
    for (size_t i = 0; i < s.size(); i++)
        s[i] = toupper(s[i]);
    return s;
}

string ToLowerCase(string s)
{
    for (size_t i = 0; i < s.size(); i++)
        s[i] = tolower(s[i]);
    return s;
}

int CountCapital(string s)
{
    int cntr = 0;
    for (size_t i = 0; i < s.size(); i++)
        isupper(s[i])?cntr++:0;
    return cntr;    
}

int CountSmall(string s)
{
    int cntr = 0;
    for (size_t i = 0; i < s.size(); i++)
        islower(s[i])?cntr++:0;
    return cntr;    
}

int countAll(string s, char x)
{
    int c = 0;
    for (size_t i = 0; i < s.size(); i++)
        if(tolower(s[i]) == tolower(x))
            c++;
    return c;    
}

bool IsVowl(char c)
{
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int CountVowls(string s)
{
    int cntr = 0;
    for (size_t i = 0; i < s.size(); i++)
        cntr += IsVowl(s[i]);
    return cntr;
}

void PrintVowls(string s)
{
    for (size_t i = 0; i < s.size(); i++)
        if(IsVowl(s[i]))
            cout<<s[i]<<'\t';
}

void PrintEachWordInString1(string s)
{
    for (size_t i = 0; i < s.size(); i++)
    {
        if(isspace(s[i]) && isalpha(s[i+1]))
        {
            cout<<endl;
            continue;
        }
        cout<<s[i];
    }   
}

void PrintEachWordInString(string s)
{
    string delim = " ";
    short pos = 0;
    string sword ;
    cout<<"\nYour string wrords are: \n\n";

    while((pos = s.find(delim)) != string::npos)
    {
        // cout<<"Delim length : "<<delim.length()<<endl;
        sword = s.substr(0, pos);
        if(sword != "")
            cout<<sword<<endl;
        s.erase(s.begin(),s.begin() + pos + delim.size());
    }
    if(s != "")
        cout<<s;

}

int CountEachWordInString(string s)
{
    int cntr = 0;
    string delim = " ";
    short pos = 0;
    string sword ;
    // cout<<"\nYour string wrords are: \n\n";

    while((pos = s.find(delim)) != string::npos)
    {
        // cout<<"Delim length : "<<delim.length()<<endl;
        sword = s.substr(0, pos);
        if(sword != "")
            cntr++;
        s.erase(s.begin(),s.begin() + pos + delim.size());
    }
    if(s != "")
        cntr++;

    return cntr;
}

vector<string> SplitString(string s, string Sp)
{
    vector<string> Res;

    string sword;

    short pos = 0;

    while((pos = s.find(Sp)) != string::npos)
    {
        sword = s.substr(0, pos);
        if(sword != "")
            Res.push_back(sword);

        s.erase(0, pos + Sp.size());
    }

    if(s != "")
        Res.push_back(s);

    return Res;
}

string TremRight(string s)
{
    string ss = s;
    for (size_t i = ss.size() - 1; i > 0; i--)
        if(isalpha(ss[i]))
            return s.substr(0,i + 1);
}

string TremLeft(string s)
{
    string ss = s;
    for (int i = 0; i < ss.size(); i++)
        if(isalpha(ss[i]))
            return ss.substr(i);
}

string Trem(string s)
{
   return TremRight(TremLeft(s));
}

int main()
{
    // string s;
    // s = ReadString(s);
    // cout<<ToLowerCase(s)<<endl;
    // cout<<ToUpperCase(s)<<endl;

    string s = "Ahmed Fawzy";
    getline(cin,s);

    // string check = "aeiou";

    // for (size_t i = 0; i < s.size(); i++)
    //     s[i] =  islower(s[i]) ? toupper(s[i]) : tolower(s[i]) ;
    // cout<<s;
    // cout<<s.size()<<endl;
    // cout<<CountCapital(s)<<endl;
    // cout<<CountSmall(s)<<endl;
    // cout<<countAll(s,'a');
    // char c;
    // cin>>c;
    // (IsVowl(c))?cout<<"YES it is vowl." : cout<<"NO it is not a vowl. ";
    // cout<<"Vowels => ";
    // cout<<CountEachWordInString(s);

    // string split ;
    // cin>>split;
    // vector<string> Spl = SplitString(s,split);
    // cout<<Spl.size()<<endl;
    // for(string &i : Spl)
    //     cout<<i<<endl;
    // cout<<s.size()<<endl;
    cout<<TremLeft(s)<<endl;
    cout<<TremRight(s)<<endl;
    cout<<Trem(s);
}   