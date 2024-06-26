#ifndef RAMEN_SERVER_HPP
#define RAMEN_SERVER_HPP

#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string>
#include <unistd.h>
#include <functional>
#include <sys/socket.h>

namespace ramen
{

    class Server
    {
    public:
        Server();
        ~Server();
        void listen(int port, std::function<void()> callback = nullptr);

    private:
        std::string m_ip_address;
        int m_socket;
        int m_new_socket;
        struct sockaddr_in m_socketAddress;
        unsigned int m_socketAddress_len;
        int m_port;
        int startServer();
        int createSocket();
        void closeServer();
    };
}

#endif