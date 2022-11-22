CC =gcc
AR =ar
FLAGS = -Wall -g
LOOP = advancedClassificationLoop.o basicClassification.o
RECURSION = advancedClassificationRecursion.o basicClassification.o
NUM_H = NumClass.h
MAIN_O = main.o

.PHONY: all clean loops recursives recursived loopd 

all:loops recursives recursived loopd mains maindloop maindrec

loops: libclassloops.a
recursives: libclassrec.a
recursived:libclassrec.so
loopd: libclassloops.so

#Create lib

libclassloops.a: $(LOOP)
	$(AR) -rcs libclassloops.a $(LOOP)
	 ranlib libclassloops.a

libclassrec.a: $(RECURSION)
	$(AR) -rcs libclassrec.a $(RECURSION)
	 ranlib libclassrec.a

libclassrec.so:$(RECURSION)
	$(CC) -fPIC -shared -o libclassrec.so $(RECURSION)
	
libclassloops.so: $(LOOP)
	$(CC) -fPIC -shared -o libclassloops.so $(LOOP)

#Create o files

$(MAIN_O): main.c $(NUM_H)
	$(CC) $(FLAGS) -c main.c

basicClassification.o: basicClassification.c $(NUM_H)
	$(CC) $(FLAGS) -c basicClassification.c

advancedClassificationLoop.o: advancedClassificationLoop.c $(NUM_H)
	$(CC) $(FLAGS) -c advancedClassificationLoop.c

advancedClassificationRecursion.o: advancedClassificationRecursion.c $(NUM_H)
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


