//crews.cpp

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <time.h>
#include <fstream>

using namespace std;

#include "crew.h"
#include "crews.h"
#include "flight.h"
#include "flights.h"

extern flights myflts;

Crews::Crews() {
	count = 0;
}

unsigned int Crews::getCount() {return count;}
void Crews::addCount() { count++;}
void Crews::minusCount() {if (count != 0) count--;}


void Crews::addCrew() {
	string a;
	unsigned int b;
	int ty;
	Crew* tempobj;

	cout << "What is the new crew member name?: ";
	cin >> a; cin.ignore();
	cout << "Crew ID?: ";
	cin >> b; cin.ignore();
	cout << "Crew type? (1 = Pilot, 2 = copilot, 3 = Cabin): ";
	cin >> ty; cin.ignore();

	tempobj = new Crew(a,b,ty);
	staff.push_back(*tempobj);
	addCount();
}

void Crews::deleteCrew() {
	unsigned int id;
	cout << "What ID?: ";
	cin >> id; cin.ignore();

	for (auto it = staff.begin(); it != staff.end(); it++) {
		if (it->getID() == id) {
			staff.erase(it);
			minusCount();
			return;
		}
	}
	cout << "Identified crew ID did not exist" << endl;
}

void Crews::printAllCrew() {
	for (auto it = staff.begin(); it != staff.end(); it++) {
		it->printInfo();
		cout << endl;
	}
}

Crew* Crews::findCrew() {
	Crew tCrew;
	unsigned int id;;
	cout << "ID of Crew to locate: "<<endl;
	cin >> id; cin.ignore();

	for (int i = 0;  i < count; i++) {
		if (staff[i].getID() == id) {
			return (&(staff[i]));
		}
	}
	cout << "That ID number not found" << endl;
	return NULL;
}

void Crews::editCrew() {
	Crew* tCrew = findCrew();
	int ns;

	if (tCrew == NULL) {
		return;
	}

	cout << "Enter new type(1 = Pilot, 2 = copilot, 3 = Cabin): ";
	cin >> ns; cin.ignore();
	tCrew->setType(ns);
}

int Crews::findAvailableCrew(time_t st, time_t end, int t)  {
	for (int i = 0; i < count; i++) {
		if (staff[i].getType() == t) {
			if (myflts.IsCrewAvail(staff[i].getID(), st, end) == 1)
				return staff[i].getID();
		}
	}
	return 0;
}

void Crews::storeCrew() {
	ofstream fout;
	fout.open("Crews.dat");
	if (!fout.is_open()) {
		cout << "unable to open file" << endl;
		return;
	}

	fout << count << endl;
	for (auto it = staff.begin(); it != staff.end(); it++) {
		fout << it->getID() << " " << it->getName() << " " 
			<< it->getType() << endl;
	}
	fout.close();
}

void Crews::loadCrew() {
	unsigned int id;
	int t;
	string nm;

	ifstream fin;
	fin.open("Crews.dat");
	if (!fin.is_open()) {
		cout << "Unable to open input file "<<endl;
		return;
	}
	fin >> count; fin.ignore();
	for (int i = 0; i < count; i++) {
		fin >> id >> nm >> t;
		fin.ignore();
		staff.push_back(Crew (nm, id, t));
	}
	fin.close();
}
