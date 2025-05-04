#include "DoublyLinkedList.h"
#include <iostream>

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

DoublyLinkedList::~DoublyLinkedList() {
    Clear();
}

void DoublyLinkedList::PushFront(int value) {
    auto newNode = std::make_unique<Node>(value);
    newNode->next = std::move(head);
    newNode->prev = nullptr;

    if (newNode->next) {
        newNode->next->prev = newNode.get();
    }
    else {
        tail = newNode.get(); // якщо список був порожнім
    }

    head = std::move(newNode);
    ++size;
}

void DoublyLinkedList::PushBack(int value) {
    auto newNode = std::make_unique<Node>(value);
    newNode->next = nullptr;
    newNode->prev = tail;

    if (!head) {
        head = std::move(newNode);
        tail = head.get();
    }
    else {
        tail->next = std::move(newNode);
        tail->next->prev = tail;
        tail = tail->next.get();
    }
    ++size;
}

void DoublyLinkedList::PopFront() {
    if (!head) return;

    head = std::move(head->next);
    if (head) {
        head->prev = nullptr;
    }
    else {
        tail = nullptr;
    }
    --size;
}

void DoublyLinkedList::PopBack() {
    if (!tail) return;

    if (tail->prev) {
        tail = tail->prev;
        tail->next.reset();
    }
    else {
        head.reset();
        tail = nullptr;
    }
    --size;
}

void DoublyLinkedList::Remove(int value) {
    Node* current = head.get();
    while (current) {
        if (current->data == value) {
            if (current == head.get()) {
                PopFront();
                return;
            }
            else if (current == tail) {
                PopBack();
                return;
            }
            else {
                Node* prev = current->prev;
                std::unique_ptr<Node> toRemove = std::move(prev->next);
                prev->next = std::move(toRemove->next);
                if (prev->next) {
                    prev->next->prev = prev;
                }
                --size;
                return;
            }
        }
        current = current->next.get();
    }
}

bool DoublyLinkedList::Find(int value) const {
    Node* current = head.get();
    while (current) {
        if (current->data == value) return true;
        current = current->next.get();
    }
    return false;
}

bool DoublyLinkedList::isEmpty() const {
    return size == 0;
}

size_t DoublyLinkedList::Size() const {
    return size;
}

void DoublyLinkedList::Clear() {
    while (head) {
        head = std::move(head->next);
    }
    tail = nullptr;
    size = 0;
}

void DoublyLinkedList::ShowForward() const {
    Node* current = head.get();
    while (current) {
        std::cout << current->data << " ";
        current = current->next.get();
    }
    std::cout << "\n";
}

void DoublyLinkedList::ShowBackward() const {
    Node* current = tail;
    while (current) {
        std::cout << current->data << " ";
        current = current->prev;
    }
    std::cout << "\n";
}

int& DoublyLinkedList::operator[](size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }

    Node* current = head.get();
    for (size_t i = 0; i < index; ++i) {
        current = current->next.get();
    }

    return current->data;
}
