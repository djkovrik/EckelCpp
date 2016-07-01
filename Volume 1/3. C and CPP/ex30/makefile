CPP = g++
OFLAG = -o

.SUFFIXES:	.o .cpp
.cpp.o:
	$(CPP) $(CPPFLAGS) -c $<

all: \
	YourPets1 \
	YourPets2

YourPets1: YourPets1.o
	$(CPP) $(OFLAG) YourPets1 YourPets1.o

YourPets2: YourPets2.o
	$(CPP) $(OFLAG) YourPets2 YourPets2.o

YourPets1.o: YourPets1.cpp
YourPets2.o: YourPets2.cpp