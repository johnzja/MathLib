// MathLib.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Math.h"
#include "ExpressionAnalyzer.h"
using namespace std;

extern const Double Double_zero;
extern const fraction frc_zero;
int Matrix::MatrixCount = 0;

extern bool(*Clear)(int AnalyzeResult, bool initialize);
extern bool Analyze_Change(int AnalyzeResult, bool initialize);



//this function is not the ultimate edition. Just for test.


int main()
{
	Clear = Analyze_Change;
	Clear(0, true);
	//Double Test.

	Math* ans = nullptr;
	string expr = "-1+2-(3/5)";
	try
	{
		Math* ans = Calculate(expr);
		ans->print();

	}
	catch (Exceptions E)
	{
		E.print();
	}
	catch (...)
	{
		cerr << "What the f**k?" << endl;
	}
	delete ans;

	

	system("pause");
    return 0;
}






