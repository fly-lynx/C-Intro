#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    const char *message = "Hello from server";

    // 1. Create a TCP socket (IPv4)
    std::cout << "Creating socket..." << std::endl;
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {
        std::cerr << "Socket creation failed" << std::endl;
        return -1;
    }
    std::cout << "Socket created successfully (fd: " << server_fd << ")" << std::endl;

    // 2. Bind the socket to an IP/Port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    std::cout << "Binding socket to port 8080..." << std::endl;
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        std::cerr << "Bind failed" << std::endl;
        return -1;
    }
    std::cout << "Socket bound to port 8080" << std::endl;

    // 3. Listen for incoming connections
    std::cout << "Setting up socket to listen for incoming connections..." << std::endl;
    if (listen(server_fd, 3) < 0) {
        std::cerr << "Listen failed" << std::endl;
        return -1;
    }
    std::cout << "Server is listening on port 8080" << std::endl;

    // 4. Accept an incoming connection
    std::cout << "Waiting for a client connection..." << std::endl;
    new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
    if (new_socket < 0) {
        std::cerr << "Accept failed" << std::endl;
        return -1;
    }
    std::cout << "Client connected! (Socket fd: " << new_socket << ")" << std::endl;

    // 5. Send data to the connected client
    std::cout << "Sending message to client..." << std::endl;
    ssize_t bytes_sent = send(new_socket, message, strlen(message), 0);
    if (bytes_sent < 0) {
        std::cerr << "Failed to send message" << std::endl;
    } else {
        std::cout << "Message sent to client (" << bytes_sent << " bytes)" << std::endl;
    }

    // 6. Close sockets
    std::cout << "Closing client socket..." << std::endl;
    close(new_socket);
    std::cout << "Client socket closed" << std::endl;

    std::cout << "Closing server socket..." << std::endl;
    close(server_fd);
    std::cout << "Server socket closed" << std::endl;

    return 0;
}
