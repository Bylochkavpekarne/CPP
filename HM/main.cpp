#include<iostream>
#include<Windows.h>
#include<string>
#include "MyList.h"
#include "People.h"
using namespace std;

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	cout << "------Робота із власними списками------\n";

	MyList<People> items;
	int action = 0;
	do
	{
		cout << "Оберіть операцію:\n";
		cout << "0.Вихід\n";
		cout << "1.Додати нового у кінець\n";
		cout << "2.Додати нового на початок\n";
		cout << "3.Показати усіх козаків\n";
		cout << "4.Видалити за індексом\n";
		cout << "5.Відсортувати\n";
		cout << "->_";
		cin >> action;
		cin.ignore();
		switch (action)
		{
		case 1:
		{
			string name, phone;
			int age;
			cout << "Вкажіть ПІБ: ";
			getline(cin, name);
			cout << "Вкажіть телефон: ";
			getline(cin, phone);
			cout << "Вкажіть вік: ";
			cin >> age;
			items.Add(People(name, phone, age));
			break;
		}
		case 2:
		{
			string name, phone;
			int age;
			cout << "Вкажіть ПІБ: ";
			getline(cin, name);
			cout << "Вкажіть телефон: ";
			getline(cin, phone);
			cout << "Вкажіть вік: ";
			cin >> age;
			items.AddFirst(People(name, phone, age));
			break;
		}
		case 3:
		{
			cout << "---------Ваші козаки і козачки :)----------\n";
			items.ShowItems();
			break;
		}
		case 4:
		{
			int index;
			cout << "Вкажіть індекс елемента для видалення: ";
			cin >> index;
			items.RemoveAt(index);
			break;
		}
		case 5:
		{
			items.Sort();
			cout << "Список відсортовано!\n";
			break;
		}
		}

	} while (action != 0);

	return 0;
}
