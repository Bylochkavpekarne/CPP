#include "iostream"
#include "Windows.h"

int main()
{
	using namespace std;
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	cout << "----- Робота з операторами If Else -----\n" ;
	// Оголошуємо змінну
	int a, b; // Оголосили дві змінні a та b типу int
	cout << "Введіть а = "; // cout вводить
	cin >> a; // cin виводить 
	cout << "Введіть b = ";
	cin >> b;
	cout << "a = " << a << "\t" << "b = " << b << endl;
	char ch; // Операцыя яку ми хочемо виконати +, -, *, /
	cout << "Вкажіть операцію яку хочете виконати (+, -, *, /): ";
	cin >> ch;
	//cout << "ch = " << ch << endl;
	int result=0; // Результат операції
	if (ch == '+')
		result = a + b;
	else if (ch == '-')
		result = a - b;
	else if (ch == '*')
		result = a * b;
	else if (ch == '/')
	{
		if (a == 0)
			cout << "Помилка! Ділення на нуль неможливе!" << endl;
		else result = a * b;

	}
	else if (ch == '*')
		result = a * b;
	else
		cout << "Помилка! Невідома операція!\n" << endl;

	cout << "Результат операції: " << result << endl;

	return 0;
}