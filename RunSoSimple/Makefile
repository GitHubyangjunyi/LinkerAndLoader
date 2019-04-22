EXECUTABLE = RunSoSimple

objects = $(EXECUTABLE).o

$(EXECUTABLE): $(objects)
	gcc -o $(EXECUTABLE) $(objects) -ldl
#use the DL(Dynamical Loading)library from /lib/libdl.so.2

$(objects):
	gcc -c $(EXECUTABLE).c

.PHONY: clean
clean:
	-rm $(EXECUTABLE) $(objects)

#gcc -fPIC -shared -o Lib.so Lib.c
#./RunSoSimple ./Lib.so