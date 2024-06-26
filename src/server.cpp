#include "ramen/server.hpp"
#include <iostream>
#include <sstream>
#include <unistd.h>

namespace
{
    void log(const std::string &message)
    {
        std::cout << message << std::endl;
    }
    void exitWithError(const std::string &errorMessage)
    {
        log("ERROR: " + errorMessage);
        exit(1);
    }
}

namespace ramen
{

    Server::Server() : m_ip_address("0.0.0.0"), m_port(), m_socket(), m_new_socket(), m_socketAddress(), m_socketAddress_len(sizeof(m_socketAddress))
    {
    }

    Server::~Server()
    {
    }

    void Server::listen(int port, std::function<void()> callback)
    {
        m_port = port;
        m_socketAddress.sin_family = AF_INET;
        m_socketAddress.sin_port = htons(m_port);
        m_socketAddress.sin_addr.s_addr = inet_addr(m_ip_address.c_str());

        if (startServer() != 0)
        {
            std::ostringstream ss;
            ss << "Failed to start Server on PORT: " << ntohs(m_socketAddress.sin_port);
            log(ss.str());
        }
    }

    int Server::startServer()
    {

        // create a socket
        m_socket = socket(AF_INET, SOCK_STREAM, 0);

        if (m_socket < 0)
        {
            exitWithError("Could not create socket");
            return 1;
        }

        // bind an address to a socket
        if (bind(m_socket, (sockaddr *)&m_socketAddress, m_socketAddress_len) < 0)
        {
            exitWithError("Cannot connect socket to address");
            return 1;
        }

        return 0;
    }

    void Server::closeServer()
    {
        close(m_socket);
        close(m_new_socket);
        exit(0);
    }
}
