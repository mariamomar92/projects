#include <iostream>
#include <string>
#include <vector>
#include "Host.h"
#include "properties.h"
#pragma once
#include "user.h"
#include <iostream>
using namespace std;

class Traveler :
    public user
{
public:
    struct Rentals
    {
        int propertyID;
        string propertyName, startDate, endDate;

    };

    vector <Rentals> rents;
   

    Traveler();
    Traveler(string fullname, string email, string gender, string password, string nationality, int age);
    int LogIn(vector<Traveler>& AllTravellers);
    void Rent(vector<Host>& AllHosts);
    bool Availability(properties property, int startDate, int endDate);
    bool PriceRange(properties property, int priceRange, int startDate, int endDate);
    void DisplayAndStoreRented(properties property, string startDate, string endDate);
    int dayOfYear(string date);
};
