CFLAGS_RSVG := $(shell pkg-config --cflags cairo librsvg-2.0)

cairo.rsvg.o: cairo.rsvg.c
	$(CC) $(CFLAGS_RSVG) -c $< -o $@
