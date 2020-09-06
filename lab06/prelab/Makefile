CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall
DEBUG=-g

OBJECTS=myHash.o wordPuzzle.o
wordPuzzle: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS)
getWordInGrid.o: getWordInGrid.cpp
myHash.o: myHash.cpp myHash.h
primenumber.o: primenumber.cpp
timer.o: timer.cpp timer.h
timer_test.o: timer_test.cpp timer.h
wordPuzzle.o: wordPuzzle.cpp myHash.h

.PHONY: clean
clean:
	-rm -f *.o a.out
