#include <stackl/stackl.hpp>



StackL::StackL(StackL&& src){
  std::swap(head_, src.head_);
}

// Удалить элемент 
void StackL::Pop(){
    if (!IsEmpty()){
        Node* temp = head_;
        head_=head_->next;
        delete temp;
    }
    else{
        throw std::out_of_range("Stack is empty");
    }
}

// Очистить 
void StackL::Clear(){
    while (!IsEmpty()) {
        Pop(); 
    }
}

// Проверка на пустоту 
bool StackL::IsEmpty() const{
    if (head_==nullptr){
        return 1;
    }
    else{
        return 0;
    }
} 

// Добавить элемент
void StackL::Push(const T val){
    head_ = new Node{val, head_};
}


// Получить элемент из начала
StackL::T& StackL::Top(){
    if (IsEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    return head_->val;
}


StackL& StackL::operator=(const StackL& src) {
  if (this != &src) {
    if (src.IsEmpty()) {
      Clear();
    } else {
      Node* p_src = src.head_;
      if (IsEmpty()) {
        head_ = new Node{src.head_->val};
      } else {
        head_->val = src.head_->val;
      }
      Node* p_dst = head_;
      while (p_src->next) {
        if (p_dst->next) {
          p_dst->next->val = p_src->next->val;
        } else {
          p_dst->next = new Node{ p_src->next->val };
        }
        p_src = p_src->next;
        p_dst = p_dst->next;
      }
      if (p_dst->next) {
        Node* tail = p_dst->next;
        p_dst->next = nullptr;
        while (tail) {
          p_dst = tail->next;
          delete tail;
          tail = p_dst;
        }
      }
    }
  }
  return *this;
}

StackL& StackL::operator=(StackL&& src) {
  std::swap(head_, src.head_);
  return *this;
}

StackL::StackL(const StackL& src) {
  if (!src.IsEmpty()) {
    head_ = new Node{src.head_->val};
    Node* p_src = src.head_;
    Node* p_dst = head_;
    while (p_src->next) {
      p_dst->next = new Node{p_src->next->val };
      p_src = p_src->next;
      p_dst = p_dst->next;
    }
  }
}