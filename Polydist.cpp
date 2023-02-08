#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <math.h>  
#include <iomanip> 
using namespace std;
//-----------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------Class Point-------------------------------------------------------------------------------------------------
class Point{
double absc;
double ord;
char point;
public:
      Point(double x, double y, char P):
       absc(x),
       ord(y),
       point(P)
       {}
     Point(const Point & Pt):
      absc(Pt.absc),
      ord(Pt.ord),
      point(Pt.point){}
      double getabsc(){return absc; }
      double getord(){return ord; }
      char getpoint(){return point; }
};
//-----------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------Prototype de fonctions--------------------------------------------------------------------------------------
double dist1(Point,Point);
double dist2(Point,Point,Point);
double coeff1(Point,Point);
double coeff2(Point,Point);
Point intersection(Point,Point, Point);
bool appartient(Point, Point, Point);
double dist3(Point, Point, Point);
bool appartient2(vector<Point>polygone, Point );
double dist4(vector<Point>polygone, Point);
vector<double>Decoupe(string);
//-----------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------Fonction distance entre deux points-------------------------------------------------------------------------
double dist1(Point P1, Point P2){
double inter, d;
inter = (P2.getord()-P1.getord())*(P2.getord()-P1.getord()) + (P2.getabsc()-P1.getabsc())*(P2.getabsc()-P1.getabsc());
d = sqrt(inter);
return d;
}
//-----------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------
//-----------------------Fonction distance entre un point et une droite--------------------------------------------------------------------
double dist2(Point p1, Point p2, Point p3){
double a,b,x,y,c,r,inter,d;
a = p2.getabsc()-p1.getabsc();
b = p2.getord()-p1.getord();
c= a*p1.getord()-b*p1.getabsc();
inter = a*a+b*b;
r= sqrt(inter);
d=(abs(b*p3.getabsc() - a*p3.getord() +c))/r;
return d;
}
//-----------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------Fonction calcul coeff1--------------------------------------------------------------------------------------
double coeff1(Point P1, Point P2){
double a;
if(P1.getabsc()==P2.getabsc()){
a = atof("INFINITY");
}
else{
a= (P2.getord()-P1.getord())/(P2.getabsc()-P1.getabsc());
}
return a;
}
//-----------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------Fonction calcul coeff1--------------------------------------------------------------------------------------
double coeff2(Point P1, Point P2){
double b;
if(P1.getabsc()==P2.getabsc()){
b = P1.getabsc();
}
else{
b= P1.getord()- ((P2.getord()-P1.getord())/(P2.getabsc()-P1.getabsc()))*P1.getabsc();
}
return b;
}
//-----------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------
//-----------------------Fonction controle de projection-----------------------------------------------------------------------------------
Point intersection(Point p1, Point p2, Point p3){
Point *P;
double a,b,D,Dt,t,dx,dy,x,y;
char I;
a = p2.getabsc()-p1.getabsc();
b = p2.getord()-p1.getord();
dx = p3.getabsc()-p1.getabsc();
dy=p3.getord()-p1.getord();
Dt= a*dx + b*dy;
D= a*a + b*b;
t= Dt/D;
//cout<<a<<endl;
//cout<<b<<endl;

        x = p1.getabsc() + a*t;
        y = p1.getord() + b*t;
P= new Point(x,y,I);
return *P;
}
//-----------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------
//-----------------------Appartenance de la projection au segment--------------------------------------------------------------------------
bool appartient(Point p1, Point p2, Point p3){
double x1, x2, y1, y2,x3,y3,petitx, petity, grdx,grdy;
x1= p1.getabsc();
x2=p2.getabsc();
x3= intersection(p1,p2,p3).getabsc();
y1=p1.getord();
y2=p2.getord();
y3= intersection(p1,p2,p3).getord();
petitx= min(x1,x2);
petity= min(y1,y2);
grdx= max(x1,x2);
grdy = max(y1,y2);
bool rep=0;
if((petitx <= x3)&&(petity<=y3)&&(grdx>=x3)&&(grdy>=y3)){
rep=1;
}
return rep;
}
//-----------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------
//-----------------------Distance entre un point et un segment-----------------------------------------------------------------------------
double dist3(Point p1, Point p2, Point p3){
double d;
if(appartient(p1,p2,p3)==1){
 d= dist2(p1,p2,p3);
}
 else{
  d= min(dist1(p1,p3),dist1(p2,p3));
 }
return d;
}
//-----------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------
//-----------------------Appartenance d'un point à un polygone-----------------------------------------------------------------------------
bool appartient2(vector<Point>polygone, Point p){
int cpt =0;
double x,y, maxy=0;
bool rep=0;
for(int i=0; i<polygone.size();++i){
if(polygone[i].getord()>=maxy){
 maxy = polygone[i].getord();
  }
}
polygone.push_back(polygone[0]);
for(int i=0; i<polygone.size();++i){
 if(polygone[i].getabsc()!=polygone[i+1].getabsc()){
  x=p.getabsc();
  y=(coeff1(polygone[i],polygone[i+1]))*x +coeff2(polygone[i],polygone[i+1]);
  if((p.getord()-y)*(maxy-y)<0){
   cpt=cpt+1;
   }
}
}
if(cpt%2==1){
 rep=1;
 }
return rep;
}
//-----------------------------------------------------------------------------------------------------------------------------------------
//-----------------------Calcul de distance d'un point à polygone--------------------------------------------------------------------------
double dist4(vector<Point>polygone,Point p){
double d;
if(appartient2(polygone,p)==1){
d=0;
}
 else{
     double l=polygone.size();
     d=dist3(polygone[l],polygone[0],p);
       //cout<<"***"<<d<<endl;
   for(int i=0; i<polygone.size();++i){
      if(d>= dist3(polygone[i],polygone[i+1],p)){
          
        d =dist3(polygone[i],polygone[i+1],p);
        // cout<<"***"<<d<<endl;
         
        }
      }
     
    }
return d;
}
//-----------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------
//---------------------------Decoupe-------------------------------------------------------------------------------------------------------
vector<double> Decoupe(string chaine){
int n;
   vector<double> stockage;
  double x0, y0;
  string lg,a0,b0,str1;
  //getline(cin,chaine);
 lg= chaine.erase(0,13);
 // cout<<lg.length()<<endl;
  a0=lg.substr(1,lg.find(",")-1);
  b0= lg.substr(lg.find(",")+1,lg.find(")")-lg.find(",")-1);
  x0= atof(a0.c_str());
  y0= atof(b0.c_str());
  stockage.push_back(x0);
  stockage.push_back(y0);
  str1=lg.substr(lg.find("[")+2,lg.length()-lg.find("[")-3);
 //cout<<str1<<endl;
 //cout<<a0<<endl;
 //cout<<b0<<endl;
 //cout<<lg<<endl;
 //cout<<x0<<endl;
 //cout<<y0<<endl;
do{
stockage.push_back(  atof(   (  str1.substr(0,str1.find(","))).c_str()       )   );
stockage.push_back(  atof(  str1.substr(  str1.find(",")+1,str1.find(")")-str1.find(",")-1 ).c_str()   )  );
str1= str1.substr(str1.find(")")+3,str1.length()- str1.find(")")-2);
//cout<<str1<<endl;
}
while(str1.find(")") +2 <str1.length());
stockage.push_back( atof(   (  str1.substr(0,str1.find(","))).c_str() )   );
stockage.push_back( atof(   (str1.substr(str1.find(",")+1,str1.length()-2)).c_str() )   );
//for(int i=0;i<stockage.size();i++){
//cout<<stockage[i];
//}
return stockage; 
}
//-----------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------
//---------------------------Programme Principal-------------------------------------------------------------------------------------------
int main(){
vector<Point>polygone;
vector<double>stockage;
Point *p;
char P;
string chaine;
getline(cin,chaine); 
stockage=Decoupe(chaine); 
p= new Point(stockage[0],stockage[1],P);
for(int i=2;i<stockage.size();i=i+2){
//cout<<stockage[i]<<endl;
//cout<<stockage[i+1]<<endl;
Point *p1;
p1=new Point(stockage[i],stockage[i+1],P);
polygone.push_back(*p1);
}
//cout<<appartient2(polygone,*p)<<endl;
cout << fixed;
cout<<setprecision(6)<<dist4(polygone,*p)<<endl;
}
