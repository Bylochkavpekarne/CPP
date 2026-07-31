#pragma once

#include<iostream>
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

	void AddFirst(MyData data)
	{
		Node* node = new Node;
		node->data = data;
		node->next = head;
		head = node;
	}

	void RemoveAt(int index)
	{
		if (head == NULL)
		{
			cout << "Список порожній!\n";
			return;
		}

		if (index == 0)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
			return;
		}

		Node* prev = head;
		for (int i = 0; i < index - 1 && prev->next != NULL; i++)
			prev = prev->next;

		if (prev->next == NULL)
		{
			cout << "Немає елемента з таким індексом!\n";
			return;
		}

		Node* toDelete = prev->next;
		prev->next = toDelete->next;
		delete toDelete;
	}

	void Sort()
	{
		if (head == NULL) return;

		bool swapped = true;
		while (swapped)
		{
			swapped = false;
			Node* current = head;
			while (current->next != NULL)
			{
				if (current->next->data < current->data)
				{
					MyData temp = current->data;
					current->data = current->next->data;
					current->next->data = temp;
					swapped = true;
				}
				current = current->next;
			}
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
};
