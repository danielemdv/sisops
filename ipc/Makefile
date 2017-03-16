PROGRAMS = pipe shm_cliente shm_servidor consumer producer redir pipe_exec background zombie
 
OBJS_PIPE = mainpipefork.o  sub_climesg.o  sub_mesgmine.o  sub_servmesg.o err.o 
 
SRCS = mainpipefork.c  sub_climesg.c  sub_mesgmine.c  sub_servmesg.c err.c mainshmcli.c mainshmserv.c pipe_exec.c background.c zombie.c
 
CC = gcc 
 
all:	$(PROGRAMS)
 
.c.o:	$(SRCS)
	$(CC) -c $*.c -o $@ -O
 
pipe:	$(OBJS_PIPE)
	$(CC) $(OBJS_PIPE)  -o $@  

background: background.o
	$(CC) background.o -o $@

zombie: zombie.o
	$(CC) zombie.o -o $@

pipe_exec: pipe_exec.o err.o
	$(CC) pipe_exec.o err.o -o $@

shm_cliente: mainshmcli.o err.o
	$(CC) mainshmcli.o err.o -o $@ -lrt -pthread

shm_servidor: mainshmserv.o err.o
	$(CC) mainshmserv.o err.o -o $@ -lrt -pthread
 
consumer: consumer.c
	$(CC) consumer.c -o $@ -lrt

producer: producer.c
	$(CC) producer.c -o $@ -lrt

redir: redir.c
	$(CC) redir.c -o $@ 

clean:	
	rm -f $(OBJS_PIPE) core *~ \#* *.o $(PROGRAMS) salida.txt 
