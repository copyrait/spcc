%{
int lines=0, words=0, s_l=0, c_l=0, num=0, spcl_char=0 ,i=0,nb=0;
%}
%%

\n {lines++; words++;}
[\t " "] words++;
[0-9] num++;
[a-z] s_l++;
[A-Z] c_l++;
. spcl_char++;
%%
int main()
{
yyin=fopen("abc.txt","r");
yylex();
printf("\nLines: %d\n",lines);
printf("Words : %d\n",words);
printf("Numbers: %d\n",num);
printf("Capital Letters: %d\n",c_l);
printf("Small Letters: %d\n",s_l);
}
int yywrap(){
return 1;
}
