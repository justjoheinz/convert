CC				=	gcc
CC_FLAGS	= -Wall -std=c99
INDENT		= gindent

TARGET		= convert
SOURCES 	= $(wildcard *.c)
HEADERS		= $(wildcard *.h)

all: $(TARGET) 
.PHONY: all

$(TARGET): $(SOURCES)
	$(CC) $(CC_FLAGS) -o $(TARGET) $(SOURCES)

indent: $(SOURCES) $(HEADERS)
	$(INDENT) --original --no-tabs $^ 

install: convert
	cp $(TARGET) ~/bin/


clean:
	rm *~
	rm $(TARGET)