//根据原书做的版本

#include<string>
#include<map>
#include<iostream>

using namespace std;

typedef float elemType;//方便转为template形式

class Matrix {
	//friend声明
	friend Matrix operator + (const Matrix&, const Matrix&);//矩阵加法
	friend Matrix operator * (const Matrix&, const Matrix&);//矩阵乘法
public:
	//两类constructor
	//不必另外设计copy constructor 或 copy assignment operator
	//也不需要destructor
	Matrix(elemType = 0.0, elemType = 0.0, elemType = 0.0, elemType = 0.0,
		elemType = 0.0, elemType = 0.0, elemType = 0.0, elemType = 0.0,
		elemType = 0.0, elemType = 0.0, elemType = 0.0, elemType = 0.0,
		elemType = 0.0, elemType = 0.0, elemType = 0.0, elemType = 0.0);//default constructor,可选择性地接受16个数据值，默认值为0
	Matrix( const elemType* );//接受一个拥有16个元素的数组，参数列表中输入为该数组的指针

	//转换为4*4的矩阵
	int rows() const { return 4; }
	int cols() const { return 4; }

	ostream& print(ostream&) const;//打印函数
 
	void operator+= ( const Matrix& );//矩阵复合运算

	//下标取元素
	elemType& operator()( int row, int column )
	{ return _matrix[ row ][ column ]; }
	elemType operator()( int row, int column ) const 
	{ return _matrix[ row ][ column ]; }

private:
	elemType _matrix[4][4];
};

Matrix operator + (const Matrix& m1, const Matrix& m2) {
	Matrix result(m1);
	result += m2;
	return result;
}

Matrix operator * (const Matrix& m1, const Matrix& m2) {
	Matrix result;
	for ( int ix = 0; ix < m1.rows(); ix++ )
		for ( int jx = 0; jx < m2.cols(); jx++ ) {
			result( ix, jx ) = 0;//初始值
			for ( int kx = 0; kx < m1.cols(); kx++ )
				result( ix, jx ) += m1( ix, kx ) * m2( kx, jx );
		}
	return result;
}

Matrix::
Matrix(elemType a1_1, elemType a1_2, elemType a1_3, elemType a1_4,
	elemType a2_1, elemType a2_2, elemType a2_3, elemType a2_4,
	elemType a3_1, elemType a3_2, elemType a3_3, elemType a3_4,
	elemType a4_1, elemType a4_2, elemType a4_3, elemType a4_4)
{
	_matrix[0][0] = a1_1; _matrix[0][1] = a1_2;
	_matrix[0][2] = a1_3; _matrix[0][3] = a1_4;
	_matrix[1][0] = a2_1; _matrix[1][1] = a2_2;
	_matrix[1][2] = a2_3; _matrix[1][3] = a2_4;
	_matrix[2][0] = a3_1; _matrix[2][1] = a3_2;
	_matrix[2][2] = a3_3; _matrix[2][3] = a3_4;
	_matrix[3][0] = a4_1; _matrix[3][1] = a4_2;
	_matrix[3][2] = a4_3; _matrix[3][3] = a4_4;
}

Matrix::
Matrix(const elemType *array)
{
	int array_index = 0;//索引
	for (int ix = 0; ix < 4; ix++)
		for (int jx = 0; jx < 4; jx++)
			_matrix[ix][jx] = array[array_index++];
}

ostream& Matrix::
print(ostream &os) const {
	int cnt = 0;
	for (int ix = 0; ix < 4; ix++)
		for (int jx = 0; jx < 4; jx++, ++cnt) {//注意jx++和++cnt间是,而非;
			if (cnt && !(cnt % 8)) os << endl;
			os << _matrix[ix][jx] << ' ';
		}
	os << endl;
	return os;
}

//简化矩阵的打印
inline ostream& operator<< (ostream& os, const Matrix &m) {return m.print( os ); }

void Matrix::
operator+= (const Matrix &m){
	for (int ix = 0; ix < 4; ix++)
		for (int jx = 0; jx < 4; jx++)
			_matrix[ix][jx] += m._matrix[ix][jx];
}

int main() {
	elemType ar1[16] = {
		1.0, 0.0, 0.0, 0.0, 2.0, 0.0, 0.0, 1.0,
		0.0, 0.0, 1.0, 0.0, 3.0, 0.0, 1.0, 2.0,};
	
	elemType ar2[16] = {
		1.0, 0.0, 4.0, 7.0, 2.0, 0.3, 6.0, 1.0,
		0.4, 1.0, 1.0, 0.5, 3.0, 5.0, 1.0, 2.0, };

	Matrix m1;
	Matrix m2(ar1);
	Matrix m3(ar2);
	Matrix m4 = m2 * m3;
	Matrix m5 = m2 + m3;

	cout << m1 << endl;
	cout << m2 << endl;
	cout << m3 << endl;
	cout << m4 << endl;
	cout << m5 << endl;

	m5 += m4;
	cout << m5 << endl;
}