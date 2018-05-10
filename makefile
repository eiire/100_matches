All: bin/100_matches bin/test

bin/100_matches: build/main.o build/matches.o
	gcc -Wall -o bin/100_matches build/main.o build/matches.o -lncurses

build/main.o: src/main.c
	gcc -Wall -c src/main.c -o build/main.o -lncurses

build/matches.o: src/matches.c
	gcc -Wall -c src/matches.c -o build/matches.o -lncurses


bin/test: build/matches.o build/test.o build/ctest.o
	gcc -Wall build/matches.o build/test.o build/ctest.o -o bin/test -lncurses
build/test.o: test/test.c
	gcc -Wall -c  test/test.c -o build/test.o -Ithirdparty -Isrc -lncurses
build/ctest.o: test/ctest.c
	gcc -Wall -c test/ctest.c -o build/ctest.o -Ithirdparty -lncurses

test: bin/test
	bin/test

.PHONY: clean
clean:
	rm -rf build/*.o
