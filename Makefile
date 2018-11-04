all: speed_test wwf

speed_test:
	g++ -DGRID_EARLY_EXIT -O3 -std=c++11 -ospeed_test -I. grid.cpp permutation.cpp speed_test.cpp trie.cpp -lSDL2

wwf:
	g++ -DGRID_EARLY_EXIT -O3 -std=c++11 -owwf -I. grid.cpp main.cpp permutation.cpp trie.cpp -lSDL2

clean:
	rm -f speed_test wwf
