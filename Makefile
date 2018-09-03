.PHONY: clean

baudcat: baudcat.c
	gcc -O3 $< -o $@

clean:
	rm -f baudcat
