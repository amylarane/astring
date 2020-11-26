SOURCES=$(wildcard src/*.c)
OBJECTS=$(patsubst src/%.c,obj/%.o,$(SOURCES))

CFLAGS=-Wall -Werror -Wpedantic -O3 --std=c11 -Iinclude -fPIC
LDFLAGS=-shared

libastring.so: $(OBJECTS)
	@echo CC $@
	@gcc $(CFLAGS) -o $@ $^ $(LDFLAGS)

obj/%.o:src/%.c
	@mkdir -p $(shell dirname $@)
	@echo LINK $@
	@gcc $(CFLAGS) -c -o $@ $^ 

clean:
	rm -rf obj libastring.so

install:
	cp libastring.so ~/lib
	cp include/astring.h ~/include
