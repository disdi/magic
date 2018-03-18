OBJS = main.o

test : $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $@

.PHONY: clean

clean:
	rm -f *.o main
