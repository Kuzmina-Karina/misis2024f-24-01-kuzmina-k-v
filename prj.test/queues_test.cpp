#include <iostream>
#include <queues/queues.hpp>
int main(){
    queues q;
    for (int i=0; i<6; i++){
        float n;
        std::cin >> n;
        q.Push(n);
    }
    std::cout << std::endl<<q.Size();
    q.Clear();
    q.Push(444);
    std::cout << std::endl<<q.Top();
    std::cout << std::endl<<q.Size();
    int ss=q.Size();
    std::cout << std::endl;
    for (int i=0; i<ss; i++){
        std::cout << q.Top() <<" ";
        q.Pop();
    }
    

}