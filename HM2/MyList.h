#pragma once

#include<iostream>
#include<fstream>
using namespace std;

template <typename MyData> class MyList
{
private:
	class Node
	{
	public:
		MyData data;
		Node* next;
	};
	Node* head;

public:
	MyList()
	{
		head = NULL;
	}

	void Add(MyData data)
	{
		if (head == NULL)
		{
			Node* node = new Node;
			node->data = data;
			node->next = NULL;
			head = node;
		}
		else
		{
			Node* node = new Node;
			node->data = data;
			node->next = NULL;
			Node* end = head;
			while (end->next != NULL)
				end = end->next;
			end->next = node;
		}
	}

	void ShowItems()
	{
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << "\n";
			temp = temp->next;
		}
	}

	void SaveToFile(const char* filename)
	{
		ofstream file(filename);
		if (!file.is_open())
		{
			cout << "Не вдалося відкрити файл для запису!\n";
			return;
		}

		Node* temp = head;
		while (temp != NULL)
		{
			file << temp->data << "\n";
			temp = temp->next;
		}

		file.close();
	}

	void LoadFromFile(const char* filename)
	{
		ifstream file(filename);
		if (!file.is_open())
		{
			cout << "Не вдалося відкрити файл для читання!\n";
			return;
		}

		while (head != NULL)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
		}

		MyData data;
		while (file >> data)
		{
			Add(data);
		}

		file.close();
	}
};
