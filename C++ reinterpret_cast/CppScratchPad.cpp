#include <iostream>
using std::cout;
using std::endl;

// --------------------------- C++ reinterpret_cast -----------------------------------------------------
//ref link:https://www.youtube.com/watch?v=wcKXGvi1JRk&list=PLRwVmtr-pp05motkiTlDIuU5ZfoRr-kWC&index=2&t=7s

struct Cow
{
	int mooCount;
	int legCount;
	char gender;
	bool isButchered;
};

int main()
{
	Cow cow;
	cow.mooCount = 8; cow.legCount = 5;
	cow.gender = 'f'; cow.isButchered = true;
}