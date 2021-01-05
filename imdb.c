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

    for(;;)
    {
        printf("Imdb top 100 movie Database\nCreated by Wahid Sadique Koly\n------------------------------\n");
        system("COLOR 0F");
        int n;
        puts("press 1 to find the movie details by rank");
        puts("press 2 to find the movies by MPAA ratings");
        puts("press 3 to find the movies of specified Country");
        puts("press 4 to find the movies by certain time period");
        puts("press 5 to find the movies by budget");
        puts("press 6 to find the movies by profit");
        puts("press 7 to find the movies by rating range");
        puts("press 8 to find the movies by metascore range");
        puts("press 9 to find the movie of longest length");
        puts("press 10 to find the movie of shortest length");
        puts("press 11 to search a movie by name");
        puts("press 12 to exit");
        scanf("%d",&n);
        if(n==1)
        {
            for(;;)
            {
                puts( "Write the rank number to view the movie details press 0 to exit");
                scanf("%d",&i);
                if(i==0)
                {
                    break;
                }
                else if(i>0 && i<=100)
                {
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
                else
                {
                    puts("No movies found");
                }
            }
            system("cls");
        }
        else if(n==2)
        {
            for(;;)
            {
                flag=0;
                puts("please put the desired rating(ex: G, PG, PG:13, R, Approved, Unrated) press E to Exit");
                scanf("%s",&a);
                fflush(stdin);
                system("COLOR F0");
                if(strcmp(a,"E")==0)
                {
                    break;
                }
                else
                {

                    for(i=0; i<100; i++)
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
            }
            system("cls");

        }
        else if(n==3)
        {
            for(;;)
            {
                flag=0;
                printf("Insert the name of the country, or press E to exit: ");
                scanf("%s",&a);
                if(strcmp(a,"E")==0)
                {
                    break;
                }
                else
                {
                    system("COLOR 2C");
                    for(i=0; i<100; i++)
                    {
                        if(strcmp(a,s[i].cntry)==0)
                        {
                            puts(s[i].name);
                            flag++;
                        }
                    }
                    if(flag==0)
                    {
                        puts("no movies found from this country, please try again");
                    }
                }
            }
            system("cls");

        }

        else if(n==4)
        {
            for(;;)
            {
                system("COLOR 84");
                flag=0;
                printf("Press 0 to extit, or\n");
                printf("Insert the year (ascending order): ");
                scanf("%d",&b);
                if(b==0)
                {
                    break;
                }

                else
                {
                    printf("to ");
                    scanf("%d",&c);
                    for(i=0; i<100; i++)
                    {
                        if(s[i].year>=b && s[i].year<=c)
                        {
                            printf("%s ",s[i].name);
                            printf("(%d)\n",s[i].year);
                            flag++;
                        }
                    }
                    if(flag==0)
                    {
                        puts("no movies found from this Time range, please try again");
                    }
                }
            }
            system("cls");
        }
        else if(n==5)
        {
            for(;;)
            {
                system("COLOR E2");
                puts("press 1 to find the movie of the highest budget"); //should check the number of movies before submission, if any less all the loop range should be changed with it
                puts("press 2 to find the movie of the lowest budgets");
                puts("press 3 to Exit");
                scanf("%d",&b);
                if(b==1)
                {
                    m=s[0].budget;
                    m_ind=0;
                    for(i=0; i<100; i++)
                    {
                        if(s[i].budget>m)
                        {
                            m=s[i].budget;
                            m_ind=i;
                        }
                    }
                    printf("%s, Budget $%d\n",s[m_ind].name,s[m_ind].budget);
                }
                else if(b==2)
                {
                    m=s[0].budget;
                    m_ind=0;
                    for(i=0; i<100; i++)
                    {
                        if(s[i].budget<m)
                        {
                            m=s[i].budget;
                            m_ind=i;
                        }
                    }
                    printf("%s, Budget $%d\n",s[m_ind].name,s[m_ind].budget);
                }
                else if(b==3)
                {
                    break;
                }
                else
                {
                    puts("wrong input");
                }
            }
            system("cls");

        }
        else if(n==6)
        {
            for(;;)
            {
                system("COLOR F0");
                puts("press 1 to find the movie of the highest profit");
                puts("press 2 to find the movie of the lowest profit");
                puts("press 3 to Exit");
                scanf("%d",&b);
                if(b==1)
                {
                    m=(s[0].gross-s[0].budget);
                    m_ind=0;
                    for(i=0; i<100; i++)
                    {
                        if((s[i].gross-s[i].budget)>m)
                        {
                            m=(s[i].gross-s[i].budget);
                            m_ind=i;
                        }
                    }
                    printf("%s, Profit(gross-budget) $%d\n",s[m_ind].name,m);
                }
                if(b==2)
                {
                    m=(s[0].gross-s[0].budget);
                    m_ind=0;
                    for(i=0; i<100; i++)
                    {
                        if((s[i].gross-s[i].budget)<m)
                        {
                            m=(s[i].gross-s[i].budget);
                            m_ind=i;
                        }
                    }
                    printf("%s, Profit(gross-budget) $%d\n",s[m_ind].name,m);
                }
                else if(b==3)
                {
                    break;
                }
                else
                {
                    puts("wrong input");
                }
            }
            system("cls");
        }
        else if(n==7)
        {
            for(;;)
            {
                system("COLOR F1");
                flag=0;
                printf("Press 0 to extit, or\n");
                printf("Insert the rating (ascending order): ");
                scanf("%f",&d);
                if(d==0)
                {
                    break;
                }

                else
                {
                    printf("to ");
                    scanf("%f",&e);
                    for(i=0; i<100; i++)
                    {
                        if(s[i].rating>=d && s[i].rating<=e)
                        {
                            puts(s[i].name);
                            flag++;
                        }
                    }
                    if(flag==0)
                    {
                        puts("no movies found from this rating range, please try again");
                    }
                }
            }
            system("cls");
        }
        else if(n==8)
        {
            for(;;)
            {
                system("COLOR F6");
                flag=0;
                printf("Press 0 to extit, or\n");
                printf("Insert the metascore (ascending order): ");
                scanf("%d",&b);
                if(b==0)
                {
                    break;
                }

                else
                {
                    printf("to ");
                    scanf("%d",&c);
                    for(i=0; i<100; i++)
                    {
                        if(s[i].mtascr>=b && s[i].mtascr<=c)
                        {
                            puts(s[i].name);
                            flag++;
                        }
                    }
                    if(flag==0)
                    {
                        puts("no movies found from this Time range, please try again");
                    }
                }
            }
            system("cls");
        }
        else if(n==9)
        {
            for(;;)
            {
                system("COLOR F5");
                puts("press 1 to find the movie of the longest length");
                puts("press 2 to Exit");
                scanf("%d",&b);
                if(b==1)
                {
                    m=s[0].rntime;
                    m_ind=0;
                    for(i=0; i<100; i++)
                    {
                        if(s[i].rntime>m)
                        {
                            m=s[i].rntime;
                            m_ind=i;
                        }
                    }
                    printf("%s, Runtime: %d minute\n",s[m_ind].name,s[m_ind].rntime);
                }
                else if(b==2)
                {
                    break;
                }
                else
                {
                    printf("wrong input");
                }
            }
            system("cls");
        }
        else if(n==10)
        {
            for(;;)
            {
                system("COLOR 1C");
                puts("press 1 to find the movie of the shortest length");
                puts("press 2 to Exit");
                scanf("%d",&b);
                if(b==1)
                {
                    m=s[0].rntime;
                    m_ind=0;
                    for(i=0; i<100; i++)
                    {
                        if(s[i].rntime<m)
                        {
                            m=s[i].rntime;
                            m_ind=i;
                        }
                    }
                    printf("%s, Runtime: %d minute\n",s[m_ind].name,s[m_ind].rntime);
                }
                else if(b==2)
                {
                    break;
                }
                else
                {
                    puts("wrong input");
                }
            }
            system("cls");
        }
        else if(n==11)
        {
            for(;;)
            {
                system("COLOR 1C");
                char h[50];
                char g[100];
                int lf=0;
                scanf("%s",&h);
                fflush(stdin);
                for(i=0; i<100; i++)
                {
                    strcpy(g,s[i].name);
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
                        lf=1;
                    }

                }
                if(lf!=1)
                {
                    puts("nothing found");
                }
                if(strcmp(h,"E")==0){
                    break;
                }
            }
            system("cls");
        }

        else if(n==12)
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
