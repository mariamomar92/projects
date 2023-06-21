#include "properties.h"
#include "Traveler.h"
#include <unordered_map>
#include <string>

static int ID = 0;

properties::properties()
{

}

properties::properties(string name, string city, string price)
{
	this->name = name;
	this->city = city;
	this->price = price;
	this->id = ID;
	ID++;
}

properties::properties(int id, string name, string city, string price)
{
	this->id = id;
	this->name = name;
	this->city = city;
	this->price = price;
}


void properties::AddRentedDates(int startDate, int endDate)
{
	Dates dates;

	dates.startDate = startDate;
	dates.endDate = endDate;

	n.push_back(dates);
}
