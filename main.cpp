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
		
	int valid = 0;
	int jfd = 0;
	temps[crs] = '\0';
//	printf("\n ------ Entrei sigma 3  ----  temps: %s  , valor de crs: %d , valor de crv: %d",temps, crs, crv);
	
	int j;
	for ( int i =0; i<= crv;i++){
		//printf(" \n ---jft== %d, valor de crs %d", jfd, crs);
		if( crs == jfd){
		valid = i-1;
		i=600;
		}else{
			jfd =0;
		}
		
		for(j =0;j<crs ;j++){
			if(temps[j] == v[i][j]){
			//	printf("  ---validei o if de sig 3");	
				jfd = 1;
			}

		}
	}

	if( jfd == 0){
	//	printf("  ---validei o else de sig 3, valor de temps = %s   ---- valor de crv = %d", temps,crv);
			for(int j = 0; j<255;j++){
				v[crv][j]=temps[j];
			}
	
	//	printf("  ---validei a igualdade sig 3, valor de v em crv = %c", v[crv]);
		printf("\n V(%s)", v[crv]);
		crv++;
	}else{
		printf("\n V(%s)", v[valid]);
	}
	
	
	
/*
	int jfd = 0; //flag
	//Finaliza temps;
	temps[crs] = '\0';
	printf("seg3///");
	//pode ser que nao esteja validando if nunca!!!!
	//For para varrer a tabela de variavel
	int posv=0;
	int i,j ;
	for (i=0; i<crv;i++){
		for(j=0;j<255;j++){
			if(temps[j] == v[i][j] && temps[j] != ' ' &&  v[i][j] != '\0'){
				jfd =+ 1;
			}
		}
	}
	printf("\n valor de crs %d, valor de jfd %d", crs, jfd); 
	if( jfd == 0 || ftt == 0){
		//copia temps na tabela
		ftt++;
		for(int j = 0; j<255;j++){
			v[crv][j]=temps[j];
			
		}
		printf("\n entrei no for de copia");
		printf("\n V(%s)", v[crv+1]);
		//incrementa variavel de controle de tabela de variaveis
		crv++;
	}else if( jfd == crs){
		printf("\n entrei no else if");
		printf("\n V(%s)", v[posv]);
	}*/
	
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


