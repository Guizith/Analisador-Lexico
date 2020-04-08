#include <iostream>
#include <stdio.h>
#include <string>

//Variaveis globais
char stc [255];

int p =0;
int tempn;
char temps[255];
char tempc;
int crs =0;
int crv =0;
char v[100][255];
char pr[9][255];



void ipr(char p[], int pos){
	int i = 0;
	for(i = 0; i<255;i++){
		if(p[i]== '\0'){
			pr[pos][i]= p[i];
			i=600;
		}else{
			pr[pos][i]= p[i];
		}
	}
	
}
 
//funcoes
void e0();
void e1();
void e2();
void e3();
void e4();
void e5();
void e6();
void aceita();
void rejeita();
void sig1();
void sig2();
void sig3();
void sig4();
void sig5();
void sig6();
void sig7();
void sig8();
void sig9();
void sig10();



int main(int argc, char** argv) {


	ipr("IF",0);
	ipr("THEN",1);
	ipr("ELSE",2);
	ipr("GOTO",3);
	ipr("LET",4);
	ipr("END",5);
	ipr("PRINT",6);
	ipr("READ",7);
	ipr("OF",8);

	printf("\n Digite a setenca:");
	scanf("%[^\n]", stc);
	fflush(stdin);
	
	//  Printa sentenca de entrada para confirmacao
	printf("Sentenca de entrada: ");
	for(int i = 0; i<40;i++){
		printf("%c", stc[i]);
	}
	printf("\n");

	
	/*
	printf("reserva: \n");
	for(int i = 0; i<8;i++){
		printf("%s", pr[i]);
			printf("\n");
	}


	//teste sig 3 com palavra reservada
	temps[0] = 'I';
	temps[1] = 'T';
	
	v[0][0] = 'I';
	v[0][1] = 'E';
	v[0][2] = '\0';
	
	crv=1;
	crs=2;
	sig3();

			*/
		
		
	e0();
	
	return 0;
}
//IF2 2IF (A>10) THEN LET B:=20%ABC IF
//============================================>>> Estados <<<============================================
void e0(){

	//printf("\n E0, %c", stc[p]);
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
	else if(stc[p]== '(' || stc[p]== ')' || stc[p]== ';' || stc[p]== '>' || stc[p]== '<' || stc[p]== '=' || stc[p]== ',' || stc[p]== '+' || stc[p]== '-' || stc[p]== '*' ||
			stc[p]== '/' || stc[p]== '@' || stc[p]== '$' || stc[p]== '!' || stc[p]== '&' || stc[p]== '#' || stc[p]== '¨' || stc[p]== '^' || stc[p]== '_' || stc[p]== '.' ||
			stc[p]== '"' || stc[p]== '\''|| stc[p]== '~' || stc[p]== '[' || stc[p]== ']'){
		
		sig9(); 
		p++;
		e5();
	}
	else if(stc[p]== ':'){
		p++;
		e3();
	}else if( stc[p] == '%'){
		p++;
		e6();
	}
	//Else estado final e print tabela var
	else{
		printf("\n\n =======> Tabela de Variaveis <======= ");
		for(int i=0;i<crv;i++){
			printf("\n i= %d  var = %s",i,v[i]);
		}
		printf("\n\n =======> Tabela de Palavras reservadas <======= ");
		for(int i=0;i<9;i++){
			printf("\n i= %d  var = %s",i,pr[i]);
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
//	printf("\n E2");

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
void e3(){	
//	printf("\n E3");

//printf("\n e3 analisado agora: %c",stc[p]);
	if(stc[p] == '='){
		p++;
		e4();
	}else{
		sig7();
		e0();
	}
}
void e4(){	
//	printf("\n E4");

	//printf("\n e4:");
	sig8();
	e0();
}
void e5(){
//		printf("\n E5");

	sig10();
	e0();
}
void e6(){
	p=254;
	e0();
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
	int validd =0;
	int jfd = 600;
	int jfp =0;
	temps[crs] = '\0';

	int j;
	for ( int i =0; i<= 9;i++){
		for(j =0;j<crs ;j++){
			if(temps[j] == pr[i][j]){
				jfp++;
			}
		}
				
		if( crs == jfp && crs != 1){
			//printf("valei palavra reservada:");
			validd = i;
			i=600;
		}else{
			jfp =0;
		}
	}
//	printf(" \n jfp: %d",jfp);
	crs++;
	if(jfp == 0 ){
		jfd =0;
		//for para comparacao de char por char de toda a temps com cada string variavel da tabela 
		for ( int i =0; i<= crv;i++){
			jfd =0;
			for(j =0;j<crs ;j++){
				if(temps[j] == v[i][j]){
					jfd++;
				}else{
					jfd--;
				}
			}
		//	printf(" \n valor jfd: %d    valor crs %d",jfd, crs);
			if( crs == jfd){
			valid = i;
			i=600;
			}else{
				jfd =0;
			}
		}
	}
	//apartir da flag decide se apenas printa ou copia e printa
	if( jfd == 0){
		for(int j = 0; j<255;j++){
			v[crv][j]=temps[j];
		}
		printf("\n V(%d)", crv);
		crv++;
	}
	else if(jfp != 0){
			printf("\n PR(%d)",validd);	
	}
	else if( jfp ==0 && jfd != 0){
		printf("\n V(%d)", valid);
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
void sig7(){
	//print variavel de tempn
	printf("\n :");	
}
void sig8(){
	//print variavel de tempn
	printf("\n :=");	
}
void sig9(){
//	printf("\n STC %c, %c , TEMPC %c", stc[p], stc[p-1], tempc);
	tempc = stc[p];	
}
void sig10(){
	//print variavel de tempn
	printf("\n %c", tempc);	
}


