#pragma once
#include "stdafx.h"
using namespace std;

#define PREC 30
class Double;

class Math
{
public:
	
protected:

};

class Exceptions :protected Math
{
public:
	Exceptions(const char* _err_info);
	~Exceptions()
	{

	}

	void display()
	{
		cerr<< errinfo << endl;
	}


private:
	char errinfo[60];
};

class Function :public Math
{

};

class Int :protected Math
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





	friend int abs_compare(const Int& a, const Int& b);
	friend ostream& operator<<(ostream& ostr, const Int& a);

	int real_length();
	unsigned int GetLength()const
	{
		return length;
	}

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


class Double :protected Math
{
public:
	Double(double x,int prec=PREC);
	Double(const Int& a, const Int& b,int prec=PREC);
	Double(const Int& a, int _exp,int prec = PREC);
	operator double() const;
	int getExpPrecision(void);
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


	protected://to be modified.
	Int val;
	int exp;
	int precision;
};

Double operator+(const Double& a, const Double& b);
Double operator-(const Double& a, const Double& b);
Double operator*(const Double& a, const Double& b);
Double operator/(const Double& a, const Double& b);
Double operator-(const Double& a);




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

class fraction :protected Math
{
public:
	fraction(int a, int b);
	fraction(Int a, Int b);
	fraction(Int a);

	fraction(double value);
	fraction(const Double& value);

	fraction() :numerator(0, 1), denominator(1, 1), value(0.0, PREC)//Default constructor:zero fraction
	{
		isSimplified = true;
		isApprox = false;
	}

	virtual ~fraction() {}

	double GetValue(void)const;
	Double GetValueD(void)const;
	void SetValue(double val);
	bool& GetApprox() { return isApprox; }
	bool GetApprox()const { return isApprox; }

	void AbortPreciseCalculation();


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

bool isInt(const fraction& frc);


class Real : protected Math
{
	//one fraction+one Double + one fraction*Sqrt[Int]


};

class Complex :protected Math
{
	//2xReal
};

class Matrix : protected Math
{
	//mxn Complex
};

class List : protected Math
{

};