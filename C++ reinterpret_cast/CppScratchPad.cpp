#include <iostream>
using std::cout;
using std::endl;

// --------------------------- C++ reinterpret_cast -----------------------------------------------------
//ref link:https://www.youtube.com/watch?v=wcKXGvi1JRk&list=PLRwVmtr-pp05motkiTlDIuU5ZfoRr-kWC&index=2&t=7s

//reinterpret cast allows you to cast a pointer type into another type
//reinterpret casting - does not change the address while changing the value type of a RAM in compile time
//one thing to point out is reinterpret cast should be used keeping in mind the packing done by the compiler and if you don't want to check the packing, then just use pragma pack 1(compiler optimization won't be applied and there would be no packing)

struct Cow		//struct defaults to public
{
	int mooCount;
	int legCount;
	char gender;
	bool isButchered;
};

int main()
{
	Cow cow;		// cow contains 2x int, char, bool, packing(compiler)
	cow.mooCount = 8; cow.legCount = 5;
	cow.gender = 'f'; cow.isButchered = true;
	Cow* cowPtr = &cow;		//cow pointer - address
	//cout << cowPtr->gender;		// -> dereference
	int* intPtr = reinterpret_cast<int*>(cowPtr);		// reinterpret_cast
	//cout << cowPtr << endl; cout << intPtr << endl;		// Result:same address as intPtr cause of reinterpret_casting
	//cout << intPtr << endl;	//Result: 8 <- the first value of struct Cow
	//############################
	//intPtr++;		//PointerArithmetic-SameAs: intPtr = intPtr + 1;
	//intPtr = intPtr + 1;	
	//cout << intPtr << endl;		//result: address + int size value
	//############################
	//cout << *intPtr << endl;	//points to mooCount value
	//intPtr++;
	//cout << *intPtr << endl;	// *intPtr points to legCount cause of intPtr++
	//############################
	intPtr += 2;
	cout << *intPtr << endl;	// points to gender(int value)
	cout << *reinterpret_cast<char*>(intPtr) << endl;	// points to gender(char value) and the value char is not save to char point value
	char* charPtr = reinterpret_cast<char*>(intPtr);
	//cout << *charPtr << endl;	// stored in charPtr value
	charPtr++;			// *charPtr pointer move to 4 bytes
	cout << *charPtr << endl;	// charPtr points to isButchered(charr value)
	cout << *reinterpret_cast<bool*>(charPtr) << endl;	// charPtr points to isButchered(bool value)
	cout << true << endl; // prove bool result of isButchered bool value
}