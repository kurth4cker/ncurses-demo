CC = cc

LDFLAGS = -lcurses

BIN = sample initfunc scanw chgat window keys leaving acs

all: $(BIN)

clean:
	rm -f $(BIN)

.SUFFIXES: .c
.c:
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)
