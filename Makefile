.POSIX:
KHCFLAGS = -std=c99 $(CFLAGS) $(CPPFLAGS)
LDLIBS = -lcurses -ltinfo

PROG = hello sample initfunc printw scanw attributes
all: $(PROG)
clean:
	rm -f $(PROG)

.c:
	$(CC) $(KHCFLAGS) $(LDFLAGS) $< $(LDLIBS) -o $@
.PHONY: all clean
