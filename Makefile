lib/libpong.a: src/ball.c include/ball.h
	gcc -c src/ball.c -Iinclude
	ar rcs $@ ball.o

bin/main: src/main.c include/ball.h lib/libpong.a
	gcc $< -lSDL2 -Iinclude -Llib -lpong -o $@
clean:
	@rm -f lib/*
	@find . name '*.o' -exec rm -f {} \;
