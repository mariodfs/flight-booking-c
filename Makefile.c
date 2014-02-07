all:    flightbooking

flightbooking:  main.o structs_and_functions.o;   gcc -o flightbooking main.o structs_and_functions.o

main.o: main.c structs_and_functions.h;   gcc -Wall -c main.c

structs_and_functions.o:    structs_and_functions.c structs_and_functions.h;   gcc -Wall -c structs_and_functions.c

clean:;   rm -f main.o structs_and_functions.o flightbooking