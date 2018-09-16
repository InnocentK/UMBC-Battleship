CXX = g++
CXXFLAGS = -g

proj4: Grid.o Player.o User.o Computer.o test_main.cpp
	$(CXX) $(CXXFLAGS) Grid.o Player.o User.o Computer.o test_main.cpp -o proj4

Computer.o: Computer.h Computer.cpp Player.o Grid.o
	$(CXX) $(CXXFLAGS) -c Computer.cpp

User.o: User.h User.cpp Player.o Grid.o
	$(CXX) $(CXXFLAGS) -c User.cpp

Player.o: Player.h Player.cpp Grid.o
	$(CXX) $(CXXFLAGS) -c Player.cpp

Grid.o: Grid.h Grid.cpp
	$(CXX) $(CXXFLAGS) -c Grid.cpp

clean:
	rm *.o*
	rm *~

run:
	./proj4

run1:
	./proj4 p4_user1.txt p4_comp1.txt

run2:
	./proj4 p4_user2.txt p4_comp2.txt

run3:
	./proj4 p4_user3.txt p4_comp3.txt

val1:
	valgrind ./proj4 p4_user1.txt p4_comp1.txt

val2:
	valgrind ./proj4 p4_user2.txt p4_comp2.txt

val3:
	valgrind ./proj4 p4_user3.txt p4_comp3.txt