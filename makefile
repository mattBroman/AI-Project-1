CXX = g++
DEBUG = 
OPTIMIZE = -03
TARGET = Blocks

$(TARGET): main.o Blocks.o
	$(CXX) -o $(TARGET) main.o Blocks.o

main.o: main.cpp
	$(CXX) $(DEBUG) -c main.cpp

Blocks.o: Blocks.cpp
	$(CXX) $(DEBUG) -c Blocks.cpp

clean :
	rm *.o