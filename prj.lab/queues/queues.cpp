#include "queuea.hpp"

/*

    queues();  // Конструктор
    ~queues(); // Деструктор

    void Push(float value); // Добавить элемент в очередь
    void Pop(); // Удалить элемент из очереди
    float Top() const; // Получить элемент из начала очереди
    bool IsEmpty() const; // Проверка, пуста ли очередь
    std::ptrdiff_t Size() const; // Получить размер очереди
    void Clear(); // Очистить очередь

*/

 // Конструктор
queues::queues(){
    head=nullptr;
    tail=nullptr;
    size=0;
}

 // Деструктор
queues::~queues(){
    Clear();
}


// Проверка, пуста ли очередь
bool IsEmpty(){
    return queues::Size() == 0;
} 



// Добавить элемент в очередь
void queues::Push(float val){
    Node* newNode = new Node(val);
    if(IsEmpty()){
        head=newNode;
        tail=newNode;
    }
    else{
        tail->next=newNode;
        tail=newNode;
    }
}















