#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>


#if __unix__
	extern void _exit(register int);
	#include <unistd.h>
	#include <sys/types.h>
	#include <sys/times.h>
#else
	#error, "sorgente non compilabile! Il sistema operativo deve essere Unix-Like"
#endif


#ifndef MAX
	#define MAX 1024
#else
	#error, "COST MAX ALREADY DEFINED"
#endif


#ifndef checker
	#define checker(x, msg) if(x) { perror(msg); _exit(EXIT_FAILURE); }
#else
	#error, "COST checker ALREADY DEFINED"
#endif


int main(int argc, char *argv[], char *envp[]){
	checker(argc != 1, "errore! il programma non accetta parametri");

	setlocale(LC_CTYPE, " ");
	unsigned short int index = 1;
	char
		get_command[MAX],
		exit_command[] = "exit";

	while(index){
		printf(">>>");	
		(strncmp(fgets(get_command, sizeof(get_command), stdin), exit_command, strlen(exit_command)) == 0)? index-- : system(get_command);
	}
	return EXIT_SUCCESS;
}

