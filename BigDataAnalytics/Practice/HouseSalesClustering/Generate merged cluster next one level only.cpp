#include <iostream>
#include <iomanip>
#include <fstream>
#include "math.h"
using namespace std;

struct ClusterOriginals
{
	char name[100];
	short prize;
};

void init_prize_clusters(ClusterOriginals * & ptrClusterOriginals,short number_of_records,ifstream & infile);
void display_prize_clusters(ClusterOriginals* ptrClusterOriginals, short number_of_records);
double* create_distance_vectore(ClusterOriginals* ptrClusterOriginals, short number_of_records);
void display_distance_vector1(ClusterOriginals* ptrCluster, double *ptrDistanceVector1, short number_of_records);
double *find_edCurrentClusterPairs(double *ptrDistanceVector1,  short number_of_records);
double find_shortest( double *edarray,short number_of_clusters );
void main()
{
	ifstream infile("HousePrizesK.csv");
	if(!infile)
	{
		cout<<"\n File not found;";
		system("pause");
		exit(EXIT_FAILURE);
	}
	short number_of_records;
	infile>>number_of_records;
	ClusterOriginals *ptrClusterOriginals;

	//sort the attribute prize
	//I have sorted the attribute outside this program using excel. sorting.
	
	//Create Clusters with a single object.
	init_prize_clusters(ptrClusterOriginals,number_of_records, infile);
	display_prize_clusters(ptrClusterOriginals, number_of_records);

	//Process original clusters table further to calculate the distnaces between pair of clusters.
	double *ptrDistanceVector1;
	ptrDistanceVector1 = create_distance_vectore( ptrClusterOriginals, number_of_records);
	
	display_distance_vector1( ptrClusterOriginals, ptrDistanceVector1, number_of_records);



	//The following should be repeated till we reach number of clusters as we have set to minimum.
	//Merge clusters having shortest distances among other clusters
	double *edarray;
	edarray = find_edCurrentClusterPairs( ptrDistanceVector1,  number_of_records);

	//	find shortest distances among other clusters.
	double sd = find_shortest( edarray, number_of_records );
	cout<<"\n Shortest distnace is "<<sd;


	short travese_cluster, new_entry_cluster;
	ClusterOriginals *ptrClustersNew;
	ptrClustersNew = new ClusterOriginals[number_of_records];
	if(!ptrClustersNew)
	{
		 cout<<"\n Runtime memory allocation failed. ";
		 system("pause");
		 exit(EXIT_FAILURE);
	}
	double *ptrDistanceVector2 ;

	//actual merge

	new_entry_cluster=0;
	strcpy((ptrClustersNew+new_entry_cluster)->name, (ptrClusterOriginals)->name);
	new_entry_cluster++;
	for(travese_cluster=1; travese_cluster<number_of_records ; travese_cluster++)
	{
		if( *(edarray+travese_cluster) == sd ) //the current cluster and the previous to current are to be merged
		{
			cout<<"\n The cluster "<<travese_cluster<<" is merged with previous.";
			strcat((ptrClustersNew-1+new_entry_cluster)->name, (ptrClusterOriginals+travese_cluster)->name);
			continue;
		}
		else
		{
			strcpy((ptrClustersNew+new_entry_cluster)->name, (ptrClusterOriginals+travese_cluster)->name);
			new_entry_cluster++;
		}
	}

	cout<<"\n Newly created clusters.";
	short k;
	for(k=0;k<new_entry_cluster;k++)
		cout<<"\n"<<(ptrClustersNew+k)->name;
	



	
	



	delete [] edarray;
	delete [] ptrClusterOriginals;
	
	system("pause");
}
void init_prize_clusters(ClusterOriginals * & ptrClusterOriginals,short number_of_records,ifstream & infile)
{
	ptrClusterOriginals = new ClusterOriginals[number_of_records];
	if(!ptrClusterOriginals)
	{
		cout<<"\n init_prize_clusters(): Runtime memory allocation failed.";
		exit(EXIT_FAILURE);
	}
	for(short i=0;i<number_of_records;i++)
	{
		char *temp_name = new char[5];
		*temp_name++ = 'C';
		
		itoa(i, temp_name, 10);
		temp_name--;
		strcpy(ptrClusterOriginals[i].name, temp_name);
		infile>>ptrClusterOriginals[i].prize;
		delete []temp_name;
	}
}

