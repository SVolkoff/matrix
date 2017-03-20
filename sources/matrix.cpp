#include "matrix.hpp"

Matrix::Matrix()
{
	str = col = 0;
	this->matr = nullptr;
}
Matrix::Matrix(int m, int n)
{
	str = m; col = n;
	matr = new int *[str];
	for (int i = 0; i < str; i++)
	{
		matr[i] = new int[col];
		for (int j = 0; j < n; j++)
			matr[i][j] = 0;
	}

}
Matrix::Matrix(Matrix &Cpymatr)
{
	str = Cpymatr.str;
	col = Cpymatr.col;
	matr = new int*[str];
	for (int i = 0; i < str; ++i)
	{
		matr[i] = new int[col];
		for (int j = 0; j < col; ++j)
			matr[i][j] = Cpymatr.matr[i][j];
	}
}
Matrix:: ~Matrix()
{
	for (int i = 0; i < str; i++)
	{
		delete[] matr[i];
	}
	delete[] matr;
}
int Matrix::lines_()
{
	return str;
}
int Matrix::columns_()
{
	return col;
}
void Matrix::scan(string fname)
{
	ifstream file;
	file.open(fname);
	if (!file.is_open())
	{
		cout << "Файл не найден" << endl;
		system("pause");
		exit(1);
	}

	else
	{
		for (int i = 0; i < str; i++)
			for (int j = 0; j < col; j++)
				file >> matr[i][j];
	}
	file.close();
}
ostream& operator << (ostream& stream, const Matrix& matrix)
{
	for (int i = 0; i < matrix.str; i++)
	{
		for (int j = 0; j < matrix.col; j++)
			stream << matrix.matr[i][j] << " ";
		stream << endl;
	}
	return stream;
}
istream& operator >> (istream& stream, const Matrix& matrix)
{
	for (int i = 0; i < matrix.str; i++)
	for (int j = 0; j < matrix.col; j++)
		stream >> matrix.matr[i][j];
	return stream;
}

Matrix Matrix::operator+ (const Matrix &matr2)const
{
	if ((str != matr2.str) || (col != matr2.col))
	{
		Matrix temp(0, 0);
		cout << "Размер матриц не совпадает";
		return temp;
	}
	else
	{
		Matrix temp(str, col);
		for (int i = 0; i < str; ++i)
		for (int j = 0; j < col; ++j)
			temp.matr[i][j] = matr[i][j] + matr2.matr[i][j];
		return temp;
	}
}
Matrix& Matrix::operator= (const Matrix &matrix)
{
	if (&matrix != this)
	{
		for (int i = 0; i < str; i++)
			delete[] matr[i];
	delete[] matr;
	}
	str = matrix.str;
	col = matrix.col;
	matr = new int*[str];
	for (int i = 0; i < str; i++)
	{
		matr[i] = new int[col];
		for (int j = 0; j < col; j++)
			matr[i][j] = matrix.matr[i][j];
	}
		
	return *this;
}
Matrix Matrix::operator* (const Matrix  &matr2)const
{
	if (matr2.str != col)
	{
		Matrix temp(0, 0);
		cout << "Размер матриц не совпадает";
		return temp;
	}

	else
	{
		Matrix temp(str, matr2.col);
		for (int i = 0; i < str; i++)
			for (int j = 0; j < matr2.col; j++)
			{
				temp.matr[i][j] = 0;
				for (int k = 0; k < col; k++)
					temp.matr[i][j] += matr[i][k] * matr2.matr[k][j];
			}
		return temp;
	}
}
bool Matrix::operator==(const Matrix& matrix)const
{
	bool f = 1;
	if (str != matrix.str || col != matrix.col)
	{
		cout << "Размер матриц не совпадает" << endl;
		return 0;
	}
	else
	{
		for (int i = 0; i < str; i++)
		for (int j = 0; j < col; j++)
			if (matr[i][j] != matrix.matr[i][j])
				f = 0;
	}
	return f;
}
