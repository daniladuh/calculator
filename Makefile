# Определяем компилятор
CC = gcc

# Определяем флаги компиляции
CFLAGS = -Wall

# Определяем целевой файл
TARGET = calculator.p

# Правило для сборки
all: $(TARGET)

$(TARGET): calculator.c
	$(CC) $(CFLAGS) -o $(TARGET) calculator.c

# Правило для очистки
clean:
	rm -f $(TARGET)
