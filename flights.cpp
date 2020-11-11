//flights.cpp
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iterator>

using namespace std;

#include "flight.h"
#include "crew.h"
#include "plane.h"
#include "flights.h"
#include "crews.h"
#include "planes.h"

extern Crews mycrew;
extern Planes myfleet;


  flights::flights()
{
    count = 0;
}

  unsigned int flights::getcount()
{
    return count;
}

  void flights::inccnt()
{
    count++;
}

  void flights::deccnt()
{
    count--;
}

  void flights::AddFlight()
{
    
    flight* flt;
    int i,j,k;
    string s;
    unsigned int ui;
    time_t timeval;
    
    flt = new flight;

    cout << "Enter flight number: ";
    cin >> ui; cin.ignore();
    flt->setflid(ui);
    cout << "Enter Plane id: ";
    cin >> s; cin.ignore();
    flt->setptn(s);
    cout << "Start time:" << endl;
    timeval = getdatetime();
//cout << "time" << timeval << endl;
    flt->setsttime(timeval);
    cout << "End time:" << endl;
    timeval = getdatetime();
//cout << "time 2" << timeval << endl;
    flt->setendtime(timeval);
    cout << "Enter starting airport: ";
    cin >> s; cin.ignore();
    flt->setsap(s);
    cout << "Enter ending airport: ";
    cin >> s; cin.ignore();
    flt->seteap(s);    
    cout << "Enter distance: ";
    cin >> ui; cin.ignore();
    flt->setdist(ui);
    cout << "Enter number of Passengers: ";
    cin >> ui; cin.ignore();
    flt->setnumpass(ui);
    flt->setstatus(1);
    cout << "how many pilots? ";
    cin >> i; cin.ignore();
    for (int n = 0; n < i; n++)
    {
//        cout << "Enter pilot id: ";
//        cin >> j; cin.ignore();
        j = mycrew.findAvailableCrew(flt->getsttime(), flt->getendtime(), 1); 
 //       cout << "pilot " << j;

        flt->addpilot(n+1, j);
    }
    cout << "how many copilots? ";
    cin >> i; cin.ignore();
    for (int n = 0; n < i; n++)
    {
//        cout << "Enter copilot id: ";
//        cin >> j; cin.ignore();
      j = mycrew.findAvailableCrew(flt->getsttime(), flt->getendtime(), 2);
 //    cout << "copilot " << j;  
      flt->addcopilot(n+1, j);
    }
    cout << "how many cabin crew? ";
    cin >> i; cin.ignore();
    for (int n = 0; n < i; n++)
    {
//        cout << "Enter crew id: ";
//        cin >> j; cin.ignore();
      j = mycrew.findAvailableCrew(flt->getsttime(), flt->getendtime(), 3);
 //    cout << "cabin " << j;  
      flt->addcabin(n+1, j);
    }
    myflights.push_back(*flt);
    inccnt();    
}
  
void flights::DeleteFlight()
{
    int fnum;
    cout << "Flight to Delete? " << endl;
    cin >> fnum; cin.ignore();
    for (auto it = myflights.begin(); it != myflights.end(); it++)
    {
        if (it->getflid() == fnum)
        {
            myflights.erase(it);
            deccnt();
            return;
        }
    }
    cout << "Flight not found" << endl;
    return;
}
 
