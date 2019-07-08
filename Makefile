.PHONY: clean

LIBS=-L. -l:libbaudcat.so
LIBS_STATIC=-L. -l:libbaudcat.a

baudcat: libbaudcat.so main.c
	gcc -O3 main.c -o $@ -Wl,-rpath,\$$ORIGIN $(LIBS)
	gcc -O3 main.c -o $@-static $(LIBS_STATIC)


libbaudcat.so: baudcat.c
	gcc -O3 -fPIC -shared -o libbaudcat.so baudcat.c
	gcc -O3 -c baudcat.c -o baudcat.o 
	ar rcs libbaudcat.a baudcat.o


clean:
	rm -f baudcat libbaudcat.so libbaudcat.a baudcat.o baudcat-static
