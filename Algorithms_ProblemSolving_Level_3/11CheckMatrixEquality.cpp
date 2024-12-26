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
            arr[i][j] = RandomNumbers(1,10);            
}

int SumMatrix(int arr[100][100], int Row, int Col)
{
    int sum = 0;
    for (size_t i = 0; i < Row; i++)
        for (size_t j = 0; j < Col; j++)
            sum += arr[i][j];
    return sum;
}


bool CheckIdentity(int arr[100][100], int arr2[100][100], int Row, int Col)
{
    return SumMatrix(arr,Row, Col) == SumMatrix(arr2,Row, Col);
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
    int arr1[100][100], arr2[100][100];
    int n = 3;
    FillRandomMatrix(arr1,n,n);
    FillRandomMatrix(arr2,n,n);
    cout<<"Matrix 1 : \n";
    PrintMatrix(arr1,n,n);
    cout<<"Matrix 2 : \n";
    PrintMatrix(arr2,n,n);
    if(CheckIdentity(arr1,arr2,n,n))
        cout<<"Yes : Matrices are equals.";
    else
        cout<<"NO : Matrices are Not equals.";
    system("pause>0");
}