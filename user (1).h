#pragma once
using namespace std;
#include <iostream>
class user
{
public:
        string fullname;
        string email;
        string password;
        string nationality;
        string gender;
        int age = 0;
        int ID = 0;
    public:
        void login();
        void signup();
};

