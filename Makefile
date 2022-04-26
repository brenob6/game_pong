CC := gcc

CFLAGS := -Wall -Wextra -pedantic
LFLAGS := -lpong -lSDL2 -lSDL2_ttf

INC := include
SRC := src
OBJ := obj
LIB := lib

MAIN := $(SRC)/main.c
SOURCE := $(filter-out $(MAIN), $(wildcard $(SRC)/*.c))
HEADER := $(wildcard $(INC)/*.h)
OBJECT := $(SOURCE:$(SRC)/%.c=$(OBJ)/%.o)
LIBRARY := $(LIB)/libpong.a

BIN := pong.app

all: $(BIN)

$(BIN): $(MAIN:$(SRC)/%.c=$(OBJ)/%.o) $(LIBRARY)
	$(CC) $< -I$(INC) -L$(LIB) $(LFLAGS) -o $@ -lm

$(LIBRARY): $(OBJECT)
	@mkdir -p $(LIB)
	ar rcs $@ $(OBJECT)

$(OBJ)/%.o: $(SRC)/%.c
	@mkdir -p $(OBJ)
	$(CC) $(CFLAGS) -MMD -c $< -I$(INC) -o $@ $(LFLAGS)

run:
	@./$(BIN)

clean:
	@rm -f ./$(LIBRARY) ./$(OBJ)/*.o ./$(BIN) ./$(OBJ)/*.d

-include $($(wildcard $(SRC)/*.c):$(SRC)/%.c=$(OBJ)/%.d)
