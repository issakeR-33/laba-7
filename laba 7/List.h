#pragma once

#include <memory>
#include <stdexcept>
#include <iostream>

template <typename T>
struct Node {
    T data;
    std::unique_ptr<Node<T>> next;

    Node(T val) : data(val), next(nullptr) {}
};

template <typename T>
class List {
private:
    std::unique_ptr<Node<T>> head;
    Node<T>* tail;
    size_t size;

public:
    List() : head(nullptr), tail(nullptr), size(0) {}

    void PushBack(const T& value) {
        std::unique_ptr<Node<T>> newNode = std::make_unique<Node<T>>(value);
        Node<T>* newTail = newNode.get();

        if (!head) {
            head = std::move(newNode);
            tail = newTail;
        } else {
            tail->next = std::move(newNode);
            tail = newTail;
        }
        ++size;
    }

    void PushFront(const T& value) {
        std::unique_ptr<Node<T>> newNode = std::make_unique<Node<T>>(value);
        if (!head) {
            tail = newNode.get();
        }
        newNode->next = std::move(head);
        head = std::move(newNode);
        ++size;
    }

    void PopBack() {
        if (!head) return;

        if (!head->next) {
            head.reset();
            tail = nullptr;
        } else {
            Node<T>* current = head.get();
            while (current->next->next) {
                current = current->next.get();
            }
            current->next.reset();
            tail = current;
        }
        --size;
    }

    void PopFront() {
        if (!head) return;

        head = std::move(head->next);
        if (!head) tail = nullptr;
        --size;
    }

    void Remove(const T& value) {
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

    bool Find(const T& value) const {
        Node<T>* current = head.get();
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

        Node<T>* current = head.get();
        for (size_t i = 0; i < index; ++i) {
            current = current->next.get();
        }
        return current->data;
    }

    void Show() const {
        if (!head) {
            std::cout << "List is empty!" << std::endl;
        } else {
            Node<T>* current = head.get();
            while (current) {
                std::cout << current->data << " ";
                current = current->next.get();
            }
            std::cout << std::endl;
        }
    }
};
