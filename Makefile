compilacion:	
	gcc -c  src/fib_complexN1_6.c -lm

	gcc -c src/fib_complexN.c -lm

	gcc -c  src/fib_complexlogN.c -lm

clean:
	rm -r fib_complexN1_6.o fib_complexN.o fib_complexlogN.o
