CC = gcc
OBJS = calculation.o sort.o

calculation: ${OBJS}
	${CC} ${OBJS} -o calculation 

calculation.o: 
	${CC} -c calculation.c

sort.o: 
	${CC} -c sort.c

${OBJS}: sort.h

.PHONY: clean
clean:
		rm -f ${OBJS}