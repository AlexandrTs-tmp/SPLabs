#include "Client.h"

void swap(float* a, float* b) {
    float tmp;
    tmp = *b;
    *b = *a;
    *a = tmp;
}

int main(int argc, char *argv[])
{
    float a = 5;
    float b = 3;
    swap(&a, &b);
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    Client coolClient;
    Client::Data* data = new Client::Data(coolClient.getData());
    data->fullName = "Bob Bub";
    coolClient.changeData(*data);
    std::cout << coolClient;

    Client* coolerClient;
    coolerClient = new Client();
    std::cout << *coolerClient;
}
