//Based on Homework 3 solution done in class
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <iterator>
using namespace std;

#include "crew.h"
#include "plane.h"
#include "flight.h"
#include "crews.h"
#include "planes.h"
#include "flights.h"


Crews mycrew;
Planes myfleet;
flights myflts;

int main()
{
   int choice = -1;

   mycrew.loadCrew();
   myfleet.loadPlanes();
    myflts.LoadFlights();
    
   while (choice != 0)
   {
   cout << "Mean Green Airlines Menu" << endl;
   cout << "1 - Add Plane" << endl;
   cout << "2 - Delete Plane" << endl;
   cout << "3 - Edit Plane" << endl;
   cout << "4 - Print all Planes" << endl;
   cout << "5- Add Crew Member" << endl;
   cout << "6 - Delete Crew  Member" << endl;
   cout << "7 - Edit Crew Member" << endl;
   cout << "8 - Print all crew" << endl;
   cout << "9 - Add Flight" << endl;
   cout << "10 - Delete Flight" << endl;
   cout << "11 - Edit Flight" << endl;
   cout << "12 - Print a Flight" << endl;
   cout << "13 - Print All Flights" << endl;
   cout << "14 - Print a Plane Schedule" << endl;
   cout << "15 - Print  Crew Schedule" << endl;
   cout << "16 - Update Flights" << endl;
   cout << "17- Cleanup Flights" << endl;
   cout << "0 - Quit" << endl;

     cout << "Enter your selection: ";
     cin >>  choice; cin.ignore();

     switch (choice)
     {
      case 1: myfleet.addPlane(); break;
      case 2: myfleet.deletePlane(); break;
      case 3: myfleet.editPlane(); break;
      case 4: myfleet.printAllPlanes(); break;
      case 5: mycrew.addCrew(); break;
      case 6: mycrew.deleteCrew(); break;
      case 7: mycrew.editCrew(); break;
      case 8: mycrew.printAllCrew(); break;
      case 9: myflts.AddFlight(); break;
      case 10: myflts.DeleteFlight(); break;
      case 11: myflts.EditFlight(); break;
      case 12:
         {
             cout << "Enter Flight Number to print ";
             unsigned int f;
             cin >> f; cin.ignore();
             myflts.PrintaFlight(f); break;
         }
      case 13: myflts.PrintAllFlights(); break;
      case 14:
             
         {
             cout << "Enter Tail Number of Plane: " << endl;
             string t;
             cin >> t; cin.ignore();
             myflts.PrintPlanSched(t); break;
             
         }
      case 15:
         {
             cout << "Enter Crew ID ";
             int id;
             cin >> id; cin.ignore();
             myflts.PrintCrewSched(id); break;
             
         }
      case 16: myflts.UpdateFlights(); break;
      case 17: myflts.Cleanup(); break;
      case 0: cout <<"exiting..." << endl; break;
      default:  cout << "Not a valid choice try again..." << endl; break;

     }
   }
   mycrew.storeCrew();
   myfleet.storePlanes();
   myflts.StoreFlights();
    
 return 0;
}
