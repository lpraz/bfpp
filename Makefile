#
# Variables
#

# Compiler options
CC = gcc
CFLAGS = -std=c99 -g

# Directories (build)
SRCDIR = src
INCLDIR = include
BUILDDIR = build

# Directories (install)
#DESTDIR =
PREFIX = /usr/bin
INSTTARGET = bfpp

# Extension
SRCEXT = c

# Specific files
TARGET = bin/a.out
SOURCES = $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS = $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

#
# Recipes
#

# Build binary from objects
$(TARGET): $(OBJECTS)
	$(CC) $^ -o $(TARGET)

# Build objects from source files
$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	$(CC) $(CFLAGS) -I $(INCLDIR) -c -o $@ $<

# Install to $(PREFIX)
.PHONY: install
install: $(TARGET)
	cp $< $(DESTDIR)$(PREFIX)/$(INSTTARGET)

# Uninstall from $(PREFIX)
.PHONY: uninstal
uninstall:
	rm -f $(DESTDIR)$(PREFIX)/$(INSTTARGET)

# Clean objects
.PHONY: clean
clean:
	rm -f $(BUILDDIR)/*.o
