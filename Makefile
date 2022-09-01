.POSIX:
RM ?= rm -f

CFLAGS += -std=c99
LDLIBS ?= -lcurses -ltinfo

PROG = hello sample initfunc printw scanw attributes
all: ${PROG}
clean:
	${RM} ${PROG}

.PHONY: all clean
