.POSIX:
# customizable macros (you can also customize CFLAGS, CPPFLAGS and LDFLAGS)
CC = cc

LDLIBS = -lncurses -ltinfo

# don't customize them
KHFLAGS = -std=c99 $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)

PROG = sample initfunc scanw chgat window keys leaving acs

all: $(PROG)
clean:
	rm -f $(PROG)

.SUFFIXES: .c
.c:
	$(CC) $(KHFLAGS) $< $(LDLIBS) -o $@
