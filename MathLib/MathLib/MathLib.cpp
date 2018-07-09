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
	Double A = fraction(2, 3).GetValueD();
	Double B = fraction(3, 6).GetValueD();
	cout << (A < B) << endl;


	system("pause");
    return 0;
}






