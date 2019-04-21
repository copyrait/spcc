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
struct stoliteral{
	char symbol[10];
	int value;
};
struct stosymbol{
	char symbol[10];
	int value;
};
struct stobase {
	char reg[10];
	char val[10];
};

void main(){
	int i,n,temp1,j=0,add=0,lc,k,flag=0,motflag=0,temp=0,nst,l,m,foundinst,foundinlit;
	char ois[] = "(0,15)";
	char str[10];
    struct stomot mot[10];
	struct stopot pot[10];
	struct stoprogram program[30];
	struct stoliteral literal[10];
	struct stoliteral symbol[10];
    struct stobase base[10];
	
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

	nst=add;
	add=0;
	for(i=0;i<6;i++) {
		if(program[i].op1[0]=='=') {
			strcpy(literal[add].symbol,program[i].op1);
			literal[add].value=lc;
			lc=lc+4;
			add++;
		}
		if(program[i].op2[0]=='=') {
			strcpy(literal[add].symbol,program[i].op2);
			literal[add].value=lc;
			lc=lc+4;
			add++;
		}
	}
    for(i=0;i<6;i++) {
		if(strcmp(program[i].instruction,"USING")==0){
			if(strcmp(program[i].op1,"*")==0) {
				strcpy(base[0].val,"0");
			} else {
				strcpy(base[0].val,program[i].op1);
			}
			strcpy(base[0].reg,program[i].op2);
		}
	}
	printf("\n\n======BT======\n");
	printf("Register no\tValue\n");
	printf("==============\n");
	printf("%s\t %s\n",base[0].reg,base[0].val);
	
	
}

