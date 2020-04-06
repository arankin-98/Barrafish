CXX = clang++
CXXFLAGS = -std=c++11 -Wall -pedantic
OBJS = rummilogic.o rummimodel.o

run_linked: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) rummikub.cpp -o run_linked

.PHONY: clean

clean:
	rm -f run_linked $(OBJS) rummikub.o
