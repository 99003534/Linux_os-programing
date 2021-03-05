all: sol8write sol8read

sol8write: sol8write.c 
	gcc -o sol8write.out sol8write.c -lpthread -lrt
	
sol8read: sol8read.c 
	gcc -o sol8read.out sol8read.c -lpthread -lrt
	
 runsol8read:
	./sol8read.out

runsol8write:
	./sol8write.out

clean:
	rm -rf *.out *.o