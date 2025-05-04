#pragma once

#include <memory>
#include <cstddef>
#include <stdexcept>

struct Node {
    int data;
    std::unique_ptr<Node> next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    std::unique_ptr<Node> head;
    Node* tail;
    size_t size;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void PushFront(int value);
    void PushBack(int value);
    void PopFront();
    void PopBack();
    void Remove(int value);
    bool Find(int value) const;
    bool isEmpty() const;
    size_t Size() const;
    void Clear();
    void ShowForward() const;
    void ShowBackward() const;
    int& operator[](size_t index);

    class Iterator {
    private:
        Node* current;
    public:
        Iterator(Node* node) : current(node) {}
        int& operator*() const { return current->data; }
        Iterator& operator++() {
            if (current) current = current->next.get();
            return *this;
        }
        bool operator!=(const Iterator& other) const { return current != other.current; }
    };

    Iterator begin() const { return Iterator(head.get()); }
    Iterator end() const { return Iterator(nullptr); }
};
