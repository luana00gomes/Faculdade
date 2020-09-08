#include <stdio.h>
#include <string.h> //para strcmp
#include <unistd.h> //para fork e pid_t     | Dá acesso a POSIX
#include <stdlib.h> // para exit

void pwd(){
	char dir_name[256];
	getcwd(dir_name, 256);
	printf("%s\n", dir_name);
}

void cd(char *path){
	if(chdir(path) != 0) //Troca para o caminho, else, retorna 0 e printa
		printf("Impossivel trocar para o diretorio %s\n", path);
}

void ler(char *file){
	printf("Lendo arquivo %s\n", file);
	
	FILE *arq = fopen(file, "r"); //abrindo arquivo
	char *texto;
	
	
	texto = (char*) malloc (1000*sizeof(char));
	int i=0;
	while(!feof(arq)){
		fscanf(arq, "%n", &texto[i]); // armazena texto do arquivo na variável
		printf("%s", &texto[i]);
		i++;
	 }
	
	fclose(arq);
	
}

int main()
{
    //Tamanho da Linha de Comando do interpretador
    char c[256];
	pid_t pid;
	int status;
	
    //Loop para principal do SHELL
    while(1) {
		//Entrada de comandos
        printf("SHELL>");
        scanf("%[^\n]",c);
        getchar();  
		if(!strcmp(c, "pwd")) {
			pid = fork();
			if(pid == 0) {
				pwd();
				exit(1);
			} else {
				waitpid(-1, &status, 0); //serve para pausar o programa até encerrar o processo filho
			}
		} else if(!strncmp(c, "cd", 2)) {
			char tmp[256];
			strncpy(tmp, &c[3], strlen(c)-3); // o comando vai ser do tipo: cd+ +"caminho". Esta linha filtra isso para encontrar apenas o caminho
			tmp[strlen(c)-3] = '\0';
			cd(tmp);
		} else if(!strncmp(c, "ler", 3)) {
			char tmp[256];
			strncpy(tmp, &c[4], strlen(c)-4); // o comando vai ser do tipo: ler+ +"nomeArquivo". Esta linha filtra isso para encontrar apenas o nome do arquivo
			tmp[strlen(c)-4] = '\0';
			pid = fork();
			if(pid == 0) {
				ler(tmp);
				exit(1);
			} else {
				waitpid(-1, &status, 0);
			}	
		} else if(!strcmp(c, "exit")) {
			return 0;
		} else {
			printf("Comando nao encontrado, tente novamente.\n");
		}
	}
}

