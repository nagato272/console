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
	#define checker(x, msg) 		\
	if(x) {		 			\
		perror(msg); 			\
		_exit(EXIT_FAILURE); 		\
	}
#else
	#error, "COST MAX ALREADY DEFINED"
#endif


main(int argc, char *argv[], char *envp[]){
	setlocale(LC_CTYPE, " ");
	checker(argc != 1, "errore! il programma non accetta parametri");

	unsigned short int index = 1;
	char
		get_command[MAX],
		exit_command[] = "exit";

	// la printf restituisce un valore intero in base al numero di caratteri che stampa
	while(index)(printf(">>>")-3+strncmp(fgets(get_command, sizeof(get_command), stdin), exit_command, strlen(exit_command))==0)?--index:system(get_command);
}

