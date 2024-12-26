#include <iostream>

using namespace std;

void Fibu(int n, int b, int e)
{
    if(n <= 0)
        return;

    int sum = b + e;
    cout<< sum << ' ';
    b = e;
    e = sum;
    Fibu(n - 1, b, e);
}

int main()
{
    cout<<0<<' '<<1<<' ';
    Fibu(5-2, 0, 1);
}