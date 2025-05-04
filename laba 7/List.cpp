#include "List.h"

#include <iostream>
using namespace std;

List::List()
	: head(nullptr)
{}

List::~List(){

	Clear();

}
//remove methods
void List::Clear() {
	while (head != nullptr) 
	{
		Node* current = head;
		head = head->next;
		delete current;
	}
}

void List::PopBack()
{
	if (head == nullptr) 
	{
		return;
	}
	else if (head->next == nullptr)// ???? ???? 1 ?????
	{
		delete head;
		head = nullptr;
	}
	else { // 2+ ?????

		Node* previews = head;
		Node* current = head->next;

		while (current->next != nullptr) // ??? ???? ?? ????
		{
			previews = current;
			current = current->next;
		}

		delete current;
		previews->next = nullptr;
	}
}

void List::PopFront() // head ???????? ?? ????? ? ?? ?? ?????????? 
{
	if (head == nullptr)
	{
		return;
	}
	else if (head->next == nullptr)
	{
		delete head;
		head = nullptr;
	}
	else 
	{
		Node* newHead = head->next;
		delete head;
		head = newHead;
	}
}

void List::PushBack(const int& value) {
	if (head == nullptr)
	{
		head = new Node{ value, nullptr };  //???????? ???????????
	}

	else
	{
		Node* current = head;

		while (current->next != nullptr)
		{
			current = current->next;
		}

		current->next = new Node{ value , nullptr };
	}
}

void List::PushFront(const int& value) {
	if (head == nullptr)
	{
		head = new Node{ value, nullptr };
	}
	else 
	{
		Node* newNode = new Node{ value, head }; // ??? ????? ???????? ???? ???? ?????? head 
		head = newNode;
	}
}

void List::Remove(const int& value) 
{
	Node* previous = nullptr;
	Node* current = head;

	while(current != nullptr)
	{
		if (current->data == value) 
		{
			if (previous == nullptr) // ????????? ?? ?? ?? ??????
			{
				head = head->next; // ??? ???? nullprt ???? ? ?????? ???? 1 ????? 
			}
			else
			{
				previous->next = current->next; // ??????????? ????? ( ????? ???? ?? ?? ????????) 
			}
			delete current;
			return;
		}   

		previous = current; // ???????? 2 ?????
		current = current->next; // ???????? 3 ?????
	}
}

bool List::Find(const int& value) const {
	if (head == nullptr)
	{
		return false;
	}

	Node* current = head;
	while (current != nullptr) {
		if (current->data == value) {
			return true;
		}
		current = current->next;
	}

	return false;
}

bool List::isEmpty() const {
	return head == nullptr;
}

size_t List::Size() const 
{
	size_t size = 0;

	Node* current = head;
	while (current != nullptr) 
	{
		size++;
		current = current->next;
	}

	return size;
}


int& List::operator [] (size_t index) 
{
	if (index >= Size()) 
	{
		throw out_of_range("Incorrect  index ");
	}
}


void List::Show()const {
	if (head == nullptr) {
		cout << "empty list!";
	}
	else {
		Node* current = head;
		
		while (current != nullptr) {
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}
}