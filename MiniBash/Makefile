EXECUTABLE = MiniBash

objects = $(EXECUTABLE).o

$(EXECUTABLE): $(objects)
	gcc -o $(EXECUTABLE) $(objects)

$(objects):
	gcc -c -g $(EXECUTABLE).c

.PHONY: clean
clean:
	-rm $(EXECUTABLE) $(objects)