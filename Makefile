FLAGS = -g -fPIC -c --std=c++17

all:
	mkdir -p bin
	g++ $(FLAGS) main.cpp -o bin/main.o
	g++ -g -o bin/run bin/main.o 


test:
	    mkdir -p obj
		g++ $(FLAGS) src/product.cpp -o obj/product.o
		g++ $(FLAGS) src/store.cpp -o obj/store.o
		g++ $(FLAGS) tests/tests_product.cpp -o obj/tests_product.o
		g++ $(FLAGS) tests/tests_store.cpp -o obj/tests_store.o
		g++ -g -o obj/tests obj/product.o obj/store.o obj/tests_product.o obj/tests_store.o -lgtest -lgtest_main -lpthread 
clean:
	rm -Rf bin
	rm -Rf obj