#include <arrayt/arrayt.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("Testing own library of template array") {
	ArrayT<int> a(5);
	CHECK(a[0] == 0);
	CHECK(a[4] == 0);
	for (std::ptrdiff_t i = 0; i < a.Size(); i++) {
		a[i] = double(i);
	}
	CHECK(a[1] == 1);
	REQUIRE(a.Size() == 5);
	CHECK_THROWS(a.Resize(-1));
	SUBCASE("Resize") {
		CHECK(a.Size() == 5);
		a.Resize(3);
		CHECK_THROWS(a[4]);
		CHECK(a.Size() == 3);
		a.Resize(8);
		CHECK(a[7] == 0);
		CHECK_THROWS(a[9]);
	}
	SUBCASE("Remove") {
		for (std::ptrdiff_t i = 0; i < a.Size(); i++)
		{
			a[i] = i;
		}
		a.Remove(0);
		CHECK(a[0] == 1);
		a.Remove(3);
		CHECK(a[2] == 3);
	}
	SUBCASE("Insert") {
		a.Insert(1, 11);
		CHECK(a[1] == 11);
		CHECK(a.Size() == 6);
		CHECK(a[2] == 1);
		CHECK(a[5] == 4);
		CHECK(a.Size() == 6);
		a.Insert(0, 12);
		CHECK(a[0] == 12);
		CHECK(a.Size() == 7);
	}
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
