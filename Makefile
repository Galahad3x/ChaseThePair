all:
	gcc ChaseThePair.c -o ChaseThePair
	gcc readSETSIZE.c -o readSETSIZE
	./readSETSIZE
	./setsGenerator < data.txt
	./ChaseThePair

clean:
	rm -rf readSETSIZE ChaseThePair
	ls
	
