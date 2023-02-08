#ifndef _SOMMET_H
#define _SOMMET_H
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
using namespace std;
#define INFINITY std::numeric_limits<double>::max()
/*
La classe Sommet permet de definir les caractéristiques de chaque point de l'univers dont le nom designé par point la hauteur, les coordonnéés
*/
class Sommet{
string point;
int hauteur;
int absc;
int ordo;
public:
//constructeur de la classe Sommet
Sommet(string _point="P", int _hauteur=0,int _absc=0,int _ordo=0):
point(_point),hauteur(_hauteur),absc(_absc),ordo(_ordo){}
//constructeur de copie de la classe Sommet
Sommet(const Sommet& S):
point(S.point),hauteur(S.hauteur),absc(S.absc),ordo(S.ordo){}
string getpoint(){return point;}
int gethauteur(){return hauteur;}
int getabsc(){return absc;}
int getordo(){return ordo;}
int denivelation(const Sommet& Depart,const Sommet& Arrivee){return Arrivee.hauteur-Depart.hauteur;}
double dpl_orthogonal(const Sommet& Depart,const Sommet& Arrivee);
double dpl_diagonal(const Sommet& Depart,const Sommet& Arrivee);
int max_absc(vector<Sommet>);
int max_ordo(vector<Sommet>);
Sommet retour_sommet(vector<Sommet>,int,int);
double poids(vector<Sommet>,Sommet,Sommet);
bool voisin(vector<Sommet>,Sommet,Sommet);
bool cadre(vector<Sommet>,Sommet);
};
//La classe Graphe permet de definir quelques méthode relatives au graphes formés par les points cet univers
class Graphe{
public:
  vector<pair<Sommet, double> > Dijsktra(vector<Sommet>,Sommet);
  Sommet Nouveau_sommet(vector<pair<Sommet, double> >,vector<Sommet>,vector<Sommet>);
  double dist_de(vector<pair<Sommet, double> >,Sommet);
  bool visiter(vector<Sommet>, Sommet);
};
#endif