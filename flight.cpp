//flight.cpp
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
using namespace std;
#include "flight.h"


  flight::flight()
{
flid = distance = npass = status = 0;
sacode = eacode = ptn = " ";
starttime = endtime = 0;
pilots[0] = pilots[1] = 0;
copilots[0] = copilots[1] = 0;
for (int i = 0; i < 6; i++)
    cabincrew[i] = 0;
}


  flight::flight( int f, string t, time_t st, time_t et, string sc, string ec, unsigned int d, unsigned int n, int stat)
{
    flid=f;
    ptn = t;
    starttime = st;
    endtime = et;
    sacode = sc;
    eacode = ec;
    distance = d;
    npass = n;
    status = stat;
    pilots[0] = pilots[1] = 0;
    copilots[0] = copilots[1] = 0;
    for (int i = 0; i < 6; i++)
        cabincrew[i] = 0;
}

void flight::setflid(unsigned int f) {flid = f;}
void flight::setptn(string t) {ptn = t;}
void flight::setsttime(time_t st) {starttime = st;}
void flight::setendtime(time_t et) {endtime = et;}
void flight::setsap(string sc) {sacode = sc;}
void flight::seteap(string ec) {eacode = ec;}
void flight::setdist(unsigned int d) {distance = d;}
void flight::setnumpass(unsigned int p){npass = p;}
void flight::setstatus(int s) {status = s;}

unsigned int flight::getflid() {return flid;}
string flight::getptn() {return ptn;}
time_t flight::getsttime() { return starttime;}
time_t flight::getendtime() { return endtime;}
string flight::getsap() {return sacode;}
string flight::geteap() {return eacode;}
unsigned int flight::getdist() {return distance;}
unsigned int flight::getstatus() {return status;}
unsigned int flight::getnumpass() {return npass; }

void flight::addpilot(int n, int pid)
{
    if (n <= 2 and n > 0) pilots[n-1] = pid;
}

void flight::addcopilot(int n, int cpid)
{
    if (n <= 2 and n > 0) copilots[n-1] = cpid;
}
  void flight::addcabin(int n, int cab)
{
    if (n <= 6 and n > 0) cabincrew[n-1] = cab;
}

int flight::getpilot(int n) {return pilots[n-1];}
int flight::getcopilot(int n) {return copilots[n-1];}
int flight::getcabin(int n) {return cabincrew[n-1];}

  void flight::printinfo()
{
    struct tm* mytm1;
    struct tm* mytm2;
    mytm1 = gmtime( &starttime);
    mytm2 = gmtime( &endtime);
    
    cout << "Flight Information" << endl;
    cout << "Flight number: " << flid << endl;
    cout << "Plane Tail Number" << ptn << endl;
    cout << "Start time: " << asctime(mytm1) << endl;
    cout << "End Time: " << asctime(mytm2) << endl;
    cout << "Starting Airport: " << sacode << endl;
    cout << "Ending Airport: " << eacode << endl;
    cout << "Flight Distance: " << distance << endl;
    cout << "Number of Passengers: " << npass << endl;
    cout << "Flight Status (1 = active, 2 = cancelled, 3 = complete): " << status << endl;
}

