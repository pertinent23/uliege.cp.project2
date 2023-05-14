### 
## Makefile skeleton
## INFO0947: Projet 2
## 
### 

## Variables

AT=tar
ATFLAGS=-zcvf
DT=doxygen

# Files
OUTPUT=tad-groupe26.tar.gz
CONFIG=doxygen.config

test_array:
	cd code && make test_array

test_list:
	cd code && make test_list

clean:
	cd code && make clean
	rm $(OUTPUT)
	clear

archive: clean
	$(AT) $(ATFLAGS) $(OUTPUT) *

doc: tetris
	$(DT) $(CONFIG)
	make clean

check_memory:
	valgrind --leak-check=full ./