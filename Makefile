vektoriai: vektoriai.o funkcijos.o utils.o
	g++ vektoriai.o funkcijos.o utils.o -o vektoriai
	rm -f vektoriai.o funkcijos.o utils.o

vektoriai.o: vektoriai.cpp
	g++ -c vektoriai.cpp -o vektoriai.o

funkcijos.o: funkcijos.cpp
	g++ -c funkcijos.cpp -o funkcijos.o

utils.o: utils.cpp
	g++ -c utils.cpp -o utils.o