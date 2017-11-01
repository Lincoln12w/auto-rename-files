
main:
	gcc -g -fPIC -shared -o libparselib.so parseFib.c

clean:
	rm -rf *.so *.so.dSYM
