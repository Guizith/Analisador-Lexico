#include <iostream>
#include <stdio.h>
#include <string>

char stc [255];
int p =0;
int tempn;
char temps[255];
int crn=0;
int crs =0;
int crv =0;
char v[100][255];

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
	
	
	for(int i = 0; i<25;i++){
		printf("%c", stc[i]);
}
	
	e0();
		
		
		for(int i=0;i<3;i++){
			printf("\n i= %d  var = %s",i,*v[i]);
		}
	return 0;
}

//2a ab2 2ab 26 a b
//Estados: 0,2,0,1,1,0,2,0,1,0,2,2,0,1,0,1,0

void e0(){
	
	if((stc[p] >= 65 && stc[p]<=90) ||(stc[p] >= 97 && stc[p]<=122) ){
	
		//printf("\n e0 achei letra: %c",stc[p]);
		sig1();
		p++;
		e1();
	}else if(stc[p] >= 48 && stc[p]<=57){
		//printf("\n e0 achei num: %c",stc[p]);
		sig4();
		p++;
		e2();
	}else if(stc[p]== ' '){
	//	printf("\n e0 achei espaco: %c",stc[p]);
		p++;
		e0();
	}else{
		for(int i=0;i<4;i++){
			printf("\n i= %d  var = %s",i,v[i]);
		}
		exit(0);
	}
}


void e1(){
	
if((stc[p] >= 65 && stc[p]<=90) ||(stc[p] >= 97 && stc[p]<=122) ){
	
	//	printf("\n e1 achei letra: %c",stc[p]);
		sig2();
		p++;
		e1();
	}else if(stc[p] >= 48 && stc[p]<=57){
	//	printf("\n e1 achei num: %c",stc[p]);
		sig2();
		p++;
		e1();
	}else{
	//	printf("\n else e1 letra: %c",stc[p]);
		sig3();
		e0();
	}
	
}

void e2(){	
	if(stc[p] >= 48 && stc[p]<=57){
	//	printf("\n e2 achei num: %c",stc[p]);
		sig5();
		p++;
		e2();
	}else{
		//printf("\n valor de p: %d",p);
	//	printf("\n else e2 letra: %c",stc[p]);	
		sig6();
		e0();
	}
}

//==========================================================================Sigmas

void sig1(){
//	printf("\nEntrei sigma 1 letra: %c",stc[p]);
	for(int i =0; i<crs;i++){
		temps[i]='\0';
	}
	temps[0] = stc[p];
	//printf ("     ---atribui %c em temps e ficou: %c",stc[p],temps[0]);
	crs=1;
}

void sig2(){
//	printf("\nEntrei sigma 2 letra: %c",stc[p]);
	temps[crs] = stc[p];
	/*
	printf("  ---valor de tem 0 = %c", temps[0]);
	printf("  ---valor de tem 1 = %c", temps[1]);
	printf("  ---valor de tem 2 = %c", temps[2]);
	printf("  ---valor de crs = %d", crs);
	printf ("     ---anexei %c em temps e ficou: %c",stc[p],temps[crs]);
	*/
	crs++;

}
void sig3(){
	
//	printf("\nEntrei sigma 3 letra: %c",stc[p]);
	
	int jfd = 0;
	temps[crs] = '\0';
	
	for ( int i =0; i< crv;i++){
		if(temps == v[i]){
		//	printf("  ---validei o if de sig 3", temps[0]);	
			printf("\n V(%c)", v[i]);
			jfd = 1;
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
	}
	
}

void sig4(){	
//	printf("\nEntrei sigma 4 letra: %c",stc[p]);
	//printf(" ---- valor de temp antes: %d",tempn);
	tempn = stc[p] - '0';
//	printf(" ---- valor de temp depois: %d",tempn);
}

void sig5(){
//	printf("\nEntrei sigma 5 letra: %c",stc[p]);
//	printf(" ---- valor de tempn antes: %d",tempn);
	tempn = (tempn*10)+(stc[p] - '0');
	//printf(" ---- valor de temp n: %d",tempn);
	//printf(" paseeei");
}

void sig6(){
//	printf("\nEntrei sigma 6 letra: %c",stc[p]);
	printf("\n N(%d)", tempn);	
}


