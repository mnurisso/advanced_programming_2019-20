EXECUTABLE = list.x
OBJECTS    = main.cc \
             list.h	\
			 ap_error.h

CC            	= g++
CFLAGS		= -Wall -Wextra -g -std=c++14
#CFLAGS		= -c
SRC			= /home/matteo/Dropbox/fisnum/lib
VPATH		= ./:$(SRC)
INCLUDE_DIRS	= -I. -I$(SRC)
LDFLAGS		= -lm

$(EXECUTABLE): 	$(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

.cc.o:
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) $<
