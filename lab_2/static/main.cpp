#include "Client.h"

int main(int argc, char *argv[])
{
    Client coolClient;
    Client::Data* data = new Client::Data();
    data->fullName = "Bob Bub";
    coolClient.changeData(*data);
    std::cout << coolClient;

    Client* coolerClient;
    coolerClient = new Client();
    std::cout << *coolerClient;
}
