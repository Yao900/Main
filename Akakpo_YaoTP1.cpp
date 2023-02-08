#include <iostream>
#include <map>
#include <string>
#include <functional>
#include <iomanip>
#include <stddef.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
class Element {
public:
	string identificateur;
	int rang;
	Element* suivant; 
	Element representant( string identificateur);
      
};
//declaration de fonction-------------------------------------------------------------------


//--------------------------------**************************--------------------------------
void functionce2(string);
void functionce(string);
Element representant( string);
Element Ranger(string);
string copyrep_0(string);
string copyrep_1(string);
string copyrep_2(string);
string copyrep_3(string);
string copyrep_4(string);
string copyrep_5(string);
bool controleclasse(string);
bool controlrep(string);
void repfunction(string);
bool Contrelrep2(string);
bool controlece(string);
bool controlecepoint(string);
bool controlerepdebut1(string);
bool controlerepdebut2(string);
//----------------------**********************------------------------------------------------
//functionce-------representant courant--------------------------------------------------------
//                                                                                           *

void functionce2(string idrep)
{
std::map<string,Element> liste;
std::map<string,Element>::iterator it = liste.begin();
string idrepe1, idrepe2, idrepe3, idrepe4;
idrepe1 = idrep.erase(0,4);
int din = idrepe1.find(",");
idrepe2 = idrepe1.substr(0,din);
 idrepe3 = idrepe1.erase(0, din+1);
int lg = idrepe3.length();
idrepe4 = idrepe3.substr(0,lg-1);
int k2, p2;
cout<<idrepe1<< endl;
cout<<idrepe3<< endl;
cout<<idrepe2<< endl;
cout<<din<< " "<< lg<< endl;
cout<<idrepe4<< endl;
k2=0;
p2=0;
for (it=liste.begin(); it!= liste.end(); ++it)
{
if(it->first == idrepe2)
{
++k2;
}
if(it->first == idrepe4)
{
++p2;
}
}
if ((k2 == 0)||(p2==0))
{
cout<< "identificateur inexistant"<< endl;
}
else
{
Element G;
Element A = G.representant(idrepe1);
Element B = G.representant(idrepe3);
if(A.identificateur==B.identificateur)
{
Element *M, *N;
M->identificateur = idrepe2;
N->identificateur = idrepe4;
if ((M->suivant==N->suivant)||(M==NULL))
{
cout<< M->identificateur<< endl;
}
else{
M=M->suivant;
N=N->suivant;
while ((M->suivant !=NULL)||(N->suivant !=NULL)||(M->suivant!=N->suivant)){
M=M->suivant;
N=N->suivant;
}
cout<< M->identificateur<< endl;
}
}
}


}


