#include<iostream>
#include<iostream>
#include <fstream>
#include<cstdio>
#include<iomanip>
#include<sstream>
#include<algorithm>
#include <string>
#include <cstdlib>
#include <map>
#include <vector>
#include <limits> 
#include "outil.h"
//#include "Sommet.h"
using namespace std;
#define INFINITY std::numeric_limits<double>::max()
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------Fonction controle_dimension------------------------------------------------------------------------------------------------------------------------------------
/*
permet de savoir si le string saisi respecte les normes
@param le string line
reourne le booleen reponse montrant si la saisie a été correcte
*/
bool controle_dimension(string line){
string element1, element2, esp;
int taille1, taille2;
bool reponse=false;
int n,longueur;
longueur= line.length();
n= line.find(" ");
if(n>=1){
element1=line.substr(0,n);
esp=line.substr(n,1);
element2=line.substr(n+1,longueur-(n+1));
taille1=atof(element1.c_str());
//taille=stoi(element1);
taille2=atof(element2.c_str());
//taille=stoi(element2);
if(taille1>=0 && taille2>=0 && esp==" "){
	reponse=true;
}
else{
	reponse=false;
}
}
else{
	reponse=false;
}
return reponse;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------Fonction controle_taille---------------------------------------------------------------------------------------------------------------------------------------
/*
permet de savoir si les dimensions du domaine en question sont des entiers naturels
@param le string line
reourne le booleen reponse montrant si la saisie a été correcte
*/
bool controle_taille(string line){
string element1, element2, esp;
int taille1, taille2;
bool reponse=false;
int n,longueur;
longueur= line.length();
n= line.find(" ");
if(n>=1){
element1=line.substr(0,n);
esp=line.substr(n,1);
element2=line.substr(n+1,longueur-(n+1));
taille1=atof(element1.c_str());
//taille=stoi(element1);
taille2=atof(element2.c_str());
//taille=stoi(element2);
if(taille1>1 && taille2>1 && esp==" "){
	reponse=true;
}
else{
	reponse=false;
}
}
else{
	reponse=false;
}
return reponse;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------Fonction la_taille1--------------------------------------------------------------------------------------------------------------------------------------------
/*
renvoie le nombre de colonnes de l'univers
@param le string line
reourne le nombre de colonnes
*/
int la_taille1(string line){
string element,esp;
int taille;
int n,longueur;
longueur= line.length();
n= line.find(" ");
element=line.substr(0,n);
esp=line.substr(n,1);
//taille=stoi(element);
taille=atof(element.c_str());
return taille;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------Fonction la_taille2--------------------------------------------------------------------------------------------------------------------------------------------
/*
renvoie le nombre de lignes de l'univers
@param le string line
reourne le nombre de lignes
*/
int la_taille2(string line){
string element,esp;
int taille;
int n,longueur;
longueur= line.length();
n= line.find(" ");
esp=line.substr(n,1);
element=line.substr(n+1,longueur-(n+1));
taille=atof(element.c_str());
//taille=stoi(element);
return taille;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------Fonction renvoyant l'abscisse d'un tresor----------------------------------------------------------------------------------------------------------------------
/*
renvoie l'abscisse d'un tésor
@param le string stockage,line 
reourne l'abscisse du trésor en question
*/
int abs_tresor(vector<Sommet>stockage,string line,int n,int m){
int val_abs;
Sommet U;
if(controle_dimension(line)==false || la_taille1(line)<0||la_taille1(line)>=n||la_taille2(line)<0||la_taille2(line)>=m||U.retour_sommet(stockage,la_taille1(line),la_taille2(line)).getpoint()=="E"){
	cerr<<"Erreur trésor"<<endl;
	exit(1);

}
else{
val_abs=la_taille1(line);
}

return val_abs;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------Fonction renvoyant l'ordonnée d'un tresor----------------------------------------------------------------------------------------------------------------------
/*
renvoie l'ordonnée d'un tésor
@param le string stockage,line 
reourne l'ordonnée du trésor en question
*/
int ordo_tresor(vector<Sommet>stockage,string line,int n,int m){
int val_abs;
Sommet U;
if(controle_dimension(line)==false || la_taille1(line)<0||la_taille1(line)>=n||la_taille2(line)<0||la_taille2(line)>=m||U.retour_sommet(stockage,la_taille1(line),la_taille2(line)).getpoint()=="E"){
	cerr<<"Erreur trésor"<<endl;
	exit(1);

}
else{
val_abs=la_taille2(line);
}

return val_abs;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------Fonction vérifiant le nombre de portes-------------------------------------------------------------------------------------------------------------------------
bool controle_porte(vector<Sommet>stockage){
	int cpt=0;
	bool reponse = false;
	for (int i = 0; i < stockage.size(); ++i)
	{
		if (stockage[i].getpoint()=="P")
		{
			cpt++;
		}
	}
if (cpt==1)
{
	reponse=true;
}
else{
	reponse = false;
	cerr<<"Erreur porte"<<endl;
	exit(1);
}
return reponse;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------Fonction renvoyant l'abscisse de la porte----------------------------------------------------------------------------------------------------------------------
int abs_porte(vector<Sommet>stockage){
	int val;
for (int i = 0; i < stockage.size(); ++i)
	{
		if (stockage[i].getpoint()=="P")
		{
			val=stockage[i].getabsc();
		}
	}
	return val;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------Fonction renvoyant ordonnée de la porte------------------------------------------------------------------------------------------------------------------------
int ord_porte(vector<Sommet>stockage){
	int val;
for (int i = 0; i < stockage.size(); ++i)
	{
		if (stockage[i].getpoint()=="P")
		{
			val=stockage[i].getordo();
		}
	}
	return val;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------Fonction renvoyant le plus court chemin connaissant les coordonnées du point de depart celle du point d'arrivée------------------------------------------------
double court_chemin(vector<Sommet>stockage,int x,int y,int w,int z){
	vector<pair<Sommet, double> >graphe;
	Sommet U;
	Graphe L;
	graphe=L.Dijsktra(stockage,U.retour_sommet(stockage,x,y));
    double val_court= L.dist_de(graphe,U.retour_sommet(stockage,w,z));
    return val_court;


}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------court chemin suivant le chemin (x0,y0)-(x1,y1)-(x2,y2)-(x3,y3)-(X0.y0)-----------------------------------------------------------------------------------------
double cycle_tresor(vector<Sommet>stockage,int x0,int y0,int x1,int y1,int x2,int y2,int x3,int y3){
	double val=court_chemin(stockage,x0,y0,x1,y1)+court_chemin(stockage,x1,y1,x2,y2)+court_chemin(stockage,x2,y2,x3,y3)+court_chemin(stockage,x3,y3,x0,y0);
	return val;

}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------cas de tresor en une hauteur supérieure------------------------------------------------------------------------------------------------------------------------
bool tresor_infini(vector<Sommet>stockage,int x0,int y0,int x1,int y1,int x2,int y2,int x3,int y3){
    bool reponse=false;
	Sommet S;
	Graphe L;
	vector<pair<Sommet, double> >graphe0=L.Dijsktra(stockage,S.retour_sommet(stockage,x0,y0));
	vector<pair<Sommet, double> >graphe1=L.Dijsktra(stockage,S.retour_sommet(stockage,x2,y2));
	vector<pair<Sommet, double> >graphe2=L.Dijsktra(stockage,S.retour_sommet(stockage,x3,y3));
	if (L.dist_de(graphe0,S.retour_sommet(stockage,x1,y1))==INFINITY && L.dist_de(graphe1,S.retour_sommet(stockage,x1,y1))==INFINITY && L.dist_de(graphe2,S.retour_sommet(stockage,x1,y1))==INFINITY)
	{
		reponse=true;
	}
    else
    {
		reponse=false;
    }
	
    return reponse;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------court chemin suivant le chemin (x0,y0)-(x2,y2)-(x3,y3)-(X0.y0)-cas ou le tresor (x1,y1) est inaccessible-------------------------------------------------------
double cycle_tresor_infini1(vector<Sommet>stockage,int x0,int y0,int x2,int y2,int x3,int y3){
	double val=court_chemin(stockage,x0,y0,x2,y2)+court_chemin(stockage,x2,y2,x3,y3)+court_chemin(stockage,x3,y3,x0,y0);
	return val;

}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------court chemin suivant le chemin (x0,y0)-------(x1,y1)-(X0.y0)-cas avec deux tresors inaccessibles---------------------------------------------------------------
void cycle_tresor_infini111(vector<Sommet>stockage,int x0,int y0,int x1,int y1){
	double val=court_chemin(stockage,x0,y0,x1,y1)+court_chemin(stockage,x1,y1,x0,y0);
	cout<<endl;
    cout<<endl;
	cout<<"Porte -> T1"<<" : "<<court_chemin(stockage,x0,y0,x1,y1)<<endl;
    //cout<<endl;
    cout<<"T1 -> Porte"<<" : "<<court_chemin(stockage,x1,y1,x0,y0)<<endl;
    //cout<<endl;
	cout<<"Total : " <<val<<endl;
	cout<<endl;
    cout<<endl;


}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------court chemin suivant le chemin (x0,y0)-------(x2,y2)-(X0.y0)-cas avec deux tresors inaccessibles---------------------------------------------------------------
void cycle_tresor_infini222(vector<Sommet>stockage,int x0,int y0,int x2,int y2){
	double val=court_chemin(stockage,x0,y0,x2,y2)+court_chemin(stockage,x2,y2,x0,y0);
	cout<<endl;
    cout<<endl;
	cout<<"Porte -> T2"<<" : "<<court_chemin(stockage,x0,y0,x2,y2)<<endl;
     // cout<<endl;
    cout<<"T2 -> Porte"<<" : "<<court_chemin(stockage,x2,y2,x0,y0)<<endl;
     // cout<<endl;
	cout<<"Total : " <<val<<endl;
	cout<<endl;
    cout<<endl;


}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------court chemin suivant le chemin (x0,y0)-------(x3,y3)-(X0.y0)-cas avec deux tresors inaccessibles---------------------------------------------------------------
void cycle_tresor_infini333(vector<Sommet>stockage,int x0,int y0,int x3,int y3){
	double val=court_chemin(stockage,x0,y0,x3,y3)+court_chemin(stockage,x0,y0,x3,y3);
	cout<<endl;
    cout<<endl;
	cout<<"Porte -> T3"<<" : "<<court_chemin(stockage,x0,y0,x3,y3)<<endl;
    //cout<<endl;
     cout<<"T3 -> Porte"<<" : "<<court_chemin(stockage,x3,y3,x0,y0)<<endl;
    // cout<<endl;
	cout<<"Total  : " <<val<<endl;
	cout<<endl;
    cout<<endl;


}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------court chemin  avec un tresor inaccessible----------------------------------------------------------------------------------------------------------------------
double cycle_tresor_affiche_bis_inffini1(vector<Sommet>stockage,int x0,int y0,int x2,int y2,int x3,int y3){
	double m1=cycle_tresor_infini1(stockage,x0,y0,x2,y2,x3, y3);
	double m2=cycle_tresor_infini1(stockage,x0,y0,x3,y3,x2, y2);
	return max(m1,m2);
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------court chemin  avec un tresor 1 inaccessible----------------------------------------------------------------------------------------------------------------------
 void cycle_tresor_affiche_inffini23(vector<Sommet>stockage,int x0,int y0,int x2,int y2,int x3,int y3){
 	double m1=cycle_tresor_infini1(stockage,x0,y0,x2,y2,x3, y3);
	double m2=cycle_tresor_infini1(stockage,x0,y0,x3,y3,x2, y2);
	if (m1<=m2)
	{
	  cout<<endl;
      cout<<endl;
	  cout<<"Porte -> T2"<<" : "<<court_chemin(stockage,x0,y0,x2,y2)<<endl;
      //cout<<endl;
      cout<<"T2 -> T3"<<" : "<<court_chemin(stockage,x2,y2,x3,y3)<<endl;
      //cout<<endl;
      //cout<<endl;
      cout<<"T3 -> Porte"<<" : "<<court_chemin(stockage,x3,y3,x0,y0)<<endl;
      //cout<<endl;
	  cout<<"Total : " <<min(m1,m2)<<endl;
	  cout<<endl;
	  cout<<endl;
	  
	}
	if (m1>=m2)
	{	
	  cout<<endl;
      cout<<endl;
	  cout<<"Porte -> T3"<<" : "<<court_chemin(stockage,x0,y0,x3,y3)<<endl;
      //cout<<endl;
      cout<<"T3 -> T2"<<" : "<<court_chemin(stockage,x3,y3,x2,y2)<<endl;
      //cout<<endl;
      //cout<<endl;
      cout<<"T3 -> Porte"<<" : "<<court_chemin(stockage,x2,y2,x0,y0)<<endl;
      //cout<<endl;
	  cout<<"Total : "<<min(m1,m2)<<endl;
	  cout<<endl;
	  cout<<endl;
	 
      
	}
	

 }
 //--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------court chemin  avec un tresor 2 inaccessible----------------------------------------------------------------------------------------------------------------------
 void cycle_tresor_affiche_inffini13(vector<Sommet>stockage,int x0,int y0,int x1,int y1,int x3,int y3){
 	double m1=cycle_tresor_infini1(stockage,x0,y0,x1,y1,x3, y3);
	double m2=cycle_tresor_infini1(stockage,x0,y0,x3,y3,x1, y1);
	if (m1<=m2)
	{
	  cout<<endl;
      cout<<endl;
	 cout<<"Porte -> T1"<<" : "<<court_chemin(stockage,x0,y0,x1,y1)<<endl;
      //cout<<endl;
      cout<<"T1 -> T3"<<" : "<<court_chemin(stockage,x1,y1,x3,y3)<<endl;
      //cout<<endl;
      //cout<<endl;
      cout<<"T3 -> Porte"<<" : "<<court_chemin(stockage,x3,y3,x0,y0)<<endl;
      //cout<<endl;
	  cout<<"Total : " <<min(m1,m2)<<endl;
	  cout<<endl;
	  cout<<endl;
	 
	}
	if (m1>=m2){
	  cout<<endl;
      cout<<endl;
	  cout<<"Porte -> T3"<<" : "<<court_chemin(stockage,x0,y0,x3,y3)<<endl;
      //cout<<endl;
      cout<<"T3 -> T1"<<" : "<<court_chemin(stockage,x3,y3,x1,y1)<<endl;
      //cout<<endl;
      //cout<<endl;
      cout<<"T1 -> Porte"<<" : "<<court_chemin(stockage,x1,y1,x0,y0)<<endl;
      //cout<<endl;
	  cout<<"Total : " <<min(m1,m2)<<endl;
	  cout<<endl;
	  cout<<endl;
	
      
	}
	

 }
 //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------court chemin  avec un tresor 3 inaccessibles-------------------------------------------------------------------------------------------------------------------
 void cycle_tresor_affiche_inffini12(vector<Sommet>stockage,int x0,int y0,int x1,int y1,int x2,int y2){
 	double m1=cycle_tresor_infini1(stockage,x0,y0,x1,y1,x2, y2);
	double m2=cycle_tresor_infini1(stockage,x0,y0,x2,y2,x1, y1);
	if (m1<=m2)
	{
	  cout<<endl;
      cout<<endl;
	  cout<<"Porte -> T1"<<" : "<<court_chemin(stockage,x0,y0,x1,y1)<<endl;
      //cout<<endl;
      cout<<"T1 -> T2"<<" : "<<court_chemin(stockage,x1,y1,x2,y2)<<endl;
      //cout<<endl;
      //cout<<endl;
      cout<<"T2 -> Porte"<<" : "<<court_chemin(stockage,x2,y2,x0,y0)<<endl;
      //cout<<endl;
	  cout<<"Total  : " <<min(m1,m2)<<endl;
	  cout<<endl;
	  cout<<endl;
	  
	}
	if (m1>=m2){
	  cout<<endl;
      cout<<endl;
	  cout<<"Porte -> T2"<<" : "<<court_chemin(stockage,x0,y0,x2,y2)<<endl;
      //cout<<endl;
      cout<<"T2 -> T1"<<" : "<<court_chemin(stockage,x2,y2,x1,y1)<<endl;
      //cout<<endl;
      //cout<<endl;
      cout<<"T1 -> Porte"<<" : "<<court_chemin(stockage,x1,y1,x0,y0)<<endl;
      //cout<<endl;
	  cout<<"Total : " <<min(m1,m2)<<endl;
      cout<<endl;
      cout<<endl;
      
	}
	

 }
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------court chemin --------------------------------------------------------------------------------------------------------------------------------------------------
double cycle_tresor_affiche_bis(vector<Sommet>stockage,int x0,int y0,int x1,int y1,int x2,int y2,int x3,int y3){
double tab[6];
tab[0]=cycle_tresor(stockage,x0,y0,x1,y1,x2,y2,x3,y3);
tab[1]=cycle_tresor(stockage,x0,y0,x1,y1,x3,y3,x2,y2);
tab[2]=cycle_tresor(stockage,x0,y0,x2,y2,x1,y1,x3,y3);
tab[3]=cycle_tresor(stockage,x0,y0,x2,y2,x3,y3,x1,y1);
tab[4]=cycle_tresor(stockage,x0,y0,x3,y3,x1,y1,x2,y2);
tab[5]=cycle_tresor(stockage,x0,y0,x3,y3,x2,y2,x1,y1);
double minim= INFINITY;
for (int i = 0; i < 6; ++i)
{
	if(minim>=tab[i])
	{
		minim=tab[i];
	}
}
return minim;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------fonction auxilliaire permettant de compter l'occurence d'un élément dans tableau--------------------------------------------------------------------------------

int minifonction(double*tab,int n,double x){
int cpt=0;
for (int i = 0; i < n; ++i)
{
	if(x==tab[i])
	{
		cpt=cpt +1;
	}
}
return cpt;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------Affichage du court chemin suivant le parcourt dans le cas ou les trois trésors sont accessibles----------------------------------------------------------------
void cycle_tresor_affiche(vector<Sommet>stockage,int x0,int y0,int x1,int y1,int x2,int y2,int x3,int y3){
double tab[6];
tab[0]=cycle_tresor(stockage,x0,y0,x1,y1,x2,y2,x3,y3);
tab[1]=cycle_tresor(stockage,x0,y0,x1,y1,x3,y3,x2,y2);
tab[2]=cycle_tresor(stockage,x0,y0,x2,y2,x1,y1,x3,y3);
tab[3]=cycle_tresor(stockage,x0,y0,x2,y2,x3,y3,x1,y1);
tab[4]=cycle_tresor(stockage,x0,y0,x3,y3,x1,y1,x2,y2);
tab[5]=cycle_tresor(stockage,x0,y0,x3,y3,x2,y2,x1,y1);
double minim= INFINITY;
for (int i = 0; i < 6; ++i)
{
	if(minim>=tab[i])
	{
		minim=tab[i];
	}
}

if(abs(tab[0]-minim)<=0.000005){

      cout<<endl;
      cout<<endl;
	  cout<<"Porte -> T1"<<" : "<<court_chemin(stockage,x0,y0,x1,y1)<<endl;
      //cout<<endl;
      cout<<"T1 -> T2"<<" : "<<court_chemin(stockage,x1,y1,x2,y2)<<endl;
      //cout<<endl;
      cout<<"T2 -> T3"<<"   :   "<<court_chemin(stockage,x2,y2,x3,y3)<<endl;
     //cout<<endl;
      cout<<"T3 -> Porte"<<" : "<<court_chemin(stockage,x3,y3,x0,y0)<<endl;
      cout<<"Total : " <<minim<<endl;
      cout<<endl;
      cout<<endl;
}
if(abs(tab[1]-minim)<=0.000005){
	 cout<<endl;
      cout<<endl;
      cout<<"Porte -> T1"<<" : "<<court_chemin(stockage,x0,y0,x1,y1)<<endl;
      //cout<<endl;
      cout<<"T1 -> T3"<<" : "<<court_chemin(stockage,x1,y1,x3,y3)<<endl;
      //cout<<endl;
      cout<<"T3 -> T2"<<" : "<<court_chemin(stockage,x3,y3,x2,y2)<<endl;
      //cout<<endl;
      cout<<"T2 -> Porte"<<" : "<<court_chemin(stockage,x2,y2,x0,y0)<<endl;
      cout<<"Total : " <<minim<<endl;
      cout<<endl;
      cout<<endl;
      
}
if(abs(tab[2]-minim)<=0.000005){
	cout<<endl;
    cout<<endl;
	cout<<"Porte -> T2"<<" : "<<court_chemin(stockage,x0,y0,x2,y2)<<endl;
      //cout<<endl;
      cout<<"T2 -> T1"<<" : "<<court_chemin(stockage,x2,y2,x1,y1)<<endl;
      //cout<<endl;
      cout<<"T1 -> T3"<<" : "<<court_chemin(stockage,x1,y1,x3,y3)<<endl;
      //cout<<endl;
      cout<<"T3 -> Porte"<<" : "<<court_chemin(stockage,x3,y3,x0,y0)<<endl;
      cout<<"Total : " <<minim<<endl;
      cout<<endl;
      cout<<endl;
     

}
if(abs(tab[3]-minim)<=0.000005){
    cout<<endl;
    cout<<endl;
	cout<<"Porte -> T2"<<" : "<<court_chemin(stockage,x0,y0,x2,y2)<<endl;
      //cout<<endl;
      cout<<"T2 -> T3"<<" : "<<court_chemin(stockage,x2,y2,x3,y3)<<endl;
      //cout<<endl;
      cout<<"T3 -> T1"<<" : "<<court_chemin(stockage,x3,y3,x1,y1)<<endl;
      //cout<<endl;
      cout<<"T1 -> Porte"<<" : "<<court_chemin(stockage,x1,y1,x0,y0)<<endl;
      cout<<"Total : " <<minim<<endl;
      cout<<endl;
      cout<<endl;
}
if(abs(tab[4]-minim)<=0.000005){
     cout<<endl;
     cout<<endl;
	cout<<"Porte -> T3"<<" : "<<court_chemin(stockage,x0,y0,x3,y3)<<endl;
      //cout<<endl;
      cout<<"T3 -> T1"<<" : "<<court_chemin(stockage,x3,y3,x1,y1)<<endl;
      //cout<<endl;
      cout<<"T1 -> T2"<<" : "<<court_chemin(stockage,x1,y1,x2,y2)<<endl;
      //cout<<endl;
      cout<<"T2 -> Porte"<<" : "<<court_chemin(stockage,x2,y2,x0,y0)<<endl;
      cout<<"Total : " <<minim<<endl;
      cout<<endl;
      cout<<endl;
      
}
if(abs(tab[5]-minim)<=0.000005){
	 cout<<endl;
      cout<<endl;

	  cout<<"Porte -> T3"<<" : "<<court_chemin(stockage,x0,y0,x3,y3)<<endl;
     // cout<<endl;
      cout<<"T3 -> T2"<<" : "<<court_chemin(stockage,x3,y3,x2,y2)<<endl;
      //cout<<endl;
      cout<<"T2 -> T1"<<" : "<<court_chemin(stockage,x2,y2,x1,y1)<<endl;
      //cout<<endl;
      cout<<"T1 -> Porte"<<" :"<<court_chemin(stockage,x1,y1,x0,y0)<<endl;
      cout<<"Total  : " <<minim<<endl;
      cout<<endl;
      cout<<endl;
}
      
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------court chemin  cas général--------------------------------------------------------------------------------------------------------------------------------------
void cycle_tresor_affiche_general(vector<Sommet>stockage,int x0,int y0,int x1,int y1,int x2,int y2,int x3,int y3){
	if ( tresor_infini(stockage, x0, y0, x1, y1, x2, y2, x3, y3)==true &&tresor_infini(stockage, x0, y0, x2, y2, x1, y1, x3, y3)==true&&tresor_infini(stockage, x0, y0, x3, y3, x1, y1, x2, y2)==true)
	{
		cout<<"Impossible de bouger"<<endl;
	}
	
    if ( tresor_infini(stockage, x0, y0, x1, y1, x2, y2, x3, y3)==true &&tresor_infini(stockage, x0, y0, x2, y2, x1, y1, x3, y3)==true&&tresor_infini(stockage, x0, y0, x3, y3, x1, y1, x2, y2)==false)
	{
	 cycle_tresor_infini333(stockage, x0, y0, x3, y3);
	}
	      
	if ( tresor_infini(stockage, x0, y0, x1, y1, x2, y2, x3, y3)==true &&tresor_infini(stockage, x0, y0, x2, y2, x1, y1, x3, y3)==false&&tresor_infini(stockage, x0, y0, x3, y3, x1, y1, x2, y2)==true)
	{
	 cycle_tresor_infini222(stockage, x0, y0, x2, y2);
	}
		         
	if ( tresor_infini(stockage, x0, y0, x1, y1, x2, y2, x3, y3)==false &&tresor_infini(stockage, x0, y0, x2, y2, x1, y1, x3, y3)==true&&tresor_infini(stockage, x0, y0, x3, y3, x1, y1, x2, y2)==true)
	{
	  cycle_tresor_infini111(stockage, x0, y0, x1, y1);
	}
			          
    if ( tresor_infini(stockage, x0, y0, x1, y1, x2, y2, x3, y3)==true &&tresor_infini(stockage, x0, y0, x2, y2, x1, y1, x3, y3)==false&&tresor_infini(stockage, x0, y0, x3, y3, x1, y1, x2, y2)==false)
    {
     cycle_tresor_affiche_inffini23(stockage,x0, y0, x2, y2, x3,y3);
	}
		                    
    if ( tresor_infini(stockage, x0, y0, x1, y1, x2, y2, x3, y3)==false &&tresor_infini(stockage, x0, y0, x2, y2, x1, y1, x3, y3)==true&&tresor_infini(stockage, x0, y0, x3, y3, x1, y1, x2, y2)==false)
	{
	  cycle_tresor_affiche_inffini13(stockage,x0, y0, x1, y1, x3,y3);
	}
		                         
    if ( tresor_infini(stockage, x0, y0, x1, y1, x2, y2, x3, y3)==false &&tresor_infini(stockage, x0, y0, x2, y2, x1, y1, x3, y3)==false&&tresor_infini(stockage, x0, y0, x3, y3, x1, y1, x2, y2)==true)
    {
	  cycle_tresor_affiche_inffini12(stockage,x0, y0, x1, y1, x2,y2);
	}
	
	
	if (tresor_infini(stockage, x0, y0, x1, y1, x2, y2, x3, y3)==false &&tresor_infini(stockage, x0, y0, x2, y2, x1, y1, x3, y3)==false&&tresor_infini(stockage, x0, y0, x3, y3, x1, y1, x2, y2)==false)
	{
		cycle_tresor_affiche(stockage, x0, y0, x1, y1, x2, y2, x3, y3);
	}

}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------fonction ouverture- du fichier et affichage des resultats------------------------------------------------------------------------------------------------------
void ouverture(int nbre_argc, string filename){

	vector<pair<Sommet, double> >graphe;
    vector <pair <Sommet,double> >::iterator s = graphe.begin();
	vector<Sommet> stockage;
	vector <Sommet>::iterator p = stockage.begin();
   int taille1,taille2,xtres1,ytres1,xtres2,ytres2,xtres3,ytres3,absporte,ordporte;
     if (nbre_argc <= 1) {
        cout << "No file name entered. Exiting...";
        exit(1);
    }
    ifstream infile(filename);
    
    if (infile.is_open() && infile.good()) {
        string line1, line2, line3, line4,line5;
        getline(infile, line1);
        bool reponse=controle_taille(line1);
        if(reponse==false){
        	cerr<<"taille incorrecte"<<endl;
        	exit(1);
        }	
        else{	
        taille1=la_taille1(line1);
        taille2=la_taille2(line1);
        Sommet Graph[taille2][taille1];
         int cpt=0;
          while (cpt<taille2){
          	getline(infile, line2);
          	for(int j=0;j<taille1;j++){
          		string w=line2.substr(2*j,1);
          		string x=line2.substr(2*j+1,1);
          		int y=atof(x.c_str());
          		//int y= stoi(x);
                Sommet* sommet = new Sommet(w,y,j,cpt);
          		Graph[cpt][j]=*sommet;
                stockage.push_back(Graph[cpt][j]);
      
          	}
            cpt++;
          }
          
        }
        Sommet U;
      //}
        Sommet Depart=U.retour_sommet(stockage,1,5);
        Sommet Arrivee =U.retour_sommet(stockage,0,1);
        Graphe L;
       graphe=L.Dijsktra(stockage,Depart);
       //cout<<"*****************************"<<endl;
      //for(s=graphe.begin(); s!= graphe.end();++s){
       //cout<<s->first.getpoint()<<" "<<s->second<<endl;
      //}
      //int m= U.max_ordo(stockage);
      //int n= U.max_absc(stockage);
      //for(int j=0;j<m+1;j++,cout<<endl){
   
      	//for(int i=0;i<n+1;i++){

      		//cout<< U.retour_sommet(stockage,i,j).getpoint()<<"    "<<L.dist_de(graphe,U.retour_sommet(stockage,i,j))<<"       ***  ";
      	//}

      //}	
      	
      controle_porte(stockage);
      absporte=abs_porte(stockage);
      ordporte=ord_porte(stockage);
      getline(infile, line3);
      xtres1=abs_tresor(stockage,line3,taille1,taille2);
      ytres1= ordo_tresor(stockage,line3,taille1,taille2);
      getline(infile, line4);
      xtres2=abs_tresor(stockage,line4,taille1,taille2);
      ytres2= ordo_tresor(stockage,line4,taille1,taille2);
      getline(infile, line5);
      xtres3=abs_tresor(stockage,line5,taille1,taille2);
      ytres3= ordo_tresor(stockage,line5,taille1,taille2);
      //cout<<xtres1<<" "<<ytres1<<endl
      cycle_tresor_affiche_general(stockage,absporte,ordporte,xtres1,ytres1,xtres2,ytres2,xtres3,ytres3);
      //cout<<"Total  : " <<cycle_tresor_affiche_bis(stockage,absporte,ordporte,xtres1,ytres1,xtres2,ytres2,xtres3,ytres3)<<endl;

    } 
    else {
        cout << "Failed to open file..";
    }
 }