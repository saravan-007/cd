#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char gram[100],part1[50],part2[50],modifiedgram[50],newgram[50];
    int i,j=0,k=0,l=0,pos;
    printf("Enter the production (A->):");
    fgets(gram,sizeof(gram),stdin);
    int len=strlen(gram);
    if(len>0 && gram[len-1]!='\n')
    {
        gram[len-1]='\0';
    }
    for(i=0;gram[i]!='\0' && gram[i]!='|';i++,j++)
    {
        part1[j]=gram[i];
    }
    part1[j]='\0';
    j=0;
    for(i=i+1;gram[i]!='\0';i++,j++)
    {
        part2[j]=gram[i];
    }
    part2[j]='\0';
    for(i=0;i<strlen(part1)&&i<strlen(part2);i++)
    {
        if(part1[i]==part2[i])
        {
            modifiedgram[k++]=part1[i];
            pos=i+1;
        }
        else
        {
            break;
        }
    }
    modifiedgram[k]='X';
    modifiedgram[k+1]='\0';
    for(i=pos,j=0;part1[i]!='\0';i++,j++)
    {
        newgram[j]=part1[i];
    }
    newgram[j++]='|';
    for(i=pos;part2[i]!='\0';i++,j++)
    {
        newgram[j]=part2[i];
    }
    newgram[j]='\0';
    printf("\nA->%s\n",modifiedgram);
    printf("X->%s\n",newgram);
    return 0;
}
