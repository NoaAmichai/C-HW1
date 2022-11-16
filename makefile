CC=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_LIB=mylib.o
FLAGS= -Wall -g
BASIC=basicClassification.o
LOOPS=advancedClassificationLoop.o
RECURSION=advancedClassificationRecursion.o


all: libmylib.so libmylib.a progmains progmaind
progmains: $(OBJECTS_MAIN) libmylib.a
	$(CC) $(FLAGS) -o progmains $(OBJECTS_MAIN) libmylib.a
progmaind: $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o progmaind $(OBJECTS_MAIN) ./libmylib.so
libmylib.so: $(OBJECTS_LIB)
	$(CC) -shared -o libmylib.so $(OBJECTS_LIB)
libmylib.a: $(OBJECTS_LIB)
	$(AR) -rcs libmylib.a $(OBJECTS_LIB)


recursives:$(BASIC) $(RECURSION) NumClass.h
recursived:$(BASIC) $(RECURSION) NumClass.h
loops: $(BASIC) $(LOOPS) NumClass.h
	$(AR) rcu libclassloops.a $(BASIC) $(LOOPS) NumClass.h
	ranlib libclassloops.a
loopd: $(BASIC) $(LOOPS) NumClass.h
	$(CC) -shared -o libclassloops.so $(BASIC) $(LOOPS)
advancedClassificationRecursion.o:advancedClassificationRecursion.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationRecursion.c

advancedClassificationLoop.o:advancedClassificationLoop.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationLoop.c

basicClassification.o:basicClassification.c NumClass.h
	$(CC) $(FLAGS) -c basicClassification.c

main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c main.c
maindloop: advancedClassificationLoop.c



.PHONY: clean all

clean:
	rm -f *.o *.a *.so progmains progmaind