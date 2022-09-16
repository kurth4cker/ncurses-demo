.POSIX:
# customizable flags (you can also customize CFLAGS, CPPFLAGS and LDFLAGS)
LDLIBS = -lncurses -ltinfo

# don't customize them
KHFLAGS = -std=c99 $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)

PROG = hello sample initfunc printw scanw attributes chgat

all: $(PROG)
clean:
	rm -f $(PROG)

.SUFFIXES: .c
.c:
	$(CC) $(KHFLAGS) $< $(LDLIBS) -o $@
