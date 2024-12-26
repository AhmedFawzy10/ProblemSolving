#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct stURL
{
    string AccountNumber;
    string PinCode;
    string Name;
    string PhoneNumber;
    double AccountBalance;
};

stURL ReadClinentData(stURL Client)
{

    cout<<"Please enter Account Number? ";
    getline(cin,Client.AccountNumber);

    cout<<"Please enter PinCode? ";
    getline(cin,Client.PinCode);

    cout<<"Please enter Name? ";
    getline(cin,Client.Name);
    
    cout<<"Please enter phone Number? ";
    getline(cin,Client.PhoneNumber);
    
    cout<<"Please enter Account Palance? ";
    cin>>Client.AccountBalance;

    return Client;
}

string SplitStruct(stURL Client, string delimiter = "#//#")
{
    string stClientRecord = "";
    stClientRecord += Client.AccountNumber + delimiter;
    stClientRecord += Client.PinCode + delimiter;
    stClientRecord += Client.Name + delimiter;
    stClientRecord += Client.PhoneNumber + delimiter;
    stClientRecord += to_string(Client.AccountBalance);
    return stClientRecord;
}

vector<string> SplitString(string str, string delimiter = "#//#")
{
    vector<string> tockens;
    string token;
    int pos = 0;
    while((pos = str.find(delimiter)) != string::npos)
    {
        token = str.substr(0, pos);
        if(token != "")
            tockens.push_back(token);
        str.erase(0, pos+delimiter.length());
    }
    if(str != "")
        tockens.push_back(str);
    return tockens;
}

stURL SplitStringURL(vector<string> str, string delimiter = "#//#")
{
    stURL Client;
    Client.AccountNumber = str[0];
    Client.PinCode = str[1];
    Client.Name = str[2];
    Client.PhoneNumber = str[3];
    Client.AccountBalance = stod(str[4]);
    return Client;
}

stURL ConvertLinetoRecord (string str, string delimiter = "#//#")
{
    stURL Client;
    short pos = 0;
    /*
    stClientRecord += Client.AccountNumber + delimiter;
    stClientRecord += Client.PinCode + delimiter;
    stClientRecord += Client.Name + delimiter;
    stClientRecord += Client.PhoneNumber + delimiter;
    stClientRecord += to_string(Client.AccountBalance);
    */
    vector<string> tokens = SplitString(str);
    Client.AccountNumber = tokens[0];
    Client.PinCode = tokens[1];
    Client.Name = tokens[2];
    Client.PhoneNumber = tokens[3];
    Client.AccountBalance = stod(tokens[4]);
    return Client;
}

void PrintLineToRecord(vector<string> tokens)
{
    for(string &s : tokens)
    {
        cout<<s<<"\n";
    }
}

int main()
{
    //******
    //** */  524#//#658484#//#Ahmed#//#01141614106#//#50000000.000000

    stURL Client;
    cout<<"Please Enter Client Data: \n\n";
    Client = ReadClinentData(Client);
    vector<string> tokens = SplitString(Client);
    cout<<"\n\n";
    cout<<"Client Record for saving is : \n\n\n";
    cout<<SplitStruct(Client);
    cout<<"\n\n";
    cout<<"========================\n";
    // vector<string> tockens = SplitString(SplitStruct(Client));
    // PrintLineToRecord(tockens);
    cout<<
}