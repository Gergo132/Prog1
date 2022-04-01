#include "std_lib_facilities.h"

template<typename T> 

struct S 
{ 

private:
	T val; 

public:
	S(T t):val{t} {}
	
	S& operator=(const T& t) { val=t; return *this; }
	T& get() { return val; }
	const T& get_const() const { return val; }
	
};

template<typename T>

void read_val(T& v) {cin>>v;}

void writevec(ostream& os, vector<int>vec)
{
    cout<<"Vector elemei:" << '\n';
    for(int i=0; i<vec.size(); i++)
    {
        cout << vec[i]<<" ";
    }
    cout << '\n';
}

int main()
{
	S<int>S_int(520);
	cout << S_int.get() << '\n';
	
	S<char>S_char('#');
	cout << S_char.get() << '\n';
	
	S<double>S_double(2.5);
	cout << S_double.get() << '\n';
	
	S<string>S_string("alma");
	cout << S_string.get() << '\n';
	
	S<vector<int>>S_vector({5,2,8,6});
	writevec(cout, S_vector.get());
	
	cout << "Enter an int: ";
	read_val(S_int.get());
	cout << S_int.get() << '\n';
	
	cout << "Enter a char: ";
	read_val(S_char.get());
	cout << S_char.get() << '\n';
	
	cout << "Enter a double: ";
	read_val(S_double.get());
	cout << S_double.get() << '\n';
	
	cout << "Enter a string: ";
	read_val(S_string.get());
	cout << S_string.get() << '\n';

	return 0;
}
