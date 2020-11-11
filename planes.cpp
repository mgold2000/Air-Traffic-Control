//planes.cpp

#include <iostream>
#include <string>
#include <cstdlib>
#include  <vector>
#include <time.h>
#include <fstream>
#include <iterator>

using namespace std;

#include "plane.h"
#include "flight.h"
#include "planes.h"
#include "flights.h"

extern flights myflts;

Planes::Planes() {planecnt = 0;}

unsigned int Planes::getCount() {return planecnt;}

void Planes :: addCount() {planecnt += 1;}

void Planes:: minusCount() { 
  if (planecnt < 1)
  {
   cout << "No Planes to remove " << endl;
   return; 
  }
 planecnt -= 1; 
}

void Planes::addPlane ()
{
  string a,b,c;
  unsigned int x,y,z;
    Plane *tempobj;

  cout << "What is the new tail number?: ";
  cin >> a; cin.ignore();
  cout << "Plane make?: ";
  cin >> b; cin.ignore();
  cout << "Plane model?: ";
  cin >> c; cin.ignore();
  cout << "Number of seats?: ";
  cin >> x; cin.ignore();
  cout << "Range?: ";
  cin >> y; cin.ignore();
  cout << "Min number of Cabin Crew?: ";
  cin >> z; cin.ignore();

  tempobj = new Plane(b,c,a,x,y,z);
  Fleet.push_back(*tempobj);
  addCount();
}

void Planes::deletePlane ()
{
  string tn;
  cout << "What Tail number to delete?: ";
  cin >> tn; cin.ignore();

  for (auto it = Fleet.begin(); it != Fleet.end(); it++)
  {
    if (it->getTailNum() == tn)
    {
     Fleet.erase(it);
     minusCount();
     return;
    }
  }
  cout << "Identified Tail Number did not exist" << endl;
}

void Planes::printAllPlanes()
{
   for (auto it = Fleet.begin(); it != Fleet.end(); it++)
   {
    it->printInfo();
    cout<<endl;
   }
}

Plane* Planes::findPlane()
{
   Plane tplane;
   string tnum;
   cout << "Tail Number of Plane to locate: "<<endl;
   cin >> tnum; cin.ignore();

   for (int i = 0;  i < planecnt; i++)
  {
    if (Fleet[i].getTailNum() == tnum)
   {
     return (&(Fleet[i]));
   }
  }
  cout << "That tail number not found" << endl;
  return NULL;

}

void Planes::editPlane ()
{
   Plane* tplane = findPlane();
   unsigned int ns, nc;

   if (tplane == NULL) 
   {
     return;
   }

   cout << "Enter new seat quantity: ";
   cin >> ns; cin.ignore();
   tplane->setSeats(ns);
   cout << "Enter new Cabin Crew Quantity: ";
   cin >> nc; cin.ignore();
   tplane->setNumCabin(nc);

}

string Planes::findAvailablePlane (time_t st, time_t end) 
{
  string j;
  for (int i = 0; i < planecnt; i++)
  {
   if (myflts.IsPlaneAvail(Fleet[i].getTailNum(), st, end))
    return Fleet[i].getTailNum();
  }
return NULL;
}

void Planes::storePlanes()
{
  ofstream fout;
  fout.open("Planes.dat");
  if (!fout.is_open()) 
  {
   cout << "unable to open file" << endl;
   return;
  }
  
  fout << planecnt << endl;
  for (auto it = Fleet.begin(); it != Fleet.end(); it++)
  {
    fout << it->getTailNum() << " " << it->getMake() << " " << it->getModel();
    fout << " " << it->getSeats() << " " << it->getRange();
    fout << " " << it->getNumCabin() << endl;
  }
  fout.close();

}

void Planes::loadPlanes()
{
  unsigned int s, r,nc;
  string mk, md,tn;

  ifstream fin;
 fin.open("Planes.dat");
 if (!fin.is_open())
 {
  cout << "Unable to open input file "<<endl;
  return;
 }
 fin >>planecnt;fin.ignore();
 for (int i = 0; i < planecnt; i++)
  {
   fin >> tn >> mk >> md >> s >> r >> nc;
   fin.ignore();
   Fleet.push_back( Plane ( tn , mk, md, s, r, nc));
  }
 fin.close();
}
