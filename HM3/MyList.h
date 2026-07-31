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

	int Size()
	{
		int count = 0;
		Node* temp = head;
		while (temp != NULL)
		{
			count++;
			temp = temp->next;
		}
		return count;
	}

	void Sort()
	{
		int n = this->Size();
		Node* temp = head;
		for (int i = 0; i < n - 1; i++)
		{
			Node* next = temp->next;
			for (int j = i + 1; j < n; j++)
			{
				if (temp->data > next->data)
				{
					MyData tempData = temp->data;
					temp->data = next->data;
					next->data = tempData;
				}
				next = next->next;
			}
			temp = temp->next;
		}
	}

	void WriteFile(string fileName)
	{
		ofstream outFile(fileName);
		Node* temp = head;
		while (temp != NULL)
		{
			outFile << temp->data << "\n";
			temp = temp->next;
		}
	}
};
