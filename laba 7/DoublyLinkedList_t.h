#ifndef DOUBLY_LINKED_LIST_TPP
#define DOUBLY_LINKED_LIST_TPP

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    Clear();
}

template<typename T>
void DoublyLinkedList<T>::PushFront(const T& value) {
    auto newNode = make_unique<Node2<T>>(value);
    newNode->next = move(head);
    newNode->prev = nullptr;

    if (newNode->next) {
        newNode->next->prev = newNode.get();
    }
    else {
        tail = newNode.get();
    }

    head = move(newNode);
    ++size;
}

template<typename T>
void DoublyLinkedList<T>::PushBack(const T& value) {
    auto newNode = make_unique<Node2<T>>(value);
    newNode->next = nullptr;
    newNode->prev = tail;

    if (!head) {
        head = move(newNode);
        tail = head.get();
    }
    else {
        tail->next = move(newNode);
        tail->next->prev = tail;
        tail = tail->next.get();
    }
    ++size;
}

template<typename T>
void DoublyLinkedList<T>::PopFront() {
    if (!head) return;

    head = move(head->next);
    if (head) {
        head->prev = nullptr;
    }
    else {
        tail = nullptr;
    }
    --size;
}

template<typename T>
void DoublyLinkedList<T>::PopBack() {
    if (!tail) return;

    if (tail->prev) {
        tail = tail->prev;
        tail->next.reset();
    }
    else {
        head.reset();
        tail = nullptr;
    }
    --size;
}

template<typename T>
void DoublyLinkedList<T>::Remove(const T& value) {
    Node2<T>* current = head.get();
    while (current) {
        if (current->data == value) {
            if (current == head.get()) {
                PopFront();
                return;
            }
            else if (current == tail) {
                PopBack();
                return;
            }
            else {
                Node2<T>* prev = current->prev;
                unique_ptr<Node2<T>> toRemove = move(prev->next);
                prev->next = move(toRemove->next);
                if (prev->next) {
                    prev->next->prev = prev;
                }
                --size;
                return;
            }
        }
        current = current->next.get();
    }
}

template<typename T>
bool DoublyLinkedList<T>::Find(const T& value) const {
    Node2<T>* current = head.get();
    while (current) {
        if (current->data == value) return true;
        current = current->next.get();
    }
    return false;
}

template<typename T>
bool DoublyLinkedList<T>::isEmpty() const {
    return size == 0;
}

template<typename T>
size_t DoublyLinkedList<T>::Size() const {
    return size;
}

template<typename T>
void DoublyLinkedList<T>::Clear() {
    while (head) {
        head = move(head->next);
    }
    tail = nullptr;
    size = 0;
}

template<typename T>
void DoublyLinkedList<T>::ShowForward() const {
    Node2<T>* current = head.get();
    while (current) {
        cout << current->data << " ";
        current = current->next.get();
    }
    cout << "\n";
}

template<typename T>
void DoublyLinkedList<T>::ShowBackward() const {
    Node2<T>* current = tail;
    while (current) {
        cout << current->data << " ";
        current = current->prev;
    }
    cout << "\n";
}

template<typename T>
T& DoublyLinkedList<T>::operator[](size_t index) {
    if (index >= size) {
        throw out_of_range("Index out of range");
    }

    Node2<T>* current = head.get();
    for (size_t i = 0; i < index; ++i) {
        current = current->next.get();
    }

    return current->data;
}

#endif // DOUBLY_LINKED_LIST_TPP
