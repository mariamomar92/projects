#include "Traveler.h"
#include "main.h"
#include "Host.h"
#include <string>

static int myID = 0;

Traveler::Traveler(string name, string Email, string Gender, string pass, string Nationality, int Age)
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

Traveler::Traveler()
{

}

int Traveler::LogIn(vector<Traveler>& AllTravellers)
{
	cout << endl << "Please enter your email: ";
	cin >> email;

	Traveler logedInTrav;

	cout << endl << "Please enter your password: ";
	cin >> password;

	for (int i = 0; i < AllTravellers.size(); i++)
	{
		if (AllTravellers[i].email == email)
		{
			if (AllTravellers[i].password == password)
			{
				logedInTrav = AllTravellers[i];
				cout << "You Have Successfully Logged In!" << endl;
				cout << "Welcome to Our Simplified Air B & B!" << endl;
				return i;
			}
		}
	}
	cout << "You don't have an account please create one: " << endl;
	logedInTrav.signup();
	AllTravellers.push_back(logedInTrav);
}


void Traveler::Rent(vector<Host>& AllHosts)
{
	int priceRange, propertyID, hostID, sDate, eDate;
	string startDate, endDate;

	cout << "Please enter your price range: ";
	cin >> priceRange;
	cout << "Please enter your start date: ";
	cin >> startDate;
	sDate = dayOfYear(startDate);
	cout << "Please enter you end date: ";
	cin >> endDate;
	cout << endl;
	eDate = dayOfYear(endDate);



	// A loop that displays available properties within the price range.

	for (int i = 0; i < AllHosts.size(); i++)
	{
		for (int j = 0; j < AllHosts[i].myProperties.size; j++)
		{
			if ((Availability(AllHosts[i].myProperties.AT(j), sDate, eDate)) && (PriceRange(AllHosts[i].myProperties.AT(j), priceRange, sDate, eDate)))
			{
				cout << "Property ID: " << AllHosts[i].myProperties.AT(j).id << endl;
				cout << "Property Name: " << AllHosts[i].myProperties.AT(j).name << endl;
				cout << "Location: " << AllHosts[i].myProperties.AT(j).city << endl;
				cout << "Host Name: " << AllHosts[i].fullname << endl;
				cout << "Host ID: " << AllHosts[i].ID << endl;
				cout << "------------------------------------------"<< endl;
			}
		}
	}


	cout << "Please enter the ID of the Property you want to rent: ";
	cin >> propertyID;
	cout << "Please enter the property's host ID: ";
	cin >> hostID;

	// A loop that finds the property that the traveler wants to rent

	for (int i = 0; i < AllHosts.size(); i++)
	{
		if (AllHosts[i].ID == hostID)
		{
			for (int j = 0; j < AllHosts[i].myProperties.size; j++)
			{
				if (AllHosts[i].myProperties.AT(j).id == propertyID)
				{
					AllHosts[i].myProperties.AT(j).AddRentedDates(sDate, eDate);
					DisplayAndStoreRented(AllHosts[i].myProperties.AT(j), startDate, endDate);
				}
			}
		}
	}


}

bool Traveler::Availability(properties property, int startDate, int endDate)
{
	if (property.n.size() == 0) 
	{
		return true;
	}
	else 
	{
		for (int i = 0; i < (property.n.size()); i++)
		{
			if ((startDate >= property.n[i].startDate && startDate <= property.n[i].endDate) || (endDate <= property.n[i].endDate && endDate >= property.n[i].startDate))
			{
				return false;
			}
		}
		
	}
	return true;
	
}


bool Traveler::PriceRange(properties property, int priceRange, int startDate, int endDate)
{
	int duration = endDate - startDate;
	if ((stoi(property.price) * duration) <= priceRange)
		return true;
	else
		return false;

}


void Traveler::DisplayAndStoreRented(properties property, string startDate, string endDate)
{
	char choice;
	Rentals rentals;
	rentals.startDate = startDate;
	rentals.endDate = endDate;
	rentals.propertyID = property.id;
	rentals.propertyName = property.name;

	rents.push_back(rentals);

	cout << "The Property has been rented successfully! \n Would you like to display your rented properties? ";
	cin >> choice;

	if (choice == 'y')
	{
		for (int i = 0; i < rents.size(); i++)
		{
			cout << "Your Property Name: " << rents[i].propertyName << endl;
			cout << "Your Property ID: " << rents[i].propertyID << endl;
			cout << "Rented from: " << rents[i].startDate + " to: " + rents[i].endDate << endl;
		}
	}

}


int days[] = { 31, 28, 31, 30, 31, 30,
			   31, 31, 30, 31, 30, 31 };

int Traveler::dayOfYear(string date)
{
	int year = stoi(date.substr(0, 4));
	int month = stoi(date.substr(5, 2));
	int day = stoi(date.substr(8));
	if (month > 2 && year % 4 == 0
		&& (year % 100 != 0 || year % 400 == 0)) {
		++day;
	}
	while (month-- > 0) {
		day = day + days[month - 1];
	}
	return day;
}