#include <iostream>
using namespace std;

void fun(int n)
{
	int arr[10] = {0}, j;
	for(int i=1; i<=n; i++)
	{
		j = i;
		while(j)
		{
			int m = j%10;
			j/=10;
			arr[m]++;
		}
	}
	for(int i=0; i<10; i++)
	{
		cout << arr[i];
		if(i == 9) cout << "\n";
		else cout << " ";
	}
}

int main() {
	int t, n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		fun(n);
	}
	return 0;
}
