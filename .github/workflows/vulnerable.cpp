#include <iostream>
#include <cstring>

void process_user_input(char* input) {
    // Allocate fixed buffer space
    const int BUFFER_SIZE = 8;
    char secure_buffer[BUFFER_SIZE];

    // REMEDIATION: strncpy requires the destination size limit.
    // We pass BUFFER_SIZE - 1 to guarantee room for the null-terminator string ending (\0).
    std::strncpy(secure_buffer, input, BUFFER_SIZE - 1);
    
    // Explicitly enforce the null-terminator at the final array index
    secure_buffer[BUFFER_SIZE - 1] = '\0';

    std::cout << "Data safely processed: " << secure_buffer << std::endl;
}

int main() {
    char* malicious_payload = "super_long_string_that_will_overflow_the_buffer";
    process_user_input(malicious_payload);
    return 0;
}