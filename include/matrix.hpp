#include <iostream>
#include <fstream>
#include <locale.h>

using namespace std;

class Matrix
{
private:
	int **matr, str, col;

public:
	Matrix();
	Matrix(int m, int n);
	Matrix(Matrix &Cpymatr);
	int сolumn_();
	int line_();
	~Matrix();
	void scan(string fname);
	friend istream& operator >> (istream& stream, const Matrix& matrix);
	friend ostream& operator << (ostream& stream, const Matrix& matrix);
	Matrix& operator =(const Matrix &matrix);
	Matrix operator+ (const Matrix &matr2)const;
	Matrix operator* (const Matrix &matr2)const;
	bool operator==(const Matrix&matrix)const;
};