void flights::EditFlight()
{
    int fnum;
    int choice = -1;
    string s;
    int j,k;
    unsigned int ui;
    time_t timeval;
    
       cout << "Flight to Edit? " << endl;
       cin >> fnum; cin.ignore();
       for (int i = 0; i < count; i++)
       {
           if (myflights[i].getflid() == fnum)
           {
              while (choice != 0)
              {
                  cout << "Edit Flight Menu\n";
                  cout << "0 - quit" << endl;
                  cout << "1 - Change Plane" << endl;
                  cout << "2 - Change starting airport" << endl;
                  cout << "3 - change ending airport" << endl;
                  cout << "4 - change start time" << endl;
                  cout << "5 - change end time" << endl;
                  cout << "6 - change number of passengers" << endl;
                  cout << "7 - add/change a pilot" << endl;
                  cout << "8 - add/change a copilot" << endl;
                  cout << "9 - add/change a cabin crew" << endl;
                  cout << "10 - change distance" << endl;
                  cout << "11 - change flight Status (1-active, 2-cncelled, 3-complete" << endl;
                  cout << "Enter choice: ";
                  cin >> choice; cin.ignore();
                  switch (choice)
                  {
                      case 0: return; break;
                      case 1:
                          cout << "Enter new plane: ";
                          cin >> s; cin.ignore();
                          myflights[i].setptn(s);
                          break;
                      case 2:
                          cout << "Enter new starting airport: ";
                          cin >> s; cin.ignore();
                          myflights[i].setsap(s);
                          break;
                      case 3:
                          cout << "Enter new ending airport: ";
                          cin >> s; cin.ignore();
                          myflights[i].seteap(s);
                          break;
                      case 4:
                          timeval = getdatetime();
                          myflights[i].setsttime(timeval);
                          break;
                      case 5:
                          timeval = getdatetime();
                          myflights[i].setendtime(timeval);
                          break;
                      case 6:
                          cout << "Enter new passenger count: ";
                          cin >> ui; cin.ignore();
                          myflights[i].setnumpass(ui);
                          break;
                      case 7:
                          cout << "Enter new pilot id: ";
                          cin >> j; cin.ignore();
                          cout << "Enter pilot position: ";
                          cin >> k; cin.ignore();
                          myflights[i].addpilot(k,j);
                          break;
                      case 8:
                          cout << "Enter new copilot id: ";
                          cin >> j; cin.ignore();
                          cout << "Enter copilot position: ";
                          cin >> k; cin.ignore();
                          myflights[i].addcopilot(k,j);
                          break;
                      case 9:
                          cout << "Enter new cabin crew id: ";
                          cin >> j; cin.ignore();
                          cout << "Enter crew position: ";
                          cin >> k; cin.ignore();
                          myflights[i].addcabin(k,j);
                          break;
                      case 10:
                          cout << "Enter new pilot id: ";
                          cin >> ui; cin.ignore();
                          myflights[i].setdist(ui);
                          break;
                      case 11:
                          cout << "Enter new status: ";
                          cin >> j; cin.ignore();
                          myflights[i].setstatus(j);
                          break;
                  }
                }
              }
               return;
           }
    cout << "Flight not found" << endl;
       return;
}

  void flights::StoreFlights()
{
    ofstream fout;
    fout.open("flights.dat");
    
    if (!fout.is_open())
    {
     cout << "unable to open flights file" << endl;
     return;
    }
    
    fout << count << endl;
    
    for (int i = 0; i < count; i++)
       {
                  
           fout <<  myflights[i].getflid() << endl;
           fout << myflights[i].getptn() << endl;
           fout  << myflights[i].getsttime() << endl;
           fout << myflights[i].getendtime() << endl;
           fout  << myflights[i].getsap() << endl;
           fout  << myflights[i].geteap() << endl;
           fout << myflights[i].getdist() << endl;
           fout << myflights[i].getnumpass() << endl;
           fout << myflights[i].getstatus() << endl;
           fout << myflights[i].getpilot(1) << " " <<myflights[i].getpilot(2) << endl;
           fout << myflights[i].getcopilot(1) << " " <<myflights[i].getcopilot(2) << endl;
           fout << myflights[i].getcabin(1) << " " <<myflights[i].getcabin(2) << endl;
            fout << myflights[i].getcabin(3) << " " <<myflights[i].getcabin(4) << endl;
            fout << myflights[i].getcabin(5) << " " <<myflights[i].getcabin(6) << endl;
       }
}
  
