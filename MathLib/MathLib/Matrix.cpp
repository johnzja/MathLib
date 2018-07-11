#include "stdafx.h"
#include "Math.h"

extern const char* _Matrix_Math_Error = "Matrix Math Error.";

static void LineValidity(const Matrix* ptr_This, bool isRow, int lineA, int lineB = -1)
{
	if (lineB != -1)//Check B
	{
		if (isRow)//Row
		{
			if (lineB < 0 || lineB >= (ptr_This->GetRowCnt()))throw Exceptions(_Matrix_Size_Error);
		}
		else//Column
		{
			if (lineB < 0 || lineB >= (ptr_This->GetColCnt()))throw Exceptions(_Matrix_Size_Error);
		}
	}
	if (isRow)//isRow==true
	{

		if (lineA< 0 || lineA >= (ptr_This->GetRowCnt()))throw Exceptions(_Matrix_Size_Error);
	}
	else
	{
		if (lineA< 0 || lineA >= (ptr_This->GetColCnt()))throw Exceptions(_Matrix_Size_Error);
	}

	return;
}

Matrix& Matrix::operator=(const Matrix& mat)
{
	if (mat.column <= 0 || mat.row <= 0 || mat.ptr == nullptr)
	{
		this->column = 0;
		this->row = 0;
		this->ptr = nullptr;
		return *this;
	}//a void matrix.

	if (this != &mat)//Two different matrices.
	{
		fraction* temp_ptr;
		if (row == mat.row && column == mat.column)//If the two matrices are of the same size, then copy the data directly.
		{
			for (int i = 0;i < row;i++)
			{
				for (int j = 0;j < column;j++)
				{
					if ((temp_ptr = dynamic_cast<fraction*>(&mat.ptr[i][j])) == nullptr)throw Exceptions(_Matrix_Pointer_Corrupted);
					*temp_ptr = simplify(*temp_ptr);
				}
			}
		}
		else
		{
			if (this->ptr != nullptr)
			{
				for (int i = 0;i < row;i++)//delete the old contents.
				{
					delete[] dynamic_cast<fraction*>(ptr[i]);
				}
				delete[] ptr;
			}
			row = mat.row; //copy normal data members
			column = mat.column;

			Math**temp = new Math*[row];    //复制指针指向的内容   
			for (int i = 0;i < row;i++)
			{
				ptr[i] = (Math*)new fraction[column];
				for (int j = 0;j < column;j++)
				{
					if ((temp_ptr = (dynamic_cast<fraction*>(mat.ptr[i]) + j)) == nullptr)throw Exceptions(_Matrix_Pointer_Corrupted);//Problems here.
					*(dynamic_cast<fraction*>(ptr[i]) + j) = simplify(*temp_ptr);
				}
			}

			ptr = temp;   //建立新指向  
		}
	}
	return *this;
}

fraction& Matrix::operator()(int i, int j)const
{
	LineValidity(this, true, i);
	LineValidity(this, false, j);
	return *(dynamic_cast<fraction*>(ptr[i]) + j);
}

Matrix operator+(const Matrix& mat1, const Matrix& mat2)
{
	mat1.ValidityCheck();
	mat2.ValidityCheck();
	if (mat1.column != mat2.column || mat1.row != mat2.row)throw Exceptions(_Matrix_Math_Error);

	Matrix ans(mat1.row, mat1.column);

	for (int i = 0;i < ans.row;i++)
	{
		for (int j = 0;j < ans.column;j++)
		{
			ans(i, j) = mat1(i, j) + mat2(i, j);
		}
	}
	return ans;
}

Matrix operator-(const Matrix& mat)
{
	mat.ValidityCheck();
	Matrix ans(mat.row, mat.column);
	for (int i = 0;i < mat.row;i++)
	{
		for (int j = 0;j < mat.column;j++)
		{
			ans(i, j) = -mat(i, j);
		}
	}
	return ans;
}

Matrix operator-(const Matrix& mat1, const Matrix& mat2)
{
	mat1.ValidityCheck();
	mat2.ValidityCheck();
	if (mat1.column != mat2.column || mat1.row != mat2.row)throw Exceptions(_Matrix_Math_Error);

	Matrix ans(mat1.row, mat1.column);

	for (int i = 0;i < ans.row;i++)
	{
		for (int j = 0;j < ans.column;j++)
		{
			ans(i, j) = mat1(i, j) - mat2(i, j);
		}
	}
	return ans;
}

bool operator==(const Matrix& mat1, const Matrix& mat2)
{
	mat1.ValidityCheck();
	mat2.ValidityCheck();
	if (mat1.row != mat2.row || mat1.column != mat2.column)return false;

	for (int i = 0;i < mat1.row;i++)
	{
		for (int j = 0;j < mat1.column;j++)
		{
			if (!(mat1(i, j) == mat2(i, j)))return false;
		}
	}
	return true;
}