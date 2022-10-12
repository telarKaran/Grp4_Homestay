OBJS1=hotel.o
OBJS2=bookings.o 
OBJS3=rooms.o 
OBJS4=customer.o 
OBJS5=mainMenu.o
INC=../header
IFLAGS=-I $(INC)
BIN=../bin
SRC=../SRC
CFLAGS=-c -g Wall
GCC =g++ 
CFLAGS=-c 
LFLAGS=-o
RM=rm 
all: $(OBJS1) $(OBJS2) $(OBJS3) $(OBJS4) $(OBJS5) $(OBJS6)
	$(GCC) $(LFLAGS)  $(BIN)/app $(BIN)/$(OBJS1)  $(BIN)/$(OBJS2) $(BIN)/$(OBJS3) $(BIN)/$(OBJS4) $(BIN)/$(OBJS5)
hotel.o:$(SRC)/hotel.cpp
	$(GCC)  $(LFLAGS) $(BIN)/$(OBJS1) $(CFLAGS) $(SRC)/hotel.cpp $(IFLAGS)
bookings.o:$(SRC)/bookings.cpp
	$(GCC)  $(LFLAGS) $(BIN)/$(OBJS2) $(CFLAGS) $(SRC)/bookings.cpp $(IFLAGS)
rooms.o:$(SRC)/rooms.cpp
	$(GCC)  $(LFLAGS) $(BIN)/$(OBJS3) $(CFLAGS) $(SRC)/rooms.cpp $(IFLAGS)
customer.o:$(SRC)/customer.cpp
	$(GCC)   $(LFLAGS) $(BIN)/$(OBJS4) $(CFLAGS)  $(SRC)/customer.cpp $(IFLAGS)
mainMenu.o:$(SRC)/mainMenu.cpp
	$(GCC)  $(LFLAGS) $(BIN)/$(OBJS5) $(CFLAGS) $(SRC)/mainMenu.cpp $(IFLAGS)
clean:
	$(RM) $(BIN)/*.exe $(BIN)/*.o
 
