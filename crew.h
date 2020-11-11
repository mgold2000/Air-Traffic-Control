enum crewtype {Pilot, CoPilot, Cabin};

class Crew {
	private:
		string name;
		unsigned int id;
		int type;
	public:
		Crew();
		Crew(string, unsigned int, int);
		string getName();
		unsigned int getID();
		int getType();
		void setName(string);
		void setID(unsigned int);
		void setType(int);
		void printInfo();
};
