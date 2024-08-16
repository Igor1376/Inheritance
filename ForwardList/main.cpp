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

class Iterator
{
	Element* Temp;
piblic:
	Iterator(Element* Temp) : Temp(Temp)
	{
		cout << "IConstructor:\t" << this << endl;

	}
	~Iterator()
	{
		cout << "IDestructor:\t" << this << endl;
	}
	Iterator& operator++()
	{
		Iterator old = *this;
		Temp = Temp->pNext;
		return old;
	}
	bool operator == (const Iterator& other)const
	{
		return this->Temp == other.Temp;
	}
	bool operator != (const Iterator& other)const
	{
		return this->Temp != other.Temp;
	}
	int operator*()const
	{
		return Temp->Data;
	}
	int& operator*()
	{
		return Temp->Data;
	}
	


};

class ForwardList
{
	ELement* Head;
	int size;
public:
	Iterator begin()
	{
		return Head;
	}
	Iterator end()
	{
		return nullptr;
	}

	

	int get_size()const
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
	ForwardList(initializer_list<int> il) :ForwardList()
	{
		for (int it = il.begin(); it != il.end(); i++)
		{
			push_back(*it);
		}
	}
	~ForwardList()
	{
		while (Head)pop_front();
		cout << "LDestructor:\t" << this << endl;
	}
	void push_front(int Dats)
	{
		Head = new Element(Data);
		size++;
	}
	void push_back(int data)
	{
		if (Head == nullptr)return push_front(Data);
		//Element* New = new Element(Data);
		Element* Temp = Head;
		while (Temp)Temp = Temp->pNext;
		
		Temp->pNext = New Element(Data);
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
		//Element* New = new Element(Data);
		Element* Temp = Head;
		For(int i = 0; i < Index; i++)
			if (Temp->pNext == nullptr)break;
				Temp = Temp->pNext;
		//New->pNext = Temp->pNext;
		//Temp->pNext = New;
				New ->pNext = new Element(Data, Temp->pNext)
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
		//Element* Temp = Head;
		//While(Temp)
			
		//{
		//	cout << Temp << tab << Temp->Data << Temp->pNext << endl;
		//	Temp = Temp->pNext;
		//}
		for (Element* Temp = Head; Temp; Temp=Temp->pNext) 
			cout << Temp << tab << Temp->Data << Temp->pNext << endl;
		cout << "Количество элементов списка: " << size << endl;
		cout << "Общее количество элементов списка: " << Element::count << endl;
	}
};
//#define BASE_CHECK
//#define COUNT_CHECK
//#define SIZE_CONSTRUCTOR_CHECK
//#define OPERATOR_PLUS_CHECK
//#define INITIALIZER_LIST_CONSTRUCTOR
//#define RANGE_BASED_FOR_ARRAY

ForwardList operator+(const ForwardList& left, const ForrwardList& right)
{
	ForwardList buffer;
	for (int i = 0; i < left.get_size(); i++)buffer.push_back(left[i]);
	for (int i = 0; i < right.get_size(); i++)buffer.push_back(right[i]);
	return buffer;
}
void Print(int arr[])
{
	for (int i = 0; i < sizeof (arr) / sizeof(arr[0]); i++)
	{
		cout << arr[i] << tab;

	}
	cout << endl;
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
#ifdef OPERATOR_PLUS_CHECK
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
#endif // OPERATOR_PLUS_CHECK
#ifdef INITIALIZER_LIST_CONSTRUCTOR



	ForwardList = { 3, 5, 8, 13, 21 }
	List.print();
#endif // INITIALIZER_LIST_CONSTRUCTOR

#ifdef RANGE_BASED_FOR_ARRAY
	int arr[] = { 3, 5, 8 , 13, 21 };
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
	for (int i : arr)
	{
		cout << i << tab;
	}
	cout << endl;
	Print(arr);
#endif RANGE_BASED_FOR_ARRAY
	ForwardList list = { 3, 5, 8, 13, 21 };
	list.print();
	for (int i : list)
	{
		cout << i << tab;

	}
	cout << endl;
	for (Iterator it = list.begin(); it != list.end()); i++)
	{
		cout* it << tab;
	}
	cout << endl;
}