#pragma once

#include <memory>
#include <stdexcept>
#include <iostream>

template <typename T>
struct Node2 {
    T data;
    std::unique_ptr<Node2<T>> next;
    Node2<T>* prev;

    Node2(T val) : data(val), next(nullptr), prev(nullptr) {}
};

template <typename T>
class DoublyLinkedList {
private:
    std::unique_ptr<Node2<T>> head;
    Node2<T>* tail;
    size_t size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void PushBack(const T& value) {
        std::unique_ptr<Node2<T>> newNode = std::make_unique<Node2<T>>(value);
        Node2<T>* newTail = newNode.get();

        if (!head) {
            head = std::move(newNode);
            tail = newTail;
        }
        else {
            tail->next = std::move(newNode);
            tail->next->prev = tail;
            tail = tail->next.get();
        }
        ++size;
    }

    void PushFront(const T& value) {
        std::unique_ptr<Node2<T>> newNode = std::make_unique<Node2<T>>(value);
        if (!head) {
            tail = newNode.get();
        }
        else {
            newNode->next = std::move(head);
            head->prev = newNode.get();
        }
        head = std::move(newNode);
        ++size;
    }

    void PopBack() {
        if (!head) return;

        if (!head->next) {
            head.reset();
            tail = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next.reset();
        }
        --size;
    }

    void PopFront() {
        if (!head) return;

        head = std::move(head->next);
        if (head) head->prev = nullptr;
        if (!head) tail = nullptr;
        --size;
    }

    void Remove(const T& value) {
        if (!head) return;

        if (head->data == value) {
            PopFront();
            return;
        }

        Node2<T>* current = head.get();
        while (current) {
            if (current->data == value) {
                if (current->next) {
                    current->next->prev = current->prev;
                }
                if (current->prev) {
                    current->prev->next = std::move(current->next);
                }
                --size;
                return;
            }
            current = current->next.get();
        }
    }

    bool Find(const T& value) const {
        Node2<T>* current = head.get();
        while (current) {
            if (current->data == value) return true;
            current = current->next.get();
        }
        return false;
    }

    bool isEmpty() const {
        return size == 0;
    }

    size_t Size() const {
        return size;
    }

    void Clear() {
        head.reset();
        tail = nullptr;
        size = 0;
    }

    T& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }

        Node2<T>* current = head.get();
        for (size_t i = 0; i < index; ++i) {
            current = current->next.get();
        }
        return current->data;
    }

    void Show() const {
        if (!head) {
            std::cout << "List is empty!" << std::endl;
        }
        else {
            Node2<T>* current = head.get();
            while (current) {
                std::cout << current->data << " ";
                current = current->next.get();
            }
            std::cout << std::endl;
        }
    }
};
