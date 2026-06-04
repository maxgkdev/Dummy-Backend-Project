#include <iostream>
#include <cstring>

void process_user_input(char* input) {
    char secure_buffer[8];
    // VULNERABILITY: strcpy does not check bounds. 
    // If input is larger than 8 bytes, it overflows the stack memory.
    std::strcpy(secure_buffer, input); 
    std::cout << "Data processed: " << secure_buffer << std::endl;
}

int main() {
    char* malicious_payload = "super_long_string_that_will_overflow_the_buffer";
    process_user_input(malicious_payload);
    return 0;
}