#pragma once

#include<iostream>
#include<fstream>
using namespace std;

class Crypto
{
private:
	string name;
	string symbol;
	double price;

public:
	Crypto()
	{
		this->name = "Не вказано";
		this->symbol = "---";
		this->price = 0.0;
	}
	Crypto(const char* name, const char* symbol, double price)
	{
		this->name = name;
		this->symbol = symbol;
		this->price = price;
	}
	Crypto(const string name, const string symbol, double price)
	{
		this->name = name;
		this->symbol = symbol;
		this->price = price;
	}

	friend ostream& operator<<(ostream& os, const Crypto& crypto)
	{
		os << crypto.name << "\t" << crypto.symbol << "\t"
			<< crypto.price;
		return os;
	}

	friend ofstream& operator<<(ofstream& os, const Crypto& crypto)
	{
		os << crypto.name << "\n" << crypto.symbol << "\n"
			<< crypto.price;
		return os;
	}

	bool operator>(const Crypto& crypto)
	{
		if (this->price > crypto.price)
			return true;
		return false;
	}
};
