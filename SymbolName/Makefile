EXECUTABLE = ManualNameMangling

objects = $(EXECUTABLE).o

$(EXECUTABLE): $(objects)
	gcc -o $(EXECUTABLE) $(objects)

$(objects):
	gcc $(EXECUTABLE).cpp

.PHONY: c
c:
	gcc -c $(EXECUTABLE).cpp

.PHONY: cg
cg:
	gcc -c -g $(EXECUTABLE).cpp

.PHONY: clean
clean:
	-rm $(EXECUTABLE) $(objects)