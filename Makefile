CC = gcc
CFLAGS = -Wall

Lab5: main.o ui.o storage.o vector.o
	$(CC) $(CFLAGS) main.o ui.o storage.o vector.o -o Lab5

main.o: main.c ui.h
	$(CC) $(CFLAGS) -c main.c

ui.o: ui.c ui.h storage.h vector.h
	$(CC) $(CFLAGS) -c ui.c

storage.o: storage.c storage.h vector.h
	$(CC) $(CFLAGS) -c storage.c

vector.o: vector.c vector.h
	$(CC) $(CFLAGS) -c vector.c

clean:
	rm -f *.o Lab5
