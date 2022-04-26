lab3: recordParser
	cd src && ./recordParser ../data/test.csv

recordParser: src/main.o src/college_structs.o src/college.o src/college_recordParser.o
	g++ -o src/recordParser src/main.o src/college_structs.o src/college.o src/college_recordParser.o

main.o: src/main.cpp
	g++ -c src/main.cpp

college_structs.o: src/college_structs.cpp src/college_structs.h
	g++ -c src/college_structs.cpp

college_recordParser.o: src/college_recordParser.cpp src/college.h
	g++ -c src/college_recordParser.cpp

college.o: src/college.cpp src/college.h
	g++ -c src/college.cpp

clean:
	rm src/*.o src/recordParser
