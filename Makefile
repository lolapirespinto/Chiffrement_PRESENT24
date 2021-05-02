CFLAGS = -Wall -g
CC = gcc

run : clean chiffrer
	./chiffrer "47a929" "d1bd2d"

chiffrer : main.o present24.o dechiffrement.o
	$(CC) main.o present24.o dechiffrement.o -lm -O3 -o chiffrer


%.o : %.c present.h dechiffrement.h
	$(CC) -c $<  $( CFLAGS )

valgrind : chiffrer
	valgrind --leak-check = full ./chiffrer 000000

clean :
	rm -f *.o
	rm -f chiffrer