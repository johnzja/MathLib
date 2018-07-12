#pragma once
#include "stdafx.h"
using namespace std;

#define PREC 30

#define EXC 0
#define FUNC 1
#define INT 2
#define DBL 3
#define FRC 4
#define REAL 5
#define CMPLX 6
#define MAT 7

class Double;

class Math
{
public:
	virtual ~Math() {}
	virtual int GetLength()const
	{
		return 0;
	}

	virtual int GetType()const = 0;

protected:

};

class Exceptions :public Math
{
public:
	Exceptions(const char* _err_info);
	virtual ~Exceptions()
	{

	}

	void display()
	{
		cerr<< errinfo << endl;
	}
	virtual int GetType() const { return EXC; }

private:
	char errinfo[70];
};

class Function :public Math
{
public:
	virtual ~Function() {}
	virtual int GetType()const { return FUNC; }
};

class Int :public Math
{
public:
	Int(int val = 0, int _length = 10);
	//	Int(long int val);
	//Int(double val_d);
	Int(const Int& src);
	Int(char* src, int length);
	Int& operator=(const Int& src);
	Int operator-()const;


	Int abs_add(const Int& b)const;
	Int abs_subtract(const Int& b)const;
	Int abs_mult(const Int& b)const;
	Int abs_divide(const Int& b, Int& res)const;

	inline char GetDigit(int n)const;
	inline bool isZero()const;

	operator int()const;

	//friend Int operator+(Int& a, Int&b);
	//friend Int operator-(Int a, Int b);
	//friend Int operator*(Int a, Int b);
	friend Int operator/(const Int& a, const Int& b);
	friend Int operator%(const Int& a, const Int& b);
	friend class Double;
	friend ostream& operator<<(ostream& ost, const Double& db);
	friend Double abs_add(const Double& a, const Double& b);
	friend Double abs_subtract(const Double& a, const Double& b);
	friend int abs_compare(const Double& a, const Double& b);
	friend Double operator*(const Double& a, const Double& b);
	friend istream& operator>>(istream& ist, Double& db);



	friend int abs_compare(const Int& a, const Int& b);
	friend ostream& operator<<(ostream& ostr, const Int& a);

	int real_length();
	virtual int GetLength()const;
	virtual int GetType() const { return INT; }


	virtual ~Int();

	bool sign;
private:

	char* data_ptr;
	char* data_tail_ptr;
	unsigned int length;//This is dynamic.
};

Int operator+(const Int& a, const Int& b);
Int operator-(const Int& a,const Int& b);
Int& operator+=(Int& a,const Int& b);
Int operator*(const Int& a, const Int& b);
Int operator/(const Int& a, const Int& b);

Int gcd(const Int& a, const Int& b);
Int abs(const Int& a);
bool operator==(const Int& a, const Int& b);


class Double :public Math
{
public:
	Double(double x,int prec=PREC);
	Double(const Int& a, const Int& b,int prec=PREC);
	Double(const Int& a, int _exp,int prec = PREC);
	operator double() const;
	int GetPrecision(void);
	int GetExp(void);
	friend int abs_compare(const Double& a, const Double& b);
	bool isZero()const;


	//Friends must be limited to necessary operators.
	friend ostream& operator<<(ostream& ost, const Double& db);
	friend Double abs_add(const Double& a, const Double& b);
	friend Double abs_subtract(const Double& a, const Double& b);
	friend Double operator+(const Double& a, const Double& b);
	friend Double operator-(const Double& a);
	friend Double operator-(const Double& a, const Double& b);
	friend Double operator*(const Double& a, const Double& b);
	friend Double operator/(const Double& a, const Double& b);
	friend bool operator==(const Double& a, const Double& b);
	friend bool operator<(const Double& a, const Double& b);
	friend bool operator>(const Double& a, const Double& b);


	friend Double pow(Double x, Double y);
	friend Double pow(Double x, int y);

