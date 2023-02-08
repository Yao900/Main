#include<iostream>
#include <random>
#include <time.h>
#include <string>
#include <vector>
#include <limits> 
using namespace std;
#define l 5
#define c 6
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
//-------------Class Point-----------------------------------------------------------------------------------
class Point
{
public:
	int ord;
	int absc;
	
};

//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
//-------------ArgumentMax-----------------------------------------------------------------------------------
int ArgumentMax(int M[l][c],int i, int j){
	int m;
	if (j==0)
	{
		if (M[i+1][j]>= max(M[i+1][j],M[i+1][j+1]))
		{
			m=j;
		}
		else{
			m= j+1;
		}
	}
	else{

		if (j==c-1)
		{
			if (M[i+1][j]>=max(M[i+1][j],M[i+1][j-1]))
			{
				m= j;
			}
			else{
				m= j-1;
			}
		}
		else{
			if (M[i+1][j]>=max(M[i+1][j+1],max(M[i+1][j],M[i+1][j-1])))
			{
				m= j;
			}
			if (M[i+1][j-1]>=max(M[i+1][j+1],max(M[i+1][j],M[i+1][j-1])))
			{
				m= j-1;
			}
			if (M[i+1][j+1]>=max(M[i+1][j+1],max(M[i+1][j],M[i+1][j-1])))
			{
				m= j+1;
			}
		}
	}
	return m;
}
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
//-------------MaxNutriments---------------------------------------------------------------------------------
vector<Point> CheminOptimal(int M[l][c]){
	vector<Point> Tmax;
	Point Vmax[l];
	Point Vinter[l];
    int k,j,m, valmax,valinter;
    valmax=0;
	for (int i = 0; i < c; ++i)
	{
		k=0;
		m=i;
		valinter=M[k][i];
		Vinter[0].absc=i;
		Vinter[0].ord=k;
		while(k<l-1){
			if (m==0)
			{
				valinter= valinter + max(M[k+1][m],M[k+1][m+1]);
			}
			else{
				if (m==c-1)
				{
						valinter=valinter + max(M[k+1][m],M[k+1][m-1]);
				}
					else{
						valinter= valinter + max(M[k+1][m],max(M[k+1][m+1],M[k+1][m-1]));
					}
			}
			
			m=ArgumentMax(M, k, m);
			++k;
			Vinter[k].absc=m;
		    Vinter[k].ord=k;	
		}
		if (valmax<valinter)
		{
			valmax=valinter;
			for (int cpt = 0; cpt < l; ++cpt)
			{
				Vmax[cpt]=Vinter[cpt];
			}
		}
	}
	for (int cpt = 0; cpt < l; ++cpt)
	{
		Tmax.push_back(Vmax[cpt]);
	}
	return Tmax;
}
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
//-------------Fonction pricipale----------------------------------------------------------------------------
int main ( int argc , char * argv [])
{
int M[l][c];
vector<Point> V;
  for(int i=0;i<l;++i){
      for(int j=0;j<c;++j){
         cin>>M[i][j];

      }

  }
clock_t start, end;
double cpu_time_used;
start = clock();
V=CheminOptimal(M);
end = clock();
cout<<"Le chemin optimal du ver de terre est:   "<<endl; 
cout<<"{";
for (int i = 0; i < l-1; ++i)
{
	cout<<"("<<V[i].ord<<";"<<V[i].absc<<")"<<"-->";
}
 cout<<"("<<V[l-1].ord<<";"<<V[l-1].absc<<")"<<"}"<<endl;
cpu_time_used = ((double) (end - start))/ CLOCKS_PER_SEC;
cout<<"cpu_time_used = "<<cpu_time_used<<endl;

}