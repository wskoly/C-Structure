#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct imdb_db
{
    int rank;
    char name[100];
    int year;
    float rating;
    char mrating[10];
    int rntime;
    int mtascr;
    char lng[20];
    char cntry[20];
    int budget;
    int gross;
};
int main()
{
    struct imdb_db s[100];
    FILE *f;
    f=fopen("imdb_db.txt","r");
    int i,b,c,flag,m,m_ind;
    float d,e;
    char a[50];
    for(i=0; i<100; i++)
    {
        fscanf(f,"%d-%[^-]-%d-%f-%[^-]-%d-%d-%[^-]-%[^-]-%d-%d",&s[i].rank,s[i].name,&s[i].year,&s[i].rating,s[i].mrating,&s[i].rntime,&s[i].mtascr,s[i].lng,s[i].cntry,&s[i].budget,&s[i].gross);
    }

    char h[50];
    char g[100];
    gets(h);
    //fflush(stdin);
    // m=strlen(h);
    //puts(h);
    for(i=0; i<10; i++)
    {
        strcpy(g,s[i].name);
        //puts(g);
        int j=0;
        flag=0;
        while ( h[j] != '\0' )
        {
            if( g[j]=='\0' )
            {
                flag++;
            }
            else if( h[j] < g[j] )
            {
                flag++;
            }
            else if( h[j] > g[j] )
            {
                flag++;
            }
            j++;
        }
        if(flag==0)
        {
            puts(g);
        }


    }


    fclose(f);
    return 0;
}
