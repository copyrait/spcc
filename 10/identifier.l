%{
#include<stdio.h>
int count=0;
int add_word(char *word);
int lookup_word(char *word);
%}
%%
#include<[a-z]*.h> {printf("%s is an include statement\n",yytext);}
main|void|int|return {printf("%s is a keyword\n",yytext);}
[a-z]([a-z]|[0-9])* {add_word(yytext); }
\{|\( printf("%s is opening bracket\n",yytext);
\}|\) printf("%s is closing bracket\n",yytext);
[0-9]* {printf("%s is a number\n",yytext);}
[=|+|-] {printf("%s is a operator\n",yytext);}
. {}
%%
void main(){
yyin = fopen("test.c","r");
yylex();
}
struct word{
char *word_name;
int count;
struct word *next;
};
struct word *word_list;

int add_word(char *word)
{
	struct word *wp;
	int _count = lookup_word(word);
	if(_count!=-1)
	{
		printf("%s is identifier ,count=%d\n", word, _count);
		return 0;
	}
	count++;
	wp = (struct word*)malloc(sizeof(struct word));
	wp->next = word_list;
	wp->word_name = (char *)malloc(strlen(word)+1);
	strcpy(wp->word_name, word);
	wp->count=count;
	word_list=wp;
	printf("%s added to word list as identifier, count = %d\n",word, count);
	return 1;
}

int lookup_word(char *word)
{
	struct word *wp = word_list;
	while(wp){
			if(strcmp(wp->word_name, word)==0)
			{
				return wp->count ;
			}
			wp = wp->next;
		}
	return -1;

}

int yywrap()
{
return 1;
}
