test:kongjian.o test.o
	cc -o test kongjian.o test.o `pkg-config --cflags --libs gtk+-2.0` -lsqlite3 
kongjian.o:kongjian.c kongjian.h
	cc -c kongjian.c `pkg-config --cflags --libs gtk+-2.0` -lsqlite3
test.o:test.c kongjian.h
	cc -c test.c `pkg-config --cflags --libs gtk+-2.0` -lsqlite3
clean:
	rm test kongjian.o test.o
