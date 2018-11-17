all: shell.o echo.o \
	ls touch rm
	gcc shell.o echo.o -o 'mshell'
shell.o: shell.c
	gcc shell.c shell.h -c
echo.o: echo.c
	gcc echo.c -c
ls: 
	gcc ls.c -o ./bin/ls
rm:
	gcc rm.c -o ./bin/rm
touch:	
	gcc touch.c -o ./bin/touch
clean:
	rm echo.o shell.o shell.h.gch



