TARGET=vaders

CXX=gcc
CXXFLAGS=
CPPFLAGS=
LDFLAGS=
LDLIBS=-lSDL_image

SRCS=vaders.c util.c globals.c input.c player.c
INCLUDES=vaders.h util.h globals.h input.h player.h
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
