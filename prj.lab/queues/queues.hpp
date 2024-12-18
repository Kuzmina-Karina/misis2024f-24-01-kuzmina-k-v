#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <sstream>
#include <iostream> 
#include <cstddef>


class queues{
public:
    queues();  // Конструктор
    ~queues(); // Деструктор

    void Push(float val); // Добавить элемент в очередь
    void Pop(); // Удалить элемент из очереди
    float Top() const; // Получить элемент из начала очереди
    bool IsEmpty() const; // Проверка, пуста ли очередь
    std::ptrdiff_t Size(); // Получить размер очереди
    void Clear(); // Очистить очередь

private:
    struct Node{
        float data; //элемент
        Node* next; //указатель на следующий элемент 
    };
    Node* head; //голова очереди
    Node* tail; //хвост очереди
    std::ptrdiff_t size_; //размер очереди
};

#endif