//--------------------------------------------------------------------------------------
//                                                                                           *
//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
//fonction controle debut2 avec?--------------------------------------------------------------
//--------------------------------------------------------------------------------------------
bool controlerepdebut2(string idrep)
{
const string Rep = "rep";
int k = idrep.find("rep");;
int n = idrep.length();
int l = idrep.find(" ");
int p = idrep.find(",");
string point = idrep.substr(n-1,1);
bool ok;
ok= true;
if ((k!=0)||(point != "?")||(l!= 3)||(p<0))
{
ok = false;
return ok;
}
else
{
ok = true;
return ok;
}
}
//--------------------------------------------------------------------------------------------
//-----------controle rep id?-----------------------------------------------------------------
bool controlerepdebut1(string idrep)
{
const string point = "?";
const string Rep = "rep";
int k = idrep.find("rep");
int sg = idrep.find(",");
int n = idrep.length();
int m = n-1;
string point2 = idrep.substr(m,1);
int l = idrep.find(" ");
bool ok;
ok= true;
if ((k!=0)||(point2!= point)||(l!= 3)||(sg>0))
{
ok = false;
return ok;
}
else
{
return ok;
}
}
//-------------------------------------------------------------------------------------------
//fonction controlece-milieu avec.-------------------------------------------------------------
bool controlecepoint(string idrep)
{
const string point = ".";
const string Rep = "ce";
string point2;
int k = idrep.find("ce");
int ex1 = k-1;
int n = idrep.length();
int m = n-1;
int l = idrep.find(" ");
point2 = idrep.substr(m, 1);
string idrepfinal = idrep.substr(0,k+2);
string idrep2 = idrep.erase(0,k+2);
int p = idrep2.find(" ");
bool ok;
ok= true;
if ((k<0)||(point2!= point)||(l!= ex1)||(p!=0))
{
ok = false;
return ok;
}
else
{

idrep = idrepfinal +idrep2;
cout<< idrep<< endl;
return ok;
}
}
//-----------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------
bool controlece(string idrep)
{
const string point = "?";
const string Rep = "ce";
string point2;
int k = idrep.find("ce");
int ex1 = k-1;
int n = idrep.length();
int m = n-1;
int l = idrep.find(" ");
point2 = idrep.substr(m, 1);
string idrepfinal = idrep.substr(0,k+2);
string idrep2 = idrep.erase(0,k+2);
int p = idrep2.find(" ");
bool ok;
ok= true;
if ((k<0)||(point2!= point)||(l!= ex1)||(p!=0))
{
ok = false;
return ok;
}
else
{
idrep = idrepfinal +idrep2;
return ok;
}
}
//Contrelrep2-avec--rep au debut et point ?------------------------------------------------
bool Contrelrep2(string idrep)
{
bool rep3;
rep3 = true;
const string point = "?";
const string Rep = "rep";
string point2;
int n = idrep.length();
int m = n-1;
point2 = idrep.substr(m, 1);
int k = idrep.find("rep");
int t = idrep.find(",");
int u = idrep.find(" ");
string idrep2 = idrep.erase(2,n-2);
int v = idrep2.find(" ");

if(( k!=0)||(point2 != point)||( t<0)||(u!=3)||(v!=1))
{
rep3 = false;
}
return rep3;
}
//------------------******************---------------------------------------------------------
void repfunction(string idrep)
{
std::map<string,Element> liste;
std::map<string,Element>::iterator it = liste.begin();
int dim = idrep.length();
string id;
id = idrep.substr(4, dim-5);
int cpt=0;
cout<< id<< endl;
for (it=liste.begin(); it!= liste.end(); ++it)
cout<<it->first<< endl;
{
if (id== it->first){
++cpt;
}
}
cout<<cpt<< endl;
if(cpt == 0)
{
cout<< "identifiant inexistant" << endl;
}
else{
Element ol = liste.find(id)->second;
string toto = ol.identificateur;
cout<< toto  << endl;
}
}
//------------------------fonction renvoyant le rang d'un Element--------------------------------
Element Ranger(string id)
{
Element I;
I.identificateur = id;
return I;
}
//--------------------------------------------------------------------------------------

//--------------fonction requete1- ce?------------------------------------------------------
void functionce(string idrep)
{
std::map<string,Element> liste;
std::map<string,Element>::iterator it = liste.begin();
string idrep4, idrep5, idrep6;
int taille = idrep.find(" ");
idrep4 = idrep.substr(0,taille);
idrep5 = idrep.erase(0,taille+4);
int l1 = idrep5.length();
idrep6 = idrep5.substr(0,l1-1);
int k1, p1;
k1=0;
p1=0;
for (it=liste.begin(); it!= liste.end(); ++it)
{
if(it->first ==liste.find(idrep4)->first)
{
k1= k1 +1;
}
}
for (it=liste.begin(); it!= liste.end(); ++it)
{
if(it->first ==liste.find(idrep6)->first) 
{
p1=p1+1;
}
}
if ((k1 == 0)||(p1==0))
{
cout<< "identificateur inexistant"<< endl;
}
else
{ 
Element T =liste.find(idrep4)->second;
Element J = liste.find(idrep6)->second;
cout<<T.identificateur<<" "<<J.identificateur<< endl;
if( T.identificateur==J.identificateur)
{
cout<< "oui"<< endl;
}
else{
cout<< "non"<< endl;
}
}
}


