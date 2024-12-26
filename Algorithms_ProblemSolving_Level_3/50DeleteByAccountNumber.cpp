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
    bool MarkForDelete = false;
};

void PrintClient(stClient client)
{
    cout<<"The following is the client details:\n\n";

    printf("Account Number: %-10s",client.AccountNumber.c_str());
    printf("\nPin Code: %-10s",client.PinCode.c_str());
    printf("\nName: %-10s",client.Name.c_str());
    printf("\nPhone: %-10s",client.Phone.c_str());
    printf("\nAccount Balance: %-10.2lf\n\n",client.AccountBalance);
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
string ConvertRecordToLine(stClient client, string delimeter = "#//#")
{
    string line = "";
    line += client.Name + delimeter + client.Phone + delimeter + client.AccountNumber + 
            delimeter + client.PinCode + delimeter + to_string(client.AccountBalance) + '\n';
    return line;
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

bool FindClientByAccountNumber(int ClientNumber, vector<stClient>& vClients, int& index)
{
    int cntr = 0;
    for(stClient& client : vClients)
    {
        if(to_string(ClientNumber) == (client.AccountNumber))
        {
            client.MarkForDelete = true;
            index = cntr;
            return 1;
        }
        cntr++;
    }
    return 0;
}

void LoadToFile(vector<stClient> vClients)
{
    fstream ClientInfo;
    ClientInfo.open(ClientsFileName, ios::out);

    if(ClientInfo.is_open())
    {
        for(stClient &client : vClients)
        {
            if(!client.MarkForDelete)
            {
                string line = ConvertRecordToLine(client);
                ClientInfo << line;
                ClientInfo << "====================" << '\n';
            }
        }
        ClientInfo.close();
    }
}


void DeleteAccount(int AccountNumber)
{
    bool Found = 0;
    vector<stClient> vClients = LoadDataFromFile(ClientsFileName, AccountNumber);
    int index;
    Found  = FindClientByAccountNumber(AccountNumber, vClients, index);
    system("cls");
    if(Found)
    {
        PrintClient(vClients[index]);
        char sure;
        cout<<"Are you sure you want to delete this account (Y/N)? ";
        cin>>sure;
        if(sure == 'y' || sure == 'Y')
        {
            LoadToFile(vClients);
            cout<<"Account deleted successfully"<<endl;
        }
        else
        {
            cout<<"Account not deleted"<<endl;
        }
    }
    else
        printf("Client with Account Number (%d) Not Found!", AccountNumber);
}

int main()
{
    char c = 'y';
    while (c == 'y' || c == 'Y')
    {
        system("cls");
        cout<<"\t\tDeleting client\n";
        cout<<"\t   ========================\n\n";
        cout<<"Enter client number : ";

        int AccountNumber;
        cin>>AccountNumber;

        DeleteAccount(AccountNumber);
        system("puase>0");
        cout<<"\nDo you want to delete another client (Y/N)? ";
        cin>>c;
    }
}