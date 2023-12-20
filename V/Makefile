VV := v
VFLAGS := -gc none -prod -autofree
CC := gcc
CFLAGS := -Os
DIR := bin

.PHONY: all clean

all: $(DIR)/ktpnik.o $(DIR)/sample.exe

clean:
	rm -rf $(DIR)/*.*

# IDK, Vlang didn't seems to support static linking between vlang
$(DIR):
	mkdir $(DIR)

$(DIR)/ktpnik.o : ktpnik/lib.v $(DIR)
	$(VV) -shared $(VFLAGS) -o $@.c $<
	$(CC) -r $(CFLAGS) -o $@.o $@.c

$(DIR)/sample.exe : sample/main.v ktpnik/lib.v $(DIR)
	$(VV) $(VFLAGS) -o $@ $<
	strip -x $@