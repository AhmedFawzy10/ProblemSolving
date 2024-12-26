#include <iostream>
#include <iomanip>

using namespace std;

int RandomNumbers(int From, int To)
{
    return rand() % (To - From + 1) + From;
}
void FillRandomMatrix(int arr[100][100], int Row, int Col)
{
    for (size_t i = 0; i < Row; i++)
        for (size_t j = 0; j < Col; j++)
            arr[i][j] = RandomNumbers(0,50);    
}



bool Count(int arr[100][100], int Row, int Col, int Num)
{
    for (size_t i = 0; i < Row; i++)
        for (size_t j = 0; j < Col; j++)
            if(arr[i][j] == Num)
                return 1;
    return 0;
}

void PrintMatrix(int arr[100][100], int Row, int Col)
{
    for (size_t i = 0; i < Row; i++)
    {
        for (size_t j = 0; j < Col; j++)
            cout << setw(3) << arr[i][j] << "\t";
        cout<<endl;
    }
}

int main()
{
    int arr[100][100];
    int n = 3;
    FillRandomMatrix(arr,n,n);
    // FillRandomMatrix(arr2,n,n);
    cout<<"Matrix 1 : \n";
    PrintMatrix(arr,n,n);
    // cout<<"Matrix 2 : \n";
    // PrintMatrix(arr2,n,n);


    cout<<"Is 0 Most? : " << Count(arr,n,n, 1);
    // system("pause>0");
}