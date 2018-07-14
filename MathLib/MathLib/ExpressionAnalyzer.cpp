#include "stdafx.h"
#include "ExpressionAnalyzer.h"

extern const char* _Object_Pointer_Corrupted;
extern const char* _Test_Debug_Error;
extern const char* _Operator_Not_Defined;
extern const Int Int_one;

Math* _calculate(Math* a, Math* b, optrs optr)// a & b should be deleted?!
{
	int aType = a->GetType();
	int bType = b->GetType();
	Math* ans = nullptr;
	Math* tmp = nullptr;

	try
	{
		switch (aType)
		{
		case EXC:throw Exceptions(_Object_Pointer_Corrupted);
		case FUNC:
			//Further code here. Function Applying& defining.
			break;


		case INT://a is an Int.
			if (bType == INT)//INT optr INT
			{
				switch (optr)
				{
				case add:
					ans = new Int((*dynamic_cast<Int*>(a)) + (*dynamic_cast<Int*>(b))); break;

				case subt:
					ans = new Int((*dynamic_cast<Int*>(a)) - (*dynamic_cast<Int*>(b))); break;

				case mult:
					ans = new Int((*dynamic_cast<Int*>(a)) * (*dynamic_cast<Int*>(b))); break;

				case  divide:
					ans = new Int((*dynamic_cast<Int*>(a)) / (*dynamic_cast<Int*>(b))); break;
				}
			}
			else if (bType == FRC)//INT optr FRC
			{
				tmp = new fraction(*dynamic_cast<Int*>(a));// now tmp is  fraction*.
				delete a;//Release the previous Int (converted into fraction.)
				a = tmp;
				switch (optr)
				{
				case add:
					ans = new fraction(*(dynamic_cast<fraction*>(a)) + *dynamic_cast<fraction*>(b)); break;

				case subt:
					ans = new fraction(*(dynamic_cast<fraction*>(a)) - *dynamic_cast<fraction*>(b)); break;

				case mult:
					ans = new fraction(*(dynamic_cast<fraction*>(a)) * (*dynamic_cast<fraction*>(b))); break;

				case divide:
					ans = new fraction(*(dynamic_cast<fraction*>(a)) / (*dynamic_cast<fraction*>(b))); break;

				default:
					break;

				}
			}
			else if (bType == DBL)//INT optr DBL
			{
				tmp = new Double(*dynamic_cast<Int*>(a), Int_one);
				delete a;
				a = tmp;

				switch (optr)
				{
				case add:
					ans = new Double(*dynamic_cast<Double*>(a) + *dynamic_cast<Double*>(b)); break;

				case subt:
					ans = new Double(*dynamic_cast<Double*>(a) - *dynamic_cast<Double*>(b)); break;

				case mult:
					ans = new Double(*dynamic_cast<Double*>(a) * *dynamic_cast<Double*>(b)); break;

				case divide:
					ans = new Double(*dynamic_cast<Double*>(a) / *dynamic_cast<Double*>(b)); break;

				case power:
					ans = new Double(pow(*dynamic_cast<Double*>(a), *dynamic_cast<Double*>(b))); break;

				default:

					break;
				}
			}
			else if (bType == MAT)//INT optr MAT
			{
				tmp = new fraction(*dynamic_cast<Int*>(a));// now tmp is  fraction*.
				delete a;//Release the previous Int (converted into fraction.)
				a = tmp;

				switch (optr)
				{
				case mult:
					ans = new Matrix(*dynamic_cast<fraction*>(a) * *dynamic_cast<Matrix*>(b)); break;

				case divide:
					ans = new Matrix(*dynamic_cast<fraction*>(a) * Ginverse(*dynamic_cast<Matrix*>(b))); break;

				default:
					throw Exceptions(_Operator_Not_Defined);
					break;
				}

			}

			break;

		case FRC:
			if (bType == FRC)//FRC optr FRC
			{
				switch (optr)
				{
				case add:
					ans = new fraction((*dynamic_cast<fraction*>(a)) + (*dynamic_cast<fraction*>(b))); break;

				case subt:
					ans = new fraction((*dynamic_cast<fraction*>(a)) - (*dynamic_cast<fraction*>(b))); break;

				case mult:
					ans = new fraction((*dynamic_cast<fraction*>(a)) * (*dynamic_cast<fraction*>(b))); break;

				case divide:
					ans = new fraction((*dynamic_cast<fraction*>(a)) / (*dynamic_cast<fraction*>(b))); break;

				case power:
					ans = new Double(pow(dynamic_cast<fraction*>(a)->GetValueD(), dynamic_cast<fraction*>(b)->GetValueD())); break;

				default:
					throw Exceptions(_Operator_Not_Defined);
					break;

				}
			}
			else if (bType == INT)//FRC optr INT
			{
				if (optr != power)
				{
					tmp = new fraction(*dynamic_cast<Int*>(b));//Convert into fraction.
					delete (Int*)b;
					b = tmp;

					switch (optr)
					{
					case add:
						ans = new fraction(*dynamic_cast<fraction*>(a) + *dynamic_cast<fraction*>(b)); break;

					case subt:
						ans = new fraction(*dynamic_cast<fraction*>(a) - *dynamic_cast<fraction*>(b)); break;

					case mult:
						ans = new fraction(*dynamic_cast<fraction*>(a) * *dynamic_cast<fraction*>(b)); break;

					case divide:
						ans = new fraction(*dynamic_cast<fraction*>(a) / *dynamic_cast<fraction*>(b)); break;

					default:
						break;

					}
				}
				else//optr==power
				{
					ans = new fraction(pow(*dynamic_cast<fraction*>(a), int(*(dynamic_cast<Int*>(b)))));
				}

			}
			else if (bType == DBL)//FRC optr DBL
			{
				tmp = new Double(dynamic_cast<fraction*>(a)->GetValueD());//Convert into Double.
				delete a;
				a = tmp;

				switch (optr)
				{
				case add:
					ans = new Double(*dynamic_cast<Double*>(a) + *dynamic_cast<Double*>(b)); break;

				case subt:
					ans = new Double(*dynamic_cast<Double*>(a) - *dynamic_cast<Double*>(b)); break;

				case mult:
					ans = new Double(*dynamic_cast<Double*>(a) * *dynamic_cast<Double*>(b)); break;

				case divide:
					ans = new Double(*dynamic_cast<Double*>(a) / *dynamic_cast<Double*>(b)); break;

				case power:
					ans = new Double(pow(*dynamic_cast<Double*>(a), *dynamic_cast<Double*>(b))); break;

				default:
					//Code here!
					break;
				}

			}
			else if (bType == MAT)//FRC optr MAT
			{
				switch (optr)
				{
				case mult:
					ans = new Matrix(*dynamic_cast<fraction*>(a) * *dynamic_cast<Matrix*>(b)); break;

				case divide:
					ans = new Matrix(*dynamic_cast<fraction*>(a) * Ginverse(*dynamic_cast<Matrix*>(b))); break;

				default:

					break;
				}
			}

			break;

		case DBL://DBL optr DBL
			if (bType == DBL)
			{
				switch (optr)
				{
				case add:
					ans = new Double(*dynamic_cast<Double*>(a) + *dynamic_cast<Double*>(b)); break;

				case subt:
					ans = new Double(*dynamic_cast<Double*>(a) - *dynamic_cast<Double*>(b)); break;

				case mult:
					ans = new Double(*dynamic_cast<Double*>(a) * *dynamic_cast<Double*>(b)); break;

				case divide:
					ans = new Double(*dynamic_cast<Double*>(a) / *dynamic_cast<Double*>(b)); break;

				case power:
					ans = new Double(pow(*dynamic_cast<Double*>(a), *dynamic_cast<Double*>(b))); break;

				default:

					break;
				}
			}
			else if (bType == INT)//DBL optr INT
			{
				if (optr != power)
				{
					tmp = new Double(*dynamic_cast<Int*>(b), Int_one);
					delete b;//Virtual Destructor called. No need to convert the type of pointer into Int* .
					b = tmp; // Replace b pointer.

					switch (optr)
					{
					case add:
						ans = new Double(*dynamic_cast<Double*>(a) + *dynamic_cast<Double*>(b)); break;

					case subt:
						ans = new Double(*dynamic_cast<Double*>(a) - *dynamic_cast<Double*>(b)); break;

					case mult:
						ans = new Double(*dynamic_cast<Double*>(a) * *dynamic_cast<Double*>(b)); break;

					case divide:
						ans = new Double(*dynamic_cast<Double*>(a) / *dynamic_cast<Double*>(b)); break;

					default:

						break;
					}
				}
				else//optr=power
				{
					ans = new Double(pow(*dynamic_cast<Double*>(a), int(*dynamic_cast<Int*>(b))));
				}
			}
			else if (bType == MAT)//DBL optr MAT
			{
				tmp = new fraction(*dynamic_cast<Double*>(a));
				delete a;
				a = tmp;

				switch (optr)
				{
				case mult:
					ans = new Matrix(*dynamic_cast<fraction*>(a) * *dynamic_cast<Matrix*>(b)); break;

				case divide:
					ans = new Matrix(*dynamic_cast<fraction*>(a) * Ginverse(*dynamic_cast<Matrix*>(b))); break;

				default:
					//Error code here.
					break;
				}
			}

			break;

		case MAT://Type of a is mat.
			if (bType == MAT)//MAT optr MAT
			{
				switch (optr)
				{
				case add:
					ans = new Matrix(*dynamic_cast<Matrix*>(a) + *dynamic_cast<Matrix*>(b)); break;

				case subt:
					ans = new Matrix(*dynamic_cast<Matrix*>(a) - *dynamic_cast<Matrix*>(b)); break;

				case mult:
					ans = new Matrix(*dynamic_cast<Matrix*>(a) * *dynamic_cast<Matrix*>(b)); break;

				case divide:
					ans = new Matrix(*dynamic_cast<Matrix*>(a) * Ginverse(*dynamic_cast<Matrix*>(b))); break;

				default:

					break;
				}
			}
			else
			{
				//Error!
			}

			break;

		default:
			throw Exceptions(_Test_Debug_Error);
		}


	}
	catch (Exceptions E)
	{
		delete a;
		delete b;
		throw;
	}
	catch (...)
	{
		delete a;
		delete b;
		throw;
		//Unknown Errors.
	}
	delete a;
	delete b;


	return ans;
}


