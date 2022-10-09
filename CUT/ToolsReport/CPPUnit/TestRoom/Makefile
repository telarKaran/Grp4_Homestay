TestRoom: testRoom.o rooms.o
	g++ -g -o TestRoom testroom.o rooms.o -lcppunit

testRoom.o: testRoom.cpp rooms.h
	g++ -g -c testRoom.cpp -lcppunit

rooms: rooms.cpp rooms.h
	g++ -g -c rooms.cpp

clean:
	echo : "clean" 
	rm rooms.o testRoom.o TestRoom