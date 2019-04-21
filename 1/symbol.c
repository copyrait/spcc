#include<stdio.h>
#include<string.h>
struct stomot{
	char opcode[10];
	int length;
};
struct stopot{
	char opcode[10];
	char routine[10];
};

struct stoprogram{
	char symbol[10];
	char instruction[10];
	char op1[10];
	char op2[10];
	int lc;
};
struct stosymbol{
	char symbol[5];
	int value;
};

void main(){
	int i,n,temp1,j=0,add=0,lc,k,flag=0,motflag=0,temp=0,nst,l,m,foundinst,foundinlit;
	char ois[] = "(0,15)";
	char str[10];
    struct stomot mot[10];
	struct stopot pot[10];
	struct stoprogram program[30];
	struct stosymbol symbol[5];
	
    strcpy(mot[0].opcode,"A");
	// strcpy(mot[1].opcode,"L");
	// strcpy(mot[2].opcode,"ST");
	mot[0].length=4;
	// mot[1].length=4;
	// mot[2].length=4;
	
	strcpy(program[0].symbol,"SAMPLE");
	strcpy(program[0].instruction,"START");
	strcpy(program[0].op1,"0");
	strcpy(program[0].op2," ");
	strcpy(program[1].symbol," ");
	strcpy(program[1].instruction,"USING");
	strcpy(program[1].op1,"*");
	strcpy(program[1].op2,"15");
	strcpy(program[2].symbol," ");
	strcpy(program[2].instruction,"A");
	strcpy(program[2].op1,"1");
	strcpy(program[2].op2,"FOUR");
	strcpy(program[3].symbol,"TEMP");
	strcpy(program[3].instruction,"EQU");
	strcpy(program[3].op1,"10");
	strcpy(program[3].op2,"");
	strcpy(program[4].symbol,"FOUR");
	strcpy(program[4].instruction,"DC");
	strcpy(program[4].op1,"F");
	strcpy(program[4].op2,"4");
	strcpy(program[5].symbol," ");
	strcpy(program[5].instruction,"END");
	strcpy(program[5].op1,"");
	strcpy(program[5].op2,"");
	printf("\n\n============PROGRAM===============\n");
	printf("SYMBOL\tINSTRUCTION\tOPERAND\t\n");
	printf("==================================\n");
	for(i=0;i<6;i++) {    
		temp1=0;
		for(j=0;j<3;j++){
			if((strcmp(mot[j].opcode,program[i].instruction))==0){
				temp=j;
				temp1=1;
				break;
			}
		}
		for(j=0;j<5;j++){
			if((strcmp(pot[j].opcode,program[i].instruction))==0){
				temp=j;
				temp1=0;
				break;
			}
		}
		if(temp1>0){ 
		printf("%s\t%s(%d)\t\t%s\t%s\t\n",program[i].symbol,program[i].instruction,mot[temp].length,program[i].op1,program[i].op2);
		}else{
		printf("%s\t%s>%s\t\t%s\t%s\t\n",program[i].symbol,program[i].instruction,pot[temp].routine,program[i].op1,program[i].op2);
		}
	}

	lc=0;
	//symbol table
	for(i=0;i<6;i++) {
		program[i].lc=lc;
		if(strcmp(program[i].symbol," ")!=0){
			strcpy(symbol[add].symbol,program[i].symbol);
			symbol[add].value=lc;
			add++;
		}
		for(j=0;j<3;j++) {
			if(strcmp(mot[j].opcode, program[i].instruction)==0) {
				lc=lc+mot[j].length;
				break;
			}
		}	
		if(strcmp(program[i].instruction, "DC")==0 || strcmp(program[i].instruction, "DS")==0) {
			lc=lc+4;
		}
	}
	
	printf("\n\n======ST======\n");
	printf("Symbol\tValue\n");
	printf("==============\n");
	for(i=0;i<add;i++) {
		printf("%s\t%d\n",symbol[i].symbol,symbol[i].value);
	}
}
