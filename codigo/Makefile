CC=gcc
CXX=g++ -std=c++11
RM=rm -f
CPPFLAGS=-g -Wall -Werror
LDFLAGS=-g 
LDLIBS=-g

SRCS=autovalores.cpp pca.cpp Matriz.cpp test.cpp
OBJS=$(subst .cpp,.o,$(SRCS))
tp2=tp2.cpp knn.cpp
knn=knn.cpp

all: $(OBJS)
    #$(CXX) $(LDFLAGS) -o autovalores $(OBJS) $(LDLIBS)
	#$(CXX) $(LDFLAGS) -o reader $(reader) $(LDLIBS) 
tp2:
	$(CXX) $(LDFLAGS) -o tp2 $(tp2) $(LDLIBS)

knn: knn.o 
	g++ --std=c++11 -o knn knn.o 
 
knn.o: knn.cpp
	g++ --std=c++11 -c "knn.cpp"

test: $(OBJS) test.o
	$(CXX) $(CPPFLAGS) -o test $^

depend: .depend

.depend: $(SRCS)
	$(RM) ./.depend
	$(CXX) $(CPPFLAGS) -MM $^>>./.depend;

clean:
	$(RM) $(OBJS)
	$(RM) *o autovalores
	$(RM) *o knn
	$(RM) *o tp2

distclean: clean
	$(RM) *~ .depend

include .depend
