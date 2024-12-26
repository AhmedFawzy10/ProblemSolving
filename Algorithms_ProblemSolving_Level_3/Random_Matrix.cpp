#include <iostream>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

void RandomMatrix(int Matrix[10][10], int Len)
{
    for (size_t i = 0; i < Len; i++)
        for (size_t j = 0; j < Len; j++)
            Matrix[i][j] = RandomNumber(1,100);    
}
void PrintRandom(int Matrix[10][10], int Len)
{
    for (size_t i = 0; i < Len; i++)
    {
        for (size_t j = 0; j < Len; j++)
            cout<<setw(3)<<Matrix[i][j]<<' ';
        cout<<endl;
    }

}
int main()
{
    srand((unsigned)time(NULL));
        
    cout<<"The flowing random numbers\n";
    int arr[10][10];
    RandomMatrix(arr,3);
    PrintRandom(arr,3);

    system("pause>0");
}