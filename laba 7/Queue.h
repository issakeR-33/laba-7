#pragma once

#include "List.h"

template <typename T>
class Queue {
private:
    List<T> list;

public:
    Queue() = default;

    // додає  в кінець
    void Enqueue(const T& value) {
        list.PushBack(value);
    }

    // видаляє ( з початку ) 
    void Dequeue() {
        if (IsEmpty()) {
            throw std::out_of_range("Queue is empty");
        }
        list.PopFront();
    }

    // подивитись варік.
    T& Peek() {
        if (IsEmpty()) {
            throw std::out_of_range("Queue is empty");
        }
        return list[0]; // перший елемент — це голова списку
    }

    bool IsEmpty() const {
        return list.isEmpty();
    }

    bool IsFull() const {
        return !IsEmpty(); 
    }

    
    void Show() const {
        list.Show();
    }
};
