#pragma once
#include <iostream>
#include <vector>
using namespace std;
class properties
{
public:
	string name;
	string city;
	string price;
	int id;

	struct Dates
	{
		int startDate, endDate;
	};


	vector<Dates> n;

	properties();
	properties(string name, string city, string price);
	properties(int id, string name, string city, string price);

	void AddRentedDates(int startDate, int endDate);

	friend std::ostream& operator <<(std::ostream& os, const properties& c)
	{
		return (os << "place name = " << c.name << ",ID = " << c.id << ", city = " << c.city << ", price = " << c.price << endl);
	}

};
