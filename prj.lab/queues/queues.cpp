#include "queues.hpp"

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


/*

// Конструктор очереди
Queue::Queue() : head_(nullptr), tail_(nullptr), size_(0) {}

// Деструктор очереди
Queue::~Queue() {
    Clear(); // Освобождаем память при уничтожении
}

// Добавить элемент в очередь
void Queue::Enqueue(float value) {
    Node* newNode = new Node(value); // Создаём новый узел
    if (IsEmpty()) {
        head_ = tail_ = newNode; // Если очередь пустая, новый узел - это и голова, и хвост
    } else {
        tail_->next = newNode; // Добавляем новый узел в конец очереди
        tail_ = newNode; // Обновляем хвост
    }
    ++size_; // Увеличиваем размер очереди
}

// Удалить элемент из очереди
void Queue::Dequeue() {
    if (IsEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    Node* temp = head_; // Сохраняем указатель на голову
    head_ = head_->next; // Перемещаем указатель головы на следующий элемент
    delete temp; // Освобождаем память
    if (head_ == nullptr) { // Если очередь теперь пустая
        tail_ = nullptr; // Обновляем указатель хвоста
    }
    --size_; // Уменьшаем размер очереди
}

// Получить элемент из начала очереди
float Queue::Front() const {
    if (IsEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    return head_->data; // Возвращаем данные из головы
}

// Проверка, пуста ли очередь
bool Queue::IsEmpty() const {
    return size_ == 0; // Проверяем, равен ли размер 0
}

// Получить размер очереди
std::size_t Queue::Size() const {
    return size_; // Возвращаем размер
}

// Очистить очередь
void Queue::Clear() {
    while (!IsEmpty()) {
        Dequeue(); // Удаляем элементы один за другим
    }
}
*/













