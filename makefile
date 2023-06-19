main: Graph.o main.o
	g++ Graph.o main.o -o generate
	
Graph.o:
	g++ -c Graph.cpp
	
main.o:
	g++ -c main.cpp
	
clean:
	-del *.o main -del generate.exe