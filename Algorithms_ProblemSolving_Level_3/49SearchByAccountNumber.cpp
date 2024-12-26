#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

const string ClientsFileName = "C:\\Users\\Eng-Ahmed_Fawzy\\Desktop\\MyFile.txt";

struct stClient//5
{
    string AccountNumber, PinCode, Name, Phone;
    double AccountBalance;
};


void Header(int NumberOfClients)
{
    // string s = "";
    // printf("\n\n\t\t\t\tClient List (%d) Client(s)\n", NumberOfClients);
    printf("\n\n%-35s Client List (%d) Client(s)\n", " ", NumberOfClients);
    cout<<"-------------------------------------------------------------------------------------------------------\n";
    printf("| Acount Number\t | Pin Code | Client Name \t\t\t| Phone \t\t| Balance\n");
    cout<<"-------------------------------------------------------------------------------------------------------\n\n";
}

void PrintClient(stClient clients)
{
    printf("| %-14s | %-8s | %-34s| %-22s| %-11lf\n", 
            clients.AccountNumber.c_str(), 
            clients.PinCode.c_str(), clients.Name.c_str(), 
            clients.Phone.c_str(), clients.AccountBalance);
}

vector<string> SplitString(string S1, string delimeter = "#//#")// every line in file
{
    vector<string> vString;

    short pos = 0;
    string word;
    while ( (pos = S1.find(delimeter)) != string::npos)
    {
        word = S1.substr(0, pos);

        if(word != "")
            vString.push_back(word);

        S1.erase(0, pos + delimeter.size());
    }
    if(S1 != "")
        vString.push_back(S1);
        
    return vString;
}

stClient ConvertLinetoRecord (string S1)
{
    vector<string> arr = SplitString(S1);
    stClient client;
    // name - phone - accountNumber - pin code - balance
    // cout<<arr[2]<<endl;
    // for(string &s : arr)
    //     cout<<s<<endl;
    client.Name = arr[0];
    client.Phone = arr[1];
    client.AccountNumber = arr[2];
    client.PinCode = arr[3];
    client.AccountBalance = stod(arr[4]);
    return client;
}

vector<stClient> LoadDataFromFile(string fileName, int accountNumber, string delimeter = "#//#")
{
    fstream ClientInfo;

    vector<stClient> vClient;

    ClientInfo.open(fileName, ios::in);

    if(ClientInfo.is_open())
    {
        string line;
        stClient client;
        while(getline(ClientInfo, line))
        {
            if(line[0] == '=')
                continue;
            client = ConvertLinetoRecord(line);
            vClient.push_back(client);

        }
        ClientInfo.close();
    }
    return vClient;
}

bool FindClientByAccountNumber(int ClientNumber, stClient & Client)
{

    vector<stClient> vClients = LoadDataFromFile(ClientsFileName, ClientNumber);
    for(stClient client : vClients)
        if(to_string(ClientNumber) == (client.AccountNumber))
        {
            Client  = client;
            return 1;
        }

    return 0;
}

void SearchOnClientByAccountNumber(int AccountNumber)
{
    stClient client;
    bool Found = FindClientByAccountNumber(AccountNumber, client);
    
    system("cls");
    if(Found)
    {
        Header(1);
        PrintClient(client);
    }
    else
        cout<<"Not Found"<<endl;

    system("pause>0");
}

int main()
{
    system("cls");
    cout<<"Enter client number : ";
    int AccountNumber;
    cin>>AccountNumber;
    SearchOnClientByAccountNumber(AccountNumber);
    
}