#include "List.h"
#include <iostream>

int main() {
    try {
        List list;

        list.PushBack(10);
        list.PushBack(20);
        list.PushFront(5);
        list.PushBack(30);

        std::cout << "Список після додавання елементів: ";
        list.Show();

        std::cout << "Елемент за індексом 1: " << list[1] << std::endl;

        list.Remove(10);
        std::cout << "Список після видалення 10: ";
        list.Show();

        list.PopFront();
        std::cout << "Список після PopFront: ";
        list.Show();

        list.PopBack();
        std::cout << "Список після PopBack: ";
        list.Show();

        std::cout << "Чи містить 20? " << (list.Find(20) ? "Так" : "Ні") << std::endl;
        std::cout << "Розмір списку: " << list.Size() << std::endl;

        std::cout << "\nСпроба доступу за неправильним індексом:" << std::endl;
        std::cout << list[5] << std::endl; // Очікувана помилка

    }
    catch (const std::out_of_range& ex) {
        std::cerr << "Помилка: " << ex.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Невідома помилка!" << std::endl;
    }

    return 0;
}
