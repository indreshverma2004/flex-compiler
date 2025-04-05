all:
	flex compute.l
	gcc lex.yy.c main.c compute.c -o compute -lm

clean:
	rm -f compute lex.yy.c
