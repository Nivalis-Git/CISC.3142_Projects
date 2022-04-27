lab3: dataParser
	cd src && ./dataParser ../data/1115.csv ../data/3115.csv ../data/3130.csv

dataParser: src/main.o src/college_structs.o src/college.o src/college_fileParser.o
	g++ -o src/dataParser src/main.o src/college_structs.o src/college.o src/college_fileParser.o

main.o: src/main.cpp
	g++ -c src/main.cpp

college_structs.o: src/college_structs.cpp src/college_structs.h
	g++ -c src/college_structs.cpp

college_fileParser.o: src/college_fileParser.cpp src/college.h
	g++ -c src/college_fileParser.cpp

college.o: src/college.cpp src/college.h
	g++ -c src/college.cpp

clean:
	rm src/*.o src/dataParser
