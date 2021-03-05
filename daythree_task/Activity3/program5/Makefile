all: sol5server sol5client

sol5server: sol5server.c 
	gcc -o sol5server.out sol5server.c -lrt
	
sol5client: sol5client.c 
	gcc -o sol5client.out sol5client.c -lrt
	
runsol5client:
	./sol5client.out

runsol6server:
	./sol5server.out

clean:
	rm -rf *.out *.o