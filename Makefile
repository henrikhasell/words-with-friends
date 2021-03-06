src=grid.cpp main.cpp permutation.cpp trie.cpp
obj=$(src:.cpp=.o)
out=wwf

CXXFLAGS=-DGRID_EARLY_EXIT -fdata-sections -ffunction-sections -O3
LDFLAGS=-lSDL2

$(out): $(obj)
	$(CXX) -o$@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	$(RM) -f $(obj) $(out)
