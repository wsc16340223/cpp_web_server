#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstdio>
#include <iostream>

int main()
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("Error socket");
        return -1;
    }

    struct sockaddr_in serv_addr = {};
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(8888);
    bind(sockfd, (sockaddr*)&serv_addr, sizeof(serv_addr));

    listen(sockfd, SOMAXCONN);

    while (true)
    {
        struct sockaddr_in cli_addr = {};
        socklen_t cli_addr_len = sizeof(cli_addr);
        int cli_sockfd = accept(sockfd, (sockaddr*)&cli_addr, &cli_addr_len);
        if (cli_sockfd < 0)
        {
            perror("Error accept");
            return -1;
        }
        std::cout << "New client fd: " << cli_sockfd << " IP: " << inet_ntoa(cli_addr.sin_addr) << " Port: " << ntohs(cli_addr.sin_port) << std::endl;
    }

    return 0;
}