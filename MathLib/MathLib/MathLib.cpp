// MathLib.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Math.h"
using namespace std;

extern const Double Db_zero;



int main()
{
	//Double Test.
	Double A = Db_zero;
	cin >> A;
	cout << ln(A) << endl;
	Double B = Db_zero;
	cin >> B;
	cout << pow(A, B) << endl;

	system("pause");
    return 0;
}






