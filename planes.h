//planes.h

class Planes {
	private:
		unsigned int planecnt;
		vector <Plane> Fleet;
	public:
		Planes();
		void addPlane();
		void deletePlane();
		Plane* findPlane();
		void editPlane();
		void storePlanes();
		void loadPlanes();
		void printAllPlanes();
		void addCount();
		void minusCount();
		unsigned int getCount(); 
		string findAvailablePlane(time_t st, time_t end);
};
