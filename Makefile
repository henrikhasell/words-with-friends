src=grid.cpp main.cpp permutation.cpp trie.cpp
obj=$(src:.cpp=.o)
out=wwf

CXXFLAGS=-DGRID_EARLY_EXIT -g -O0
LDFLAGS= -lSDL2

$(out): $(obj)
	$(CXX) -o$@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	$(RM) -f $(obj) $(out)
