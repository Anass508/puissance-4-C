all: puissance_4

fonction.o: fonction.c fonction.h
	gcc -c fonction.c -o fonction.o

puissance_4.o: puissance_4.c fonction.c fonction.h
	gcc -c puissance_4.c -o puissance_4.o

puissance_4: puissance_4.o fonction.o 
	gcc -o puissance_4 fonction.o puissance_4.o
clean:
	rm -f puissance_4 *.o *~

mrproper: clean
	rm -f puissance_4
