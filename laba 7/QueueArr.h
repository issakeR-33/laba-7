
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <memory>
#include <exception>

using namespace std;

template <typename T>
class Queue {
private:
    int front;
    int rear;
    T arr[100];
    int m_size;
public:
    Queue() :front{ 0 }, rear{ -1 }, m_size{ 0 } {};

    void enqueue(T value) {
        if (m_size > 100) {
            isFull();
        }
        else {
            rear++;
            arr[rear] = value;
            m_size++;
        }
    }

    void dequeue() {
        if (m_size <= 0) {
            isEmpty();
        }
        else {
            front++;
            arr[front];
            m_size--;
        }
    }

    bool isEmpty() {
        if (m_size <= 0) throw out_of_range("stack is empty");
        return true;
    }
    void peek() {
        cout << arr[front - 1] << endl;
    }
    bool isFull() {
        if (m_size >= 100) throw out_of_range("stack is full");
        return true;
    }

    friend ostream& operator<<(ostream& os, const Queue<T>& obj) {
        int index = obj.front;
        for (int count = 0; count < obj.m_size; ++count) {
            os << obj.arr[index] << " ";
            index = (index + 1) % 100;
        }
        return os;
    }

};
#endif //QUEUE_H