TARG=hello prob2 prob3 prob4 
CC=build-checker
CC1=cov-translate
CC1FLAGS=--dir analysis-dir
CC2=gcc
CC2FLAGS=-c
all: $(TARG) s7_test
hello:
	$(CC) hello
prob2:
	$(CC) prob2
prob3:
	$(CC) prob3
prob4:
	$(CC) prob4
s7_test: 
	$(CC1) $(CC1FLAGS) $(CC2) $(CC2FLAGS) $@.c
clean:
	rm -r $(TARG) analysis-dir
