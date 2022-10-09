Test: testApp.o rooms.o
	g++ -g -o Test testApp.o rooms.o -lcppunit

testApp: testApp.cpp rooms.h Bookings.h
	g++ -g -c testApp.cpp -lcppunit

rooms: rooms.cpp rooms.h
	g++ -g -c rooms.cpp 

clean: 
	echo "clean"
	rm rooms.o testApp.o Test
