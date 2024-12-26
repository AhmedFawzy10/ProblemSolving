#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

void ReadArray(int arr[3][3], int Row, int Colmuns)
{
    int cntr = 0;
    for (size_t i = 0; i < Row; i++)
        for (size_t j = 0; j < Colmuns; j++)
            arr[i][j] = ++cntr;
}

void PrintArray2D(int arr[3][3], int Row, int Colmuns)
{
    for (size_t i = 0; i < Row; i++)
    {
        for (size_t j = 0; j < Colmuns; j++)
            cout<<arr[j][i]<<"\t\t";
        cout<<endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[3][3];

    printf("The following is a %d x %d Random Matrix: \n", 3, 3);
    ReadArray(arr, 3, 3);
    PrintArray2D(arr,3, 3);

    system("pause >0");
}