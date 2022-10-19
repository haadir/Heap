CXX := g++
CXXFLAGS := -g -Wall --std=c++11
#VALGRIND := valgrind --tool=memcheck --leak-check=yes
OBJS = llrec-test.o llrec.o
OBJS2 = stack-test.o

all: llrec-test stack-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------

llrec-test: $(OBJS)
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ $(OBJS)

stack-test: $(OBJS2)
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ $(OBJS2)
	
llrec-test.o: llrec-test.cpp llrec.h
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c llrec-test.cpp

llrec.o: llrec.cpp llrec.h
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c llrec.cpp

stack_test.o: stack_test.cpp stack.h
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c stack_test.cpp

clean:
	rm -f *.o rh llrec-test *~ stack-test *~

.PHONY: clean t