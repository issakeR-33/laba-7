#pragma once

#include "List.h"

template <typename T>
List<T>::List() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
void List<T>::PushBack(const T& value) {
    std::unique_ptr<Node<T>> newNode = std::make_unique<Node<T>>(value);
    Node<T>* newTail = newNode.get();

    if (!head) {
        head = std::move(newNode);
        tail = newTail;
    }
    else {
        tail->next = std::move(newNode);
        tail = newTail;
    }
    ++size;
}

template <typename T>
void List<T>::PushFront(const T& value) {
    std::unique_ptr<Node<T>> newNode = std::make_unique<Node<T>>(value);
    if (!head) {
        tail = newNode.get();
    }
    newNode->next = std::move(head);
    head = std::move(newNode);
    ++size;
}

template <typename T>
void List<T>::PopBack() {
    if (!head) return;

    if (!head->next) {
        head.reset();
        tail = nullptr;
    }
    else {
        Node<T>* current = head.get();
        while (current->next->next) {
            current = current->next.get();
        }
        current->next.reset();
        tail = current;
    }
    --size;
}

template <typename T>
void List<T>::PopFront() {
    if (!head) return;

    head = std::move(head->next);
    if (!head) tail = nullptr;
    --size;
}

template <typename T>
void List<T>::Remove(const T& value) {
    if (!head) return;

    if (head->data == value) {
        PopFront();
        return;
    }

    Node<T>* prev = head.get();
    while (prev->next && prev->next->data != value) {
        prev = prev->next.get();
    }

    if (prev->next) {
        if (prev->next.get() == tail) {
            tail = prev;
        }
        prev->next = std::move(prev->next->next);
        --size;
    }
}

template <typename T>
bool List<T>::Find(const T& value) const {
    Node<T>* current = head.get();
    while (current) {
        if (current->data == value) return true;
        current = current->next.get();
    }
    return false;
}

template <typename T>
bool List<T>::isEmpty() const {
    return size == 0;
}

template <typename T>
size_t List<T>::Size() const {
    return size;
}

template <typename T>
void List<T>::Clear() {
    head.reset();
    tail = nullptr;
    size = 0;
}

template <typename T>
T& List<T>::operator[](size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }

    Node<T>* current = head.get();
    for (size_t i = 0; i < index; ++i) {
        current = current->next.get();
    }
    return current->data;
}

template <typename T>
void List<T>::Show() const {
    if (!head) {
        std::cout << "List is empty!" << std::endl;
    }
    else {
        Node<T>* current = head.get();
        while (current) {
            std::cout << current->data << " ";
            current = current->next.get();
        }
        std::cout << std::endl;
    }
}
