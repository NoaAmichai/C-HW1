CC=gcc
AR=ar
FLAGS= -Wall -g
BASIC = basicClassification.o
LOOPS=advancedClassificationLoop.o
RECURSION=advancedClassificationRecursion.o

all:loops recursives loopd recursived mains maindloop maindrec

loopd: libclassloops.so
loops: libclassloops.a
recursives: recursives.a
recursived: libclassrec.so

# creat lib
recursives.a: $(BASIC) $(RECURSION)
	$(AR) -rcs libclassrec.a $(BASIC) $(RECURSION)

libclassrec.so: $(BASIC) $(RECURSION)
	$(CC) -shared -o libclassrec.so $(BASIC) $(RECURSION)

libclassloops.a: $(BASIC) $(LOOPS)
	$(AR) -rcs libclassloops.a $(BASIC) $(LOOPS)

libclassloops.so: $(BASIC) $(RECURSION)
	$(CC) -shared -o libclassloops.so $(BASIC) $(RECURSION)

#creat o
advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationRecursion.c

advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationLoop.c

basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(FLAGS) -c basicClassification.c

#creat mains


#recursived:$(BASIC) $(RECURSION) NumClass.h
#	$(CC) -shared -o libclassrec.so $(BASIC) $(RECURSION)
#
#loops: $(BASIC) $(LOOPS) NumClass.h
#	$(AR) rcu libclassloops.a $(BASIC) $(LOOPS) NumClass.h
#
#loopd: $(BASIC) $(LOOPS) NumClass.h
#	$(CC) -shared -o libclassloops.so $(BASIC) $(LOOPS)

mains: main.o recursives.a
	$(CC) $(FLAGE) -o mains main.o recursives.a

maindloop: main.o libclassloops.so
	$(CC) $(FLAGE) -o maindloop main.o ./libclassloops.so

maindrec: main.o libclassrec.so
	$(CC) $(FLAGE) -o maindrec main.o ./libclassrec.so

main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all

clean:
	rm -f *.o *.a *.so 


#all: libmylib.so libmylib.a progmains progmaind
#
#progmains: $(OBJECTS_MAIN) libmylib.aibmylib.a
#
#progmaind: $(OBJECTS_MAIN)
#	$(CC) $(FLAGS) -o progmaind $(OBJECTS_MAIN) ./libmylib.so
#
#libmylib.so: $(OBJECTS_LIB)
#	$(CC) -shared -o libmylib.so $(OBJECTS_LIB)
#
#libmylib.a: $(OBJECTS_LIB)
#	$(AR) -rcs libmylib.a $(OBJECTS_LIB)