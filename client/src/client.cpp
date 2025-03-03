#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstdio>

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
    connect(sockfd, (sockaddr*)&serv_addr, sizeof(serv_addr));
    
    return 0;
}