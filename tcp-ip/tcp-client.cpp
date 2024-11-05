#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};

    // 1. Create a TCP socket
    std::cout << "Creating socket..." << std::endl;
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        std::cerr << "Socket creation error" << std::endl;
        return -1;
    }
    std::cout << "Socket created successfully (fd: " << sock << ")" << std::endl;

    // 2. Define server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);

    // 3. Convert IP address to binary
    std::cout << "Converting IP address to binary format..." << std::endl;
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        std::cerr << "Invalid address or Address not supported" << std::endl;
        return -1;
    }
    std::cout << "IP address conversion successful" << std::endl;

    // 4. Connect to the server
    std::cout << "Connecting to server at 127.0.0.1 on port 8080..." << std::endl;
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cerr << "Connection failed" << std::endl;
        return -1;
    }
    std::cout << "Connected to the server successfully!" << std::endl;

    // 5. Receive message from server
    std::cout << "Receiving message from server..." << std::endl;
    ssize_t bytes_received = read(sock, buffer, 1024);
    if (bytes_received < 0) {
        std::cerr << "Failed to receive message from server" << std::endl;
    } else {
        std::cout << "Message received from server (" << bytes_received << " bytes): " << buffer << std::endl;
    }

    // 6. Close the socket
    std::cout << "Closing socket..." << std::endl;
    close(sock);
    std::cout << "Socket closed" << std::endl;

    return 0;
}