	virtual ~Double(){}
	virtual int GetLength()const;
	virtual int GetType()const
	{
		return DBL;
	}

	private://to be modified.
	Int val;
	int exp;
	int precision;
};

Double operator+(const Double& a, const Double& b);
Double operator-(const Double& a, const Double& b);
Double operator*(const Double& a, const Double& b);
Double operator/(const Double& a, const Double& b);
Double operator-(const Double& a);
istream& operator>>(istream& ist, Double& db);




//Comparative operators
bool operator==(const Double& a, const Double& b);
bool operator<(const Double& a, const Double& b);
bool operator>(const Double& a, const Double& b);

Double abs(Double x);
Double pow(Double x, int y);
Double ArcTan(const Double& x);
Double exponent(Double x);
Double lnop(Double x);
Double ln(Double x);
Double pow(Double x, Double y);

class fraction :public Math
{
public:
	fraction() :numerator(0, 1), denominator(1, 1), value(0.0, PREC)//Default constructor:zero fraction
	{
		isSimplified = true;
		isApprox = false;
	}

	fraction(int a, int b);
	fraction(Int a, Int b);
	fraction(Int a);

	fraction(double value);
	fraction(const Double& value);


	virtual ~fraction() {}

	double GetValue(void)const;
	Double GetValueD(void)const;
	void SetValue(double val);
	//bool& GetApprox() { return isApprox; }
	bool GetApprox()const { return isApprox; }

	void AbortPreciseCalculation();
	virtual int GetType()const
	{
		return FRC;
	}


	fraction& operator+=(const fraction& b);
	fraction& operator-=(const fraction& b);
	fraction& operator*=(const fraction& b);
	fraction& operator/=(const fraction& b);


	friend fraction simplify(const fraction& a);
	friend bool operator==(const fraction& a, const fraction & b);

	friend fraction operator+(const fraction& a, const fraction& b);
	friend fraction operator-(const fraction& a);
	friend fraction operator-(const fraction& a, const fraction& b);

	friend fraction operator*(const fraction& a, const fraction& b);
	friend fraction reciprocal(const fraction& a);
	friend void displayFrac(const fraction& a, bool newline);
	friend bool isInt(const fraction& frc);



private:

	Int numerator;
	Int denominator;
	Double value;
	bool isApprox;
	bool isSimplified;
};

ostream& operator<<(ostream& ost, const fraction& frac);

fraction operator+(const fraction& a, const fraction& b);
fraction operator-(const fraction& a);
fraction operator-(const fraction& a, const fraction& b);
fraction operator*(const fraction& a, const fraction& b);
fraction operator/(const fraction& a, const fraction& b);
fraction pow(const fraction& frc, const int& n);
fraction reciprocal(const fraction& a);
bool operator!=(const fraction& a, const fraction& b);


bool isInt(const fraction& frc);


class Real : public Math
{
	//one fraction+one Double + one fraction*Sqrt[Int]
public:
	virtual int GetType()const
	{
		return REAL;
	}


};

class Complex :public Math
{
public:
	virtual int GetType()const
	{
		return CMPLX;
	}

	//2xReal
};

//Matrix Class started here.
class Matrix;
struct SelectArray;
Matrix reduce(const Matrix& mat, int DeleteCol, int DeleteRow = 0);
Matrix GaussEliminate(const Matrix& mat, int* rankptr = nullptr, SelectArray** sarray = nullptr);
Matrix Identity(int n);
Matrix NullSpace(const Matrix& mat);