void display_prize_clusters(ClusterOriginals* ptrClusterOriginals, short number_of_records)
{
	cout<<endl<<setw(20)<<"Cluster ID"<<setw(10)<<"Prize"<<endl;
	for(short i=0;i<number_of_records;i++)
		cout<<setw(20)<<ptrClusterOriginals[i].name<<setw(10)<<ptrClusterOriginals[i].prize<<endl;
}


double* create_distance_vectore( ClusterOriginals* ptrClusterOriginals, short number_of_records)
{
	double *pptrDistanceVector;
	pptrDistanceVector = new double [number_of_records*number_of_records];
	if(!pptrDistanceVector)
	{
		cout<<"\n create_distance_vectore(): Runtime memory allocation failed. ";
		system("pause");
		exit(EXIT_FAILURE);
	}

	short i,j;

	for(i=0;i<number_of_records;i++)
	{
			*( pptrDistanceVector+ (number_of_records*i)+i  )= 0;
	}

	for(i=1;i<number_of_records;i++)
	{
		for(j=0;j<i;j++)
		{
			*(pptrDistanceVector + (number_of_records*i) + j ) = ((ptrClusterOriginals+i)->prize) - ((ptrClusterOriginals+j)->prize);
			*(pptrDistanceVector + (number_of_records*j) + i ) = ((ptrClusterOriginals+i)->prize) - ((ptrClusterOriginals+j)->prize);
		}
	}
	return pptrDistanceVector;
}

void display_distance_vector1(ClusterOriginals *ptrCluster, double *ptrDistanceVector1, short number_of_records)
{
	short i;
	cout<<endl<<"     ";
	for(i=0;i< number_of_records; i++)
		cout<<setw(5)<<(ptrCluster+i)->name;
	cout<<endl;
	for(i=0;i<number_of_records;i++)
	{
		cout<<setw(5)<<(ptrCluster+i)->name;
		for(short j=0;j<number_of_records; j++)
		{
			cout<<setw(5)<<*(ptrDistanceVector1+(i*number_of_records)+j);
		}
		cout<<endl;
	}
}
double *find_edCurrentClusterPairs( double *ptrDistanceVector1,  short number_of_clusters)
{
	double *edarray = new double [number_of_clusters];
	if(!edarray)
	{
		cout<<"\n find_edCurrentClusterPairs(): Runtime memory allocation failed.";
		system("pause");
		exit(EXIT_FAILURE);
	}
	*(edarray) = 0;

	short i,j;
	for(i=1;i<number_of_clusters;i++)
	{
		double ed=0;
		for(j=0;j<number_of_clusters;j++)
		{   
			double temp_sq = ( (*(ptrDistanceVector1+(i*number_of_clusters) + j )) -    ( * (  ptrDistanceVector1 + ( (i-1)*number_of_clusters) + j)  ) );
			ed+= (temp_sq * temp_sq)  ;
		}
		
		ed = sqrt(ed);

		*(edarray+i) = ed;
	}
	cout<<"\n Ed distance array between cluster pairs.";
	for(i=0;i<number_of_clusters;i++)
	{
		cout<<endl<<*(edarray+i);
	}

	return edarray;
}

double find_shortest( double *edarray, short number_of_clusters )
{
	
	double sd = *(edarray+1);

	for(short i=2;i<number_of_clusters;i++)
	{
		if( *(edarray+i) < sd)
		{
			sd = *(edarray+i);
		}
	}
	return sd;
}