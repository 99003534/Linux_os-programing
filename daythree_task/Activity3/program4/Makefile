all: sol4send sol4receive

sol4send: sol4send.c 
	gcc -o sol4send.out sol4send.c -lrt
	
sol4receive: sol4receive.c 
	gcc -o sol4receive.out sol4receive.c -lrt
	
runsol4receive:
	./sol4receive.out

runsol4send:
	./sol4send.out

clean:
	rm -rf *.out *.o