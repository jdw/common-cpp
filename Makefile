ifeq ($(DEBUG),yes)
	CXXFLAGS=-Wall -g
	LDFLAGS=-Wall -g
else
	CXXFLAGS=-Wall
	LDFLAGS=-Wall
endif

CC = g++
SRCPATH=src
LIBPATH=$(SRCPATH)/lib
OBJECTS=$(SRCPATH)/tests.o
TARGETS=tests
INCLUDES=-I./$(LIBPATH)

all: $(TARGETS)

tests: $(OBJECTS)
	$(CC) $(LIBS) -o $(@) $(OBJECTS)

$(SRCPATH)/%.o: $(SRCPATH)/%.cpp
	$(CC) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

install:
	
clean:
	@rm -f $(SRCPATH)/*.o $(SRCPATH)/*.gch $(LIBPATH)/*.gch $(TARGETS)