void flights::LoadFlights()
{
    ifstream fin;
    fin.open("flights.dat");
    
    if (!fin.is_open())
    {
     cout << "unable to open flights file" << endl;
     return;
    }
    
   fin >> count;
    
    for (int i = 0; i < count; i++)
       {
           int j,k;
           string s;
           time_t t;
           unsigned int ui;
           
           myflights.push_back (flight());
           fin >> ui;
           myflights[i].setflid(ui);
           fin >> s;
           myflights[i].setptn(s);
           fin >> t;
           myflights[i].setsttime(t);
           fin >> t;
           myflights[i].setendtime(t);
           fin >> s;
           myflights[i].setsap(s);
           fin >> s;
           myflights[i].seteap(s);
           fin >> j;
           myflights[i].setdist(j);
           fin >> ui;
           myflights[i].setnumpass(ui);
           fin >> j;
           myflights[i].setstatus(j);
           fin >> j >> k;
           myflights[i].addpilot(1,j);
           myflights[i].addpilot(2,k);
           fin >> j >> k;
           myflights[i].addcopilot(1,j);
           myflights[i].addcopilot(2,k);
           fin >> j >> k;
           myflights[i].addcabin(1,j);
           myflights[i].addcabin(2,k);
           fin >> j >> k;
           myflights[i].addcabin(3,j);
           myflights[i].addcabin(4,k);
           fin >> j >> k;
           myflights[i].addcabin(5,j);
           myflights[i].addcabin(6,k);
       }
}
  
int flights::FindFlight(unsigned int fnum)
{

    
    for (int i = 0; i < count; i++)
    {
        if (myflights[i].getflid() == fnum)
        {
           return i;
        }
    }
    cout << "Flight not found" << endl;
    return -1;
}
  
void flights::PrintaFlight(unsigned int fnum)
{
        
    for (int i = 0; i < count; i++)
    {
        if (myflights[i].getflid() == fnum)
        {
        cout << "Flight Information for flight " <<fnum << endl;
       
        cout << "Plane number: " << myflights[i].getptn() << endl;
          
        struct tm* mytm1;
        struct tm* mytm2;
        time_t tm1, tm2;
        
        tm1 = myflights[i].getsttime();
        mytm1 = gmtime(&tm1);
        cout << "Start time: " << asctime(mytm1) << endl;

        tm2 = myflights[i].getendtime();
        mytm2 = gmtime(&tm2);
            
        cout << "End Time: " << asctime(mytm2) << endl;
            
        cout << "Starting Airport: " << myflights[i].getsap() << endl;
        cout << "Ending Airport: " << myflights[i].geteap() << endl;
            cout << "distance: " << myflights[i].getdist() << endl;
            cout << "Number of passengers: " << myflights[i].getnumpass() << endl;
        cout << endl;
        return;
        }
    }
}
  
void flights::PrintAllFlights()
{
    for (int i = 0; i < count; i++)
    {
        cout << "Flight Schedule for All Plane: " << endl;
       
        cout << "Flight number: " << myflights[i].getflid() << endl;
        cout << "Plane number: " << myflights[i].getptn() << endl;
          
        struct tm* mytm1;
        struct tm* mytm2;
        time_t tm1, tm2;
        
        tm1 = myflights[i].getsttime();
        mytm1 = gmtime(&tm1);
        cout << "Start time: " << asctime(mytm1) << endl;

        tm2 = myflights[i].getendtime();
        mytm2 = gmtime(&tm2);
            
        cout << "End Time: " << asctime(mytm2) << endl;
        cout << "Starting Airport: " << myflights[i].getsap() << endl;
        cout << "Ending Airport: " << myflights[i].geteap() << endl;
        cout << endl;
        
    }
}

  
void flights::PrintPlanSched(string tn)
{
  
    
    for (int i = 0; i < count; i++)
    {
        cout << "Flight Schedule for Plane: " << tn << endl;
        if (myflights[i].getptn() == tn)
        {
            cout << "Flight number: " << myflights[i].getflid() << endl;
          
            struct tm* mytm1;
            struct tm* mytm2;
            time_t tm1, tm2;
            
            tm1 = myflights[i].getsttime();
            mytm1 = gmtime(&tm1);
            cout << "Start time: " << asctime(mytm1) << endl;

            tm2 = myflights[i].getendtime();
            mytm2 = gmtime(&tm2);
                
            cout << "End Time: " << asctime(mytm2) << endl;
            
            cout << "Starting Airport: " << myflights[i].getsap() << endl;
            cout << "Ending Airport: " << myflights[i].geteap() << endl;
            cout << endl;
        }
    }
}
  
