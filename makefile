350compiler: 350compiler.o
	g++ -o 350compiler 350compiler.o

350compiler.o: 350compiler.cpp
	g++ -c 350compiler.cpp

clean:
	$(RM) 350compiler



