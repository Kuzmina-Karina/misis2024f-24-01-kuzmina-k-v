#include "queues.hpp"

 // Конструктор
queues::queues(){
    head=nullptr;
    tail=nullptr;
    size_=0;
}

 // Деструктор
queues::~queues(){
    Clear();
}

std::ptrdiff_t queues::Size(){
    return size_;
}

// Удалить элемент из очереди
void queues::Pop(){
    if (!IsEmpty()){
        Node* temp = head;
        head=head->next;
        delete temp;
        if (head==nullptr){
            tail=nullptr;
        }
        size_--;
    }
    else{
        throw std::out_of_range("Queue is empty");
    }
}

// Очистить очередь
void queues::Clear(){
    while (!IsEmpty()) {
        Pop(); 
    }
}

// Проверка, пуста ли очередь
bool queues::IsEmpty() const{
    if (size_== 0){
        return 1;
    }
    else{
        return 0;
    }
} 

// Добавить элемент в очередь
void queues::Push(float val){
    Node* temp = new Node{val, head};
    if(IsEmpty()){
        head=temp;
        tail=temp;
    }
    else{
        tail->next=temp; // хз по моему тут ошибка надо на голову 
        tail=temp;
    }
    size_++;
}


// Получить элемент из начала очереди
float queues::Top() const{
    if (IsEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    return head->data;
}

