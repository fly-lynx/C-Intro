#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int server_fd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024] = {0};
    const char *response = "Hello from UDP server";
    socklen_t client_len = sizeof(client_addr);

    // 1. Create a UDP socket
    std::cout << "Creating UDP socket..." << std::endl;
    server_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (server_fd < 0) {
        std::cerr << "Socket creation failed" << std::endl;
        return -1;
    }
    std::cout << "Socket created successfully (fd: " << server_fd << ")" << std::endl;

    // 2. Bind the socket to a specific port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    std::cout << "Binding socket to port 8080..." << std::endl;
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Bind failed" << std::endl;
        close(server_fd);
        return -1;
    }
    std::cout << "Socket bound to port 8080" << std::endl;

    // 3. Receive data from client
    std::cout << "Waiting for data from client..." << std::endl;
    ssize_t bytes_received = recvfrom(server_fd, buffer, 1024, 0, (struct sockaddr *)&client_addr, &client_len);
    if (bytes_received < 0) {
        std::cerr << "Failed to receive data" << std::endl;
    } else {
        std::cout << "Received " << bytes_received << " bytes from client: " << buffer << std::endl;
    }

    // 4. Send response to client
    std::cout << "Sending response to client..." << std::endl;
    ssize_t bytes_sent = sendto(server_fd, response, strlen(response), 0, (struct sockaddr *)&client_addr, client_len);
    if (bytes_sent < 0) {
        std::cerr << "Failed to send response" << std::endl;
    } else {
        std::cout << "Response sent to client (" << bytes_sent << " bytes)" << std::endl;
    }

    // 5. Close socket
    std::cout << "Closing server socket..." << std::endl;
    close(server_fd);
    std::cout << "Server socket closed" << std::endl;

    return 0;
}
