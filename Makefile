CFLAGS = -I../..
ifeq ($(OS),Windows_NT)
	LDFLAGS = -s -lopengl32 -lgdi32
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Darwin)
		LDFLAGS = -framework OpenGL -framework Cocoa
	else ifeq ($(UNAME_S),Linux)
		LDFLAGS = -s -lGLU -lGL -lX11
	endif
endif

icono: icono.o tigr.o
	gcc -o icono icono.o tigr.o $(CFLAGS) $(LDFLAGS)
icono.o: icono.c
	gcc -c icono.c
tigr.o: tigr/tigr.c tigr/tigr.h
	gcc -c tigr/tigr.c
GUIXML: GUIXML.o xml.o
	gcc -o GUIXML GUIXML.o xml.o
GUIXML.o: GUIXML.c
	gcc -c GUIXML.c
xml.o: xml.c/src/xml.c xml.c/src/xml.h
	gcc -c xml.c/src/xml.c
clean:
	del icono icono.o tigr.o GUIXML GUIXML.o xml.o