vektoriai: vektoriai.o funkcijos.o
	g++ vektoriai.o funkcijos.o -o vektoriai
	rm -f vektoriai.o funkcijos.o

vektoriai.o: vektoriai.cpp
	g++ -c vektoriai.cpp -o vektoriai.o

funkcijos.o: funkcijos.cpp
	g++ -c funkcijos.cpp -o funkcijos.o