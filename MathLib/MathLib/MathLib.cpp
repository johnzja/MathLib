// MathLib.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Math.h"
using namespace std;


int main()
{
	//Double Test.
	Double A = fraction(1,3).GetValueD();
	Double B = fraction(-3, 9).GetValueD();
	Double C = A + B;
	cout << C << endl;
	cout << (C + B) << endl;


	system("pause");
    return 0;
}






