#include<iostream>

using namespace::std;

struct B1 
{
	virtual void vf() const { cout << "B1::vf()\n"; }
	void f() const { cout << "B1::f()\n"; }
	virtual void pvf() const { cout << "B1::pvf()\n"; }
};

struct D1 : B1
{
	void vf() const override { cout << "D1::vf()\n"; }
	void f() const { cout << "D1::f()\n"; }
	void pvf() const { cout << "D1::pvf()\n"; }
};

void call(const B1& b){
	b.vf();
	b.f();
	b.pvf();
}

struct D2 : D1
{
	void pvf() const override { cout << "D2::pvf()\n"; }
};

struct B2
{
	virtual void pvf() const = 0; 
};

struct D21 : B2
{

	string s = "whatever";
	void pvf() const { cout << s << '\n'; }

};

struct D22 : B2
{
	int i = 0;
	void pvf() const { cout << i << '\n'; } 
};

void f(B2& b2)
{
	b2.pvf();
}

int main(){
	
	B1 b1;
	D1 d1;

	call(b1);
	call(d1);

	cout << "End call." << '\n' << '\n';

	B1& r {d1};
	call(r);

	cout << "End ref call." << '\n' << '\n';

	D2 d2;
	call(d2);
	cout << "End D2 call." << '\n' << '\n';

	D21 d21;
	D22 d22;
	f(d21);
	f(d22);
	cout << "End of whatever this was." << '\n' << '\n';

return 0;
}
