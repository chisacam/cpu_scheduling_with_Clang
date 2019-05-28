CC = gcc
TARGET = cpu_scheduling

$(TARGET): cpu_scheduling.o
	$(CC) -o cpu_scheduling cpu_scheduling.o

cpu_scheduling.o: cpu_scheduling.c
	$(CC) -c -o cpu_scheduling.o cpu_scheduling.c