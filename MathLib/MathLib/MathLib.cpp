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

	const char* a = "239999999999999999999999996502";
	const char* b = "240000000000000000000000006308";
	
	Double A = Double(Int((string)a), 0);
	Double B = Double(Int((string)b), 0);

	
	cout << B - A << endl;
	



	system("pause");
    return 0;
}






