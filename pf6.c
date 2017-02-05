#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<string.h>
#define L 16
int main()
{
    int i,test;
    char binary[L],dup[L],a[L];
    void input(char binary[]);
    int check(char binary[]);
    void compl(char binary[],char a[]);
    //clrscr();
    printf("Enter Binary no of Maximum Length 16\n");
    input(binary);
    strcpy(dup,binary);
    test=check(binary);
    if(test==0)
    {
        printf("\nInvalid Binary Number.");
        exit(1);
    }
    printf("\nOriginal Binary No:%s",dup);
    compl(binary,a);
    printf("\n2's complement is %s",a);
    //getch();
    return 0;
}
void input(char binary[])
{
    printf("Enter Binary numbers(0 or 1) without spaces up to Max 16 bits:\n");
    scanf("%s",binary);
    return;
}

int check(char binary[])
{
    int i,l,x=1;
    l=strlen(binary);
    for(i=0; i<l; i++)
    {
        if(!((binary[i]=='0')||(binary[i]=='1')))
            x=0;
        break;
    }
    return(x);
}
void compl(char binary[],char a[])
{
    int check;
    /*char a[L];*/
    int l,i;
    l=strlen(binary);
    for(i=l-1; i>=0; i--)
    {
        if(binary[i]=='0')
            a[i]='1';
        else
            a[i]='0';
    }
    for(i=l-1; i>=0; i--)
    {
        if(i==l-1)
        {
            if(a[i]=='0')
                a[i]='1';
            else
            {
                a[i]='0';
                check=1;
            }

        }
        else
        {
            if((check==1)&&(a[i]=='0'))
            {
                a[i]='1';
                check=0;
            }

            else if((check==1)&&(a[i]=='1'))
            {
                a[i]='0';
                check=1;
            }
        }
    }
    a[l]='\0';
    return;
}
