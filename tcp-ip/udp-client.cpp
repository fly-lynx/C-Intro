#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[1024] = {0};
    const char *message = "Hello from UDP client";

    // 1. Create a UDP socket
    std::cout << "Creating UDP socket..." << std::endl;
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        std::cerr << "Socket creation error" << std::endl;
        return -1;
    }
    std::cout << "Socket created successfully (fd: " << sock << ")" << std::endl;

    // 2. Define server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);

    // Convert IP address to binary
    std::cout << "Converting server IP address to binary format..." << std::endl;
    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        std::cerr << "Invalid address or Address not supported" << std::endl;
        return -1;
    }
    std::cout << "IP address conversion successful" << std::endl;

    // 3. Send message to server
    std::cout << "Sending message to server..." << std::endl;
    ssize_t bytes_sent = sendto(sock, message, strlen(message), 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (bytes_sent < 0) {
        std::cerr << "Failed to send message" << std::endl;
    } else {
        std::cout << "Message sent to server (" << bytes_sent << " bytes)" << std::endl;
    }

    // 4. Receive response from server
    socklen_t addr_len = sizeof(server_addr);
    std::cout << "Waiting for response from server..." << std::endl;
    ssize_t bytes_received = recvfrom(sock, buffer, 1024, 0, (struct sockaddr *)&server_addr, &addr_len);
    if (bytes_received < 0) {
        std::cerr << "Failed to receive response" << std::endl;
    } else {
        std::cout << "Response received from server (" << bytes_received << " bytes): " << buffer << std::endl;
    }

    // 5. Close socket
    std::cout << "Closing client socket..." << std::endl;
    close(sock);
    std::cout << "Client socket closed" << std::endl;

    return 0;
}
