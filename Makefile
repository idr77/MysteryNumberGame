#Makefile

# Répertoires
SRC_DIR = ./src
INCLUDE_DIR = ./include

# Options compilateur
CC = gcc
DEBUG = yes
CFLAGS =  -I$(INCLUDE_DIR) -Wall -pedantic

ifeq ($(DEBUG), yes)
	CFLAGS += -g
endif

LDFLAGS = `sdl2-config --cflags --libs` -lSDL2_image -lSDL2_mixer -lSDL2_ttf

# Fichiers
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:.c=.o)
EXEC = NombreMystere

#Règles
all: $(EXEC) clean

NombreMystere: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)


# Règles de nettoyage
.PHONY: clean mrproper

clean:
	rm -rf $(SRC_DIR)/*.o $(SRC_DIR)/*~ 

mrproper: clean
	rm -rf $(EXEC)
