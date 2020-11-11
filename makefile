sum: main.o crew.o crews.o flight.o flights.o plane.o planes.o
	g++ -o sum main.o crew.o crews.o flight.o flights.o plane.o planes.o
main.o: crew.h crews.h flight.h flights.h plane.h planes.h crew.cpp crews.cpp flight.cpp flights.cpp plane.cpp planes.cpp
	g++ -c main.cpp
crew.o: crew.h
	g++ -c crew.cpp
crews.o: crew.h crews.h flight.h flights.h crew.cpp flight.cpp flights.cpp
	g++ -c crews.cpp
flight.o: flight.h
	g++ -c flight.cpp
flights.o: crew.h crews.h plane.h planes.h flight.h flights.h crew.cpp crews.cpp plane.cpp planes.cpp flight.cpp
	g++ -c flights.cpp
plane.o: plane.h
	g++ -c plane.cpp
planes.o: plane.h planes.h flight.h flights.h plane.cpp flight.cpp flights.cpp
	g++ -c planes.cpp
clean:
	rm *.o sum
run:
	./out
