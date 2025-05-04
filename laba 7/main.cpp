#include "List.h"  // Для однозв'язного списку
#include "DoublyLinkedList.h"  // Для двозв'язного списку
#include <iostream>

int main() {
    try {
        // Однозв'язний список
        List singleList;

        singleList.PushBack(10);
        singleList.PushBack(20);
        singleList.PushFront(5);
        singleList.PushBack(30);

        std::cout << "Однозв'язний список після додавання елементів: ";
        singleList.Show();

        std::cout << "Елемент за індексом 1 (однозв'язний): " << singleList[1] << std::endl;

        singleList.Remove(10);
        std::cout << "Список після видалення 10 (однозв'язний): ";
        singleList.Show();

        singleList.PopFront();
        std::cout << "Список після PopFront (однозв'язний): ";
        singleList.Show();

        singleList.PopBack();
        std::cout << "Список після PopBack (однозв'язний): ";
        singleList.Show();

        std::cout << "Чи містить 20 (однозв'язний)? " << (singleList.Find(20) ? "Так" : "Ні") << std::endl;
        std::cout << "Розмір однозв'язного списку: " << singleList.Size() << std::endl;

        std::cout << "\nСпроба доступу за неправильним індексом (однозв'язний):" << std::endl;
        std::cout << singleList[5] << std::endl; // Очікувана помилка

        // Двозв'язний список
        DoublyLinkedList doubleList;

        doubleList.PushBack(100);
        doubleList.PushBack(200);
        doubleList.PushFront(50);
        doubleList.PushBack(300);

        std::cout << "\nДвозв'язний список після додавання елементів: ";
        doubleList.ShowForward();  // Виведення списку вперед

        std::cout << "Елемент за індексом 1 (двозв'язний): " << doubleList[1] << std::endl;

        doubleList.Remove(100);
        std::cout << "Список після видалення 100 (двозв'язний): ";
        doubleList.ShowForward();

        doubleList.PopFront();
        std::cout << "Список після PopFront (двозв'язний): ";
        doubleList.ShowForward();

        doubleList.PopBack();
        std::cout << "Список після PopBack (двозв'язний): ";
        doubleList.ShowForward();

        std::cout << "Чи містить 200 (двозв'язний)? " << (doubleList.Find(200) ? "Так" : "Ні") << std::endl;
        std::cout << "Розмір двозв'язного списку: " << doubleList.Size() << std::endl;

        std::cout << "\nСпроба доступу за неправильним індексом (двозв'язний):" << std::endl;
        std::cout << doubleList[5] << std::endl; // Очікувана помилка

    }
    catch (const std::out_of_range& ex) {
        std::cerr << "Помилка: " << ex.what() << std::endl;  // Обробка винятку для неправильного індексу
    }
    catch (...) {
        std::cerr << "Невідома помилка!" << std::endl;  // Обробка інших помилок
    }

    return 0;
}
