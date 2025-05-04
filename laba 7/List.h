#pragma once

#include <memory>      // для std::unique_ptr
#include <cstddef>     // для size_t
#include <stdexcept>   // для std::out_of_range

// Структура вузла (елемент списку)
struct Node {
    int data;
    std::unique_ptr<Node> next;

    Node(int val) : data(val), next(nullptr) {}
};

// Клас однозв'язного списку
class List {
private:
    std::unique_ptr<Node> head;  // Умний вказівник на перший елемент
    Node* tail;                  // Сирий вказівник на останній елемент (для PushBack)
    size_t size;                 // Кількість елементів

public:
    List();
    ~List() = default;

    // Основні операції
    void PushBack(const int& value);
    void PushFront(const int& value);
    void PopBack();
    void PopFront();
    void Remove(const int& value);

    // Допоміжні методи
    bool Find(const int& value) const;
    bool isEmpty() const;
    size_t Size() const;
    void Clear();
    void Show() const;

    // Доступ за індексом
    int& operator[](size_t index);

    // Ітератор для циклів for-each
    class Iterator {
    private:
        Node* current;
    public:
        Iterator(Node* node) : current(node) {}

        int& operator*() const {
            return current->data;
        }

        Iterator& operator++() {
            current = current->next.get();
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
    };

    Iterator begin() const { return Iterator(head.get()); }
    Iterator end() const { return Iterator(nullptr); }
};
