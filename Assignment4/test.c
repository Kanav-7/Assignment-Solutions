#include "iostream"
using namespace std;

int main()
{
	for (int i = 0; i < 100000; ++i)
	{
		cout << "0";
	}
	cout << "\n";
	cout << 500000;
	for (int i = 0; i < 500000; ++i)
	{
		cout << "2 1 50000 50001 100000\n";
	}

}