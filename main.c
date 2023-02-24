#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LINE_LEN 200
typedef struct
{

    int Day;
    int Month;
    int Year;
} date;
typedef struct
{
    int id;
    char last[20];
    char first[20];
    int salary;
    date Birth;
    char address[40];
    char email[40];
    char Mobileno[12];
} Employee;
Employee e[100];
int n=0;

Employee Parse(char *line)
{
    char delimiter[4] = ",-\n";
    Employee E;
    char* token = strtok(line, delimiter);
    int i = 0;
    while(token != NULL)
    {
        if(i==0)
        {
            E.id = atoi(token);
        }
        if(i==1)
        {
            strcpy(E.last, token);
        }
        if(i==2)
        {
            strcpy(E.first, token);
        }
        if(i == 3)
        {
            E.salary = atoi(token);
        }
        if(i==4)
        {
            E.Birth.Day = atoi(token);

        }
        if(i==5)
        {
            E.Birth.Month = atoi(token);
        }
        if(i==6)
        {
            E.Birth.Year = atoi(token);
        }

        if(i==7)
        {
            strcpy(E.address, token);
        }
        if(i==8)
        {
            strcpy(E.Mobileno, token);
        }

        if(i==9)
        {
            strcpy(E.email, token);
        }
        token = strtok(NULL, delimiter);
        i++;
    }
    return E;
}
void printlastname(i)
{

}
void printsalary()
{
    int i,pass;
    Employee t[n],x[n];
    for(i=0; i<n; i++)
    {
        t[i]=e[i];
    }
    for(pass=0; pass<n; pass++)
    {

        for(i=0; i<n-pass; i++)
        {
            if(t[i].salary<t[i+1].salary)
            {
                x[i]=t[i];
                t[i]=t[i+1];
                t[i+1]=x[i];
            }

        }
    }
    for(i=0; i<n; i++)
    {
        printf("\n(EMPLOYEE)\n");
        printf("\n ID:             %d", t[i].id);
        printf("\n Last:           %s", t[i].last);
        printf("\n First:          %s", t[i].first);
        printf("\n salary:         %d", t[i].salary);
        printf("\n birth day:      %d", t[i].Birth.Day);
        printf("\n birth month:    %d", t[i].Birth.Month);
        printf("\n birth year:     %d", t[i].Birth.Year);
        printf("\n address:        %s", t[i].address);
        printf("\n Mobile:         %s", t[i].Mobileno);
        printf("\n email:          %s", t[i].email);
    }
}
void printname()
{
    int i,pass;
    Employee t[n],x[n];
    for(i=0; i<n; i++)
    {
        t[i]=e[i];
    }
    for(pass=1; pass<n; pass++)
    {

        for(i=0; i<n-pass; i++)
        {
            if(strcasecmp(t[i].last,t[i+1].last)>0)
            {
                x[i]=t[i];
                t[i]=t[i+1];
                t[i+1]=x[i];
            }

        }
    }
    for(i=0; i<n; i++)
    {
        printf("\n(EMPLOYEE)\n");
        printf("\n ID:             %d", t[i].id);
        printf("\n Last:           %s", t[i].last);
        printf("\n First:          %s", t[i].first);
        printf("\n salary:         %d", t[i].salary);
        printf("\n birth day:      %d", t[i].Birth.Day);
        printf("\n birth month:    %d", t[i].Birth.Month);
        printf("\n birth year:     %d", t[i].Birth.Year);
        printf("\n address:        %s", t[i].address);
        printf("\n Mobile:         %s", t[i].Mobileno);
        printf("\n email:          %s", t[i].email);
    }
}
void printbirth()
{
    int i,pass;

    Employee t[n],x[n];
    for(i=0; i<n; i++)
    {
        t[i]=e[i];
    }

    for(pass=1; pass<n; pass++)
    {

        for(i=0; i<n-pass; i++)
        {
            if(t[i].Birth.Year>t[i+1].Birth.Year)
            {
                x[i]=t[i];
                t[i]=t[i+1];
                t[i+1]=x[i];
            }
            else if(t[i].Birth.Year==t[i+1].Birth.Year)
            {
                if(t[i].Birth.Month>t[i+1].Birth.Month)
                {
                    x[i]=t[i];
                    t[i]=t[i+1];
                    t[i+1]=x[i];
                }
                else if(t[i].Birth.Month==t[i+1].Birth.Month)
                {
                    if(t[i].Birth.Day>t[i+1].Birth.Day)
                    {
                        x[i]=t[i];
                        t[i]=t[i+1];
                        t[i+1]=x[i];
                    }
                }
            }



        }
    }


    for(i=0; i<n; i++)
    {
        printf("\n(EMPLOYEE)\n");
        printf("\n ID:             %d", t[i].id);
        printf("\n Last:           %s", t[i].last);
        printf("\n First:          %s", t[i].first);
        printf("\n salary:         %d", t[i].salary);
        printf("\n birth day:      %d", t[i].Birth.Day);
        printf("\n birth month:    %d", t[i].Birth.Month);
        printf("\n birth year:     %d", t[i].Birth.Year);
        printf("\n address:        %s", t[i].address);
        printf("\n Mobile:         %s", t[i].Mobileno);
        printf("\n email:          %s", t[i].email);
    }
}

