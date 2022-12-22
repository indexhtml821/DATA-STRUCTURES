FLAGS = -g -fPIC -c --std=c++17

all:
	mkdir -p bin
	g++ $(FLAGS) main.cpp -o bin/main.o
	g++ -g -o bin/run bin/main.o 

clean:
	rm -Rf bin
	rm -Rf obj
