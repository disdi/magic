OBJS = main.o
CFLAGS = -O3

test : $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $@

.PHONY: clean

clean:
	rm -f *.o test
