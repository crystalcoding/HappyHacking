all: app.o dialog.o
	g++ app.o dialog.o `wx-config --cxxflags`  `wx-config --libs` 

app.o: app.h app.cpp
	g++ `wx-config --cxxflags` app.h app.cpp -c

dialog.o: dialog.cpp dialog.h
	g++ `wx-config --cxxflags` dialog.h dialog.cpp -c 