TARGET=vaders

CXX=gcc
CXXFLAGS=-Wno-unknown-pragmas
CPPFLAGS=-g
LDFLAGS=
LDLIBS=-lSDL_image

SRCS=vaders.c util.c globals.c input.c player.c enemy.c bullet.c images.c
INCLUDES=vaders.h util.h globals.h input.h player.h enemy.h bullet.h images.h
OBJS=$(subst .c,.o,$(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(TARGET) $(OBJS) $(LDLIBS) `sdl-config --cflags --libs`

$(SRCS):
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -I$(INCLUDES)

clean:
	rm -rf *.o $(TARGET)

install:
	sudo cp $(TARGET) /usr/bin/$(TARGET)
