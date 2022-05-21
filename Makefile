LINK_TARGET = main
LD_LIBS = -lglfw -lGL

OBJS = 			\
	window.o	\
	render.o	\
	main.o

all: $(LINK_TARGET)

$(LINK_TARGET): $(OBJS)
	gcc -o $@ $^ $(LD_LIBS) 

%.o: %.c
	gcc -o $@ -c $<

main.o: window.h render.h

clean:
	rm main main.o window.o render.o