#ifndef CLIENT_H
#define CLIENT_H

#include "string"
#include <iostream>

class Client
{
public:
    enum Nationality {
        Ukrainian,
        Russian,
        American,
        German,
        Chinese,
        Japanese
    };
    enum Gender {
        Male,
        Female,
        Object
    };
    enum FamilyState {
        Single,
        Married,
        Divorced
    };
    struct Data {
        std::string fullName = "Boba Buba";
        Gender gender = Gender::Object;
        std::string birthDate = "01.01";
        int age = 18;
        int heigth = 0;
        int weight = 0;
        FamilyState familyState = FamilyState::Single;
        std::string* hobbies = new std::string("No hobbies");
        std::string info = "I'm very attractive, please call me";
        // int signCode;
        // int relationCode; // ????????????
        Nationality nationality = Nationality::Japanese;
        std::string address = "Without a fixed place of residence";
        std::string phoneNum = "+380 00 000 0000";
        std::string partnerInfo = "I'm looking for someone who loves tomatoes";
    };

private:
    int code;
    Data data;

    bool checkData(Data);
public:
    Client();
    Client(int _code);
    Client(int, Data);
    ~Client();
    bool changeData(Data);
    Data getData();

    friend std::ostream& operator<<(std::ostream &out, const Client &client) {
        out << client.data.fullName << "\n" << client.data.gender << "\n" << client.data.age << "\n";
        if (client.data.info.size() > 0) {
            out << client.data.info << "\n";
        }
        return out;
    }
};

#endif // CLIENT_H
