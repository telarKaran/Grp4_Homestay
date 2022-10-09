TestBookings: testBookings.o
	g++ -g -o TestBookings testBookings.o -lcppunit

testBookings: testBookings.cpp Bookings.h
	g++ -g -c testBookings.cpp -lcppunit

clean:
	echo : "clean"
	rm testBookings.o TestBookings