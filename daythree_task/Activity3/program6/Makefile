all: sol6server sol6client

sol6server: sol6server.c 
	gcc -o sol6server.out sol6server.c -lrt
	
sol6client: sol6client.c 
	gcc -o sol6client.out sol6client.c -lrt
	
runsol6client:
	sol6client.out

runsol6server:
	./sol6.out

clean:
	rm -rf *.out *.o