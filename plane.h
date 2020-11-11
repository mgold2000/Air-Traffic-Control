//plane.h
class Plane {
	private:
		string make, model, tailNum;
		unsigned int seats, range, numCabin;
	public:
		Plane();
		Plane(string, string, string, 
				unsigned int, unsigned int, unsigned int);
		void setMake (string);
		void setModel (string);
		void setTailNum (string);
		void setSeats (unsigned int);
		void setRange(unsigned int);
		void setNumCabin(unsigned int);
		string getMake ();
		string getModel();
		string getTailNum();
		unsigned int getSeats();
		unsigned int getRange();
		unsigned int getNumCabin();
		void printInfo();
		~Plane();
};
