#include<iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <ginac/ginac.h>
using namespace std;
using namespace GiNaC;
//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------
vector<string> Binaire(int longueur){
vector<string> V;
if(longueur==1){

	V.push_back("0");
	V.push_back("1");
}
if (longueur>=2)
{
	  vector<string>V2;
	  V2= Binaire(longueur-1);
	  for (int i = 0; i < V2.size(); ++i)
	  {
	  	V.push_back("0"+V2[i]);
	  	V.push_back("1"+V2[i]);
	  }
	  
}
return V;

}
//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------
void Etat(int n){
for (int i = 1; i < n+1; ++i)
{
	for (int j = 0; j < Binaire(i).size(); ++j)
	{
		cout<<Binaire(i)[j]<<endl;
	}
}
}
//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	//vector<string>V;
	//V=Binaire(n);
	//for (int i = 0; i < V.size(); ++i)
	//{
		//cout<<V[i]<<endl;
	//}
	//string stl;
	//getline(cin,stl);
	//cout<<"virgule position1 "<<stl.find(",")<<endl;
	//cout<<stl.substr(1,1)<<endl;
	//cout<<stl.substr(3,stl.length()-2);
    Etat(n);
	return 0;
}