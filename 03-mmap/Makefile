mmap: mmap.c
	gcc mmap.c -o mmap -static

run: ./mmap
	./mmap

strace: ./mmap
	strace -ff ./mmap thread
