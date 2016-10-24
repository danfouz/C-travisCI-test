compilacion:	
	gcc -o fib_complexN1_6 src/fib_complexN1_6.c -lm

	gcc -o fib_complexN src/fib_complexN.c -lm

	gcc -o fib_complexNlogN src/fib_complexNlogN.c -lm

clean:
	rm -r fib_complexN1_6 fib_complexN fib_complexNlogN
