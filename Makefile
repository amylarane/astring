SOURCES=$(wildcard src/*.c)
OBJECTS=$(patsubst src/%.c,obj/%.o,$(SOURCES))

CFLAGS=-Wall -Werror -Wpedantic -O3 --std=c11 -Iinclude -fPIC
LDFLAGS=-shared

libtstring.so: $(OBJECTS)
	@echo CC $@
	@gcc $(CFLAGS) -o $@ $^ $(LDFLAGS)

obj/%.o:src/%.c
	@mkdir -p $(shell dirname $@)
	@echo LINK $@
	@gcc $(CFLAGS) -c -o $@ $^ $(LDFLAGS)

clean:
	rm -rf obj libtstring.so

install:
	cp libtstring.so ~/lib
	cp include/tstring.h ~/include
