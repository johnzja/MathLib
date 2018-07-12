#include "stdafx.h"
#include "ExpressionAnalyzer.h"

extern const char* _Object_Pointer_Corrupted;

Math* _calculate(Math* a, Math* b, char optr)// a & b should be deleted?!
{
	int aType = a->GetType();
	int bType = b->GetType();
	
	switch (aType)
	{
	case EXC:throw Exceptions(_Object_Pointer_Corrupted);
	case FUNC:
		//Further code here.
		break;


	case INT:

		break;

	case FRC:

		break;

	case DBL:

		break;
	case MAT:

		break;

	default:
		throw 
	}





}
