// MathLib.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Math.h"
using namespace std;


int main()
{
	//Double Test.
	Double A = fraction(2, 3).GetValueD();
	Double B = fraction(3, 6).GetValueD();
	cout << (A < B) << endl;


	system("pause");
    return 0;
}






