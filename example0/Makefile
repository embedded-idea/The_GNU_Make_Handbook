# target ... : prerequisites ...
# recipe 

app : main.o
#will give you a main.o object file
	gcc -o app main.o

main.o : main.c
#final generate excutble file
	gcc -c main.c

clean:
	rm *.o app