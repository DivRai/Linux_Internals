# This makefile contain variable and multiple targets. Here created object files as targets. If I want to 
# compile an individual file then compilation becomes easier because only respective file is being compiled.

$(CC) = gcc

appln: main.o mean.o sub.o
	$(CC) main.o mean.o sub.o -o appln

main.o: main.c mean.h
	$(CC) -c main.c

mean.o: mean.c mean.h
	$(CC) -c mean.c

sub.o: sub.c mean.h
	$(CC) -c sub.c

clean:
	rm -f *.o
