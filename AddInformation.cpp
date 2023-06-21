#include "AddInformation.h"


AddInformation::AddInformation(vector<Host>& AllHosts, vector<Traveler>& AllTravellers)
{
	Host h("Sherry Fady", "sherryfady40@gmail.com", "F", "12345", "Egyptian", 20);
	Host h1("Hla Hatem", "hla0@gmail.com", "F", "123456", "Egyptian", 20);
	Host h2("Hannia Tarek", "htarek@gmail.com", "F", "1234567", "Korean", 25);
	Host h3("Maria Fady", "msawiris@gmail.com", "F", "12345678", "Egyptian", 23);

	properties p("Villa", "Mexico", "1200");
	h.myProperties.append(p);
	h.AddProperty("Mansion", "USA", "8000");
	h1.AddProperty("House", "Berlin", "3200");
	h1.AddProperty("Villa", "Berlin", "2800");
	h2.AddProperty("Room", "Venice", "2000");
	h2.AddProperty("Apartment", "Venice", "1500");
	h3.AddProperty("Villa", "France", "4000");
	h3.AddProperty("Apartment", "France", "2000");

	AllHosts.push_back(h);
	AllHosts.push_back(h1);
	AllHosts.push_back(h2);
	AllHosts.push_back(h3);


	Traveler t("Mariam Omar", "omarmariam@gmail.com", "F", "12", "Egyptian", 19);
	Traveler t1("Laila Khaled", "lola@gmail.com", "F", "123", "Egyptian", 30);
	Traveler t2("Amal Gameel", "amalgameel@gmail.com", "F", "1234", "Nigerian", 50);
	Traveler t3("Fady Sawiris", "fsawiris@gmail.com", "M", "123456789", "Egyptian", 52);

	AllTravellers.push_back(t);
	AllTravellers.push_back(t1);
	AllTravellers.push_back(t2);
	AllTravellers.push_back(t3);

}