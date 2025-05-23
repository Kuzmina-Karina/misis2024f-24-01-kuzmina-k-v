#include <rational/rational.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>


TEST_CASE("[rational] - Rational ctor") {
    CHECK((Rational() == Rational(0, 1)));
    CHECK((Rational(3) == Rational(3, 1)));
    CHECK((Rational(-3) == Rational(-3, 1)));
    CHECK((Rational(10, 6) == Rational(5, 3)));
    CHECK((Rational(-10, 6) == Rational(-5, 3)));
    CHECK((Rational(10, -6) == Rational(-5, 3)));
    CHECK((Rational(-10, -6) == Rational(5, 3)));
    CHECK((Rational(-10, 6) == Rational(10, -6)));
    CHECK((Rational(7, 3) + Rational(9, 5) == Rational(62, 15)));
    CHECK((Rational(7, 3) + Rational(9, 5) == Rational(124, 30)));
    CHECK((Rational(7, 3) + Rational(9, 5) == Rational(-62, -15)));
    CHECK((Rational(7, 3) - Rational(9, 5) == Rational(8, 15)));
    CHECK((Rational(7, 3) - Rational(9, 5) == Rational(16, 30)));
    CHECK((Rational(7, 3) - Rational(9, 5) == Rational(-16, -30)));
    CHECK((Rational(7, 3) * Rational(9, 5) == Rational(21, 5)));
    CHECK((Rational(7, 3) * Rational(9, 5) == Rational(42, 10)));
    CHECK((Rational(7, 3) * Rational(9, 5) == Rational(-21, -5)));
    CHECK((Rational(7, 3) / Rational(9, 5) == Rational(35, 27)));
    CHECK((Rational(7, 3) / Rational(9, 5) == Rational(-35, -27)));
    CHECK((Rational(7, 1) == int(7)));
    CHECK((Rational(14, 2) == int(7)));
    CHECK((Rational(7, 3) + int(9) == Rational(34, 3)));
    CHECK((Rational(7, 3) + int(9) == Rational(-68, -6)));
    CHECK((Rational(17, 3) - int(3) == Rational(8, 3)));
    CHECK((Rational(17, 3) - int(3) == Rational(-16, -6)));
    CHECK((Rational(17, 3) - int(3) == Rational(16, 6)));
    CHECK((Rational(17, 3) * int(3) == Rational(17, 1)));
    CHECK((Rational(17, 3) * int(3) == Rational(34, 2)));
    CHECK((Rational(17, 3) * int(3) == Rational(-17, -1)));
    CHECK((Rational(17, 3) / int(3) == Rational(17, 9)));
    CHECK((Rational(17, 3) / int(3) == Rational(-17, -9)));
    CHECK((Rational(17, 3) / int(3) == Rational(34, 18)));
    CHECK((Rational(7, 3) + int(9) == Rational(34, 3)));
    CHECK((Rational(7, 3) + int(9) == Rational(-68, -6)));
    CHECK((int(9) + Rational(7, 3) == Rational(34, 3)));
    CHECK((int(9) + Rational(7, 3) == Rational(-68, -6)));
    CHECK((int(3) - Rational(17, 3) == Rational(-8, 3)));
    CHECK((int(3) - Rational(17, 3) == Rational(-16, 6)));
    CHECK((int(3) * Rational(17, 3) == Rational(17, 1)));
    CHECK((int(3) * Rational(17, 3) == Rational(34, 2)));
    CHECK((int(3) * Rational(17, 3) == Rational(-17, -1)));
    CHECK((int(3) / Rational(17, 3) == Rational(9, 17)));
    CHECK((int(3) / Rational(17, 3) == Rational(-9, -17)));
    CHECK((int(3) / Rational(17, 3) == Rational(18, 34)));
    CHECK((int(3) + Rational(17, 3) == Rational(26, 3)));
    CHECK((int(3) + Rational(17, 3) == Rational(-52, -6)));
    CHECK((Rational(17, 3) < Rational(34, 18) == false));
    CHECK((Rational(5, 3) == Rational(34, 18) == false));
    CHECK((Rational(-10, 6) <= Rational(34, 18) == true));
    CHECK((Rational(7, 3) >= Rational(9, 18) == true));
    CHECK((Rational(7, 3) == Rational(14, 6) == true));
    CHECK((Rational(7, 3) != Rational(9, 18) == true));
    CHECK((Rational(17, 3) > Rational(34, 18) == true));
    CHECK((Rational(5, 3) < Rational(34, 18) == true));
    CHECK((Rational(-10, 6) > Rational(34, 18) == false));
    CHECK((Rational(7, 3) > Rational(9, 18) == true));
    Rational x(1, 1);
    x -= Rational(17, 3);
    CHECK(x == Rational(-14, 3));
    CHECK(x == (-(-x)));
    
    Rational a(17, 3);
    Rational b;
    SUBCASE("adding int value") {
        std::cout << a;
        a += 1;
        std::cout << a;
        CHECK(a == Rational(20, 3));
    }

    SUBCASE("deduction int value") {
        a -= 2;
        CHECK(a == Rational(11, 3));
    }

    SUBCASE("multiplying by int value") {
        a *= 0;
        CHECK(a == Rational(0, 3));
    }
}



 