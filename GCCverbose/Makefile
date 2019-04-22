EXECUTABLE = Demo

objects = $(EXECUTABLE).o

$(EXECUTABLE): $(objects)
	gcc --verbose -o $(EXECUTABLE) $(objects)

$(objects):
	gcc --verbose -c -g $(EXECUTABLE).c

.PHONY: c
c:
	gcc --verbose -c -m32 $(EXECUTABLE).c

.PHONY: cg
cg:
	gcc --verbose -c -g -m32 $(EXECUTABLE).c

.PHONY: clean
clean:
	-rm $(EXECUTABLE) $(objects)