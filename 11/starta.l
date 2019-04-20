%{
int count=0;
%}
%%
(a|A)[a-z]*[0-9]*(b|B) count++;
. {};
%%
int main()
{
yyin=fopen("words.txt","r");
yylex();
printf("\nWords starting with a and ending with b : %d\n",count);
}
int yywrap(){
return 1;
}
