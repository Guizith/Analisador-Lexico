#include <iostream>
#include <stdio.h>
#include <string>

//Variaveis globais
char stc [255];
int p =0;
int tempn;
char temps[255];
int crs =0;
int crv =0;
char v[100][255];


//funcoes
void e0();
void e1();
void e2();
void aceita();
void rejeita();
void sig1();
void sig2();
void sig3();
void sig4();
void sig5();
void sig6();


int main(int argc, char** argv) {

	printf("\n Digite a setenca:");
	scanf("%[^\n]", stc);
	fflush(stdin);
	
	//  Printa sentenca de entrada para confirmacao
	printf("Sentenca de entrada: ");
	for(int i = 0; i<25;i++){
		printf("%c", stc[i]);
}
	printf("\n");
	e0();
	
	return 0;
}

//============================================>>> Estados <<<============================================
void e0(){
	//if para letras
	if((stc[p] >= 65 && stc[p]<=90) ||(stc[p] >= 97 && stc[p]<=122) ){
		sig1();
		p++;
		e1();
	}
	//else if para numeros
	else if(stc[p] >= 48 && stc[p]<=57){
		sig4();
		p++;
		e2();
	}
	//Else if para espacos
	else if(stc[p]== ' '){
		p++;
		e0();
	}
	//Else estado final e print tabela var
	else{
		printf("\n\n =======> Tabela de Variaveis <======= ");
		for(int i=0;i<crv;i++){
			printf("\n i= %d  var = %s",i,v[i]);
		}
		exit(0);
	}
}


void e1(){
	//If para letras
	if((stc[p] >= 65 && stc[p]<=90) ||(stc[p] >= 97 && stc[p]<=122) ){
		sig2();
		p++;
		e1();
	}
	//else if para numeros
	else if(stc[p] >= 48 && stc[p]<=57){
		sig2();
		p++;
		e1();
	}
	//else para espaco
	else{
		sig3();
		e0();
	}
	
}

void e2(){	
	//If para numeros
	if(stc[p] >= 48 && stc[p]<=57){
		sig5();
		p++;
		e2();
	}
	//Else para espaco ou letras
	else{	
		sig6();
		e0();
	}
}

//============================================>>> Sigmas <<<============================================

void sig1(){
	//for para zerar temps
	for(int i =0; i<crs;i++){
		temps[i]='\0';
	}
	//atribuicao de tmps e variavel de controle(crs)
	temps[0] = stc[p];
	crs=1;
}

void sig2(){
	//Anexa no espaco vazio e incrementa variavel de controle
	temps[crs] = stc[p];
	crs++;
}

void sig3(){
	//variaveis auxiliares 
	int valid = 0;		//flag para saber qual variavel da tabela corresponde a temps
	int jfd = 0;
	temps[crs] = '\0';

	//for para comparacao de char por char de toda a temps com cada string variavel da tabela 
	int j;
	for ( int i =0; i<= crv;i++){
		if( crs == jfd){
		valid = i-1;
		i=600;
		}else{
			jfd =0;
		}
		for(j =0;j<crs ;j++){
			if(temps[j] == v[i][j]){
				jfd = 1;
			}

		}
	}
	//apartir da flag decide se apenas printa ou copia e printa
	if( jfd == 0){
		for(int j = 0; j<255;j++){
			v[crv][j]=temps[j];
		}
		printf("\n V(%s)", v[crv]);
		crv++;
	}else{
		printf("\n V(%s)", v[valid]);
	}	
}

void sig4(){	
	//tempn = stc[p] numerico
	tempn = stc[p] - '0';
}

void sig5(){
	//tempn eh a juncao dos digitos ex: tempn = 1 stc[p] = 1   tempm==11
	tempn = (tempn*10)+(stc[p] - '0');
}

void sig6(){
	//print variavel de tempn
	printf("\n N(%d)", tempn);	
}


