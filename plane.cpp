//plane.cpp

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

#include "plane.h"

Plane::Plane() {
  make = model = tailNum = "";
  seats = range = numCabin = 0;
}

Plane::Plane(string mk,string md,string tn,unsigned int ns,unsigned int r,unsigned int mc) {
  make = mk;
  model = md;
  tailNum = tn;
  seats = ns;
  range = r;
  numCabin = mc;
}

string Plane::getMake() {return make;}
string Plane::getModel() {return model;}
string Plane::getTailNum() {return tailNum;}
unsigned int Plane::getSeats() {return seats;}
unsigned int Plane::getRange() {return range;}
unsigned int Plane::getNumCabin() {return numCabin;}

Plane::~Plane() {}

void Plane::setMake (string x) {make = x;}
void Plane::setModel (string x) {model = x;}
void Plane::setTailNum(string x) {tailNum = x;}
void Plane::setSeats(unsigned int n) {seats = n;}
void Plane::setRange(unsigned int n) {range = n;}
void Plane::setNumCabin(unsigned int n) {numCabin = n;}

void Plane::printInfo() {
  cout << "Plane Info" <<endl;
  cout << "Make: " << make << " Model: " << model <<endl;
  cout << "Tail Number: " << tailNum << " Number of Seats: "<< seats << endl;
  cout << "Range: " << range << " Min Cabin Crew: " << numCabin << endl;
}
  
