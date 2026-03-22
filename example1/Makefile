app : main.o add.o sub.o mul.o div.o eat.o \
	play.o study.o sleep.o 
	gcc -o app main.o add.o sub.o mul.o div.o \
	 eat.o play.o study.o sleep.o

main.o : main.c main.h
	gcc -c main.c
add.o : add.c add.h main.h
	gcc -c add.c
sub.o : sub.c sub.h main.h
	gcc -c sub.c
mul.o : mul.c mul.h main.h
	gcc -c mul.c
div.o : div.c div.h main.h
	gcc -c div.c
eat.o : eat.c eat.h main.h
	gcc -c eat.c
play.o : play.c play.h main.h
	gcc -c play.c
study.o : study.c study.h main.h
	gcc -c study.c
sleep.o : sleep.c sleep.h main.h
	gcc -c sleep.c

clean :
	rm app main.o add.o sub.o mul.o \
	div.o eat.o play.o study.o sleep.o
