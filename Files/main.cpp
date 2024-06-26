#define _CRT_SECURE_NO_WARNINGS 
#include<iostream> 
#include<fstream>
#include<ctime>

using std::cin;
using std::cout;
using std::endl;

//#define WRITE_TO_FILE
#define READ_FROM_FILE

void main()
{
	setlocale(LC_ALL, "");
#ifdef WRITE_TO_FILE

	std::ofstream fout; // создает поток
	fout.open("File.txt", std::ios_base::app);// открываем поток
	// дописать конец файла
	//fout << "HelloWorld" << endl; // пишем в поток
	
	
	time_t now = time(NULL);
	fout << ctime(&now) << endl;

	fout.close();

	system("start winword File.txt");
#endif
#ifdef READ_FROM_FILE
	std::ifstream fin("File.txt");
	if (fin.is_open())
	{
		const int SIZE = 256;
		char buffer[SIZE]{};

		while (!fin.eof())
		{
			//fin >> buffer;
			fin.getline(buffer, SIZE);
			cout << buffer << endl;
		}
		fin.close();
	}
	else
	{
		std::cerr << "Error: File not found" << endl;
	}
#endif 

}