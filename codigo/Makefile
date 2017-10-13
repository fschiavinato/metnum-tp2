CC=gcc
CXX=g++ -std=c++11
RM=rm -f
CPPFLAGS=-g 
LDFLAGS=-g 
LDLIBS=-g

SRCS=autovalores.cpp
OBJS=$(subst .cpp,.o,$(SRCS))
tp2=tp2.cpp
knn=knn.cpp

all: $(OBJS)
	$(CXX) $(LDFLAGS) -o autovalores $(OBJS) $(LDLIBS)

tp2:
	$(CXX) $(LDFLAGS) -o tp2 $(tp2) $(LDLIBS)

knn: knn.o	
	g++ --std=c++11 -o knn knn.o 
 
knn.o: knn.cpp
	g++ --std=c++11 -c "knn.cpp"

depend: .depend

.depend: $(SRCS)
	$(RM) ./.depend
	$(CXX) $(CPPFLAGS) -MM $^>>./.depend;

clean:
	$(RM) $(OBJS)
	$(RM) *o tp2
	$(RM) *o knn

distclean: clean
	$(RM) *~ .depend

include .depend
