CFLAGS = -Wall -g
CC = gcc

run : clean chiffrer
	./chiffrer 

chiffrer : main.o present24.o dechiffrement.o attaque.o
	$(CC) main.o present24.o dechiffrement.o attaque.o -lm -O3 -o chiffrer


%.o : %.c present.h dechiffrement.h attaque.h
	$(CC) -c $<  $( CFLAGS )

valgrind : chiffrer
	valgrind --leak-check = full ./chiffrer 000000

clean :
	rm -f *.o
	rm -f chiffrer