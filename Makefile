OBJECTS_C = $(patsubst %.c,%.o,$(wildcard c/*.c))
OBJECTS_ASM = $(patsubst %.nasm,%.o,$(wildcard asm/*.nasm))

c/%.o: c/%.c
	gcc -c $< -o $@

asm/%.o: asm/%.nasm
	nasm -felf64 $< -o $@

blas_l1_asm.a: $(OBJECTS_ASM)
	ar rcs $@ $^

blas_l1_c.a: $(OBJECTS_C)
	ar rcs $@ $^

test.o: test.c
	gcc -c test.c -o test.o

test_c: blas_l1_c.a test.o
	gcc -o test_c test.o blas_l1_c.a

test_asm: blas_l1_asm.a test.o
	gcc -o test_asm test.o blas_l1_asm.a

clean:
	rm -f test_* **/*.o *.o *.a *.gch

all: test_c test_asm
