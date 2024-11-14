# Define the compiler and source files
CC = cc
SRC = main.c
OUT = {{PROJECT_NAME}}

# Use pkg-config to get SDL3 flags
SDL3_CFLAGS = $(shell pkg-config sdl3 --cflags)
SDL3_LIBS = $(shell pkg-config sdl3 --libs)

$(OUT): $(SRC)
	$(CC) -o $(OUT) $(SRC) $(SDL3_CFLAGS) $(SDL3_LIBS)

run: $(OUT)
	./$(OUT)

clean:
	rm -f $(OUT)

.PHONY: clean run
