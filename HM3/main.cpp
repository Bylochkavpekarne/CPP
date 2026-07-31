#include<iostream>
#include<Windows.h>
#include<string>
#include "MyList.h"
#include "Crypto.h"
using namespace std;

void menu();

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	cout << "------Робота із криптовалютами------\n";

	menu();

	return 0;
}

void menu()
{
	MyList<Crypto> items;
	int action = 0;
	do
	{
		cout << "Оберіть операцію:\n";
		cout << "0.Вихід\n";
		cout << "1.Додати нову валюту\n";
		cout << "2.Показати усі валюти\n";
		cout << "3.Сортувати список\n";
		cout << "4.Записати у файл\n";
		cout << "->_";
		cin >> action;
		cin.ignore();
		switch (action)
		{
		case 1:
		{
			string name, symbol;
			double price;
			cout << "Вкажіть назву: ";
			getline(cin, name);
			cout << "Вкажіть символ: ";
			getline(cin, symbol);
			cout << "Вкажіть ціну: ";
			cin >> price;
			items.Add(Crypto(name, symbol, price));
			break;
		}
		case 2:
		{
			cout << "---------Список криптовалют----------\n";
			items.ShowItems();
			break;
		}
		case 3:
		{
			items.Sort();
			cout << "----Список відсортовано :)-----\n";
			break;
		}
		case 4:
		{
			string fileName;
			cout << "Вкажіть назву файлу: ";
			getline(cin, fileName);
			items.WriteFile(fileName);
			cout << "-----Валюти записано у файл " << fileName << "------\n";
			break;
		}
		}

	} while (action != 0);
}
