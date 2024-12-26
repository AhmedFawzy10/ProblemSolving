#include <iostream>
using namespace std;

int main()
{
    cout<<"Enter the number : ";
    int x;
    cin>>x;
    int a = 1, b = 1;
    cout<<1<<' '<<1<<' ';
    for (size_t i = 0; i < x - 2; i++)
    {
        int c = a + b;
        cout<<c<<' ';
        a = b;
        b = c;
    }
    
}