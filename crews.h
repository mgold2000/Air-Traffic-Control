class Crews {
	private:
		unsigned int count;
		vector <Crew> staff;
	public:
		Crews();
		void addCrew();
		void editCrew();
		Crew*  findCrew();
		void deleteCrew();
		unsigned int getCount();
		void addCount();
		void minusCount();
		void printAllCrew();
		void loadCrew();
		void storeCrew();
		int findAvailableCrew(time_t, time_t, int);
};

