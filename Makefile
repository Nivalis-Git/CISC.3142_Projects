lab1: lab1_src/data_parser.o
	g++ lab1_src/data_parser.o -o lab1_src/data_parser
	#cd lab1_src
	#./data_parser
	#xdg-open lab1_src/data_analysis.txt

main.o: lab2_src/main.cpp
	g++ -c lab1_src/main.cpp

calc.o: lab2_src/calc.cpp lab2_src/calc.h

clean:
	rm lab1_src/*.o lab1_src/data_parser
