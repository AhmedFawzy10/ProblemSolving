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

string ColvertVectorToLine(vector<string> ClientInfo, string delimeter = "#//#")
{
    string sword = "";
    for(string &s : ClientInfo)
        sword += s + delimeter;
    sword.resize(sword.size() - delimeter.size());
    return sword;
}

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
    printf("| %-14s | %-8s | %-34s| %-22s| %-11lf\n", clients.AccountNumber.c_str(), clients.PinCode.c_str(), clients.Name.c_str(), clients.Phone.c_str(), clients.AccountBalance);
    // cout<<"| "<<clients.AccountNumber<<setw(11)<<" | " << clients.PinCode << setw(7) << " | " << clients.Name << setw(25) << " | "  << clients.Phone << setw(13) << " | " << clients.AccountBalance ;
    // cout<<clients.Name<<endl;
    // cout<<clients.Phone<<endl;
    // cout<<clients.AccountNumber<<endl;
    // cout<<clients.PinCode<<endl;
    // cout<<clients.AccountBalance<<endl;

}

void PrintClients(vector<stClient> clients, int numberOfClients)
{
    Header(numberOfClients);
    for (int i = 0; i < numberOfClients; i++)
    {
        PrintClient(clients[i]);
    }
    cout<<"\n-------------------------------------------------------------------------------------------------------\n\n";

}

stClient ConvertLineToVector(string line, string delimeter = "#//#")
{
    int pos = line.find(delimeter);
    stClient client;
    string arr[5];
    for (int i = 0; i < 4; i++)
    {
        arr[i] = line.substr(0,pos);
        line.erase(0, pos + delimeter.size());
        pos = line.find(delimeter);
    }
    arr[4] = line;
    client.Name = arr[0];
    client.Phone = arr[1];
    client.AccountNumber = arr[2];
    client.PinCode = arr[3];
    client.AccountBalance = stod(arr[4]);

    return client;
}

vector<stClient> LoadDataFromFile(string fileName, string delimeter = "#//#")
{
    fstream ClientInfo;

    ClientInfo.open(fileName, ios::in);

    vector<stClient> clients;
    if(ClientInfo.is_open())
    {
        string line;
        while(getline(ClientInfo, line))
        {
            if(line[0] == '=')
                continue;
            clients.push_back(ConvertLineToVector(line));
        }
    }
    return clients;
}

void Reading_FormFile(string fileName, string delimeter = "#//#")
{
    vector<stClient> clients = LoadDataFromFile(fileName, delimeter);

    PrintClients(clients, clients.size());
    // system("puese 0<");
}

int main()
{
    // char Again = 'y';
    // while(Again == 'y' || Again == 'Y')
    // {
        system("CLS");
        // AddingAClient();
        Reading_FormFile(ClientsFileName);
    //     cout<<"Do you want to add more? ";
    //     cin>>Again;
    // }

    // string s = "Ahmed Fawzy#//#01018108745#//#225545#//#1810#//#5000.000000";
    // stClient st = ConvertLineToStruct(s);
    // Header(3);
    // PrintClients(st,3);
    // string s = "Ahmed";
    // printf("%s",s.c_str());
    // cout<<st.Name<<endl;
    // cout<<st.Phone<<endl;
    // cout<<st.AccountNumber<<endl;
    // cout<<st.PinCode<<endl;
    // cout<<st.AccountBalance<<endl;

}