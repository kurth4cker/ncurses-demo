.POSIX:
KHFLAGS = -std=c99 $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)
LDLIBS = -lcurses -ltinfo

PROG = hello sample initfunc printw scanw attributes
all: $(PROG)
clean:
	rm -f $(PROG)

.c:
	$(CC) $(KHFLAGS) $< $(LDLIBS) -o $@
.PHONY: all clean
