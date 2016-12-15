compilacion:	
	gcc -c fib_complexN1_6 src/fib_complexN1_6.c -lm

	gcc -c fib_complexN src/fib_complexN.c -lm

	gcc -c fib_complexlogN src/fib_complexlogN.c -lm

clean:
	rm -r fib_complexN1_6 fib_complexN fib_complexlogN
