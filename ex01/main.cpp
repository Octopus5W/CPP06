#include "Serializer.hpp"
#include <iostream>

int main() {
    Data data;
    data.number = 666;
    data.name = "test";

    std::cout << "Original Data address: " << &data << std::endl;
    std::cout << "Original Data members: " << data.number << ", " << data.name << std::endl << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized value in uintptr_t: " << raw << std::endl;

    Data* ptr = Serializer::deserialize(raw);
    std::cout << "Deserialized address : " << ptr << std::endl << std::endl;

    if (ptr == &data) {
        std::cout << "SUCCESS: deserialized pointer matches original pointer." << std::endl;
        std::cout << "Recovered Data members: " << ptr->number << ", " << ptr->name << std::endl;
    } else {
        std::cout << "ERROR: pointers do not match." << std::endl;
    }

    return 0;
}
