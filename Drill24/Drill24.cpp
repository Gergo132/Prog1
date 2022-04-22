#include "std_lib_facilities.h"
#include "Matrix.h"
#include "MatrixIO.h"
#include "complex"
#include "numeric"

using namespace Numeric_lib;

void sqrtfrominput()
{
	int input;
	cout << "Enter an integer number: ";	
	cin >> input;
	if (input<0)
		cout << "No square root" << endl;
	else
		cout << "The square root of " << input << " is " << sqrt(input) << endl;
}

int main()
{
	try
	{
	//1
	cout << "Sizes of data types:" << endl << endl;
	cout << "The size of char: " << sizeof(char) << endl;
	cout << "The size of short: " << sizeof(short) << endl;
	cout << "The size of int: " << sizeof(int) << endl;
	cout << "The size of long: " << sizeof(long) << endl;
	cout << "The size of float: " << sizeof(float) << endl;
	cout << "The size of double: " << sizeof(double) << endl;
	cout << "The size of int*: " << sizeof(int*) << endl;
	cout << "The size of double*: " << sizeof(double*) << endl << endl;
	
	//2
	Matrix<int> a(10);
	Matrix<int> b(100);
	Matrix<double> c(10);
	Matrix<int,2> d(10,10);
	Matrix<int,3> e(10,10,10);
	cout << "The sizes of Matrixes:" << endl << endl;
	cout << "The size of Matrix<int> a(10): " << sizeof(a) << endl;
	cout << "The size of Matrix<int> b(100): " << sizeof(b) << endl;
	cout << "The size of Matrix<double> c(10): " << sizeof(c) << endl;
	cout << "The size of Matrix<int,2> d(10,10): " << sizeof(d) << endl;
	cout << "The size of Matrix<int,3> e(10,10,10): " << sizeof(e) << endl << endl;

	//3
	cout << "The number of elements in the Matrixes:" << endl;
	cout << "The number of elements in Matrix<int> a(10): " << a.size() << endl;
	cout << "The number of elements in Matrix<int> b(100): " << b.size() << endl;
	cout << "The number of elements in Matrix<double> c(10): " << c.size() << endl;
	cout << "The number of elements in Matrix<int,2> d(10,10): " << d.size() << endl;
	cout << "The number of elements in Matrix<int,3> e(10,10,10): " << e.size() << endl;

	//4
	sqrtfrominput();
	
	//5
	Matrix<double>tendouble(10);
	cout << "Enter 10 float numbers: " << endl;
	float f_input=0;
	for (int i=0; i<10; ++i)
		{
			cin >> tendouble(i);
		}
	cout << tendouble << endl;
	
	//6
	int n,m;
	cout << "Enter the dimensions of the multiplication table: " << endl;
	cin >> n >> m;
	
	Matrix<double,2> m_table(n,m);

	for (int i=0; i<n; ++i)
		{
			for (int j=0; j<m; ++j)
				m_table(i,j)=i*j;		
		}	
		
	for (int i=0; i<n; ++i)
		{
			for (int j=0; j<m; ++j)
				cout << m_table(i,j) << ' ';
			cout << endl;
		}
	
	//7
	Matrix<complex<double >> c_matrix(10);
	cout << "Enter ten complex numbers: " << endl;
	for (int i=0; i<10; ++i)
		{
			cin >> c_matrix(i);
		}
	cout << c_matrix << endl;
	complex<double> sum=accumulate(c_matrix.data(),c_matrix.data()+c_matrix.size(),complex<double>{});
	cout << sum << endl;
	
	//8
	Matrix<int,2>six_m(2,3);
	cout << "Enter 6 integers: " << endl;
	for (int i=0; i<2; ++i)
		{
			for (int j=0; j<3; ++j)
				{
					cin >> six_m(i,j);
				}
		}	
	cout << six_m << endl;
	
	
	return 0;
	}
	
	
	catch(exception& e)
	{
		cerr << "error: " << e.what() << '\n'; 
		return 1;
	}
	catch(...)
	{
		cerr << "Unknown Expcetion." << '\n'; 
		return 2;
	}
}
