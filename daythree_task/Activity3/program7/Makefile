all: sol7Gpipe sol7Gpipe1 sol7Gpipe2

sol7Gpipe: sol7Gpipe.c sol7.h
	gcc -o sol7Gpipe.out sol7Gpipe.c -lrt
	
sol7Gpipe1: sol7Gpipe1.c sol7.h
	gcc -o sol7Gpipe1.out sol7Gpipe1.c -lrt

sol7Gpipe2: sol7Gpipe2.c sol2g.h
	gcc -o sol7Gpipe2.out sol7Gpipe2.c -lrt
	
runsol7Gpipe:
	./sol7Gpipe.out

runsol7Gpipe1:
	./sol7Gpipe1.out

runsol7Gpipe2:
	./sol7Gpipe2.out

clean:
	rm -rf *.out *.o