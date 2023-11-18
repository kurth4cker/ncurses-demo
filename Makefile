CC = cc

LDLIBS = -lcurses

BIN = sample initfunc scanw chgat window keys leaving acs

all: $(BIN)

clean:
	rm -f $(BIN)

.SUFFIXES: .c
.c:
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@ $< $(LDLIBS)
