#include<iostream>
#include<Windows.h>
#include "Doubly.h"
using namespace std;

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);
	cout << "--Двохзв'язні списки--\n";

	Doubly<int> myList;
	myList.Add(12);
	myList.Add(18);
	myList.Add(9);
	myList.Add(13);
	cout << "-----Набір елементів у списку------\n";
	myList.ShowList();

	cout << "------Відсортований список-----\n";
	myList.Sort();
	myList.ShowList();

	cout << "------Видалення в кінці списку-----\n";
	myList.Remove(13);
	myList.ShowList();

	return 0;
}
