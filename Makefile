CPPFLAGS = -std=c++98

lab1: lab1_src/data_parser.o
	g++ lab1_src/data_parser.o -o lab1_src/data_parser
	#cd lab1_src
	#./data_parser
	#xdg-open lab1_src/data_analysis.txt

data_parser.o: lab1_src/data_parser.cpp
	g++ -c lab1_src/data_parser.cpp

clean:
	rm lab1_src/*.o lab1_src/data_parser
