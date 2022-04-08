#include "std_lib_facilities.h"

template<typename Iter1, typename Iter2>
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
	for (auto i=f1; i!=e1; i++)
		{
		*f2=*i;
		f2++;
		}
		return f2;
};
int main()
{
	int a[10] = {0,1,2,3,4,5,6,7,8,9};
	vector<int> v  {0,1,2,3,4,5,6,7,8,9};
	list<int> l  {0,1,2,3,4,5,6,7,8,9};
	cout << "Base numbers: " << "{0,1,2,3,4,5,6,7,8,9}\n";
	
	int a2[10]; my_copy(begin(a), end(a), begin(a2)); 
	vector<int> v2 = v;
	list<int> l2 = l; //base konténerek
	
	cout << "Increased array: ";
		for (auto& x: a)
			{
			x+=2;
			cout << x <<' ';
			} 
			cout << '\n';


	cout << "Increased list: ";
		for (auto& x: l)
			{
			x+=3;
			cout << x << ' ';
			} 
			cout << '\n';
		
	
	cout << "Increased vector: ";
		for (auto& x: v)
			{
			x+=5;
			cout << x << ' ';
			} 
			cout << '\n';
		
	
	cout << "Increased array copied into vector: ";
	my_copy(begin(a), end(a), begin(v2));
		for (auto x: v2)
			cout << x << ' '; cout << '\n';

	cout << "Increased list copied into array: ";
	my_copy(l.begin(), l.end(), begin(a2));
		for (auto x: a2)
			cout << x << ' '; cout << '\n';


	int value1 = 3, value2 = 27;  //A két keresett elem
	auto elem1 = find(v.begin(), v.end(), value1); //Megkeresem melyik memóriacímen van
		if (elem1 != v.end())
			cout << value1 << " is at " << "index: " << distance(v.begin(), elem1) << '\n';
		else
			cout << value1 << " is not in the increased vector.\n";

	auto elem2 = find(l.begin(), l.end(), value2);
		if (elem2 != l.end())
			cout << value2 << " is at " << "index: " << distance(l.begin(), elem2) << '\n';
		else
			cout << value2 << " is not in the increased list.\n";

	return 0;
}

