//flight.h

class flight
{
  private:

  unsigned int flid;
  string ptn;
  int pilots[2];
  int copilots[2];
  int cabincrew[6];
  time_t starttime;
  time_t endtime;
  string sacode, eacode;
  unsigned int distance;
  unsigned int npass;
  int status;

  public:

  flight();
  flight( int, string, time_t, time_t, string, string, unsigned int, unsigned int, int);

  void setflid(unsigned int);
  void setptn(string);
  void setsttime(time_t);
  void setendtime(time_t);
  void setsap(string);
  void seteap(string);
  void setdist(unsigned int);
  void setnumpass(unsigned int);
  void setstatus(int);

  unsigned int getflid();
  string getptn();
  time_t getsttime();
  time_t getendtime();
  string getsap();
  string geteap();
  unsigned int getdist();
  unsigned int getnumpass();
  unsigned int getstatus();

  void addpilot(int, int);
  void addcopilot (int, int);
  void addcabin(int, int);

  int getpilot(int);
  int getcopilot(int);
  int getcabin(int);

  void printinfo();

};
