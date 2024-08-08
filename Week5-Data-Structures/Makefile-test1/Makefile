CFLAGS = -Wno-implicit-function-declaration

all: final
# all and final, left of the ':' are called targets
# final, main.o, hello.o , right of the ':' are called source files(target sources)
# we can run targets like make all, or make final, etc
final: main.o hello.o # if the source files are not made yet
# make will go down and make them each to enable making the final target
	@echo "Linking and producing the final application"
	# the '@' sign hides the line in terminal
	gcc $(CFLAGS) main.o hello.o -o final
	chmod +x final

# instead of running: gcc -Wno-implicit-function-declaration -c main.c
# Wno(no warnings), compiling the main.c file will create a main.o object file
#target main.o requires main.c to be compiled
main.o: main.c
	@echo "Compiling the main file"
	gcc $(CFLAGS) -c main.c

#target hello.o requires hello.c to be compiled
hello.o: hello.c
	@echo "Compiling the hello file"
	gcc $(CFLAGS) -c hello.c

clean:
	@echo "Removing everything but the source files"
	rm main.o hello.o final
