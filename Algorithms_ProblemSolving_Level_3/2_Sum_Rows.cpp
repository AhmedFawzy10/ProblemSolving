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
            arr[i][j] = RandomNumbers(1,100);
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

int SumEachRow(int arr[3][3], int Row, int Colmuns)
{
    int sum = 0;
    for (size_t i = 0; i < Colmuns; i++)
        sum += arr[Row][i];// Make row const and change col 
    return sum;    
}

void PrintSumOfEachRow(int arr[3][3], int Row, int Colmuns)
{
    printf("\nThe following is the sum of each row in the matrix: \n\n");

    for(int i = 0; i < Row; ++i)        // Sending index of row that want to sum
        cout<<"Row " << i+1 << " Sum = "<<SumEachRow(arr,i,Colmuns)<<endl;
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[3][3];

    printf("The following is a %d x %d Random Matrix: \n", 3, 3);
    ReadArray(arr, 3, 3);
    PrintArray2D(arr,3, 3);
    PrintSumOfEachRow(arr,3, 3);
    system("pause >0");
}