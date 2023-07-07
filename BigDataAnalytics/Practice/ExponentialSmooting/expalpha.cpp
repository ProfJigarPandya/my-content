/ Take Alpha in range 0.1 to 0.9 and generate different result set. */

#include <stdio.h>

void main()
{
 FILE *fpin,*fpout;
 long unsigned int input[200]={0};
 double output[200]={0.0};
 int i=-1,j,k,len;
 long unsigned int temp;
 float alpha=0.1;
 char outputfilename[30],inputfilename[30];
 char ta[3];

 printf("\n Enter input file name ");
 scanf("%s",inputfilename);

// printf("\n Enter output file name ");
// scanf("%s",outputfilename);

// printf("\n Enter alpha ");
// scanf("%f",&alpha);

 fpin = fopen(inputfilename,"r");
 if(fpin == NULL)
 {
	printf("\n input  File not found ");
	return;
 }

 len = strlen(inputfilename);
 while(!feof(fpin))
 {
   ++i;
   fscanf(fpin,"%lu",&input[i]);
 }
 fclose(fpin);

 for(k=1,alpha = 0.1;alpha<1.0;k++,alpha+=0.1)
 {

	 strncpy(outputfilename,inputfilename,len-4);
	 ta[0] = k+'0';
	 ta[1] = '\0';
	 strcat(outputfilename,ta);
	 strcat(outputfilename,".txt");
	 fpout = fopen(outputfilename,"w");
	 if(fpout == NULL)
	 {
		printf("\n output File can't be created ");
		return;
	 }

	 output[0] = (double) input[0];
	 fprintf(fpout,"%lf",output[0]);

	 for(j=1;j<i;j++)
	{
		 output[j] = alpha * input[j-1] + (float) ( 1 - alpha) * output[j-1];
		 fprintf(fpout,"\n%lf",output[j]);
	}
	fflush(fpout);
	fclose(fpout);
 }

















 getch();
}