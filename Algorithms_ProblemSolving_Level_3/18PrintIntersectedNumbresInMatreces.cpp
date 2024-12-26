#include <iostream>
#include <iomanip>

using namespace std;

int RandomNumbers(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

void FillRandomMatrix(int arr[3][3], int Row, int Col)
{
    for (size_t i = 0; i < Row; i++)
        for (size_t j = 0; j < Col; j++)
            arr[i][j] = RandomNumbers(0,10);    
}

bool IsPalindromMatrix(int arr[3][3], int Row, int Col)
{
    for (size_t i = 0; i < Row; i++)
        for (int j = 0; j < Col/2; j++)
            if(arr[i][j] != arr[i][Col - 1 - j])
                return 0;
    return 1;
}

void PrintMatrix(int arr[3][3], int Row, int Col)
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
    int arr[3][3] = {
        {1,2,1},
        {7,5,7},
        {0,2,0}
    };
    
    // FillRandomMatrix(arr,3,3);
    // FillRandomMatrix(arr2,3,3);
    cout<<"Matrix : \n";
    PrintMatrix(arr,3,3);
    // cout<<"Matrix 2: \n";
    // PrintMatrix(arr2,3,3);
    if(IsPalindromMatrix(arr,3,3))
        cout<<"Is Palindrom Matrix..";
    else
        cout<<"NOT Palindrom Matrix..";
}