void flights::PrintCrewSched(int id)
{
       
       for (int i = 0; i < count; i++)
       {
           cout << "Flight Schedule for crew member: " << id << endl;
           if (myflights[i].getpilot(1) == id ||
               myflights[i].getpilot(2) == id ||
               myflights[i].getcopilot(1) == id ||
               myflights[i].getcopilot(2) == id ||
               myflights[i].getcabin(1) == id ||
               myflights[i].getcabin(2) == id ||
               myflights[i].getcabin(3) == id ||
               myflights[i].getcabin(4) == id ||
               myflights[i].getcabin(5) == id ||
               myflights[i].getcabin(6) == id
               )
           {
               cout << "Flight number: " << myflights[i].getflid() << endl;
             
             struct tm* mytm1;
              struct tm* mytm2;
              time_t tm1, tm2;
              
              tm1 = myflights[i].getsttime();
              mytm1 = gmtime(&tm1);
              cout << "Start time: " << asctime(mytm1) << endl;

              tm2 = myflights[i].getendtime();
              mytm2 = gmtime(&tm2);
                  
              cout << "End Time: " << asctime(mytm2) << endl;
               
               cout << "Starting Airport: " << myflights[i].getsap() << endl;
               cout << "Ending Airport: " << myflights[i].geteap() << endl;
               cout << endl;
           }
       }
}

  
void flights::Cleanup()
{
    for (auto it = myflights.begin(); it != myflights.end(); it++)
    {
        if (it->getstatus() == 2 || it->getstatus() == 3)
            myflights.erase(it);
    }
}

  
void flights::UpdateFlights()
{
    time_t currtime;
    currtime = time(NULL);
    
    for (int i = 0; i < count; i++)
    {
        if (myflights[i].getendtime() < currtime)
            myflights[i].setstatus(3);
    }
}

  
bool flights::IsPlaneAvail(string pt, time_t st, time_t end)
{
    bool stat = 1;
    for (int i = 0; i < count; i++)
    {
      if (myflights[i].getptn() == pt)
      {
        if (st >= myflights[i].getsttime() || end <= myflights[i].getendtime())
        { 
         stat = 0;
        return stat;
        }
 
      }
    }
return stat;
}
  
bool flights::IsCrewAvail (int id, time_t st, time_t end)
{
    bool stat = 1;
    for (int i=0; i < count; i++)
    {
      if ( id == myflights[i].getpilot(1) || id == myflights[i].getpilot(2) ||
           id == myflights[i].getcopilot(1) || id == myflights[i].getcopilot(2) ||
           id == myflights[i].getcabin(1) || id == myflights[i].getcabin(2) ||
           id == myflights[i].getcabin(3) || id == myflights[i].getcabin(4) ||
           id == myflights[i].getcabin(5) || id == myflights[i].getcabin(6) )
      {
        if ((st <= myflights[i].getendtime()&& st >= myflights[i].getsttime())
            || (  end <= myflights[i].getendtime() && end >= myflights[i].getsttime()) )
        {
          stat = 0;
          return stat;
        }
      }
    }
return stat;
}
  

time_t flights::getdatetime()
{
 time_t rawtime, newtime;
 struct tm * timeinfo;
 int year, month ,day;
 int hour, minute;
   
   cout << "Enter year: "; cin >> year; cin.ignore();
   cout << "Enter month: "; cin >> month; cin.ignore();
   cout << "Enter day: "; cin >> day; cin.ignore();
   cout << "Enter hour (0-23): "; cin >> hour; cin.ignore();
   cout << "Enter minute (0-59): "; cin >> minute; cin.ignore();

 /* get current timeinfo and modify it to the user's choice */
 time ( &rawtime );
 timeinfo = gmtime ( &rawtime );
 timeinfo->tm_year = year - 1900;
 timeinfo->tm_mon = month - 1;
 timeinfo->tm_mday = day;
 timeinfo->tm_hour = hour;
 timeinfo->tm_min = minute;
 timeinfo->tm_sec = 0;

 /* call mktime: timeinfo->tm_wday will be set */
 newtime = mktime ( timeinfo );
 return newtime;
 

}
