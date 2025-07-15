#define R 3
#define C 3
int addmatrices(int m1[][C],int m2[][C],int m[][C])
{
 	int i,j;

	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			m[i][j]=m1[i][j]+m2[i][j];
		}
	}
	return 0; //success
}
