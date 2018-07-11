// MathLib.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Math.h"
using namespace std;

extern const Double Double_zero;
extern const fraction frc_zero;
int Matrix::MatrixCount = 0;

//this function is not the ultimate edition. Just for test.

ostream& operator<<(ostream& ostr, const Matrix& mat)
{
	int row = mat.GetRowCnt();
	int col = mat.GetColCnt();
	for (int i = 0;i < row;i++)
	{
		for (int j = 0;j < col;j++)
		{
			ostr << mat(i, j) << "   ";
		}
		ostr << endl;
	}
	return ostr;
}

int main()
{
	//Double Test.
	Matrix A(3, 3);
	A(0, 0) = fraction(1, 3);
	A(1, 0) = A(2, 0) = A(0, 1) = A(2, 1) = A(0, 2) = A(1, 2) = frc_zero;
	A(1, 1) = fraction(1, 5);
	A(2, 2) = fraction(0, 7);

	Matrix B = A * A;

	

	cout << B << endl;


	system("pause");
    return 0;
}






