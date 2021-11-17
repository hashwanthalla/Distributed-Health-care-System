#include<stdio.h>
#include<math.h>
#include <string.h>
#include <stdlib.h>
#define LSIZ 1000
#define RSIZ 1000
int main()
{
  int AorP=0;
  char contactnumber[10000];
  char AORPNMBR[100000];
  printf("Please enter the Adhar or PAN card number\n");
  scanf("%s",AORPNMBR);
  char line[RSIZ][LSIZ];
	char fname[60];
	int finalamount=0;
    FILE *fptr = NULL;
    FILE *fp=NULL;
    FILE *fptran=NULL;
    int i = 0;
    int tot = 0;
     char *a;
     char *b;
     char *c;
     char decision[100];
 int amount=0;

    fptr = fopen("C:/test/adhaar.txt", "r");
    while(fgets(line[i], LSIZ, fptr))
	{
        line[i][strlen(line[i]) - 1] = '\0';
        i++;
    }
    tot = i;
    for(i=0;i<tot-2;i++)
    {
        int init_size = strlen(line[i]);
	    char delim[] = " ";

	   char *ptr = strtok(line[i], delim);


	   a=ptr;
       ptr = strtok(NULL, delim);
       b=ptr;
       ptr = strtok(NULL, delim);
       c=ptr;
       ptr = strtok(NULL, delim);

       if(strcmp(AORPNMBR,a)==0||strcmp(AORPNMBR,b)==0)
     {

         AorP=1;
           break;

    }


    }

    if(AorP==0)
    {
        fp = fopen("C:/test/newentry.txt", "a");

        printf("Sorry your Adhar or PAN card number does not exist with us please enter your contact phn number we will check with govt and will intimate you\n");
       scanf("%s",contactnumber);
       fprintf(fp,"%s   ",AORPNMBR);
       fprintf(fp,"%s\n",contactnumber);

         printf("Your contact number has been saved we will check with govt records and contact you in the mean time");
         fclose(fp);
    }
    else
    {

     printf("We are calculating your subsidy amount please enter your medical bill\n");

     scanf("%d",&amount);
       int x=atoi(c);
       //printf("%d---%d\n",amount,x);
       double perc = ((double)amount/(double)x)*(int)100;
       if(perc>100)
       {

           perc=100;
       }
       printf("You can avail a subsidy perc of: %.2lf\n",perc);
       printf("please let us know wether the amount is sufficient for you or not: with if yes \"Y\" if no \"N\" \n");

       scanf("%s",decision);
       if(strcmp("Y",decision)==0)
       {
         finalamount=(int)(perc*(double)amount)/100;
         printf("%d-----\n",finalamount);
          printf("We had transfered your amount thanks for visiting us");
          fptran = fopen("C:/test/transferrecord.txt","a");

      //  printf("Sorry your Adhar or PAN card number does not exist with us please enter your contact phn number we will check with govt and will intimate you\n");


         fprintf(fptran,"%s    ",AORPNMBR);
         fprintf(fptran,"%s    ",decision);
         fprintf(fptran,"%d\n",finalamount);
         fclose(fptran);

       }
       else
       {

           printf("Sorry for not getting upto your expected subsidy percentage our team will personally contact you\n");
           fptran = fopen("C:/test/transferrecord.txt","a");

      //  printf("Sorry your Adhar or PAN card number does not exist with us please enter your contact phn number we will check with govt and will intimate you\n");


         fprintf(fptran,"%s    ",AORPNMBR);
         fprintf(fptran,"%s    ",decision);
         fprintf(fptran,"%d\n",finalamount);
         fclose(fptran);


       }

    }


}
