all:
	flex compute.l
	gcc -o main main.c compute.c lex.yy.c -lm
