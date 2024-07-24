#include <iostream>
using namespace std;

int main()
{
	int x, y, z, minutes = 0;
	cin >> x >> y >> z;
	int s = x + y + z;
	int maxi = max(max(x, y), z);
	int mini = min(min(x, y), z);
	int mid = s - maxi - mini;
	bool condition = (mini + mid) > maxi;
    bool NegCondition = (mini + mid) <= maxi;
	if (condition)
		cout << 0;
	else
	{
		while (NegCondition)
		{
			minutes++;
			mini++;
		}
		cout << minutes;
	}
}
