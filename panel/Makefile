.POSIX:
CC = cc

LDLIBS = -lpanel -lncurses -ltinfo

KHFLAGS = -std=c99 $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)

PROG = basic browsing

all: $(PROG)
clean:
	rm -f $(PROG)

.SUFFIXES: .c
.c:
	$(CC) $(KHFLAGS) $< $(LDLIBS) -o $@
