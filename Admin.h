#pragma once
#include"user.h"
#include "properties.h"
#include "host.h"
#include "Traveler.h"
using namespace std;



class Admin : public user
{
public:
	Admin();
	Admin(string fullname, string email, string gender, string password, string nationality, int age);
	bool LogIn();
	void ViewProperties(vector<Host>& AllHosts);
	void update(vector<Host>& AllHosts);
	Host host;
};