//--------------------------------------------------------------------------------------
Element Element::representant( string identificateur)
{
Element representant;
std::map<string,Element> liste;
std::map<string,Element>::iterator it = liste.begin();
for (it=liste.begin(); it!= liste.end(); ++it)
{
if (identificateur == it->first)
{
representant = it->second;
}
}
return representant;
}
//---------------------------------------------------------------------------
string copyrep_0(string copy1)
{
string tabvar[6];
string copy;
string a, b, c, d, e,f,g,h,v,w, z;
int k, l, t, n, m, p;
const string esp = " ";
const string virgule = ",";
const string point = ".";
int dim = copy1.length();
copy = copy1.substr(0,dim-1);
k = copy.find(esp);
f = copy.substr(0, k);
a = copy.erase(0,k+5);
l= a.find(virgule);
if (l<0){
tabvar[0] = f;
tabvar[1] =a;
tabvar[2] = esp;
tabvar[3] = esp;
tabvar[4] = esp;
tabvar[5] = esp;
}
else{
g = a.substr(0, l);
b = a.erase(0,l+1);
t= b.find(virgule);
if(t<0){
tabvar[0] = f;
tabvar[1] =g;
tabvar[2] = b;
tabvar[3] = esp;
tabvar[4] = esp;
tabvar[5] = esp;
}
else{
h = b.substr(0, t);
c= b.erase(0,t+1);
n= c.find(virgule);
if (n<0)
{
tabvar[0] = f;
tabvar[1] =g;
tabvar[2] = h;
tabvar[3] = c;
tabvar[4] = esp;
tabvar[5] = esp;
}
else{
v= c.substr(0, n);
d =c.erase(0,n+1);
m= d.find(virgule);
if (m<0)
{
tabvar[0] = f;
tabvar[1] =g;
tabvar[2] = h;
tabvar[3] = v;
tabvar[4] = d;
tabvar[5] = esp;
}
else{
e= d.substr(0, m);
tabvar[0] = f;
tabvar[1] =g;
tabvar[2] = h;
tabvar[3] = v;
tabvar[4] = e;
tabvar[5] =d.erase(0, m+1); 
}
}
}
}
return tabvar[0];
}
//id1
string copyrep_1(string copy1)
{
string tabvar[6];
string copy;
string a, b, c, d, e,f,g,h,v,w, z;
int k, l, t, n, m, p;
const string esp = " ";
const string virgule = ",";
const string point = ".";
int dim = copy1.length();
copy = copy1.substr(0,dim-1);
k = copy.find(esp);
f = copy.substr(0, k);
a = copy.erase(0,k+5);
l= a.find(virgule);
if (l<0){
tabvar[0] = f;
tabvar[1] =a;
tabvar[2] = esp;
tabvar[3] = esp;
tabvar[4] = esp;
tabvar[5] = esp;
}
else{
g = a.substr(0, l);
b = a.erase(0,l+1);
t= b.find(virgule);
if(t<0){
tabvar[0] = f;
tabvar[1] =g;
tabvar[2] = b;
tabvar[3] = esp;
tabvar[4] = esp;
tabvar[5] = esp;
}
else{
h = b.substr(0, t);
c= b.erase(0,t+1);
n= c.find(virgule);
if (n<0)
{
tabvar[0] = f;
tabvar[1] =g;
tabvar[2] = h;
tabvar[3] = c;
tabvar[4] = esp;
tabvar[5] = esp;
}
else{
v= c.substr(0, n);
d =c.erase(0,n+1);
m= d.find(virgule);
if (m<0)
{
tabvar[0] = f;
tabvar[1] =g;
tabvar[2] = h;
tabvar[3] = v;
tabvar[4] = d;
tabvar[5] = esp;
}
else{
e= d.substr(0, m);
tabvar[0] = f;
tabvar[1] =g;
tabvar[2] = h;
tabvar[3] = v;
tabvar[4] = e;
tabvar[5] =d.erase(0, m+1); 
}
}
}
}
 
return tabvar[1];
//cout<< a<< endl;
}
//id2
string copyrep_2(string copy1)
{
string tabvar[6];
string copy;
string a, b, c, d, e,f,g,h,v,w, z;
int k, l, t, n, m, p;
const string esp = " ";
const string virgule = ",";
const string point = ".";
int dim = copy1.length();
copy = copy1.substr(0,dim-1);
k = copy.find(esp);
f = copy.substr(0, k);
a = copy.erase(0,k+5);
l= a.find(virgule);
if (l<0){
tabvar[0] = f;
tabvar[1] =a;
tabvar[2] = esp;
tabvar[3] = esp;
tabvar[4] = esp;
tabvar[5] = esp;
}
else{
g = a.substr(0, l);
b = a.erase(0,l+1);
t= b.find(virgule);
if(t<0){
tabvar[0] = f;
tabvar[1] =g;
tabvar[2] = b;
tabvar[3] = esp;
tabvar[4] = esp;
tabvar[5] = esp;
}
else{
h = b.substr(0, t);
c= b.erase(0,t+1);
n= c.find(virgule);
if (n<0)
{
tabvar[0] = f;
tabvar[1] =g;
tabvar[2] = h;
tabvar[3] = c;
tabvar[4] = esp;
tabvar[5] = esp;
}
else{
v= c.substr(0, n);
d =c.erase(0,n+1);
m= d.find(virgule);
if (m<0)
{
tabvar[0] = f;
tabvar[1] =g;
tabvar[2] = h;
tabvar[3] = v;
tabvar[4] = d;
tabvar[5] = esp;
}
else{
e= d.substr(0, m);
tabvar[0] = f;
tabvar[1] =g;
tabvar[2] = h;
tabvar[3] = v;
tabvar[4] = e;
tabvar[5] =d.erase(0, m+1); 
}
}
}
}
 
return tabvar[2];
}

