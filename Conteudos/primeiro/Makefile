CC = gcc 
RM = rm # no windowns é del
TARGET = pontos

all: objetos
	$(CC) main.o vetor.o -o $(TARGET)

objetos: main.c vetor.c
	$(CC) -c main.c
	$(CC) -c vetor.c

clean: 
	$(RM) *.o pontos
	$(RM) $(TARGET)