class Matrix : public Math
{
	friend Matrix operator+(const Matrix& mat1, const Matrix& mat2);
	friend Matrix operator-(const Matrix& mat);
	friend Matrix operator-(const Matrix& mat1, const Matrix& mat2);
	friend bool operator==(const Matrix& mat1, const Matrix& mat2);
	friend Matrix reduce(const Matrix& mat, int DeleteCol, int DeleteRow);
	friend fraction det(const Matrix& mat);
	friend Matrix inverse(const Matrix& mat);
	friend Matrix adj(const Matrix& mat);
	friend Matrix operator*(const Matrix& mat1, const Matrix& mat2);
	friend Matrix operator*(const fraction& frc, const Matrix& mat);
	friend Matrix operator%(const Matrix& mat1, const Matrix& mat2);
	friend Matrix Transpose(const Matrix& mat);
	friend Matrix GaussEliminate(const Matrix& mat, int* rankptr, SelectArray** sarray);
	friend Matrix matmerge_row(const Matrix& mat1, const Matrix& mat2);
	friend Matrix LeftNullSpace(const Matrix& mat);
	friend fraction Gdet(const Matrix& mat);
	friend Matrix Ginverse(const Matrix& mat);



public:
	Matrix()//Standard blank matrix.The nullptr indicates that it is a blank matrix.
	{
		row = 0;
		column = 0;
		ptr = nullptr;
		MatrixCount++;
	}

	Matrix(int rowNum, int columnNum) :row(rowNum), column(columnNum)
	{
		assert(rowNum >=0 && columnNum >= 0);
		ptr = new Math*[row];
		for (int i = 0;i < row;i++)
		{
			ptr[i] = (Math*)(new fraction[column]);//Here: should call the constructor!
		}
		MatrixCount++;
	}

	Matrix(const Matrix& mat);//the Copy Constructor includes simplification
	Matrix& operator=(const Matrix& mat);
	fraction& operator()(int i, int j)const;
	bool ValidityCheck()const;

	void swap(int lineA, int lineB);
	void add(int lineA, int lineB, const fraction& rate);
	void mult(int line, const fraction& rate);

	void col_swap(int lineA, int lineB);
	void col_add(int lineA, int lineB, const fraction& rate);
	void col_mult(int line, const fraction& rate);

	int rank();
	Matrix EigenEqu();//return a 1xn matrix.

	virtual ~Matrix()
	{
		for (int i = 0;i < row;i++)
		{
			delete[] dynamic_cast<fraction*>(ptr[i]);
		}
		delete[] ptr;
		MatrixCount--;
	}

	Matrix GetRow(int Row);
	Matrix GetColumn(int Column);
	void ReplaceColumn(const Matrix& B, int pos_col);

	int GetRowCnt()const { return row; }
	int GetColCnt()const { return column; }
	static int GetMatrixCnt() { return MatrixCount; }

	virtual int GetType()const
	{
		return MAT;
	}

protected:
	int row;
	int column;
	Math** ptr;
	static int MatrixCount;
};

//Matrix class ended here.



struct SelectArray//In resources.
{

	SelectArray(int ArrLength) :ArrayLength(ArrLength)//ArrLength>=1
	{
		SArrayPtr = new bool[ArrayLength];
		//Initialize as false?
		return;
	}

	void initialize(bool initAsOne = true)
	{
		OverFlowFlag = false;
		SArrayPtr[0] = initAsOne;//InitialValue=0001;
		for (int i = 1;i < ArrayLength;i++)
		{
			SArrayPtr[i] = false;
		}
		return;
	}

	~SelectArray()
	{
		delete[] SArrayPtr;
	}



	void operator++(int)
	{
		for (int i = 0;i < ArrayLength;i++)
		{
			if (!SArrayPtr[i])
			{
				SArrayPtr[i] = true;
				return;
			}
			else
			{
				SArrayPtr[i] = false;
			}
		}
		OverFlowFlag = true;
		return;
	}

	int truecnt(void)const
	{
		int cnt = 0;
		for (int i = 0;i < ArrayLength;i++)
		{
			if (SArrayPtr[i])cnt++;
		}
		return cnt;
	}

	int falsecnt(void)const
	{
		return ArrayLength - truecnt();
	}


	bool OverFlowFlag;
	bool* SArrayPtr;
	int ArrayLength;
};
