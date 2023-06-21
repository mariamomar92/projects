#include "Admin.h"

static int myID = 0;

Admin::Admin()
{

}

Admin::Admin(string fullname, string email, string gender, string password, string nationality, int age)
{
}

bool Admin::LogIn()
{
	bool loggedin = false;
	string email = "polasameh9@gmail.com";
	string password = "1243";
	string mail;
	string pass;

	cout << endl << "Please enter your email: ";
	cin >> mail;

	cout << endl << "Please enter your password: ";
	cin >> pass;
	if (email == mail && pass == password) {
		cout << "You have succesfully logged in!" << endl;
		return true;
	}
	else {
		cout << "Invalid login information" << endl;
		return false;
	}
}

void Admin::ViewProperties(vector<Host>& AllHosts)
{
	cout << "Displaying all properties: " << endl << endl;
	for (int j = 0; j < AllHosts.size(); j++) 
	{
		cout << "Host Name: " << AllHosts[j].fullname<< endl;
		cout << "Host ID: " << AllHosts[j].ID<< endl;
		AllHosts[j].ViewProperties();
	}
	
}

void Admin::update(vector<Host>& AllHosts)
{
	int hostID , index = 0;
	int updateChoice;
	string choice;
	bool flag = false;

	do 
	{
		cout << "Please enter the host id to update:";
		cin >> hostID;

		for (int j = 0; j < AllHosts.size(); j++)
		{
			if (AllHosts[j].ID == hostID)
			{
				AllHosts[j].update();
				index = j;
			}
		}

		
		cout << "Would you like to see the updated Properties? " << endl;
		cout << "Your updated Properties: " << endl;
		system("CLS");
		AllHosts[hostID].ViewProperties();

		cout << "Would you like to update another Property?" << endl;
		cin >> choice;
		if (choice == "y")
			flag = true;
		else
			flag = false;

	} while (flag == true);
}
	


