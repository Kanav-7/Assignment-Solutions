#include "iostream"
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int flag=0,c,d,l;
		cin >> c >> d >> l;

		if(l%4==0&&l<=4*(c+d)&&l>=4*d)
		{
			if(c>2*d)
			{
				if(l>=4*(3*d-c))
				flag=1;
			}
			else
				flag = 1;
		}
		cout << (flag?"Yes\n":"No\n");
	}
	return 0;
}