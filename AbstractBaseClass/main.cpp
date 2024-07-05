#include<iostream>
using namespace std;


class Animal
{
public:
	virtual void sound() = 0;
};
class Cat:public Animal {};
class Tiger :public Cat
{
public:
	void sound()override
	{
		cout << "RRRRRRR" << endl;
	}
};
class HomeCat :public Cat
{
public:
	void sound()override
	{
		cout << "MIAU" << endl;

	}
};
void main()
{
	setlocale(LC_ALL, "");
	//cout << "Hello AbstractBase" << endl;
	//Animal animal;
	//Cat cat;
	Tiger tiger;
	tiger.sound();
	HomeCat home;
	home.sound();
}