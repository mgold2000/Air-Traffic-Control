//flights.h


class flights
{
  private:

  unsigned int count;
  vector <flight> myflights;

  public:

  flights();

  unsigned int getcount();
  void inccnt();
  void deccnt();

  void AddFlight();
  void DeleteFlight();
  void EditFlight();
  void StoreFlights();
  void LoadFlights();
  int FindFlight(unsigned int);
  void PrintaFlight(unsigned int);
  void PrintAllFlights();

  void PrintPlanSched(string);
  void PrintCrewSched(int);

  void Cleanup();

  void UpdateFlights();

  bool IsPlaneAvail(string, time_t, time_t);
  bool IsCrewAvail (int, time_t, time_t);
    
  time_t getdatetime();
  
};
