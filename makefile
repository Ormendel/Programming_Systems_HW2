CC=gcc 
AR=ar
MAINOBJECTS=main.o
LIBOBJECTS=myBank.o myBank.h
LIBa=libmyBank.a
LIBso=libmyBank.so
FLAGS= -Wall -g 

all: myBankd myBanks mains maind 

mains: $(MAINOBJECTS) $(LIBa)
	$(CC) $(FLAGS) -o mains $(MAINOBJECTS) $(LIBa)
maind: $(MAINOBJECTS)
	$(CC) $(FLAGS) -o maind $(MAINOBJECTS) ./$(LIBso)

myBankd: $(LIBOBJECTS)
	$(CC) -shared -o $(LIBso) $(LIBOBJECTS)
myBanks: $(LIBOBJECTS)
	$(AR) -rcs $(LIBa) $(LIBOBJECTS)

main.o: main.c myBank.h
	$(CC) $(FLAGS) -c main.c
myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c -fPIC myBank.c

.PHONY: clean all
	mains maind 
clean: 
	rm -f *.o mains maind $(LIBso) $(LIBa)




