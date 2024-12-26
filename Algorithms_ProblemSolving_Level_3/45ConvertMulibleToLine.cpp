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

string SplitStruct(stURL Client, string delimiter = "#//#"  )
{
    string stClientRecord = "";
    stClientRecord += Client.AccountNumber + delimiter;
    stClientRecord += Client.PinCode + delimiter;
    stClientRecord += Client.Name + delimiter;
    stClientRecord += Client.PhoneNumber + delimiter;
    stClientRecord += to_string(Client.AccountBalance);
    return stClientRecord;
}

int main()
{
    stURL Client;
    cout<<"Please Enter Client Data: \n\n";
    Client = ReadClinentData(Client);

    cout<<"\n\n";
    cout<<"Client Record for saving is : \n";
    cout<<SplitStruct(Client);
}