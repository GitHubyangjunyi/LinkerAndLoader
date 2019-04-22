EXECUTABLE = StaticLinkab
EXECUTABLE1 = a
EXECUTABLE2 = b

objects = $(EXECUTABLE1).o $(EXECUTABLE2).o

$(EXECUTABLE): $(objects)
	gcc -o $(EXECUTABLE) $(objects)

$(objects):
	gcc -c $(EXECUTABLE1).c $(EXECUTABLE2).c

.PHONY: c
c:
	gcc -c -m32 $(EXECUTABLE1).c $(EXECUTABLE2).c

.PHONY: cg
cg:
	gcc -c -g -m32 $(EXECUTABLE1).c $(EXECUTABLE2).c

.PHONY: ld
ld:
	ld $(objects) -e main -o ab

.PHONY: clean
clean:
	-rm $(EXECUTABLE) $(objects)