//id3
string copyrep_3(string copy1)
{
string tabvar[6];
string copy;
string a, b, c, d, e,f,g,h,v,w, z;
int k, l, t, n, m, p;
const string esp = " ";
const string virgule = ",";
const string point = ".";
int dim = copy1.length();
copy = copy1.substr(0,dim-1);
k = copy.find(esp);
f = copy.substr(0, k);
a = copy.erase(0,k+5);
l= a.find(virgule);
if (l<0){
tabvar[0] = f;
tabvar[1] =a;
tabvar[2] = esp;
tabvar[3] = esp;
tabvar[4] = esp;
tabvar[5] = esp;
}
else{
g = a.substr(0, l);
b = a.erase(0,l+1);
t= b.find(virgule);
if(t<0){
tabvar[0] = f;
tabvar[1] =g;
tabvar[2] = b;
tabvar[3] = esp;
tabvar[4] = esp;
tabvar[5] = esp;
}
else{
h = b.substr(0, t);
c= b.erase(0,t+1);
n= c.find(virgule);
if (n<0)
{
tabvar[0] = f;
tabvar[1] =g;
tabvar[2] = h;
tabvar[3] = c;
tabvar[4] = esp;
tabvar[5] = esp;
}
else{
v= c.substr(0, n);
d =c.erase(0,n+1);
m= d.find(virgule);
if (m<0)
{
tabvar[0] = f;
tabvar[1] =g;
tabvar[2] = h;
tabvar[3] = v;
tabvar[4] = d;
tabvar[5] = esp;
}
else{
e= d.substr(0, m);
tabvar[0] = f;
tabvar[1] =g;
tabvar[2] = h;
tabvar[3] = v;
tabvar[4] = e;
tabvar[5] =d.erase(0, m+1); 
}
}
}
}
return tabvar[3];
}

//id4
string copyrep_4(string copy1)
{
string tabvar[6];
string copy;
string a, b, c, d, e,f,g,h,v,w, z;
int k, l, t, n, m, p;
const string esp = " ";
const string virgule = ",";
const string point = ".";
int dim = copy1.length();
copy = copy1.substr(0,dim-1);
k = copy.find(esp);
f = copy.substr(0, k);
a = copy.erase(0,k+5);
l= a.find(virgule);
if (l<0){
tabvar[0] = f;
tabvar[1] =a;
tabvar[2] = esp;
tabvar[3] = esp;
tabvar[4] = esp;
tabvar[5] = esp;
}
else{
g = a.substr(0, l);
b = a.erase(0,l+1);
t= b.find(virgule);
if(t<0){
tabvar[0] = f;
tabvar[1] =g;
tabvar[2] = b;
tabvar[3] = esp;
tabvar[4] = esp;
tabvar[5] = esp;
}
else{
h = b.substr(0, t);
c= b.erase(0,t+1);
n= c.find(virgule);
if (n<0)
{
tabvar[0] = f;
tabvar[1] =g;
tabvar[2] = h;
tabvar[3] = c;
tabvar[4] = esp;
tabvar[5] = esp;
}
else{
v= c.substr(0, n);
d =c.erase(0,n+1);
m= d.find(virgule);
if (m<0)
{
tabvar[0] = f;
tabvar[1] =g;
tabvar[2] = h;
tabvar[3] = v;
tabvar[4] = d;
tabvar[5] = esp;
}
else{
e= d.substr(0, m);
tabvar[0] = f;
tabvar[1] =g;
tabvar[2] = h;
tabvar[3] = v;
tabvar[4] = e;
tabvar[5] =d.erase(0, m+1); 
}
}
}
}
return tabvar[4];
}
//id5
string copyrep_5(string copy1)
{
string tabvar[6];
string copy;
string a, b, c, d, e,f,g,h,v,w, z;
int k, l, t, n, m, p;
const string esp = " ";
const string virgule = ",";
const string point = ".";
int dim = copy1.length();
copy = copy1.substr(0,dim-1);
k = copy.find(esp);
f = copy.substr(0, k);
a = copy.erase(0,k+5);
l= a.find(virgule);
if (l<0){
tabvar[0] = f;
tabvar[1] =a;
tabvar[2] = esp;
tabvar[3] = esp;
tabvar[4] = esp;
tabvar[5] = esp;
}
else{
g = a.substr(0, l);
b = a.erase(0,l+1);
t= b.find(virgule);
if(t<0){
tabvar[0] = f;
tabvar[1] =g;
tabvar[2] = b;
tabvar[3] = esp;
tabvar[4] = esp;
tabvar[5] = esp;
}
else{
h = b.substr(0, t);
c= b.erase(0,t+1);
n= c.find(virgule);
if (n<0)
{
tabvar[0] = f;
tabvar[1] =g;
tabvar[2] = h;
tabvar[3] = c;
tabvar[4] = esp;
tabvar[5] = esp;
}
else{
v= c.substr(0, n);
d =c.erase(0,n+1);
m= d.find(virgule);
if (m<0)
{
tabvar[0] = f;
tabvar[1] =g;
tabvar[2] = h;
tabvar[3] = v;
tabvar[4] = d;
tabvar[5] = esp;
}
else{
e= d.substr(0, m);
tabvar[0] = f;
tabvar[1] =g;
tabvar[2] = h;
tabvar[3] = v;
tabvar[4] = e;
tabvar[5] =d.erase(0, m+1); 
}
}
}
} 
return tabvar[5];
}

