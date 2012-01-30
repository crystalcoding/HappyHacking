rundate: main.o mydate.o
	g++ -g mydate.o main.o -o rundate

main.o: main.cc
	g++ -g -c main.cc

mydate.o: mydate.cc mydate.h
	g++ -g -c mydate.h mydate.cc 

clean:
	rm mydate.o main.o


