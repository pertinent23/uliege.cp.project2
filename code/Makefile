### 
## Makefile skeleton
## INFO0030: Projet 4
## 
### 

## Variables

# Tools & flags
CC=gcc
CFLAGS=--std=c99 --pedantic -Wall -W -Wmissing-prototypes -lm
LD=gcc
LDFLAGS=-lm

EXEC_LIST=itineraireflamme_liste_test
EXEC_ARRAY=itineraireflamme_tableau_test
OBJECTS=seatest.o region.o itineraireflamme_tableau.o itineraireflamme_liste.o itineraireflamme_tableau_test.o itineraireflamme_liste_test.o

test_array: seatest.o region.o itineraireflamme_tableau.o itineraireflamme_tableau_test.o
	$(LD) $^ -o $(EXEC_ARRAY) $(LDFLAGS)

test_list: seatest.o region.o itineraireflamme_liste.o itineraireflamme_liste_test.o
	$(LD) $^ -o $(EXEC_LIST) $(LDFLAGS)

$(OBJECTS): %.o: %.c
	$(CC) -o $@ -c $^ $(CFLAGS)

clean: 
	rm -f *.o $(EXEC_ARRAY) $(EXEC_LIST) tempCodeRunnerFile *~
	clear