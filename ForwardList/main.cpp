#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;


#define tab "\"
#define delimiter "\n------------------------------------------------------------\n"

class Element
{
	int Data;
	Element* pNext;
	static int count = 0;
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		cout << "EDestructor:\t" << this << endl;
	}
	friend class ForwardList;

};
class ForwardList
{
	ELement* Head;
	int size;
public:
	int get_size(const)
	{
		return size;
	}
	ForwardList()
	{
		Head = nullptr;
		size = 0;
		cout << "LConsrtuctor:\t" << this << endl;
	}
	explicit ForwardList(int size):ForwardList()
	{
		while (size--)push_front(0);
	}
	ForwardList(const ForwardList& other) :ForwardList()
	{
		*this = other;
		cout << "CopyConstructor :\t" << this << endl;
	}
	ForwardList(ForwardList&& other) :ForwardList()
	{
		*this = std::move(other);
		cout << "MovieConstructor:" << this << endl;
	}
	~ForwardList()
	{
		while (Head)pop_front();
		cout << "LDestructor:\t" << this << endl;
	}
	void push_front(int Dats)
	{
		Element* New = new Element(Data);
		New->pNext = Head;
		size++;
	}
	void push_back(int data)
	{
		if (Head == nullptr)return push_front(Data);
		Element* New = new Element(Data);
		Element* Temp = Head;
		while (Temp)Temp = Temp->pNext;
		
		Temp->pNext = New;
		size++;

	}

	void insert(int Index, int Data)
	{
		if (Index > size)
		{
			count << "Error: out of range" << endl;
			return;
		}
		if (Index == 0)return push_front(Data);
		Element* New = new Element(Data);
		Element* Temp = Head;
		For(int i = 0; i < Index; i++)
			if (Temp->pNext == nullptr)break;
				Temp = Temp->pNext;
		New->pNext = Temp->pNext;
		Temp->pNext = New;
		size++;

	}

	void pop_front()
	{
		if (Head == nullptr)return;
		Element* Erased = Head;
		Head = Head->pNext;
		delete[] Erased;
		size--;

	}
	void pop_back()
	{
		if (Head->pNext == nullptr)return pop_front();
		Element* Temp = Head;
		while (Temp->pNext->pNext)Temp = Temp->pNext;
		delete Temp->pNext;
		Temp->pNext = nullptr;
		size--;
	}
	ForwardList& operator = (const ForwardList& other)
	{
		if (this == &other)return *this;
		this->~ForwardList();
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
			push_back(Temp->Data);
		cout << "CopyAssignment: \t" << this << endl;
		return *this;
	}
	ForwardList& operator = (ForwardList&& other)
	{
		if (this == &other)return *this;
		this->~ForwardList();
		this->Head = other.Head;
		this -> size = other.size;
		other.Head = nullptr;
		other.size = 0;
		cout << "MovieAssignment:\t" << this << endl;
	}
	int& operator[](int index)
	{
		Element* Temp = Head;
		for (int i = 0; i < index; i++)
			return Temp->Data;

	}
	const int& operator[](int index)const
	{
		Element* Temp = Head;
		for (int i = 0; i < index; i++)
			return Temp->Data;
	
	}


	void print()const
	{
		Element* Temp = Head;
		While(Temp)
		{
			cout << Temp << tab << Temp->Data << Temp->pNext << endl;
			Temp = Temp->pNext;
		}
		cout << "Количество элементов списка: " << size << endl;
		cout << "Общее количество элементов списка: " << Element::count << endl;
	}
};
//#define BASE_CHECK
//#define COUNT_CHECK
//#define SIZE_CONSTRUCTOR_CHECK

ForwardList operator+(const ForwardList& left, const ForrwardList& right)
{
	ForwardList buffer;
	for (int i = 0; i < left.get_size(); i++)buffer.push_back(left[i]);
	for (int i = 0; i < right.get_size(); i++)buffer.push_back(right[i]);
	return buffer;
}

void main()
{
	setlocale(LC_ALL, "");
#ifdef BASE_CHECK


	int n;
	cout << "Введите количество элементов списка: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		//list.push_front(rand()) % 100);
		list.push_back(rand()) % 100);
	}
	list.print();
	list.push_back(123);
	list.print();
	list.pop_front();
	list.print();
	int index;
	int value;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << " Введите значение добавляемого элемента: "; cin >> value;
	list.insert(index, value);
	list.print();
#endif // BASE_CHECK
#ifdef COUNT_CHECK


	ForwardList1 List1;
	List1.push_back(3);
	List1.push_back(5);
	List1.push_back(8);
	List1.push_back(13);
	List1.push_back(21);
	List1.print();

	ForwardList1 List2;
	List2.push_back(34);
	List2.push_back(55);
	List2.push_back(89);
	List2.print();

#endif // COUNT_CHECK
#ifdef SIZE_CONSTRUCTOR_CHECK
	ForwardList list = (5);
	for (int i = 0; i < list.get_size(); i++)
	{
		list[i] = rand() % 100;
	}
	for (int i = 0; i < list.get_size(); i++)
	{
		cout << list[i] << tab;

	}
	cout << endl;
#endif //SIZE_CONSTRUCTOR_CHECK

	ForwardList list1;
	list1.push_back(3);
	list1.push_back(5);
	list1.push_back(8);
	list1.push_back(13);
	list1.push_back(21);
	list1.print();

	ForwardList list2;
	list2.push_back(34);
	list2.push_back(55);
	list2.push_back(89);
	list2.print();
	
	cout << delimiter << endl;
	//ForwardList list3 = list1 + list2;
	cout << delimiter << endl;
	Forwardlist list3;
	cout << delimiter << endl;
	list3 = list1 + list2;
	cout << delimiter << endl;
	list3.print();


}