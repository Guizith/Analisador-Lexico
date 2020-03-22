#include <iostream>
#include <stdio.h>
#include <string.h>

char stc [255];
int p =0;
int tempn;
char temps[255];
int crn=0;
int crs =0;
int crv =0;
char v[255];


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
	

	
	//e0();
	
	
	return 0;
}

void e0(){
	
	if((stc[p] >= 65 && stc[p]<=90) ||(stc[p] >= 97 && stc[p]<=122) ){
	
		printf("\n e0 achei letra: %c",stc[p]);
		p++;
		//sig1();
		e1();
	}else if(stc[p] >= 48 && stc[p]<=57){
		printf("\n e0 achei num: %c",stc[p]);
		p++;
		//sig4();
		e2();
	}else if(stc[p]== ' '){
		printf("\n e0 achei espaco: %c",stc[p]);
		p++;
		e0();
	}else{
		exit(0);
	}
}


void e1(){
	
if((stc[p] >= 65 && stc[p]<=90) ||(stc[p] >= 97 && stc[p]<=122) ){
	
		printf("\n e2 achei letra: %c",stc[p]);
		p++;
		//sig2();
		e1();
	}else if(stc[p] >= 48 && stc[p]<=57){
		printf("\n e1 achei num: %c",stc[p]);
		p++;
		//sig2();
		e1();
	}else{
		printf("\n else e1 letra: %c",stc[p]);
		p++;
		//sig3();
		e0();
	}
	
}

void e2(){	
	if(stc[p] >= 48 && stc[p]<=57){
		printf("\n e2 achei num: %c",stc[p]);
		p++;
		//sig5();
		e2();
	}else{
		//printf("\n valor de p: %d",p);
		printf("\n else e2 letra: %c",stc[p]);
		p++;
		//sig6();
		e0();
	}
}


void sig1(){
	
	for(int i =0; i<crs;i++){
		temps[i]='\0';
	}
	temps[0] = stc[p];
	crs=1;
}

void sig2(){
	temps[crs] = stc[p];
	crs++;

}
void sig3(){
	int jfd = 0;
	temps[crs] = '\0';
	
	for ( int i =0; i< crv;i++){
		if(temps == v[i]){
			printf("%c", v[i]);
			jfd = 1;
		}	
	}
	if( jfd == 0){
		v[crv] == temps;
		printf("%c", v[crv]);
	}
	
}

void sig4(){	
	tempn = stc[p] - '\0';
}

void sig5(){
	tempn = (tempn*10)+(stc[p]-'\0')
	
}

void sig6(){
	printf("%d", tempn[crn]);	
}


