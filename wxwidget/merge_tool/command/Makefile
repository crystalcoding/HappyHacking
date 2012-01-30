all: app.o dialog.o
	g++ app.o dialog.o `wxgtk2-2.6-config --cxxflags`  `wxgtk2-2.6-config --libs` 

app.o: app.h app.cpp
	g++ `wxgtk2-2.6-config --cxxflags` app.h app.cpp -c

dialog.o: dialog.cpp dialog.h
	g++ `wxgtk2-2.6-config --cxxflags` dialog.h dialog.cpp -c 