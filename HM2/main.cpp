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
		cout << "1.Додати нового\n";
		cout << "2.Показати усіх козаків\n";
		cout << "3.Зберегти у файл\n";
		cout << "4.Завантажити із файлу\n";
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
			cout << "---------Ваші козаки і козачки :)----------\n";
			items.ShowItems();
			break;
		}
		case 3:
		{
			items.SaveToFile("people.txt");
			cout << "Збережено у people.txt\n";
			break;
		}
		case 4:
		{
			items.LoadFromFile("people.txt");
			cout << "Завантажено із people.txt\n";
			break;
		}
		}

	} while (action != 0);

	return 0;
}
