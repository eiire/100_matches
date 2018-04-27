All: bin/100_matches

bin/100_matches: build/main.o build/matches.o
	gcc -Wall -o bin/100_matches build/main.o build/matches.o

build/main.o: src/main.c
	gcc -Wall -c src/main.c -o build/main.o

build/matches.o: src/matches.c
	gcc -Wall -c src/matches.c -o build/matches.o

.PHONY: clean
clean:
	rm -rf build/*.o
