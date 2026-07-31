#pragma once

#include<iostream>
using namespace std;

template <typename T> class Doubly
{
private:
	class Node
	{
	public:
		T data;
		Node* next;
		Node* prev;
	};
	Node* head;
public:
	Doubly()
	{
		head = NULL;
	}

	void Add(T data)
	{
		if (head == NULL)
		{
			Node* myNode = new Node;
			myNode->data = data;
			myNode->prev = myNode->next = NULL;
			head = myNode;
		}
		else
		{
			Node* temp = head;
			while (temp->next != NULL)
				temp = temp->next;
			Node* newNode = new Node();
			newNode->data = data;
			newNode->prev = temp;
			newNode->next = NULL;
			temp->next = newNode;
		}
	}

	void ShowList()
	{
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << "\n";
			temp = temp->next;
		}
	}

	void Remove(T data)
	{
		if (head == NULL)
			return;
		Node* temp = head;

		while (temp != NULL && temp->data != data)
			temp = temp->next;

		if (temp == NULL)
		{
			cout << "--Елемент, який ви хочете видалити ми не знайли--\n";
			return;
		}
		if (temp == head)
		{
			head = head->next;
			if (head != NULL)
				head->prev = NULL;
			delete temp;
			return;
		}
		if (temp->next != NULL)
		{
			temp->next->prev = temp->prev;
		}
		temp->prev->next = temp->next;
		delete temp;
	}

	void Sort()
	{
		if (head == NULL)
			return;

		bool swapped = true;
		while (swapped)
		{
			swapped = false;
			Node* current = head;
			while (current->next != NULL)
			{
				if (current->data > current->next->data)
				{
					T tempData = current->data;
					current->data = current->next->data;
					current->next->data = tempData;
					swapped = true;
				}
				current = current->next;
			}
		}
	}
};
