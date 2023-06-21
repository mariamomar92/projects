//#include <vector>
//#include "Host.h"
//#include"Traveler.h"
//#include"user.h"
//#include"linkedlist.h"
//#include "AddInformation.h"
//#include "Admin.h"
//#include <list>
//#include <string>
//#include <iostream>
//using namespace std;
//
//int main() {
//    int choice;
//    int login;
//    char addPlace;
//    static int usertype;
//
//   
//    vector <Traveler> AllTravellers;
//    vector<Admin> AllAdmins;
//    vector<Host> AllHosts;
//
//
//    linkedlist AllProperties;
//    properties pObj;
//
//    Traveler Travobj;
//    Host hostobj;
//    Admin adminobj;
//    
//    
//    
//    AddInformation addInfo(AllTravellers);
//    //AddInformation AddInfo(AllAdmins);
//
//    cout << "Are you a \n1-TRAVELER \n2-HOST \n3-ADMIN?";
//    cin >> usertype;
//
//
//    switch (usertype)
//    { 
//        //case one is Traveler
//    case 1: cout << "Do you want to log in or sign up?(1 to SIGNUP 2 to LOGIN)";
//        cin >> login; 
//        //1 for signup 2 for log in//
//        if (login == 1) 
//        {
//            Travobj.signup();
//            AllTravellers.push_back(Travobj);
//        }
//        else 
//        {
//            //login function
//        }
//        break;
//
//    case 2: //Host
//        cout << "Do you want to log in or sign up?(1 to SIGNUP 2 to LOGIN)";
//        cin >> login; //1 for signup 2 for log in//
//        if (login == 1) 
//        {
//            hostobj.signup();
//            AllHosts.push_back(hostobj);
//        }
//        else
//        {
//            //login function
//        }
//        cout << "add place? (y/n)" << endl;
//        cin >> addPlace;
//        while (addPlace == 'y') 
//        {
//            pObj.addinfo();
//            hostobj.myProperties.append(pObj);
//            cout << "add anther place?" << endl;
//            cin >> addPlace;
//            
//            
//            //break;
//        }
//    case 3: //Admin
//        adminobj.View();
//        cout << "Displaying all avaliable places. Please choose a place to edit: " << endl;
//        hostobj.myProperties.display();
//        hostobj.update();
//        hostobj.myProperties.display();
//    default:
//        break;
//    }
//
//
//    return 0;
//}
#include <vector>
#include "Host.h"
#include"Traveler.h"
#include"user.h"
#include"linkedlist.h"
#include "AddInformation.h"
#include "Admin.h"
#include <list>
#include <string>
#include <iostream>
using namespace std;

int main() 
{
    int login;
    char addPlace;
    static int usertype;

    vector<Host> AllHosts;
    vector <Traveler> AllTravellers;

    linkedlist AllProperties;
    properties pObj;

    Traveler Travobj;
    Traveler travelerLoggedIn;
    Host hostobj;
    Host hostLoggedIn;
    Admin adminobj;
    Admin adminLoggedIn;
    AddInformation addInformation(AllHosts, AllTravellers);

    bool flag = true;

    do
    {
        cout << "Are you a \n1-TRAVELER \n2-HOST \n3-ADMIN" << endl;
        cin >> usertype;
        system("CLS");

        switch (usertype)
        {
        case 1:
            cout << "Do you want to\n1.Log In\n2.Sign Up\n";
            cin >> login;
            system("CLS");
            if (login == 1)
            {
                int x = Travobj.LogIn(AllTravellers);
                int choice;
                cout << "Here are the avaliable properties for rent: " << endl;
                AllTravellers[x].Rent(AllHosts);
            }
            else
            {
                Travobj.signup();
                AllTravellers.push_back(Travobj);
                cout << AllTravellers[4].fullname;
                //system("CLS");
                Travobj.LogIn(AllTravellers);
            }
            break;
        case 2:
            cout << "Do you want to\n1.Log In\n2.Sign Up\n";
            cin >> login;
            if (login == 1)
            {
                int choice;
                hostLoggedIn = hostobj.LogIn(AllHosts);
                cout << "Would you like to:\n1.Add a Property\n2.View your Properties\n3.Update" << endl;
                cin >> choice;
                if (choice == 1)
                    hostLoggedIn.AddProperty();
                else if (choice == 2)
                    hostLoggedIn.ViewProperties();
                else
                    hostLoggedIn.update();
            }
            else
            {
                hostobj.signup();
                AllHosts.push_back(hostobj);
            }
        case 3: //Admin
            bool answer;
            answer = adminobj.LogIn();
            if (answer)
            {
                adminobj.ViewProperties(AllHosts);
                adminobj.update(AllHosts);

            }
        default:
            break;
        }

        cout << "Do You Want to:\n1.Log Out\n2.Log in as another user" << endl;
        int x;
        cin >> x;
        if (x == 1)
            flag = false;
        else
            flag = true;

        system("CLS");

    } while (flag == true);

    return 0;
}
