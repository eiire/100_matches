All: bin/100_matches bin/test
	./bin/test


bin/100_matches: build/main.o build/matches.o
	gcc -Wall -Werror -o bin/100_matches build/main.o build/matches.o -lncurses

build/main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/main.o

build/matches.o: src/matches.c
	gcc -Wall -Werror -c src/matches.c -o build/matches.o


bin/test: build/matches.o build/test.o build/ctest.o
	gcc -Wall -Werror build/matches.o build/test.o build/ctest.o -o bin/test -lncurses

build/test.o: test/test.c
	gcc -Wall -Werror -c  test/test.c -o build/test.o -Ithirdparty -Isrc

build/ctest.o: test/ctest.c
	gcc -Wall -Werror -c test/ctest.c -o build/ctest.o -Ithirdparty


.PHONY: clean
clean:
	rm -rf build/*.o
