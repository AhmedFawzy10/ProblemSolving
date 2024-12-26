#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

const string ClientsFileName = "C:\\Users\\Eng-Ahmed_Fawzy\\Desktop\\MyFile.txt";

struct stClient
{
    string AccountNumber, PinCode, Name, Phone;
    double AccountBalance;
};

vector<string> ConvertStructToVector(stClient Client)
{
    vector<string> Res;
    Res.push_back(Client.Name);
    Res.push_back(Client.Phone);
    Res.push_back(Client.AccountNumber);
    Res.push_back(Client.PinCode);
    Res.push_back(to_string(Client.AccountBalance));
    return Res;
}

string ColvertVectorToLine(vector<string> Client, string delimeter = "#//#")
{
    string sword = "";
    for(string &s : Client)
        sword += s + delimeter;
    sword.resize(sword.size() - delimeter.size());
    return sword;
}

void AddToFile(string s, string res)
{
    fstream Client_Data;
    Client_Data.open(ClientsFileName, ios::out | ios::app);
    if(Client_Data.is_open())
    {
        Client_Data << res;
        Client_Data << "\n====================\n";
        Client_Data.close();
    }

}

stClient ReadClient()
{
    stClient Client;

    cout<<"Enter Name?\n";
    //Usage of std::ws will extract all the whitespace character
    getline(cin >> ws, Client.Name);// cin whitespace
    cout<<"Enter Phone?\n";
    cin>>Client.Phone;

    cout<<"Enter Account Number ?\n";
    cin>>Client.AccountNumber;
    cout<<"Enter Pin Code?\n";
    cin>>Client.PinCode;

    cout<<"Enter Account Balance?\n";
    cin>>Client.AccountBalance;

    return Client;
}

void AddingAClient()
{
    stClient Client;
    cout<<"Add new Client:\n\n\n";
    
    Client = ReadClient();
    
    AddToFile(ClientsFileName, ColvertVectorToLine(ConvertStructToVector(Client)));

    cout<<"\nSuccess\n";
}

int main()
{
    char Again = 'y';
    while(Again == 'y' || Again == 'Y')
    {
        system("CLS");
        AddingAClient();
        cout<<"Do you want to add more? ";
        cin>>Again;
    }
}