void printemloyee(i)
{
    printf("\n(EMPLOYEE)\n");
    printf("\n ID:             %d", e[i].id);
    printf("\n Last:           %s", e[i].last);
    printf("\n First:          %s", e[i].first);
    printf("\n salary:         %d", e[i].salary);
    printf("\n birth day:      %d", e[i].Birth.Day);
    printf("\n birth month:    %d", e[i].Birth.Month);
    printf("\n birth year:     %d", e[i].Birth.Year);
    printf("\n address:        %s", e[i].address);
    printf("\n Mobile:         %s", e[i].Mobileno);
    printf("\n email:          %s", e[i].email);
}
void load(FILE *fp)
{
    int i = 0;
    char line[200];
    fp =  fopen("Company.txt", "r");
    if(fp != NULL)
    {
        printf("\nContents of file:\n");
        while(fgets(line, 200, fp) != NULL)
        {
            e[n]=Parse(line);
            n++;
        }
        fclose(fp);
    }
}
void print(f)
{
    int i;
    for(i=0; i<n; i++)
        printemloyee(i);

}


Employee search(char name[])
{
    int i,flag=0;
    for(i=0; i<n; i++)
    {
        if(strcasecmp(name,e[i].last)==0)
        {
            printemloyee(i);
            flag=1;
        }

    }
    if(flag==0)
        printf("\nno employees found\n\n");
}
int valid_number(char *p)
{
    int i=0;
    while(p[i]!='\0')
    {
        if(!(p[i]>='0' && p[i]<='9'))
            return 0;
        i++;
    }
    return 1;
}
int valid_email(char *email)
{
    int i=0,u=0,t=0;
    while(email[i]!='\0')
    {
        if(email[i]=='@')
            t=i;
        if(email[i]=='.')
            u=i;
        i++;
    }
    if(u==0||t==0)
        return 0;
    if(t-u<1)
        return 1;
    else
        return 0;
}
void add()
{
    char phone[100],id[100];
    getchar();
    do
    {
        printf("\nenter the ID: ");
        gets(id);
    }
    while(!valid_number(id));
    e[n].id=atoi(id);
    printf("\nenter the last name: ");
    scanf("%s",e[n].last);
    printf("\nenter the first n: ");
    scanf("%s",e[n].first);
    printf("\nenter the salary: ");
    scanf("%d",&e[n].salary);
    printf("\nenter the day: ");
    scanf("%d",&e[n].Birth.Day);
    printf("\nenter the Month: ");
    scanf("%d",&e[n].Birth.Month);
    printf("\nenter the Year: ");
    scanf("%d",&e[n].Birth.Year);
    printf("\nenter the address: ");
    scanf("%s",e[n].address);
    do
    {
        printf("\nenter the email: ");
        scanf("%s",e[n].email);
    }
    while(!valid_email(e[n].email));
    getchar();
    do
    {
        printf("\nenter the mobile number: ");
        gets(e[n].Mobileno);
    }
    while(!valid_number(e[n].Mobileno));

    n=n+1;

}
/*

*/
void save(FILE *fp)
{
    int i;

    fp =  fopen("Company.txt", "w");
    for (i=0; i<n; i++)
    {

        fprintf(fp,"%d,%s,%s,%d,%d-%d-%d,%s,%s,%s\n",e[i].id,e[i].last,e[i].first,e[i].salary,e[i].Birth.Day,e[i].Birth.Month,e[i].Birth.Year,e[i].address,e[i].Mobileno,e[i].email);
      //  if(i==n-2)
        //{

        //fprintf(fp,"\n");
       //}
    }
    fclose(fp);

}
//

