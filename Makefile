all: puissance_4

fonction.o: src/fonction.c include/fonction.h
	gcc -c src/fonction.c -Iinclude -o fonction.o

puissance_4.o: src/puissance_4.c src/fonction.c include/fonction.h
	gcc -c src/puissance_4.c -Iinclude -o puissance_4.o

puissance_4: puissance_4.o fonction.o 
	gcc -o puissance_4 fonction.o puissance_4.o

clean:
	rm -f puissance_4 *.o *~

mrproper: clean
	rm -f puissance_4
