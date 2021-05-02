CFLAGS = -Wall -g
CC = gcc

run : clean chiffrer
	./chiffrer "000000" "000000"


chiffrer : main.o present24.o 
	$(CC) main.o present24.o -lm -O3 -o chiffrer


%.o : %.c present.h 
	$(CC) -c $<  $( CFLAGS )

valgrind : chiffrer
	valgrind --leak-check = full ./chiffrer 000000

clean :
	rm -f *.o
	rm -f chiffrer