ifeq ($(DEBUG),yes)
	CXXFLAGS=-Wall -g
	LDFLAGS=-Wall -g
	DEFENITIONS= -D DEBUG=1
else
	CXXFLAGS=-Wall
	LDFLAGS=-Wall
	DEFENITIONS=
endif

CC = g++
SRCPATH=src
LIBPATH=$(SRCPATH)/lib
OBJECTS=$(SRCPATH)/tests.o
TARGETS=tests
INCLUDES=-I./$(LIBPATH)
HOMEINC=$(HOME)/include

all: $(TARGETS)

tests: $(OBJECTS)
	$(CC) $(LIBS) $(DEFENITIONS) -o $(@) $(OBJECTS)

$(SRCPATH)/%.o: $(SRCPATH)/%.cpp
	$(CC) $(CXXFLAGS) $(INCLUDES) $(DEFENITIONS) -c $< -o $@

install:
	@cp -f $(LIBPATH)/*h $(HOMEINC)
	
clean:
	@rm -f $(SRCPATH)/*.o $(SRCPATH)/*.gch $(LIBPATH)/*.gch $(TARGETS)
