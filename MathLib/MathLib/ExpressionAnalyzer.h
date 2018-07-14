#pragma once
#include "Math.h"

enum optrs
{
	add = 0, subt, mult, divide, power, null
};
#define OPND 0//operand.
#define SIGN 1//+-
#define OPTR 2//*/^
#define UNIDENT 3
#define BRAC_LEFT 4
#define BRAC_RIGHT 5
#define EQU_SIGN 6
#define UNIDENT_ERROR "Unidentified Syntax!"
#define SYNTAX_ERROR "Syntax Error!"
#define BRAC_ERROR "Brackets don`t match!"
#define UNIDENT_FUNC_ERROR "Unidentified function Error!"
#define UNKNOWN_MAT_ERROR "Undefined Matrix!"

//OperatorName

#define PI 3.14159265358979323846264
#define EULER_NUM 2.7182818284590452353602874713526624977572470936999595749 




Math* _calculate(Math* a, Math* b, optrs optr);
