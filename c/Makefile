APP=gethost
CC=gcc
OBJS=socket.o
ALL:$(APP)


msgsend:msgsend.o
	$(CC) -o $@ $<

msgrecv:msgreceive.o
	$(CC) -o $@ $<

strstr:strstr.o
	$(CC) -o $@ $<
	
$(APP):$(OBJS)
	$(CC) -o $(APP) $(OBJS)
%.o:%.c
	$(CC) -o $@ -c $<
clean:
	rm *.o $(APP) msgsend msgrecv strstr
