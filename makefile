CXX = g++
DEBUG = -g
OPTIMIZE = -03
TARGET = search

$(TARGET): main.o Blocks.o StateTree.o Node.o
	$(CXX) -o $(TARGET) main.o Blocks.o StateTree.o Node.o

main.o: main.cpp
	$(CXX) $(DEBUG) -c main.cpp

Blocks.o: Blocks.cpp
	$(CXX) $(DEBUG) -c Blocks.cpp

Node.o: Node.cpp
	$(CXX) $(DEBUG) -c Node.cpp

StateTree.o: StateTree.cpp
	$(CXX) $(DEBUG) -c StateTree.cpp

clean :
	rm *.o