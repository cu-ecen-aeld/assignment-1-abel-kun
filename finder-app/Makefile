#####################################
# @author : Arun Belamge
# @date	  : 23-02-2025
#####################################




#General CFlags and Compiler options
CFLAGS = -g -Wall

ifeq ($(CROSS_COMPILE), true)
	CC = aarch64-none-linux-gnu-gcc
	
else
	CC = gcc
endif

.PHONY: build clean help

build: 
	$(CC) $(CFLAGS) writer.c -o writer
	
clean:
	rm -rf writer 
	
	
help:
	@echo "Use 'make build' to use native compiler"
	@echo "Use 'make build CROSS_COMPILE=true' to use cross-compiler"
	@echo "Use 'make clean' to clear the output files"
