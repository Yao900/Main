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
#include "Sommet.h"
using namespace std;
#define INFINITY std::numeric_limits<double>::max()
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------Fonction dpl_orthogonal----------------------------------------------------------------------------------------------------------------------------------------
/*
Cette fonction permet de caractériser les deplacements horizontaux et verticaux
@parma Depart qui est le sommet de depart et Arrivee celui d'arrivée
renvoie dpl qui est le deplacement orthogonal élémentaire
*/

double Sommet::dpl_orthogonal(const Sommet& Depart,const Sommet& Arrivee){
int h= denivelation(Depart,Arrivee);
double dpl;
if(Arrivee.point=="E"||h<=-2|| h>=2){
	dpl= INFINITY;
}
else{
if(h==0 || h==-1){
	if(Arrivee.point=="F"){
		dpl=2;
	}
	else{
		if(Depart.point=="R" && Arrivee.point=="R"){
			dpl=0.5;
		}
		else{
			dpl=1;
		}
	}

}
if(h==1){
    if(Arrivee.point=="F"){
		dpl=4;
	}
	else{
		if(Depart.point=="R" && Arrivee.point=="R"){
			dpl=1;
		}
		else{
			dpl=2;
		}
	}

}

}
return dpl;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------Fonction dpl_diagonal------------------------------------------------------------------------------------------------------------------------------------------
/*
Cette fonction permet de caractériser les deplacements obliques
@parma Depart qui est le sommet de depart et Arrivee celui d'arrivée
renvoie dpl qui est le deplacement diagonal élémentaire
*/

double Sommet::dpl_diagonal(const Sommet& Depart,const Sommet& Arrivee){
int h= denivelation(Depart,Arrivee);
double dpl;
if(Arrivee.point=="E"||h<=-2|| h>=2){
	dpl= INFINITY;
}
else{
if(h==0 || h==-1){
	if(Arrivee.point=="F"){
		dpl=2.8;
	}
	else{
		if(Depart.point=="R" && Arrivee.point=="R"){
			dpl=0.7;
		}
		else{
			dpl=1.4;
		}
	}

}
if(h==1){
    if(Arrivee.point=="F"){
		dpl=5.6;
	}
	else{
		if(Depart.point=="R" && Arrivee.point=="R"){
			dpl=1.4;
		}
		else{
			dpl=2.8;
		}
	}

}

}
return dpl;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------retour_sommet retourne un sommet connaissance ses cordonnées---------------------------------------------------------------------------------------------------
/*
cette fonction retourne le sommet connaissant les coordonnées de cette derniere
@param les entiers x et y et le vecteur de sommet stockage
retour ici qui est le sommet recherché
*/
Sommet Sommet::retour_sommet(vector<Sommet>stockage,int x,int y){
Sommet*ici;
vector <Sommet>::iterator p= stockage.begin();
for(p=stockage.begin(); p!= stockage.end();++p ){
      if(x==p->absc && y==p->ordo){
      	ici=new Sommet(p->point,p->hauteur,p->absc,p->ordo);
      	
      }
    
}
return *ici;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------Fonction max_absc retournant la plus grand absc----------------------------------------------------------------------------------------------------------------
/*
retourne l'abscisse maximale des points de l'univers
@param le tableau de Sommet nommé stockage
valeur retour val 
*/
int Sommet::max_absc(vector<Sommet>stockage){
	vector <Sommet>::iterator p= stockage.begin();
	int val=0;
	for(p=stockage.begin(); p!= stockage.end();++p ){
      if(val<p->absc){
      	val=p->absc;
      }
  }
  return val;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------Fonction max_absc retournant la plus grand ordo----------------------------------------------------------------------------------------------------------------
/*
retourne l'ordonnée maximale des points de l'univers
@param le tableau de Sommet nommé stockage
valeur retour val 
*/
int Sommet::max_ordo(vector<Sommet>stockage){
	vector <Sommet>::iterator p= stockage.begin();
	int val=0;
	for(p=stockage.begin(); p!= stockage.end();++p ){
      if(val<p->ordo){
      	val=p->ordo;
      }
  }
  return val;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------Fonction permettant de savoir si un sommet est membre de la matrice--------------------------------------------------------------------------------------------
/*
Vérifie si il n y a pas debordement des points 
@param stockage
retourne le booleen reponse
*/
bool Sommet::cadre(vector<Sommet>stockage,Sommet Depart){
bool reponse = false;
for (int i = 0; i < stockage.size(); ++i)
{
	if(stockage[i].getpoint()==Depart.getpoint()&& stockage[i].getabsc()==Depart.getabsc() && stockage[i].getordo()==Depart.getordo()){
		reponse=true;
	}
}
return reponse;

}


//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------Fonction calculant le poids d'un arc---------------------------------------------------------------------------------------------------------------------------
/* 
calcule la distance minimale entre deux sommets voisins
@param stockage, sommet de depart Depart et sommet d'arrivée Arrivée
retour dist qui est la distance voulue
*/
double Sommet::poids(vector<Sommet>stockage,Sommet Depart,Sommet Arrivee){
	Sommet inter;
    int n= inter.max_absc(stockage);
    int m= inter.max_ordo(stockage);
    int i= Depart.absc;
    int j= Depart.ordo;
    int k= Arrivee.absc;
    int t= Arrivee.ordo;
    double dist=INFINITY; 
if (cadre(stockage,Arrivee)==true)
{
if(((i==0 && k==n)||(i==n && k==0))&&(j==t)){
	
		dist= dpl_orthogonal(Depart,Arrivee);
}
if (((i==0 && k==n)||(i==n && k==0))&&abs(j-t) ==1){
	
		dist= dpl_diagonal(Depart,Arrivee);
	
}
 if ((j==t && abs(i-k)==1)||(i==k)&& abs(j-t)==1)
    {
    	dist= dpl_orthogonal(Depart,Arrivee);
    }  
  if(abs(i-k)==1 && abs(j-t)==1){
  	 dist= dpl_diagonal(Depart,Arrivee);
  }
}
    return dist;

}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------Fonction indiquant si deux sommets sont voisins----------------------------------------------------------------------------------------------------------------
/*
permet de savoir si deux points sont voisins l"un l'autre
@stockage, Depart et Arrivee
retourne le booléen reponse
*/
bool Sommet::voisin(vector<Sommet>stockage,Sommet Depart,Sommet Arrivee){
	Sommet inter;
    int n= inter.max_absc(stockage);
    int m= inter.max_ordo(stockage);
    int i= Depart.absc;
    int j= Depart.ordo;
    int k= Arrivee.absc;
    int t= Arrivee.ordo;
    bool reponse=false;
 if (cadre(stockage,Arrivee)==true)
{
 if((i==0 && k==n)||(i==n && k==0)){
	if (j==t)
	{
		reponse=true;
	}
	if (abs(j-t) ==1)
	{
		reponse=true;
	}

}
 if ((j==t && abs(i-k)==1)||(i==k)&& abs(j-t)==1)
    {
    	reponse= true;
    }  
  if(abs(i-k)==1 && abs(j-t)==1){
  	 reponse=true;
    }
}
    return reponse;
   
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------Fonction renvoyant un booleen indiquant qu'un sommet est visiter ou pas----------------------------------------------------------------------------------------
/*
permet de savoir si un sommet est déjà visité
@vecteur predecesseur, stockant les sommets déjà visités, Depart, point visé 
retourne le booléen reponse
*/
bool Graphe::visiter(vector<Sommet>predecesseur, Sommet Depart){
	vector <Sommet>::iterator s = predecesseur.begin();
	bool reponse=false;
	for(s=predecesseur.begin(); s!= predecesseur.end();++s){
		if(s->getabsc()==Depart.getabsc() && s->getordo()==Depart.getordo()) {
			reponse=true;


		}


	}
	return reponse;

}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------Fonction renvoyant le noeud ayant la valeur de distance plus petite--------------------------------------------------------------------------------------------
/*
renvoie le prochain sommet à visiter dans l'algorithme de Dijsktra
@param le vecteur de pair graph1, stock des couples sommet distances le vecteur predecesseur
retourne le sommet à visiter
*/
Sommet Graphe::Nouveau_sommet(vector<pair<Sommet, double> >graphe1,vector<Sommet>stockage,vector<Sommet>predecesseur){
	vector <pair <Sommet,double> >::iterator s = graphe1.begin();
	Sommet nouveau;
	Sommet inter;
	double distmin = INFINITY;
	for(s=graphe1.begin(); s!= graphe1.end();++s){
        if(s->second<distmin && visiter(predecesseur,s->first)==false){
        	distmin=s->second;
        	//nouveau=new Sommet(s->first.getpoint(),s->first.gethauteur(),s->first.getabsc(),s->first.getordo());
        	nouveau=s->first;
        	//cout<<distmin<<"*****"<<endl;
        
	    }
	    
    }
        return nouveau;// *nouveau;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------Fonction liste renvoyant la distance connaissant le sommet-----------------------------------------------------------------------------------------------------
/*
@param graphe et le sommet en question
renvoie dist_inter
*/
double Graphe::dist_de(vector<pair<Sommet, double> >graphe,Sommet Depart){
	vector <pair <Sommet,double> >::iterator s = graphe.begin();
	double dist_inter;
	for(s=graphe.begin(); s!= graphe.end();++s){
		if(s->first.getabsc()==Depart.getabsc() && s->first.getordo()==Depart.getordo()) {
			dist_inter=s->second;

		}

	}
	return dist_inter;

}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------Fonction liste calculant le plus court chemin------------------------------------------------------------------------------------------------------------------
/*
Cette fonction calcule le plus cours chemin partant d'un point vers les autres points de l'univers
@param la matrice de sommets et Depart qui est le point de depart
retourne graphe qui est un vecteur de pair composée de Sommet et de distance
*/
vector<pair<Sommet, double> > Graphe::Dijsktra(vector<Sommet>stockage,Sommet Depart){
vector<pair<Sommet, double> >graphe;
vector<Sommet>predecesseur;
Sommet tab[stockage.size()];
Sommet inter1;
vector <pair <Sommet,double> >::iterator p = graphe.begin();
vector <Sommet>::iterator s = stockage.begin();
predecesseur.push_back(Depart);
for(s=stockage.begin(); s!= stockage.end();++s){
      if(s->getabsc()!=Depart.getabsc() || s->getordo()!=Depart.getordo()) {
         Sommet*inter2=new Sommet(s->getpoint(),s->gethauteur(),s->getabsc(),s->getordo());
        graphe.push_back( make_pair(*inter2,INFINITY) );	
      }
      else{
      	if (s->getabsc()==Depart.getabsc() && s->getordo()==Depart.getordo())
      	{
      		graphe.push_back( make_pair(Depart,0) );
      	}
      	
      }

} 
int cpt=0; 
   tab[cpt]=Depart;
   bool existe=true;
while(cpt<stockage.size()-1 && existe==true){
	 for(p=graphe.begin(); p!= graphe.end();++p){
		
		if(inter1.voisin(stockage,tab[cpt],p->first)==true && visiter(predecesseur,p->first)==false && p->second>=dist_de(graphe,tab[cpt])+ inter1.poids(stockage,tab[cpt],p->first)){
		p->second=dist_de(graphe,tab[cpt]) + inter1.poids(stockage,tab[cpt],p->first);

		}
	}
	Sommet inter3=Nouveau_sommet(graphe,stockage,predecesseur); 
	existe=inter1.cadre(stockage,inter3);
	if(existe==true){
		cpt=cpt +1;
		tab[cpt]=inter3;
	predecesseur.push_back(tab[cpt]);

	}
	
	 
} 
  
return graphe;

}
