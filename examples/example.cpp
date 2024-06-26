#include "ramen/server.hpp"
#include <iostream>

void onSuccess()
{
    std::cout << "Server created";
}

int main()
{
    using namespace ramen;

    std::cout << "running";

    Server server = Server();

    server.listen(8000, &onSuccess);

    return 0;
}