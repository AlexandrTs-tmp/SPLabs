#include "Client.h"

Client::Client() {

}

Client::Client(int _code, Data _data) {
    code = _code;
    if (checkData(_data)) {
        data = _data;
    }
}

Client::~Client() {
}

bool Client::changeData(Data _data) {
    int status = 0;
    if (checkData(_data)) {
        data = _data;
        status = 1;
    }
    return status;
}

bool Client::checkData(Data _data) {
    int status = 1;
    if (_data.age < 18) {
        status = 0;
    }
    return status;
}

