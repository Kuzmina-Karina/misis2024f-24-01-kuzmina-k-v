#include <arrayt/arrayt.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("[arrayt] - ctor") {
  CHECK(ArrayT<double>().Size() == 0);
}

/*
#include <arrayt/arrayt.hpp>
#include <iostream>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
int main(){
    int n;
    std::cin >> n;
    ArrayT<int> a(n);
    for(ptrdiff_t i=0; i<a.Size(); i++){
        a[i] = double(i);
    }
    for (int i=0; i<a.Size(); i++){
        std::cout << a[i] << " ";
    }


    ptrdiff_t v;
    std::cin >> v;
    double g=4;
    a.Insert(v, g);
    for (int i=0; i<a.Size(); i++){
        std::cout << a[i] << " ";
    }


    int m;
    std::cin >> m;
    a.Resize(m);
        for (int i=0; i<a.Size(); i++){
        std::cout << a[i] << " ";
    }


    a.Remove(v);
    for (int i=0; i<a.Size(); i++){
        std::cout << a[i] << " ";
    }
}
*/
