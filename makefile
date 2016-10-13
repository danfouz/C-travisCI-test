compilacion:	
	gcc -o p1 p1.c -lm

	gcc -o p2 p1-2.c -lm

	gcc -o p3 p1-3.c -lm

	gcc -o test test.c -lm
clean:
	rm -r p1 p2 p3 test
