# 1. Configuración del compilador
CC = gcc
# Carpeta donde está tu código
SRC_DIR = src
# Flags: -I es para decirle donde buscar los .h
CFLAGS = -Wall -Wextra -g -I$(SRC_DIR)

# Nombre del ejecutable final
TARGET = trukito

# 2. Archivos fuente
# Esto busca AUTOMÁTICAMENTE todos los .c dentro de src/
SRCS = $(wildcard $(SRC_DIR)/*.c)

# 3. Reglas
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET).exe $(TARGET)