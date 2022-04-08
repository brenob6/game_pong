lib/libpong.a: src/ball.c include/ball.h src/player.c include/player.h src/events.c include/events.h src/window.c include/window.h
	mkdir -p lib
	gcc -c src/window.c -Iinclude
	gcc -c src/events.c -Iinclude
	gcc -c src/ball.c -Iinclude
	gcc -c src/player.c -Iinclude
	ar rcs $@ ball.o player.o events.o window.o

bin/main: src/main.c lib/libpong.a include/ball.h include/player.h include/events.h
	mkdir -p bin
	gcc $< -lSDL2 -Iinclude -Llib -lpong -lm -o $@

clean:
	@rm -f lib/*
	@find . name '*.o' -exec rm -f {} \;
