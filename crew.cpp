#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

#include "crew.h"

Crew::Crew() {
  name = "";
  id =0;
  type = 0;
}

Crew::Crew (string n, unsigned int i, int t) {
   name = n;
   id = i;
   type = t;
}

string Crew::getName() {return name;}

unsigned int Crew::getID() {return id;}

int Crew::getType() {return type;}

void Crew::setName (string n) {name = n;}

void Crew::setID (unsigned int num) {id = num;}

void Crew::setType(int t) {type = t;}

void Crew::printInfo() {
  cout << "Crew ID: " << id << endl;
  cout << "Crew Name: " << name << endl;
  cout << "Crew Type: " << type << endl;
}