//fonction controlant la saisie du nom dela classe

bool controleclasse(string equivclass)
{
const string point = ".";
string point2;
int p = equivclass.find(" ");
int n = equivclass.length();
int m = n-1;
bool ok;
ok = false;
point2 = equivclass.substr(m, 1);
if (( point2 == point)&&(p<0))
{
ok = true;
}
else
{
ok = false;
}
return ok;
}

//fonction controle de saisie des elements d'une classe d'eauivalence

bool controlrep(string idrep)
{
const string point = ".";
string point2;
string idrep3;
int k = idrep.find("rep");
int n = idrep.length();
int m = n-1;
bool ok;
int u = idrep.find(" ");
idrep3 = idrep.substr(0,u+3);
point2 = idrep.substr(m,1);
string idrep2 = idrep.erase(0,u+3);
int v = idrep2.find(" ");
if((k>0)&&(point2 == point)&&(u == k-1)&&(v==1))
{
ok = true;
idrep = idrep3 + idrep2;
return ok;
}
else
{
ok=0;
idrep = idrep3 + idrep2;
return ok;
}
}
//------------------fonction----principale--------------------------------------------------
int main()
{
std::map<string,Element> liste;
std::map<string,Element>::iterator it = liste.begin();
string id_0, id_1, id_2,id_3,id_4,id_5,id_6,idrep;
Element A, B, C, D, E,F,G,H;
bool ok, rep1, rep2,rep3,rep4,rep5,rep6;
ok = true;
rep1= false;
rep2 = false;
rep3= false;
rep4 = false;
rep5= false;
rep6 = false;
//cout<< "créez une classe"<< endl;
const string reponse3 = " ";
string reponse;
cout<<"*************************"<< endl;
cout<<"*"<<"Le but de ce programme:*"<< endl;
cout<<"*"<<" "<<"**"<<" "<<"***"<<" "<<"**"<<" "<<"**"<<" "<<"**********"<< endl;
cout<<" "<< endl;
cout<<"->Construire des classes d'éauivalence;"<< endl;
cout<<" "<< endl;
cout<<"-> Ajouter des éléments dans une classe existente;"<< endl;
cout<< " "<< endl;
cout<<"-> Faire l’union de deux classes existantes;"<< endl;
cout<< " "<< endl;
cout<<"-> Vérifier que deux éléments sont présentement dans la même classe d’équivalence;"<< endl;
cout<< " "<< endl;
cout<<"-> Donner le représentant courant d’une classe d’équivalence;"<< endl;
cout<< " "<< endl;
cout<<"-> Donner le représentant minimal commun de deux éléments;"<< endl;
cout<< " "<< endl;
cout<< "taper la touche espace puis la touche Entrée pour sortir du programme"<< endl;
do{
getline(cin,idrep);
if (idrep == reponse3)
{
cout<< "Merci d'avoir utilisé ce programme"<< endl;
}
else{
int rg;
rep1 = controleclasse(idrep);
if (rep1== true)
{
int longueur= idrep.length();
id_0 = idrep.substr(0,longueur-1);
A.identificateur = id_0;
A.rang = 0;
A.suivant = NULL;
liste.insert ( std::pair<string,Element>(A.identificateur,A) );
}else{
rep2 = controlrep(idrep);
if (rep2== true)
{
id_1 = copyrep_0(idrep);
id_2 = copyrep_1(idrep);
id_3 = copyrep_2(idrep);
id_4 = copyrep_3(idrep);
id_5 = copyrep_4(idrep);
id_6 = copyrep_5(idrep);
int n= 0;
for (it=liste.begin(); it!= liste.end(); ++it)
{
//cout<< it->first << endl; 
if (id_1 == it->first)
{
 ++n;
}
}
if(n == 0)
{
ok = false;
cout<<id_1<< " "<<"n'existe pas dans la liste, saisie invalide"<< endl;
}
else{
int k = 0;
for (it=liste.begin(); it!= liste.end(); ++it)
{
//cout<< it->first << endl;
if (id_2 == it->first)
{
++k;
}
}
if(k != 0)
{
cout<<" "<< endl;
}
else{
B.identificateur = id_2;
 rg = A.rang;
 A.rang = rg +1;
B.rang = A.rang;
B.suivant = &A;

C.identificateur = id_2;
C.rang = rg;
C.suivant = &B;
liste.insert ( std::pair<string,Element>(C.identificateur,A) );
}
if(id_3 != " ")
{
int m = 0;
for (it=liste.begin(); it!= liste.end(); ++it)
{
//cout<< it->first << endl;
if (id_3 == it->first)
{
++k;
}
}
if(m != 0)
{
cout<<id_3<< " "<< endl;
}
else{
D.identificateur = id_3;
D.rang = rg;
D.suivant = &B;
liste.insert ( std::pair<string,Element>(D.identificateur,A) );
}
}
if(id_4 != " ")
{
int t = 0;
for (it=liste.begin(); it!= liste.end(); ++it)
{
//cout<< it->first << endl;
if (id_4 == it->first)
{
++t;
}
}
if(t!= 0)
{
cout<<id_4<< " "<< endl;
}
else{
E.identificateur = id_4;
E.rang = rg;
E.suivant = &B;
liste.insert ( std::pair<string,Element>(E.identificateur,A) );
}
}
if(id_5 != " ")
{
int q = 0;
for (it=liste.begin(); it!= liste.end(); ++it)
{
//cout<< it->first << endl;
if (id_5 == it->first)
{
++q;
}
}
if(q != 0)
{
cout<< " "<< endl;
}
else{
F.identificateur = id_5;
F.rang = rg;
F.suivant = &B;
liste.insert ( std::pair<string,Element>(F.identificateur,A) );
}
}
if(id_6 != " ")
{
int s = 0;
for (it=liste.begin(); it!= liste.end(); ++it)
{
//cout<< it->first << endl;
if (id_6 == it->first)
{
++s;
}
}
if(s != 0)
{
cout<<id_6<< " "<< endl;
}
else{
G.identificateur = id_6;
G.rang = rg;
G.suivant = &B;
liste.insert ( std::pair<string,Element>(G.identificateur,A) );
}
}
}
}
else
{
rep3 = controlerepdebut1(idrep);
if(rep3== true)
{
//repfunction(idrep);
int dim = idrep.length();
string id;
id = idrep.substr(4, dim-5);
int cpt= 0;
for (it=liste.begin(); it!= liste.end(); ++it)
{
if (it->first ==liste.find(id)->first){
cpt = cpt+1;
}
}
if(cpt == 0)
{
cout<< "identifiant inexistant" << endl;
}
else{
Element ol = liste.find(id)->second;
string toto = ol.identificateur;
cout<< toto  << endl;
}
}
else
{
rep4 = controlece(idrep);
if(rep4 == true)
{
string idrep4, idrep5, idrep6;
int taille = idrep.find(" ");
idrep4 = idrep.substr(0,taille);
idrep5 = idrep.erase(0,taille+4);
int l1 = idrep5.length();
idrep6 = idrep5.substr(0,l1-1);
int k1, p1;
k1=0;
p1=0;
for (it=liste.begin(); it!= liste.end(); ++it)
{
if(it->first ==liste.find(idrep4)->first)
{
k1= k1 +1;
}
}
for (it=liste.begin(); it!= liste.end(); ++it)
{
if(it->first ==liste.find(idrep6)->first) 
{
p1=p1+1;
}
}
if ((k1 == 0)||(p1==0))
{
cout<< "identificateur inexistant"<< endl;
}
else
{ 
Element T =liste.find(idrep4)->second;
Element J = liste.find(idrep6)->second;
if( T.identificateur==J.identificateur)
{
cout<< "oui"<< endl;
}
else{
cout<< "non"<< endl;
}
}

}//fin if pour rp4==true
else{
rep5 =controlerepdebut2(idrep);
 if(rep5== true)
{
string idrepe1, idrepe2, idrepe3, idrepe4;
idrepe1 = idrep.erase(0,4);
int din = idrepe1.find(",");
idrepe2 = idrepe1.substr(0,din);
 idrepe3 = idrepe1.erase(0, din+1);
int lg = idrepe3.length();
idrepe4 = idrepe3.substr(0,lg-1);
int k2, p2;
k2=0;
p2=0;
for (it=liste.begin(); it!= liste.end(); ++it)
{
if(it->first == liste.find(idrepe2)->first)
{
k2 = k2+1;
}
if(it->first == liste.find(idrepe4)->first)
{
p2= p2+1;
}
}
if ((k2 == 0)||(p2==0))
{
cout<< "identificateur inexistant"<< endl;
}
else{
Element S,T;
S= liste.find(idrepe2)->second;
T= liste.find(idrepe4)->second;
Element courant1,courant2;
courant1.identificateur = idrepe2;
courant2.identificateur = idrepe4;
if(S.identificateur ==T.identificateur){
//while( (courant1->suivant!=NULL)||(courant2->suivant!=NULL)||(courant1->suivant!=courant2->suivant))
//{
//if (courant1->suivant==NULL)
//{
Element H;
H.rang = courant1.rang +1;
cout<<H.identificateur<<endl;
//}
//else{
//courant1 = courant1->suivant;
//}
//if ((courant2->suivant==NULL)||(courant1->suivant==courant2->suivant))
//{
//cout<<courant2->identificateur<<endl;
//}
////else{
//courant2 = courant2->suivant;
//}

//}
}
else{
cout<< idrepe2<<" "<<"et"<<" "<<idrepe4<< " "<<"ne sont pas dans la meme classe"<<endl;
}
}



}//fin if rep5 =true
else{
rep6=controlecepoint(idrep);
if(rep6 == true){
string copy, idrepf1,idrepf2;
int k;
const string esp = " ";
const string virgule = ",";
const string point = ".";
int dim2 = idrep.length();
copy = idrep.substr(0,dim2-1);
k = idrep.find(esp);
idrepf1 = idrep.substr(0, k);
idrepf2 = copy.erase(0,k+4);
int k2, p2;
k2=0;
p2=0;
for (it=liste.begin(); it!= liste.end(); ++it)
{
if(it->first == liste.find(idrepf1)->first)
{
k2 = k2+1;
}
if(it->first == liste.find(idrepf2)->first)
{
p2= p2+1;
}
}
if ((k2 == 0)||(p2==0))
{
cout<< "identificateur inexistant"<< endl;
}// fin if d'existence de idrepf1 dans la liste
else{
for (it=liste.begin(); it!= liste.end(); ++it)
{
if(it->second.identificateur == liste.find(idrepf2)->second.identificateur)
{
string echange = it->first;
liste.erase(it);
liste.insert ( std::pair<string,Element>(echange,liste.find(idrepf1)->second) );
}//fin if
}//fin for
}//fin   if d'existence de idrepf1 dans laliste
}//fin else rep5 ==1
else{

cout<<"Saisie invalide"<< endl;
}
}//fin else de rep5 = 0
}// fin else rep4 ==0
}//else fin rp3==0
//-------------------------------------------------------------------------------------------

//---------
}//fin else pour rep2 = 0--------
}//---fin else rep1 = 0----
}//--fin else idrep!= reponse3
}//--fin do---

while ((idrep!= reponse3)&&(ok==true));

}
//------------------fonction----principale--------------------------------------------------

