#pragma once
#include "user.h"
#include "properties.h"
#include "linkedlist.h"
using namespace std;
#include<iostream>


class Host :
    public user
{
public:
    linkedlist myProperties;
    
public:
    Host(void);
    Host(string fullname, string email, string gender, string password, string nationality, int age);
    Host LogIn(vector<Host>& AllHosts);
    void AddProperty(string name, string city, string price);
    void AddProperty();
    void ViewProperties();
    void update();
};