All: bin/100_matches

bin/100_matches: build/main.o
	gcc -Wall -o bin/100_matches build/main.o

build/main.o: src/main.c
	gcc -Wall -c src/main.c -o build/main.o

.PHONY: clean
clean:
	rm -rf build/*.o
