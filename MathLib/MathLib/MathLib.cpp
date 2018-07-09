// MathLib.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Math.h"
using namespace std;

Double ArcTan(const Double& x)
{
	Double ans = x;
	Double mul = x * x;
	Double base = x * mul;

	for (int i = 1;i <= 200;i++)//100 terms of series.
	{
		if (i % 2)
		{
			ans = ans - Double((Int)1, (Int)(2 * i + 1)) * base;
		}
		else
		{
			ans = ans + Double((Int)1, (Int)(2 * i + 1)) * base;
		}
		base = base * mul;
	}

	return ans;
}

int main()
{
	//Double Test.
	fraction A = fraction(1, 3);
	fraction B = fraction(3, 6);
	
	cout << pow(A, -10) << endl;
	



	system("pause");
    return 0;
}






