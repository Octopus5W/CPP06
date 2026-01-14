#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base * generate(void) {
    int r = time(NULL) % 3;
    if (r == 0)
        return new A();
    else if (r == 1)
        return new B();
    else
        return new C();
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A => Success" << std::endl;
    else
        std::cout << "A => Fail" << std::endl;
    if (dynamic_cast<B*>(p))
        std::cout << "B => Success" << std::endl;
    else
        std::cout << "B => Fail" << std::endl;
    if (dynamic_cast<C*>(p))
        std::cout << "C => Success" << std::endl;
    else
        std::cout << "C => Fail" << std::endl;
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A => Success" << std::endl;
    } catch (std::exception &e) {
        std::cerr << "A " << e.what() << std::endl;
    }

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B => Success" << std::endl;
    } catch (std::exception &e) {
        std::cerr << "B " << e.what() << std::endl;
    }

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C => Success" << std::endl;
    } catch (std::exception &e) {
        std::cerr << "C " << e.what() << std::endl;
    }
}

int main() {

    Base* ptr = generate();
    std::cout << "Pointer identify: " << std::endl;
    identify(ptr);
    std::cout << "-----------------" << std::endl;
    std::cout << "Reference identify: " << std::endl;
    identify(*ptr);
    delete ptr;

    return 0;
}