all: hotel.o bookings.o rooms.o customer.o mainMenu.o
	g++ -o ./bin/app ./bin/hotel.o ./bin/bookings.o ./bin/rooms.o ./bin/customer.o ./bin/mainMenu.o
hotel.o:./src/hotel.cpp
	g++ -o ./bin/hotel.o -c ./src/hotel.cpp
bookings.o:./src/bookings.cpp
	g++ -o ./bin/bookings.o -c ./src/bookings.cpp
rooms.o:./src/rooms.cpp
	g++ -o ./bin/rooms.o -c ./src/rooms.cpp
customer.o:./src/customer.cpp
	g++ -o ./bin/customer.o -c ./src/customer.cpp
mainMenu.o:./src/mainMenu.cpp
	g++ -o ./bin/mainMenu.o -c ./src/mainMenu.cpp
clean:
	./bin/*.exe ./bin/*.o
 
