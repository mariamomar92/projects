#include "Host.h"
using namespace std;
#include <vector>
#include <string>

static int myID = 0;

Host::Host(void)
{

}

Host::Host(string name, string Email, string Gender, string pass, string Nationality, int Age)
{
	fullname = name;
	email = Email;
	gender = Gender;
	password = pass;
	nationality = Nationality;
	age = Age;
	ID = myID;
	myID++;

}

Host Host::LogIn(vector<Host>& AllHosts)
{
	int choice;
	cout << endl << "Please enter your email: ";
	cin >> email;

	Host logedInTrav;

	cout << endl << "Please enter your password: ";
	cin >> password;

	for (int i = 0; i < AllHosts.size(); i++)
	{
		if (AllHosts[i].email == email)
		{
			if (AllHosts[i].password == password)
			{
				logedInTrav = AllHosts[i];
				cout << "You Have Successfully Logged In!" << endl;
				cout << "Welcome to Our Simplified Air B & B!" << endl;
				return AllHosts[i];

				break;
			}
		}

		cout << "You don't have an account please create one: " << endl;
		logedInTrav.signup();
		AllHosts.push_back(logedInTrav);

	}
}

void Host::AddProperty(string name, string city, string price)
{
	properties p(name, city, price);
	myProperties.append(p);
}

void Host::AddProperty()
{
	string name, city, price;
	cout << "Please enter your Property Name: ";
	cin >> name;
	cout << "Please enter the City: ";
	cin >> city;
	cout << "Please enter your Property's price per night: ";
	cin >> price;
	AddProperty(name, city, price);
}

void Host::ViewProperties()
{
	for (int i = 0; i < myProperties.size; i++)
	{
		cout << "PROPERTY " << i + 1 << endl << endl;
		cout << "Property Name: " << myProperties.AT(i).name << endl;
		cout << "Property City: " << myProperties.AT(i).city << endl;
		cout << "Property Price: " << myProperties.AT(i).price << endl;
		cout << "Property ID: " << myProperties.AT(i).id << endl;
		cout << "___________________________________" << endl;
	}
}

void Host::update()
{
	int IDD;
	int updateChoice;
	string choice;
	
	cout << "\nPlease enter the property ID to update:";
	cin >> IDD;
	for (int i = 0; i < myProperties.size; i++)
	{
		if (myProperties.AT(i).id == IDD)
		{
			cout << "What do you want to update: 1-Name,2-city, 3-price";
			cin >> updateChoice;
			if (updateChoice == 1)
			{
				cout << "enter new name:";
				cin >> choice;
				properties newProperty = properties(myProperties.AT(i).id, choice, myProperties.AT(i).city, myProperties.AT(i).price);
				myProperties.InsertAt(newProperty, i);
				myProperties.DeleteAt(i + 1);
				cout << myProperties.AT(i).name << endl;
			}
			else if (updateChoice == 2)
			{

				cout << "enter new city:";
				cin >> choice;
				properties newProperty = properties(myProperties.AT(i).id, myProperties.AT(i).name, choice, myProperties.AT(i).price);
				myProperties.InsertAt(newProperty, i);
				myProperties.DeleteAt(i + 1);
				cout << myProperties.AT(i).city << endl;
			}
			else if (updateChoice == 3)
			{
				cout << "Enter new price:";
				cin >> choice;
				properties newProperty = properties(myProperties.AT(i).id, myProperties.AT(i).name, myProperties.AT(i).city, choice);
				myProperties.InsertAt(newProperty, i);
				myProperties.DeleteAt(i + 1);
				cout << myProperties.AT(i).price << endl;
			}
			else{
				cout << "wrong choice";
			}
		}
	}
}