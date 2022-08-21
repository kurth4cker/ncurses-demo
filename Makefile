.POSIX:

LDLIBS ?= -lncurses -ltinfo

all: hello
clean:
	${RM} hello
