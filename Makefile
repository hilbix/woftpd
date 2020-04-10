#

PROG=$(patsubst .o,,$(wildcard *.o))
GITVER=$(shell git rev-parse --short HEAD)
GITURL=$(patsubst .git,,$(shell git config --local --get remote.origin.url))
CFLAGS=-Wall -O3 -DPROG_VERSION='g$(GITVER)' -DPROG_URL='$(GITURL)'

.PHONY:	love
love:	all

.PHONY:	all
all:	$(PROG)

.PHONY:	clean
clean:
	rm -f $(PROG)

