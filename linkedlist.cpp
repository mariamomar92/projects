#include "linkedlist.h"
#include "linkedlist.h"
#include"node.h"
#include<iostream>
#include<assert.h>
using namespace std;

linkedlist::linkedlist() {
	size = 0;
	head = tail = NULL;
}

void linkedlist::append(properties val)
{
	node* temp = new node(val);
	if (head == NULL) {
		head = tail = temp;
	}
	else {
		tail->next = temp;
		tail = tail->next;
	}
	size++;
}

void linkedlist::display()
{
	node* temp = head;
	while (temp != NULL) {
		cout << temp->data;
		cout << endl;
		temp = temp->next;

	}
}

properties linkedlist::AT(int index)
{
	node* current = head;
	int count = 0;
	while (current != NULL) {
		if (count == index)
			return (current->data);
		count++;
		current = current->next;
	}

	assert(0);
}

void linkedlist::InsertAt(properties val, int pos)
{
	assert(pos >= 0 && pos < size);
	node* tmp = head;
	node* newNode = new node(val);
	if (pos == 0)
	{
		newNode->next = head;
		head = newNode;
	}
	else
	{
		for (int i = 0; i < pos - 1; i++)
			tmp = tmp->next;

		newNode->next = tmp->next;
		tmp->next = newNode;
	}
	size++;
}

void linkedlist::DeleteAt(int pos)
{
	assert(pos >= 0 && pos < size);
	node* tmp = head;
	if (pos == 0)
	{
		head = head->next;
		delete tmp;
	}
	else
	{
		for (int i = 0; i < pos - 1; i++)
			tmp = tmp->next;
		node* del = tmp->next;
		tmp->next = del->next;
		delete del;
		if (pos == size - 1)
			tail = tmp;
	}
	size--;
}