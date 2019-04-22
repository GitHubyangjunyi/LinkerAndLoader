EXECUTABLE = SectionMapping

objects = $(EXECUTABLE).o

$(EXECUTABLE): $(objects)
	gcc -static -o $(EXECUTABLE) $(objects)

$(objects):
	gcc -c $(EXECUTABLE).c

.PHONY: c
c:
	gcc -c -m32 $(EXECUTABLE).c

.PHONY: cg
cg:
	gcc -c -g -m32 $(EXECUTABLE).c

.PHONY: clean
clean:
	-rm $(EXECUTABLE) $(objects)