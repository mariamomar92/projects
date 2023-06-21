#pragma once
#include <vector>
#include "Host.h"
#include "Traveler.h"
#include "Admin.h"
#include "properties.h"

class AddInformation
{
public:
	AddInformation(vector<Host>& AllHosts, vector<Traveler>& AllTravelers);
};