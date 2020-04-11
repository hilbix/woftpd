#

PROG=$(patsubst %.c,%,$(wildcard *.c))
GITVER=$(shell git rev-parse --short HEAD)
GITURL=$(patsubst .git,,$(shell git config --local --get remote.origin.url))
CFLAGS=-Wall -O3 -DGIT_VER='"g$(GITVER)"' -DGIT_URL='"$(GITURL)"' -Wno-unused-function

.PHONY:	love
love:	all

.PHONY:	all
all:	minilib $(PROG)

.PHONY:	clean
clean:
	rm -f $(PROG)
	$(MAKE) -C minilib "$@"

.PHONY:	minilib
minilib:
	[ -e minilib/.git ] || git submodule update --init
	$(MAKE) -C minilib all

