EXECUTABLE = TinyHelloWorld

objects = $(EXECUTABLE).o

$(EXECUTABLE): $(objects)
	ld -static -e nomain -o TinyHelloWorld TinyHelloWorld.o
$(objects):
	gcc -c -fno-builtin $(EXECUTABLE).c

.PHONY: ld
ld:
	gcc -c -fno-builtin $(EXECUTABLE).c
	ld -static -o TinyHelloWorld TinyHelloWorld.o -T TinyHelloWorld.lds

.PHONY: lds
lds:
	gcc -c -fno-builtin $(EXECUTABLE).c
	ld -s -static -o TinyHelloWorld TinyHelloWorld.o -T TinyHelloWorld.lds

.PHONY: clean
clean:
	-rm $(EXECUTABLE) $(objects)