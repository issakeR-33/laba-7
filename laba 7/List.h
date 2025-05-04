#pragma once

class List {
private:
	struct Node
	{
		int data;
		Node* next;
	};

	Node* head;

public:
	List();

	~List();

	//remove methods
	void Clear();
	void PopBack();
	void PopFront();
	void Remove(const int& value);

	
	bool Find(const int& value) const;
	bool isEmpty() const;
	size_t Size() const;

	//push methods 
	void PushBack(const int& value);
	void PushFront(const int& value);


	int& operator [] (size_t index);


	void Show() const;

};