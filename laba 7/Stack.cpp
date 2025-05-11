#pragma once

#include <memory>
#include <stdexcept>
#include <iostream>
#include "List.h"  // Підключаємо List, який ти надав

template <typename T>
class Stack {
private:
    List<T> list;  // Використовуємо вже реалізований List як основу для стека

public:
    // Додавання елемента на верх стека (Push)
    void Push(const T& value) {
        list.PushFront(value);  // Додаємо елемент на початок списку (верх стека)
    }

    // Видалення елемента з верхівки стека (Pop)
    void Pop() {
        if (IsEmpty()) {
            throw std::out_of_range("Stack is empty");
        }
        list.PopFront();  // Видаляємо верхній елемент зі списку
    }

    // Погляд на верхній елемент без його видалення (Peek)
    T& Peek() {
        if (IsEmpty()) {
            throw std::out_of_range("Stack is empty");
        }
        return list[0];  // Доступ до першого елемента списку
    }

    // Перевірка, чи порожній стек
    bool IsEmpty() const {
        return list.isEmpty();
    }

    

    // Виведення елементів стека
    void Show() const {
        list.Show();  // Використовуємо метод Show з List
    }
};
