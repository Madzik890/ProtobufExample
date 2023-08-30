#include <iostream>
#include <fstream>

#include "protocol/person.pb.h"

int main() {
    // Create a Person message
    Person person;
    person.set_name("Alice");
    person.set_age(25);
    person.set_email("alice@example.com");

    // Serialize the Person message to a binary format
    std::string serialized_data;
    person.SerializeToString(&serialized_data);

    // Write the serialized data to a file
    std::ofstream output_file("person_data.bin", std::ios::binary);
    if (output_file.is_open()) {
        output_file.write(serialized_data.c_str(), serialized_data.size());
        output_file.close();
    } else {
        std::cerr << "Failed to open the output file." << std::endl;
        return 1;
    }

    // Deserialize the data
    Person deserialized_person;
    std::ifstream input_file("person_data.bin", std::ios::binary);
    if (input_file.is_open()) {
        std::string serialized_data((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
        deserialized_person.ParseFromString(serialized_data);
        input_file.close();
    } else {
        std::cerr << "Failed to open the input file." << std::endl;
        return 1;
    }

    // Print the deserialized Person message
    std::cout << "Name: " << deserialized_person.name() << std::endl;
    std::cout << "Age: " << deserialized_person.age() << std::endl;
    std::cout << "Email: " << deserialized_person.email() << std::endl;

    return 0;
}