//
void save_delete(FILE *fp)
{
    int i;

    fp =  fopen("Company.txt", "w");
    for (i=0; i<n; i++)
    {

        fprintf(fp,"%d,%s,%s,%.d,%d-%d-%d,%s,%s,%s\n",e[i].id,e[i].last,e[i].first,e[i].salary,e[i].Birth.Day,e[i].Birth.Month,e[i].Birth.Year,e[i].address,e[i].Mobileno,e[i].email);
        if(i==n-2)
        {

           // fprintf(fp,"\n");
        }
    }
    fclose(fp);

}
void deletee(char h[20],char j[20])
{
    int i,c,r;
    for(i=0; i<n; i++)
    {
        if((strcasecmp(h,e[i].last)==0)&&(strcasecmp(j,e[i].first)==0))
        {
            for( r=i; r<n-1; r++)
            {
                e[r]=e[r+1];

            }
            n--;
            i--;
        }
    }


}
void modify(int k)
{
    int m,i;
    for(i=0; i<n; i++)
    {
        if(k==e[i].id)
        {

            m=i;
            printf("\nenter the last name: ");
            scanf("%s",e[m].last);
            printf("\nenter the first n: ");
            scanf("%s",e[m].first);
            printf("\nenter the salary: ");
            scanf("%d",&e[m].salary);
            printf("\nenter the day: ");
            scanf("%d",&e[m].Birth.Day);
            printf("\nenter the Month: ");
            scanf("%d",&e[m].Birth.Month);
            printf("\nenter the Year: ");
            scanf("%d",&e[m].Birth.Year);
            printf("\nenter the address: ");
            scanf("%s",e[m].address);
            printf("\nenter the email: ");
            scanf("%s",e[m].email);
            printf("\nenter the mobile: ");
            scanf("%s",e[m].Mobileno);

        }
    }
}
int main()
{
    int d,f,k,w,i;
    char h[20],j[20];
    FILE *fp = NULL;
    load(fp);
    while(1)
    {
        printf("\n if you want the stored data enter (1)\n if you want to search enter (2)\n if you want to add an employee enter (3)\n if you want to delete an employee enter (4)\n if you want to modify or edit in an employee enter (5)\n if you want to save the data enter (6)\n if you want to quit enter (7)\n");
        printf("\nenter your required: ");
        scanf("%d",&d);

        char name[100];
        if(d==1)
        {

            printf("\n if you want to print according to the last name enter (10)\n if you want to print according to the salary enter(11)\n if you want to print according to the date of birth enter (12)\n if you want to print according to the the all data stored enter (13)\n");
            printf("\nenter your required: ");
            scanf("%d",&f);

            if(f==10)
                printname();
            else if(f==11)
                printsalary();
            else if(f==12)
                printbirth();
            else if(f==13)
                print(f);
        }
        else if(d==2)
        {
            printf("\n enter the last name of the emplyee : ");
            scanf("%s",name);
            search(name);

        }
        else if(d==3)
        {

            add();
            printf("if you want to save this data \n enter (1)\nif you do not want to save \n enter (2) ");
            scanf("%d",&w);
            if(w==1)
                save(fp);
            else if (w==2)
            {
                while(w==2)
                    break;
            }


        }

        else if(d==4)
        {
            printf("\nenter the last & first name:\n");
            scanf("%s %s",h,j);

            deletee(h,j);
            printf("if you want to save this data \n enter (1)\nif you do not want to save \n enter (2) ");
            scanf("%d",&w);
            if(w==1)
                save_delete(fp);
            else if (w==2)
            {
                while(w==2)
                    break;
            }
        }
        else if(d==5)
        {
            printf("\nenter the id\n");
            scanf("%d",&k);
            modify(k);
            printf("if you want to save this data \n enter (1)\nif you do not want to save \n enter (2) ");
            scanf("%d",&w);
            if(w==1)
                save(fp);
            else if (w==2)
            {
                while(w==2)
                    break;
            }
        }

        else if(d==6)
            save(fp);
        else if(d==7)
        {
            printf("            \n\n\n\n\n  ********see you in next project ya dactra********\n\n\n\n\n ");
            exit(0);
        }

    }
    return 0;
}
