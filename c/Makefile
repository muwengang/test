APP=gethost
CC=gcc
OBJS=socket.o
ALL:$(APP)


$(APP):$(OBJS)
	$(CC) -o $(APP) $(OBJS)
%.o:%.c
	$(CC) -o $@ -c $<
clean:
	rm *.o $(APP)
