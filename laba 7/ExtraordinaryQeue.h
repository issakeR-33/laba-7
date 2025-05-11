#pragma once

#include "List.h"  // Підключаємо твій однозв'язний список

template <typename T>
class OutputQueue {
private:
    List<T> list;  // внутрішній список

public:
    OutputQueue() = default;

    // Вставка в початок
    void EnqueueFront(const T& value) {
        list.PushFront(value);
    }

    // Вставка в кінець
    void EnqueueBack(const T& value) {
        list.PushBack(value);
    }

    // Видалення тільки з початку
    void Dequeue() {
        if (IsEmpty()) {
            throw std::out_of_range("Queue is empty");
        }
        list.PopFront();
    }

    // Перегляд елементу з початку
    T& Peek() {
        if (IsEmpty()) {
            throw std::out_of_range("Queue is empty");
        }
        return list[0];
    }

    bool IsEmpty() const {
        return list.isEmpty();
    }

    bool IsFull() const {
        return false;  // нема фіксованого розміру, бо список динамічний
    }

    void Show() const {
        list.Show();
    }
};
