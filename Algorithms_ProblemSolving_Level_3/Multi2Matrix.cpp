#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int RandomNumbers(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

void ReadArray(int arr[3][3], int Row, int Colmuns)
{
    for (size_t i = 0; i < Row; i++)
        for (size_t j = 0; j < Colmuns; j++)
            arr[i][j] = RandomNumbers(1, 10);
}

void PrintArray2D(int arr[3][3], int Row, int Colmuns)
{
    for (size_t i = 0; i < Row; i++)
    {
        for (size_t j = 0; j < Colmuns; j++)
            cout<<arr[i][j]<<"\t\t";
        cout<<endl;
    }
}

void Mult(int arr[3][3], int arr2[3][3], int arr3[3][3], int Row, int Colmuns)
{
    for (size_t i = 0; i < Row; i++)
        for (size_t j = 0; j < Colmuns; j++)
            arr3[i][j] = arr[i][j] * arr2[i][j];

}

int main()
{
    srand((unsigned)time(NULL));

    int arr[3][3];
    int arr2[3][3];
    int arr3[3][3];


    printf("Matrix1: \n");
    ReadArray(arr, 3, 3);
    PrintArray2D(arr,3, 3);

    printf("Matrix2: \n");
    ReadArray(arr2, 3, 3);
    PrintArray2D(arr2,3, 3);
    cout<<"\n\n==================================\n\n";
    Mult(arr, arr2, arr3, 3, 3);
    PrintArray2D(arr3,3,3);
    system("pause >0");
}