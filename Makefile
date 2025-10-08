CC = gcc
CFLAGS = -O2 -Wall -Wextra -std=c99
TARGET = kernel
SRCS = /theCpart/kernel.c
OBJS = $(SRCS:.c=.o)
all:$(TARGET)
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS) $(TARGET)
check:
	@echo "Why would there be a kernel test otherwise than virtualization????? Hello????"
.PHONY: all clean
