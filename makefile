CC =gcc
AR =ar
FLAGS = -Wall -g
BASIC = basicClassification.o
LOOP = advancedClassificationLoop.o
RECURSION = advancedClassificationRecursion.o
NUM_H = NumClass.h
MAIN_O = main.o

.PHONY: clean loops recursives recursived loopd all

all: loops recursives recursived loopd mains maindloop maindrec $(MAIN_O)

loops: libclassloops.a
recursives: libclassrec.a
recursived:libclassrec.so
loopd: libclassloops.so

#Create lib

libclassloops.a: $(BASIC) $(LOOP)
	$(AR) -rcs libclassloops.a $(BASIC) $(LOOP)
	ranlib libclassloops.a

libclassrec.a: $(BASIC) $(RECURSION)
	$(AR) -rcs libclassrec.a $(BASIC) $(RECURSION)
	ranlib libclassrec.a

libclassrec.so:$(BASIC) $(RECURSION)
	$(CC) -shared -o libclassrec.so $(BASIC) $(RECURSION)
	
libclassloops.so: $(BASIC) $(LOOP)
	$(CC) -shared -o libclassloops.so $(BASIC) $(LOOP)

#Create o files

$(MAIN_O): main.c $(NUM_H)
	$(CC) $(FLAGS) -c main.c

$(BASIC): basicClassification.c $(NUM_H)
	$(CC) $(FLAGS) -c basicClassification.c

$(LOOP): advancedClassificationLoop.c $(NUM_H)
	$(CC) $(FLAGS) -c advancedClassificationLoop.c

$(RECURSION): advancedClassificationRecursion.c $(NUM_H)
	$(CC) $(FLAGS) -c advancedClassificationRecursion.c

#Create mains
mains: $(MAIN_O) libclassrec.a
	$(CC) $(FLAGS) -o mains $(MAIN_O) libclassrec.a

maindloop: $(MAIN_O) libclassloops.so
	$(CC) $(FLAGS) -o maindloop $(MAIN_O) ./libclassloops.so

maindrec: $(MAIN_O) libclassrec.so
	$(CC) $(FLAGS) -o maindrec $(MAIN_O) ./libclassrec.so

clean:
	rm -f *.o *.a *.so mains maindrec maindloop	


