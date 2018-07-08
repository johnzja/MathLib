#include "stdafx.h"
#include "math.h"

extern const char*   _Divide_By_Zero;
extern const char* _Negative_Base;
const double precision = 1e-10;

fraction zero = fraction();
fraction one = fraction(1,1);
//Constructor
fraction::fraction(int a, int b)//Constructor of a/b  (unsimplified)
{
	if (b == 0)throw Exceptions(_Divide_By_Zero);
	isSimplified = false;
	isApprox = false;
	numerator = a;
	denominator = b;
}

fraction::fraction(Int a, Int b)
{
	if (b.isZero())throw Exceptions(_Divide_By_Zero);
	isSimplified = false;
	isApprox = false;
	numerator = a;
	denominator = b;
	//Value not initialized.
}


fraction::fraction(double value) :value(value)
{
	isApprox = true;
	isSimplified = true;
}

fraction::fraction(Int a)
{
	denominator = 1;
	numerator = a;
	isSimplified = true;
	isApprox = false;
	//value = static_cast<double>(a);
}
//Return the greatest common factor.
//Simplify a fraction
fraction simplify(const fraction& a)
{
	if (a.isSimplified == true || a.isApprox == true)
	{
		return a;//Do not need to simplify.
	}
	if (a.denominator.isZero())throw Exceptions(_Divide_By_Zero);

	fraction ans;
	Int i = abs(a.numerator);
	Int j = abs(a.denominator);

	if (i.isZero()) return zero;
								
	Int d = gcd(i, j); //Assure that i,j !=0

	if ((a.numerator.sign ^ a.denominator.sign))//They are of different symbol.
	{
		ans.numerator = -i / d;
	}
	else
	{
		ans.numerator = i / d;
	}

	ans.denominator = j / d;
	ans.isSimplified = true;
	ans.isApprox = false;
	
	return ans;
}

double fraction::GetValue(void)const
{
	if (isApprox)
	{
		return value;
	}
	else
	{
		return double(Double(numerator, denominator, 24));
	}
}

void fraction::SetValue(double val)
{
	value = val;
	isApprox = true;
	isSimplified = true;
}


bool operator==(const fraction& a, const fraction & b)
{
	fraction c = simplify(a);
	fraction d = simplify(b);
	if (c.isApprox == false && d.isApprox == false) return c.denominator == d.denominator && c.numerator == d.numerator;
	else
	{
		return (c.value - d.value) < precision;
	}
}


fraction operator+(const fraction& a, const fraction& b)
{

	if (a.isApprox == false && b.isApprox == false)
	{
		if (a.denominator.isZero() || b.denominator.isZero())throw Exceptions(_Divide_By_Zero);
		fraction ans(a.numerator*b.denominator + a.denominator*b.numerator, a.denominator*b.denominator);//Here: call which constructor?
		return simplify(ans);
	}
	else
	{
		fraction ans;
		ans.isApprox = true;
		ans.isSimplified = true;
		ans.value = a.value + b.value;
		return ans;
	}
}

fraction operator-(const fraction& a)
{
	if (a.isApprox == false)
	{
		fraction ans(-a.numerator, a.denominator);
		return simplify(ans);
	}
	else
	{
		fraction ans;
		ans.isApprox = true;
		ans.isSimplified = true;
		ans.value = -a.value;
		return ans;
	}
}

fraction operator-(const fraction& a, const fraction& b)
{
	return a + (-b);
}

fraction operator*(const fraction& a, const fraction& b)
{
	if (a.isApprox == false && b.isApprox == false)
	{
		fraction ans(a.numerator*b.numerator, a.denominator*b.denominator);
		return simplify(ans);
	}
	else
	{
		fraction ans;
		ans.isSimplified = true;
		ans.isApprox = true;
		ans.value = a.value * b.value;
		return ans;
	}
}

fraction& operator*=(fraction& a,const fraction& b)
{
	a = a * b;
	return a;
}

fraction reciprocal(const fraction& a)
{
	if (a.isApprox == false)
	{
		if (a.denominator.isZero() || a.numerator.isZero())throw Exceptions(_Divide_By_Zero);

		fraction ans(a.denominator, a.numerator);//The reciprocal.
		return simplify(ans);
	}
	else
	{
		fraction ans;
		ans.isApprox = true;
		ans.isSimplified = true;
		if (abs(a.value) < precision)throw Exceptions(_Divide_By_Zero);
		ans.value = 1.0 / a.value;
		return ans;
	}
}

fraction operator/(const fraction& a, const fraction& b)
{
	return a * reciprocal(b);
}


void displayFrac(const fraction& a, bool newline)
{
	if (!a.GetApprox())
	{

		if (a.denominator.isZero())throw Exceptions(_Divide_By_Zero);
		//a = simplify(a);//Nonsense.

		if (a.numerator.isZero())
		{
			cout << 0;
		}
		else
		{
			if (a.denominator==one)
			{
				cout << a.numerator;
			}
			else
			{
				cout << a.numerator << "/" << a.denominator;
			}
		}
	}
	else
	{
		if (abs(a.value) < precision)cout << 0;
		else
		{
			cout << a.value;
		}
	}

	if (newline)
	{
		cout << endl;
	}

}

//Fast power calculation.
fraction pow(const fraction& frc, const int& n)
{
	if (n == 0)
	{
		if (frc.GetValue() <= 0)throw Exceptions(_Negative_Base);
		return one;
	}
	else if (n > 0)
	{
		fraction base = frc;
		fraction ans = zero;
		int _n = n;

		while (_n)
		{
			if (_n & 1)ans *= base;
			base *= base;
			_n >>= 1;
		}
		return ans;
	}
	else
	{
		if (frc == zero)throw Exceptions(_Negative_Base);
		return pow(reciprocal(frc), -n);
	}

}

/*
bool isInt(const fraction& frc)
{
	if (frc.isApprox == true)return false;
	fraction temp = simplify(frc);
	if (temp.denominator == 1)return true;
	else return false;

}
*/

ostream& operator<<(ostream& ost, const fraction& frac)
{
	displayFrac(frac, false);
	return ost;
}
