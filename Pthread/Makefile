EXECUTABLE = Pthread

objects = $(EXECUTABLE).o

$(EXECUTABLE): $(objects)
	gcc -o $(EXECUTABLE) $(objects) -lpthread

$(objects):
	gcc -c -g $(EXECUTABLE).c

.PHONY: c
c:
	gcc -c -m32 $(EXECUTABLE).c

.PHONY: cg
cg:
	gcc -c -g -m32 $(EXECUTABLE).c

.PHONY: clean
clean:
	-rm $(EXECUTABLE) $(objects)