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
    imdb_db s[250];
    FILE *f;
    f=fopen("imdb_db.txt","r");
    int i,flag;
    char a[50];
    for(i=0; i<250; i++)
    {
        fscanf(f,"%d-%[^-]-%d-%f-%[^-]-%d-%d-%[^-]-%[^-]-%d-%d",&s[i].rank,s[i].name,&s[i].year,&s[i].rating,s[i].mrating,&s[i].rntime,&s[i].mtascr,s[i].lng,s[i].cntry,&s[i].budget,&s[i].gross);
    }
    for(;;)
    {
        int n;
        puts("press 1 to find the movie details by rank");
        puts("press 2 to find the movies by MPAA ratings");
        puts("press 3 to find the movie of longest length");
        puts("press 4 to find the movie of shortest length");
        puts("press 5 to find the movies of specified Country");
        puts("press 6 to find the movies by certain time period");
        puts("press 7 to find the movies by budget");
        puts("press 8 to find the movies by Earnings");
        puts("press 9 to find the movies by rating range");
        puts("press 10 to find the movies by metascore range");
        puts("press 11 to exit");
        scanf("%d",&n);
        if(n==1)
        {
            puts( "Write the rank number to view the movie details");
            scanf("%d",&i);
            --i;
            system("COLOR 0A");
            puts("Rank:");
            printf("%d\n\n",s[i].rank);
            puts("Name:");
            puts(s[i].name);
            printf("\n");
            puts("Release Year:");
            printf("%d\n\n",s[i].year);
            puts("Rating:");
            printf("%.1f\n\n",s[i].rating);
            puts("MPAA Rating:");
            puts(s[i].mrating);
            printf("\n");
            puts("Runtime (in minute):");
            printf("%d\n\n",s[i].rntime);
            puts("Metascore:");
            printf("%d\n\n",s[i].mtascr);
            puts("Language:");
            puts(s[i].lng);
            printf("\n");
            puts("Country of Origin:");
            puts(s[i].cntry);
            printf("\n");
            puts("Budget($):");
            printf("%d\n\n",s[i].budget);
            puts("Gross($):");
            printf("%d\n\n",s[i].gross);

        }
        else if(n==2)
        {
            flag=0;
            puts("please put the desired rating(ex: G, PG, PG:13, R, Approved, Unrated");
            scanf("%s",&a);
            fflush(stdin);

            for(i=0; i<250; i++)
            {
                if(strcmp(a,s[i].mrating)==0)
                {
                    puts(s[i].name);
                    flag++;
                }
            }
            if(flag==0)
            {
                puts("no movies found, please try again");
            }

        }
        else if(n==3)
        {

        }

        else if(n==4)
        {
        }
        else if(n==5)
        {
        }
        else if(n==6)
        {
        }
        else if(n==7)
        {
        }
        else if(n==8)
        {
        }
        else if(n==9)
        {
        }
        else if(n==10)
        {
        }
        else if(n==11)
        {
            return 0;
        }
        else
        {
            puts("wrong input");
        }
    }
    fclose(f);
    return 0;
}
