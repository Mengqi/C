# The C Makefile

#
# To modify: Modify macro "PROGRAM" and macro "SOURCES"
# Note: Every time modification is made to header files,
#	run "make clean" & "make".
#
# ----------------------------------------------------------

#
# The PROGRAM macro defines the name of the program or project. It
# allows the program name to be changed by editing in only one
# location.
#

PROGRAM	= test

#
# The HOME macro is the home directory of the program.
#
# The INCLUDEDIRS macro contains a list of include directories
# to pass to the compiler so it can find necessary headers files.
#
# The LIBDIRS macro contains a list of library directories
# to the linker so it can find necessary libraries.
#
# The LIBS macro contains a list of libraries that the executable
# must be linked against.
#

HOME = ..

INCLUDEDIRS	= \
	-I$(HOME)/include \

LIBDIRS	= \
	-L$(HOME)/lib

LIBS = -lm

#
# The SOURCES macro contains a list of source files.
#
# The OBJECTS macro converts the SOURCES macro into a list of
# object files.
#
# The CC macro defines the C compiler
#
# The CFLAGS macro contains a list of options to be passed to
# the compiler. Adding "-g" to this line will cause the compiler
# to add debugging information to the executable.
#
# The LDFLAGS macro contains all of the library and library
# directory information to be passed to the linker.
#

SOURCES	= test.c hello.c
OBJECTS	= $(SOURCES:.c=.o)

CC	= gcc
CFLAGS	= -DESRI_UNIX $(INCLUDEDIRS)

LDFLAGS	= $(LIBDIRS) $(LIBS)

#
# Default target: the first target is the default target.
#

all: $(PROGRAM)

#
# Link target: automatically builds its object dependencies before
# executing its link command.
#

$(PROGRAM): $(OBJECTS)
	$(CC) -o $@ $(OBJECTS) $(LDFLAGS)

#
# Object targets: rules that define objects, their dependencies, and
# a list of commands for compilation.
#

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

#
# Run target: "make run" to execute the application
#	      You will need to add $(VARIABLE_NAME) for any command line
#	      parameters that you defined earlier in this file.
#

.PHONY: run

run:
	./$(PROGRAM)

#
# Clean target: "make clean" to remove unwanted objects and executables.
#

.PHONY: clean

clean:
	rm -f $(PROGRAM) $(OBJECTS)

