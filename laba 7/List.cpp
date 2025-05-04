#include "List.h"
#include <iostream>

List::List() : head(nullptr), tail(nullptr), size(0) {}

// Додає елемент в кінець списку
void List::PushBack(const int& value) {
    std::unique_ptr<Node> newNode = std::make_unique<Node>(value);
    Node* newTail = newNode.get();

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

// Додає елемент на початок списку
void List::PushFront(const int& value) {
    std::unique_ptr<Node> newNode = std::make_unique<Node>(value);
    if (!head) {
        tail = newNode.get();
    }
    newNode->next = std::move(head);
    head = std::move(newNode);
    ++size;
}

// Видаляє останній елемент
void List::PopBack() {
    if (!head) return;

    if (!head->next) {
        head.reset();
        tail = nullptr;
    }
    else {
        Node* current = head.get();
        while (current->next->next) {
            current = current->next.get();
        }
        current->next.reset();
        tail = current;
    }
    --size;
}

// Видаляє перший елемент
void List::PopFront() {
    if (!head) return;

    head = std::move(head->next);
    if (!head) tail = nullptr;
    --size;
}

// Видаляє перший елемент з вказаним значенням
void List::Remove(const int& value) {
    if (!head) return;

    if (head->data == value) {
        PopFront();
        return;
    }

    Node* prev = head.get();
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

// Повертає true, якщо значення знайдено
bool List::Find(const int& value) const {
    Node* current = head.get();
    while (current) {
        if (current->data == value) return true;
        current = current->next.get();
    }
    return false;
}

// Повертає true, якщо список порожній
bool List::isEmpty() const {
    return size == 0;
}

// Повертає кількість елементів
size_t List::Size() const {
    return size;
}

// Очищує весь список
void List::Clear() {
    head.reset();
    tail = nullptr;
    size = 0;
}

// Доступ до елемента за індексом (з перевіркою)
int& List::operator[](size_t index) {
    if (index >= size) {
        throw std::out_of_range("Індекс виходить за межі списку");
    }

    Node* current = head.get();
    for (size_t i = 0; i < index; ++i) {
        current = current->next.get();
    }
    return current->data;
}

// Вивід усіх елементів у консоль
void List::Show() const {
    if (!head) {
        std::cout << "Список порожній!" << std::endl;
    }
    else {
        Node* current = head.get();
        while (current) {
            std::cout << current->data << " ";
            current = current->next.get();
        }
        std::cout << std::endl;
    }
}
