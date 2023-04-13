CC = g++-12
CFLAGS = -std=c++14 -O2

SRCS = main.cpp 
OBJS = $(SRCS:.cpp=.o)

TEST_CASES_NUMBER := $(shell seq 1 5)

RANGE = 1 2

INPUT_PREFIX := tests/input

OUTPUT_PREFIX := output

all: program
	for j in $(RANGE); do \
		for i in $(TEST_CASES_NUMBER); do \
			echo "./program --test $$j < $(INPUT_PREFIX)$$i.in > $(OUTPUT_PREFIX)$$j$$i.txt"; \
			./program $$j --test < $(INPUT_PREFIX)$$i.in > $(OUTPUT_PREFIX)$$j$$i.txt; \
		done; \
		for i in $(TEST_CASES_NUMBER); do \
			diff -q -bB -y $(OUTPUT_PREFIX)$$j$$i.txt tests/output$$i.out; \
		done; \
		echo "Executing program with $$j"; \
		./program $$j; \
	done

program: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o program

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) program output*
