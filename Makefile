lab2: calculator
	cd lab2_src && ./calculator

calculator: lab2_src/main.o lab2_src/prefix.o
	g++ -o lab2_src/calculator lab2_src/main.o lab2_src/prefix.o

main.o: lab2_src/main.cpp
	g++ -c lab2_src/main.cpp

prefix.o: lab2_src/prefix.cpp lab2_src/prefix.h
	g++ -c lab2_src/prefix.cpp

clean:
	rm lab2_src/*.o lab2_src/calculator
