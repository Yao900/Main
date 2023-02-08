#include<iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;
using std::setprecision;
//using namespace GiNaC;
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
class etat
{
public:

    vector<bool>bin;
    vector<int>mot;
    string comppar;
    int longueur;

	
};
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
class transit
{
public:
	int airx;
	int periy;
	int feuillez;
	int compconn;
	int coef;
	
};
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
class polytransit
{
public:
	vector<transit>poly;
	
	
};
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
int BoolToInt(bool b){
	int n;
	if (b==0)
	{
		n=0;
	}
	else{
		n=1;
	}
	return n;
}
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
//----valeur absolue-------------------------------------------------------------------------------
int Abs(int n){
	int r;
	if (n>=0)
	{
		r=n;
	}
	else{
		r=-n;
	}
	return r;
}
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
string EspSpp(string commande){
commande.erase(remove_if(commande.begin(),commande.end(),::isspace),commande.end());
return commande;
}
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
bool StringTobool(string str){
	bool b;
  if (str=="0")
  {
  	b=0;
  }
  if (str=="1")
  {
  	b=1;
  }
  return b;
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
int stringToMot(string str){
  int ent;
  if (str=="0")
  {
  	ent=0;
  }
  if (str=="1")
  {
  	ent=1;
  }
  if (str=="2")
  {
  	ent=2;
  }
  if (str=="3")
  {
  	ent=3;
  }
  return ent;
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
bool ConpatibleMotL33(etat e1, etat e2){
     bool rep=0;
     int l1,l2,l3,l4,l5,l6;
     l1=BoolToInt(e2.bin[0]);
     l2=BoolToInt(e2.bin[1]);
     l3=BoolToInt(e2.bin[2]);
     l4=BoolToInt(e1.bin[0]);
     l5=BoolToInt(e1.bin[1]);
     l6=BoolToInt(e1.bin[2]);
       
         if (l1*(l4+l2)==e2.mot[0] && l2*(l1+l5+l3)==e2.mot[1] && l3*(l6+l2)==e2.mot[2])
         {
         
         	rep=1;
         }
         //cout<<"-----"<<l1*(l4+l2)<<"="<<e2.mot[0]<<endl;
         //cout<<"-----"<<l2*(l1+l5+l3)<<"="<<e2.mot[1]<<endl;
         //cout<<"-----"<<l3*(l6+l2)<<"="<<e2.mot[2]<<endl;
        //cout<<"+++"<<rep<<endl;

	return rep;
}
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

//--------------------------Extreme01------------------------------------------------------------------
bool Extreme01(etat e){
	bool rep =0;
	if(e.longueur>=2  && e.bin[0]==0 && e.bin[e.longueur-1]==1){
        rep=1;
	}
	return rep;
}

//-------------------------------------------------------------------------------------------------
//--------------------------Extreme10------------------------------------------------------------------
bool Extreme10(etat e){
	bool rep =0;
	if(e.longueur>=2  && e.bin[0]==1 && e.bin[e.longueur-1]==0){
        rep=1;
	}
	return rep;
}
//-------------------------------------------------------------------------------------------------
//--------------------------Extreme00------------------------------------------------------------------
bool Extreme00(etat e){
	bool rep =0;
	if(e.longueur>=2  && e.bin[0]==0 && e.bin[e.longueur-1]==0){
        rep=1;
	}
	return rep;
}

//-------------------------------------------------------------------------------------------------
//--------------------------Extreme11------------------------------------------------------------------
bool Extreme11(etat e){
	bool rep =0;
	if(e.longueur>=2  && e.bin[0]==1 && e.bin[e.longueur-1]==1){
        rep=1;
	}
	return rep;
}
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
bool ConpatibleMotL32(etat e1, etat e2){
     bool rep=0;
     int l1,l2,l4,l5,l6;
     l1=BoolToInt(e2.bin[0]);
     l2=BoolToInt(e2.bin[1]);
     l4=BoolToInt(e1.bin[0]);
     l5=BoolToInt(e1.bin[1]);
     l6=BoolToInt(e1.bin[2]);

     if (Extreme00(e1)==1)
     {
     	rep=0;
     }
     else{
     	if (Extreme01(e1)==1 && (l1*(l4+l2)==e2.mot[0]&& l2*(l5+l1)==e2.mot[1]))
     	{
     		rep=1;
     	}
     	else{
     		if (Extreme10(e1)==1 &&(l1*(l5+l2)==e2.mot[0] && l2*(l6+l1)==e2.mot[1] ))
     		{
     			rep=1;
     		}
     		else{
     			if (Extreme11(e1)==1 && (l1*(l4+l2)==e2.mot[0] && l2*(l5+l1)==e2.mot[1]) ||(l1*(l5+l2)==e2.mot[0] && l2*(l6+l1)==e2.mot[1]) )
     			{
     				rep=1;
     			}
     		}
     	}
     }
   

	return rep;
}
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
bool ConpatibleMotL31(etat e1, etat e2){
     bool rep=0;
     int l1,l4,l5,l6;
     l1=BoolToInt(e2.bin[0]);
     l4=BoolToInt(e1.bin[0]);
     l5=BoolToInt(e1.bin[1]);
     l6=BoolToInt(e1.bin[2]);
       
      if (Extreme00(e1)==1)
     {
     	rep=0;
     }
     else{
     	if (Extreme01(e1)==1 && l1*l4==e2.mot[0])
     	{
     		rep=1;
     	}
     	else{
     		if (Extreme10(e1)==1 && l1*l6==e2.mot[0])
     		{
     			rep=1;
     		}
     		else{
     			if (Extreme11(e1)==1 && ( (l1*l4==e2.mot[0]) ||(l1*l5==e2.mot[0]) || (l1*l6==e2.mot[0])  ))
     			{
     				rep=1;
     			}
     		}
     	}
     }   
   

	return rep;
}
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
bool ConpatibleMotL22(etat e1, etat e2){
     bool rep=0;
     int l1,l2,l4,l5;
     l1=BoolToInt(e2.bin[0]);
     l2=BoolToInt(e2.bin[1]);
     l4=BoolToInt(e1.bin[0]);
     l5=BoolToInt(e1.bin[1]);
       
         if ((l1*(l4+l2)==e2.mot[0] && l2*(l5+l1)==e2.mot[1]))
         {
         
         	rep=1;
         }
   

	return rep;
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
bool ConpatibleMotL21(etat e1, etat e2){
     bool rep=0;
     int l1,l4,l5;
     l1=BoolToInt(e2.bin[0]);
     l4=BoolToInt(e1.bin[0]);
     l5=BoolToInt(e1.bin[1]);
     
      if (Extreme00(e1)==1)
     {
     	rep=0;
     }
     else{
     	if (Extreme01(e1)==1 && l1*l4==e2.mot[0])
     	{
     		rep=1;
     	}
     	else{
     		if (Extreme10(e1)==1 && l1*l5==e2.mot[0])
     		{
     			rep=1;
     		}
     		else{
     			if (Extreme11(e1)==1 && ( (l1*l4==e2.mot[0]) ||(l1*l5==e2.mot[0])   ))
     			{
     				rep=1;
     			}
     		}
     	}
     }   
   
 
         

	return rep;
}
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
bool ConpatibleMotL11(etat e1, etat e2){
     bool rep=0;
     int l1,l4;
     l1=BoolToInt(e2.bin[0]);
     l4=BoolToInt(e1.bin[0]);
     
     
       
         if ((l1*l4==e2.mot[0]) )
         {
         
         	rep=1;
         }
   

	return rep;
}
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
bool ConpatibleMot(etat e1, etat e2){
     bool rep=0;
     int l1,l2,l3,l4,l5,l6;
     l1=BoolToInt(e2.bin[0]);
     l2=BoolToInt(e2.bin[1]);
     l3=BoolToInt(e2.bin[2]);
     l4=BoolToInt(e1.bin[0]);
     l5=BoolToInt(e1.bin[1]);
     l6=BoolToInt(e1.bin[2]);
       
         if (e1.longueur==3 && e2.longueur==3)
         {
         
         	rep=ConpatibleMotL33(e1,e2);
         }
         if (e1.longueur==3 && e2.longueur==2)
         {
         
         	rep=ConpatibleMotL32(e1,e2);
         }
         if (e1.longueur==3 && e2.longueur==1)
         {
         
         	rep=ConpatibleMotL31(e1,e2);
         }
         if (e1.longueur==2 && e2.longueur==2)
         {
         
         	rep=ConpatibleMotL22(e1,e2);
         }
   
         if (e1.longueur==2 && e2.longueur==1)
         {
         
         	rep=ConpatibleMotL21(e1,e2);
         }
   
         if (e1.longueur==1 && e2.longueur==1)
         {
         
         	rep=ConpatibleMotL11(e1,e2);
         }
   
   

	return rep;
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
bool TransPossFP3(etat e1, etat e2){
	bool rep=1;
	if (e1.longueur <e2.longueur)
	{
		rep=0;
	}
	if ((e1.comppar=="{{0},{1}}" && e2.comppar=="{{0,1}}" )|| (e2.comppar=="{{0},{1}}" && e1.comppar=="{{0,1}}"))
		{
			rep=0;
		}
		
	if (ConpatibleMot(e1,e2)==0)
		{
				rep=0;
				//cout<<"??? "<<ConpatibleMot(e1,e2)<<endl;
		}
	return rep;
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
//-----------------------
int PerimetreEtat(vector<bool>ligne){
    int Dp=0;
    if (ligne.size()==1)
    {
    	Dp= 4*ligne[0];
    }
    else{
    	if (ligne.size()==2)
    	{
    		Dp=4*ligne[0]-2*(ligne[0]*ligne[1]) + 4*ligne[1];
    	}
    	else{
    		for (int i = 0; i < ligne.size()-1; ++i){
                 Dp= Dp+4*ligne[i]-2*(ligne[i]*ligne[i+1]);
            } 
            Dp= Dp + 4*ligne[ligne.size()-1];
    	}
    }
    return Dp;

}
//-------------------------------------------------------------------------------------------------
//-------------------Fonction -------------------------------------------------------

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
transit ProduitTransit(transit t1, transit t2){
	transit tp;
	tp.airx=t1.airx + t2.airx;
	tp.periy=t1.periy + t2.periy;
	tp.feuillez=t1.feuillez+t2.feuillez;
	tp.compconn=t1.compconn+t2.compconn;
	tp.coef=t1.coef*t2.coef;

	return tp;
}
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
bool MemePartieLitterale(transit t1, transit t2){
	bool rep=0;
	if (t1.airx ==t2.airx && t1.periy==t2.periy && t1.feuillez==t2.feuillez && t1.compconn==t2.compconn)
	{

         rep=1;
	}
	return rep;
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
polytransit SommeBinaire(transit t1, transit t2){
	polytransit pt;
	transit tp;
	vector<transit>V;
	if (MemePartieLitterale( t1, t2)==1)
	{
	tp.airx=t1.airx;
	tp.periy=t1.periy;
	tp.feuillez=t1.feuillez;
	tp.compconn=t1.compconn;
	tp.coef=t1.coef+t2.coef;
	pt.poly.push_back(tp);

	}
	else{
		pt.poly.push_back(t1);
		pt.poly.push_back(t2);
	}
	return pt;
}
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
polytransit Sommetri(transit t1,transit t2,transit t3){
	transit pt1,pt2;
	polytransit pt;
	vector<transit>V1;
	vector<transit>V2;
	vector<transit>V3;
	V1= SommeBinaire(t1,t2).poly;
	if (V1.size()==1)
	{
		pt.poly=SommeBinaire(V1[0],t3).poly;
	}
	else{
		if (MemePartieLitterale(V1[0],t3)==1)
		{
	          pt1.airx=V1[0].airx ;
	          pt1.periy=V1[0].periy;
	          pt1.feuillez=V1[0].feuillez;
	          pt1.compconn=V1[0].compconn;
	          pt1.coef=V1[0].coef+t3.coef;
	          pt.poly.push_back(pt1);
	          pt.poly.push_back(V1[1]);

		}
		else{
			if (MemePartieLitterale(V1[1],t3)==1)
			{
			  pt1.airx=V1[1].airx ;
	          pt1.periy=V1[1].periy;
	          pt1.feuillez=V1[1].feuillez;
	          pt1.compconn=V1[1].compconn;
	          pt1.coef=V1[1].coef+t3.coef;
	          pt.poly.push_back(pt1);
	          pt.poly.push_back(V1[0]);
			}
			else{
			      pt.poly.push_back(t1);
	              pt.poly.push_back(t2);	
	              pt.poly.push_back(t3);	
			}
		}
	}
	return pt;
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
//-------
//---------------
int AireEtat(vector<bool>ligne){
    int A=0;
    
    		for (int i = 0; i < ligne.size(); ++i){
                 A= A+ ligne[i];
            } 
    return A;

}
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
//-----------------------
int PeriTransitMemeLongueur(etat e1, etat e2){
    int P=PerimetreEtat(e2.bin);
       
       for (int i = 0; i < e1.longueur; ++i)
       {
        P =P- 2*(e2.bin[i]*e1.bin[i]);
       }
    		
    return P;

}
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
int NombreDeComposantes(etat e){
   int a=AireEtat(e.bin);
   int p=PerimetreEtat(e.bin);
   int nc;
   nc= (p-2*a)/2;
   return nc;

}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
int NombreCelluleDegre0EtatInit(etat e){
	int nc0;
	if (e.longueur==1)
	{
		nc0=e.bin[0];
	}
	if (e.longueur==2)
	{
		nc0=e.bin[0]*(1-e.bin[0]*e.bin[1]) + e.bin[1]*(1-e.bin[0]*e.bin[1]);
	}
	if (e.longueur>2)
	{
		nc0= e.bin[0]*(1-e.bin[0]*e.bin[1]) + e.bin[e.longueur-1]*(1-e.bin[e.longueur-2]*e.bin[e.longueur-1]);
		for (int i = 1; i < e.longueur-1; ++i)
		{
			nc0=nc0 +e.bin[i]*(1-max(e.bin[i-1]*e.bin[i],e.bin[i]*e.bin[i+1]));
		}
	}
	return nc0;
}
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
//-----------Nombre de feuilles d'un état initial---------------------------------------------------
int NombreDefeuilleEtatInitial(etat e){
	int nf,n, nc0;
	n=NombreDeComposantes(e);
	nc0=NombreCelluleDegre0EtatInit(e);
	nf=2*(n-nc0);
	return nf;
}
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
//-----nombre de feuilles d'un état intermédiaire de même longueur que l'état qui le precede-------
int NomreDefeuilleEtatInter(etat e1, etat e2){
	int nf,nf1,n12,n01;
	nf=0;
	if (e1.longueur==e2.longueur && e2.longueur>2)
	{
		
	
          n12=0;
          n01=0;
	      nf1=NombreDefeuilleEtatInitial(e2);
	      for (int i = 0; i < e2.longueur; ++i)
	      {
		        n12=n12 + e1.bin[i]*e2.bin[i]*(min(1,min(e2.mot[i],min(Abs(1-e2.mot[i]),Abs(3-e2.mot[i])))));
		        n01=n01 + e1.bin[i]*e2.bin[i]*(min(1,min(e2.mot[i],min(Abs(2-e2.mot[i]),Abs(3-e2.mot[i])))));
	      }
	
	     nf=nf+nf1-n12+n01;
	}
	if (e2.longueur==2)
	{
		for (int i = 0; i < 2; ++i)
		{
			nf= nf + min(1,  min(e2.mot[i],Abs(2-e2.mot[i])  ));
		}
	}
	if (e2.longueur==1)
	{
		nf=e2.mot[0];
	}
	return nf;
}
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
bool EtatInitial(etat e){
	bool rep=0;
	if (e.longueur==1 && e.bin[0]==1 && e.mot[0]==0)
	{
		rep=1;
	}
	if (e.longueur==2 && BoolToInt(e.bin[0])*BoolToInt(e.bin[1])==e.mot[0])
	{
		rep=1;
	}
	if (e.longueur>2)
	{
		    int cpt=0;
		       if(BoolToInt(e.bin[0])*BoolToInt(e.bin[1])==e.mot[0] &&  BoolToInt(e.bin[e.longueur-2])*BoolToInt(e.bin[e.longueur-1])==e.mot[e.longueur-1]){
			      cpt= cpt+2;
	           }
	           for (int i = 1; i < e.longueur-1; ++i)
	           {
		            if (BoolToInt(e.bin[i])*(BoolToInt(e.bin[i-1])+BoolToInt(e.bin[i+1]))==e.mot[i])
		            {
			            cpt++;
		            }
	           }
               if (cpt==e.longueur)
               {
               	rep=1;
               }

	}
	return rep;

}
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
//---Nombre de feuilles pour une transition--------------------------------------------------------
int VariationNbreFeuilleML(etat e1, etat e2){
    int f,nf,n12,n01, a,b;
    nf=NomreDefeuilleEtatInter(e1,e2);
    n12=0;
    n01=0;
    for (int i = 0; i < e2.longueur; ++i)
    {    b=BoolToInt(e1.bin[i]);
    	 a=BoolToInt(e2.bin[i]);
    	n12=n12+a*b*min(1,min(e1.mot[i]+a*b,min(Abs(1-a*b-e1.mot[i]),min(Abs(3-a*b-e1.mot[i]),Abs(4-a*b-e1.mot[i])))));
    	n01=n01+a*b*min(1,min(e1.mot[i]+a*b,min(Abs(2-a*b-e1.mot[i]),min(Abs(3-a*b-e1.mot[i]),Abs(4-a*b-e1.mot[i])))));
    }
    f=nf-n12+n01;
    return f;
}
//---------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------
vector<int> VariationNbreFeuille32(etat e1, etat e2){
	vector<int>Vp;
	int f,nf,n12,n01,n011,c121,c212,c011,c012;
	int l1,l2,l3,l4,l5,l6;
	nf=NomreDefeuilleEtatInter(e1,e2);
     l1=BoolToInt(e2.bin[0]);
     l2=BoolToInt(e2.bin[1]);
     l3=BoolToInt(e1.bin[0]);
     l4=BoolToInt(e1.bin[1]);
     l5=BoolToInt(e1.bin[2]);
     if (l1*(l2+l3)==e2.mot[0] && l2*(l1+l4)==e2.mot[1] && Extreme01(e1)==1)
     {
        c121=l1*l3*min(1,min(e1.mot[0]+l1*l3,min(Abs(1-l1*l3-e1.mot[0]),min(Abs(3-l1*l3-e1.mot[0]),Abs(4-l1*l3-e1.mot[0])))));
        c212=l2*l4*min(1,min(e1.mot[1]+l2*l4,min(Abs(1-l2*l4-e1.mot[1]),min(Abs(3-l2*l4-e1.mot[1]),Abs(4-l2*l4-e1.mot[1])))));
        c011=l1*l3*min(1,min(e1.mot[0]+l1*l3,min(Abs(2-l1*l3-e1.mot[0]),min(Abs(3-l1*l3-e1.mot[0]),Abs(4-l1*l3-e1.mot[0])))));
        c012=l2*l4*min(1,min(e1.mot[1]+l2*l4,min(Abs(2-l2*l4-e1.mot[1]),min(Abs(3-l2*l4-e1.mot[1]),Abs(4-l2*l4-e1.mot[1])))));
        n12=c121+c212;
        n01=c012+c011;
        f=nf-n12+n01;
        Vp.push_back(f);

     }
     else{
     	   if (l1*(l2+l4)==e2.mot[0] && l2*(l1+l5)==e2.mot[1] && Extreme10(e1)==1)
           {
             c121=l1*l4*min(1,min(e1.mot[1]+l1*l4,min(Abs(1-l1*l4-e1.mot[1]),min(Abs(3-l1*l4-e1.mot[1]),Abs(4-l1*l4-e1.mot[1])))));
             c212=l2*l5*min(1,min(e1.mot[2]+l2*l5,min(Abs(1-l2*l5-e1.mot[2]),min(Abs(3-l2*l5-e1.mot[2]),Abs(4-l2*l5-e1.mot[2])))));
             c011=l1*l4*min(1,min(e1.mot[1]+l1*l4,min(Abs(2-l1*l4-e1.mot[1]),min(Abs(3-l1*l4-e1.mot[1]),Abs(4-l1*l4-e1.mot[1])))));
             c012=l2*l5*min(1,min(e1.mot[2]+l2*l5,min(Abs(2-l2*l5-e1.mot[2]),min(Abs(3-l2*l5-e1.mot[2]),Abs(4-l2*l5-e1.mot[2])))));
             n12=c121+c212;
             n01=c012+c011;
             f=nf-n12+n01;
             Vp.push_back(f);

           }
           else{
           	     if (Extreme11(e1)==1)
           	     {
           	     	  if (l1*(l2+l3)==e2.mot[0] && l2*(l1+l4)==e2.mot[1])
                        {
                            c121=l1*l3*min(1,min(e1.mot[0]+l1*l3,min(Abs(1-l1*l3-e1.mot[0]),min(Abs(3-l1*l3-e1.mot[0]),Abs(4-l1*l3-e1.mot[0])))));
                            c212=l2*l4*min(1,min(e1.mot[1]+l2*l4,min(Abs(1-l2*l4-e1.mot[1]),min(Abs(3-l2*l4-e1.mot[1]),Abs(4-l2*l4-e1.mot[1])))));
                            c011=l1*l3*min(1,min(e1.mot[0]+l1*l3,min(Abs(2-l1*l3-e1.mot[0]),min(Abs(3-l1*l3-e1.mot[0]),Abs(4-l1*l3-e1.mot[0])))));
                            c012=l2*l4*min(1,min(e1.mot[1]+l2*l4,min(Abs(2-l2*l4-e1.mot[1]),min(Abs(3-l2*l4-e1.mot[1]),Abs(4-l2*l4-e1.mot[1])))));
                            n12=c121+c212;
                            n01=c012+c011;
                            f=nf-n12+n01;
                            Vp.push_back(f);

                       }
                      if (l1*(l2+l4)==e2.mot[0] && l2*(l1+l5)==e2.mot[1])
                       {
                           c121=l1*l4*min(1,min(e1.mot[1]+l1*l4,min(Abs(1-l1*l4-e1.mot[1]),min(Abs(3-l1*l4-e1.mot[1]),Abs(4-l1*l4-e1.mot[1])))));
                           c212=l2*l5*min(1,min(e1.mot[2]+l2*l5,min(Abs(1-l2*l5-e1.mot[2]),min(Abs(3-l2*l5-e1.mot[2]),Abs(4-l2*l5-e1.mot[2])))));
                           c011=l1*l4*min(1,min(e1.mot[1]+l1*l4,min(Abs(2-l1*l4-e1.mot[1]),min(Abs(3-l1*l4-e1.mot[1]),Abs(4-l1*l4-e1.mot[1])))));
                           c012=l2*l5*min(1,min(e1.mot[2]+l2*l5,min(Abs(2-l2*l5-e1.mot[2]),min(Abs(3-l2*l5-e1.mot[2]),Abs(4-l2*l5-e1.mot[2])))));
                           n12=c121+c212;
                           n01=c012+c011;
                           f=nf-n12+n01;
                          Vp.push_back(f);

                       }
           	     }
           }
     }
     return Vp;
}


//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
vector<int> VariationNbreFeuille31(etat e1, etat e2){
	vector<int>Vp;
	int f,nf,n12,n01;
	int l1,l3,l4,l5;
	 nf=NomreDefeuilleEtatInter(e1,e2);
     l1=BoolToInt(e2.bin[0]);
     l3=BoolToInt(e1.bin[0]);
     l4=BoolToInt(e1.bin[1]);
     l5=BoolToInt(e1.bin[2]);
     if (e2.mot[0]==BoolToInt(l1*l3) && Extreme01(e1)==1)
     {
     	n12=l1*l3*min(1,min(e1.mot[0]+l1*l3,min(Abs(1-l1*l3-e1.mot[0]),min(Abs(3-l1*l3-e1.mot[0]),Abs(4-l1*l3-e1.mot[0])))));
     	n01=l1*l3*min(1,min(e1.mot[0]+l1*l3,min(Abs(2-l1*l3-e1.mot[0]),min(Abs(3-l1*l3-e1.mot[0]),Abs(4-l1*l3-e1.mot[0])))));
     	f=nf - n12 + n01;
     	Vp.push_back(f);
     }
     else{
     	  if (e2.mot[0]==BoolToInt(l1*l5) && Extreme10(e1)==1)
           {
            n12=l1*l5*min(1,min(e1.mot[2]+l1*l5,min(Abs(1-l1*l5-e1.mot[2]),min(Abs(3-l1*l5-e1.mot[2]),Abs(4-l1*l5-e1.mot[2])))));
            n01=l1*l5*min(1,min(e1.mot[2]+l1*l5,min(Abs(2-l1*l5-e1.mot[2]),min(Abs(3-l1*l5-e1.mot[2]),Abs(4-l1*l5-e1.mot[2])))));
            f=nf - n12 + n01;
            Vp.push_back(f);
           }
            else{
            	   if (Extreme11(e1)==1)
            	   {
            	   	      if (e2.mot[0]==BoolToInt(l1*l3))


                           {
                               n12=l1*l3*min(1,min(e1.mot[0]+l1*l3,min(Abs(1-l1*l3-e1.mot[0]),min(Abs(3-l1*l3-e1.mot[0]),Abs(4-l1*l3-e1.mot[0])))));
                               n01=l1*l3*min(1,min(e1.mot[0]+l1*l3,min(Abs(2-l1*l3-e1.mot[0]),min(Abs(3-l1*l3-e1.mot[0]),Abs(4-l1*l3-e1.mot[0])))));
                               f=nf - n12 + n01;
                               Vp.push_back(f);
                            }
                           if (e2.mot[0]==BoolToInt(l1*l4))
                            {
                                n12=l1*l4*min(1,min(e1.mot[1]+l1*l4,min(Abs(1-l1*l4-e1.mot[1]),min(Abs(3-l1*l4-e1.mot[1]),Abs(4-l1*l4-e1.mot[1])))));
                                n01=l1*l4*min(1,min(e1.mot[1]+l1*l4,min(Abs(2-l1*l4-e1.mot[1]),min(Abs(3-l1*l4-e1.mot[1]),Abs(4-l1*l4-e1.mot[1])))));
                                f=nf - n12 + n01;
                                Vp.push_back(f);
                            }
                         if (e2.mot[0]==BoolToInt(l1*l5))
                            {
                               n12=l1*l5*min(1,min(e1.mot[2]+l1*l5,min(Abs(1-l1*l5-e1.mot[2]),min(Abs(3-l1*l5-e1.mot[2]),Abs(4-l1*l5-e1.mot[2])))));
                               n01=l1*l5*min(1,min(e1.mot[2]+l1*l5,min(Abs(2-l1*l5-e1.mot[2]),min(Abs(3-l1*l5-e1.mot[2]),Abs(4-l1*l5-e1.mot[2])))));
                               f=nf - n12 + n01;
                               Vp.push_back(f);
                            }



            	   }
            }
     }
     
     return Vp;
}
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

vector<int> VariationNbreFeuille21(etat e1, etat e2){
	vector<int>Vp;
	int f,nf,n12,n01;
	int l1,l3,l4;
	 nf=NomreDefeuilleEtatInter(e1,e2);
     l1=BoolToInt(e2.bin[0]);
     l3=BoolToInt(e1.bin[0]);
     l4=BoolToInt(e1.bin[1]);
     if (e2.mot[0]==BoolToInt(l1*l3) && Extreme01(e1)==1){
        n12=l1*l3*min(1,min(e1.mot[0]+l1*l3,min(Abs(1-l1*l3-e1.mot[0]),min(Abs(3-l1*l3-e1.mot[0]),Abs(4-l1*l3-e1.mot[0])))));
     	n01=l1*l3*min(1,min(e1.mot[0]+l1*l3,min(Abs(2-l1*l3-e1.mot[0]),min(Abs(3-l1*l3-e1.mot[0]),Abs(4-l1*l3-e1.mot[0])))));
     	f=nf - n12 + n01;
     	Vp.push_back(f);
     }
     else{
     	    if (e2.mot[0]==BoolToInt(l1*l4) && Extreme10(e1)==1)
             {
                 n12=l1*l4*min(1,min(e1.mot[1]+l1*l4,min(Abs(1-l1*l4-e1.mot[1]),min(Abs(3-l1*l4-e1.mot[1]),Abs(4-l1*l4-e1.mot[1])))));
                 n01=l1*l4*min(1,min(e1.mot[1]+l1*l4,min(Abs(2-l1*l4-e1.mot[1]),min(Abs(3-l1*l4-e1.mot[1]),Abs(4-l1*l4-e1.mot[1])))));
                 f=nf - n12 + n01;
                 Vp.push_back(f);
             }
             else{

                   if (Extreme11(e1)==1)
                   {
                   	

                            if (e2.mot[0]==BoolToInt(l1*l3)){
                                n12=l1*l3*min(1,min(e1.mot[0]+l1*l3,min(Abs(1-l1*l3-e1.mot[0]),min(Abs(3-l1*l3-e1.mot[0]),Abs(4-l1*l3-e1.mot[0])))));
                                n01=l1*l3*min(1,min(e1.mot[0]+l1*l3,min(Abs(2-l1*l3-e1.mot[0]),min(Abs(3-l1*l3-e1.mot[0]),Abs(4-l1*l3-e1.mot[0])))));
                                f=nf - n12 + n01;
                                Vp.push_back(f);
                            }
                            if (e2.mot[0]==BoolToInt(l1*l4))
                             {
                                n12=l1*l4*min(1,min(e1.mot[1]+l1*l4,min(Abs(1-l1*l4-e1.mot[1]),min(Abs(3-l1*l4-e1.mot[1]),Abs(4-l1*l4-e1.mot[1])))));
                                n01=l1*l4*min(1,min(e1.mot[1]+l1*l4,min(Abs(2-l1*l4-e1.mot[1]),min(Abs(3-l1*l4-e1.mot[1]),Abs(4-l1*l4-e1.mot[1])))));
                                f=nf - n12 + n01;
                                Vp.push_back(f);
                             }

                   }

             }
     }
     
     return Vp;

 }
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
vector<int>VariationNbreFeuille(etat e1, etat e2){

	vector<int>Vp;
	if (e1.longueur==e2.longueur)
	{
		Vp.push_back(VariationNbreFeuilleML(e1,e2));
	}
	if (e1.longueur==3 && e2.longueur==2)
	{
		Vp=VariationNbreFeuille32(e1,e2);
	}
	if (e1.longueur==3 && e2.longueur==1)
	{
		Vp= VariationNbreFeuille31(e1,e2);
	}
	if (e1.longueur==2 && e2.longueur==1)
	{
		Vp=VariationNbreFeuille21(e1,e2);
	}
	return Vp;
}


//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
vector<int> PeriTransit32(etat e1, etat e2){
	vector<int>Vp;
	int P, P1,P2;
	int l1,l2,l3,l4,l5;
    P=PerimetreEtat(e2.bin);
    l1=BoolToInt(e2.bin[0]);
    l2=BoolToInt(e2.bin[1]);
    l3=BoolToInt(e1.bin[0]);
    l4=BoolToInt(e1.bin[1]);
    l5=BoolToInt(e1.bin[2]);  	
    if (l1*(l3+l2)==e2.mot[0] && l2*(l1+l4)==e2.mot[1] && Extreme01(e1)==1)
    {
    	P1=P-2*(l1*l3+l2*l4);
    	Vp.push_back(P1);
    }
    else{
    	  if (l1*(l4+l2)==e2.mot[0] && l2*(l1+l5)==e2.mot[1] && Extreme10(e1)==1)
          {
              P2=P-2*(l1*l4+l2*l5);
              Vp.push_back(P2);
          }
          else{
          	   if (Extreme11(e1)==1)
          	   {
          	   	      
                     if (l1*(l3+l2)==e2.mot[0] && l2*(l1+l4)==e2.mot[1])
                      {
                          P1=P-2*(l1*l3+l2*l4);
                          Vp.push_back(P1);
                      }
                      if (l1*(l4+l2)==e2.mot[0] && l2*(l1+l5)==e2.mot[1])
                      {
                         P2=P-2*(l1*l4+l2*l5);
                         Vp.push_back(P2);
                      }

          	   }
          }
    }
    
    return Vp;

}
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
vector<int> PeriTransit31(etat e1, etat e2){
	vector<int>Vp;
	int P, P1,P2,P3;
	int l1,l3,l4,l5;
    P=PerimetreEtat(e2.bin);
    l1=BoolToInt(e2.bin[0]);
    l3=BoolToInt(e1.bin[0]);
    l4=BoolToInt(e1.bin[1]);
    l5=BoolToInt(e1.bin[2]);  	
    if (l1*l3==e2.mot[0] && Extreme01(e1)==1)
    {
    	P1=P-2*l1*l3;
    	Vp.push_back(P1);
    }
    else{
    	 if (l1*l5==e2.mot[0] && Extreme10(e1)==1)
         {
            P3=P-2*l1*l5;
            Vp.push_back(P3);
         }
          else{
          	   if (Extreme11(e1)==1)
          	   {
          	   	    
                       if (l1*l3==e2.mot[0])
                       {
                          P1=P-2*l1*l3;
                          Vp.push_back(P1);
                       }
                          if (l1*l4==e2.mot[0])
                       {
                          P2=P-2*l1*l4;
                          Vp.push_back(P2);
                        }
                       if (l1*l5==e2.mot[0])
                       {
                          P3=P-2*l1*l5;
                          Vp.push_back(P3);
                       }

          	   }
          }
    }
    
    return Vp;

}
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
int NombreDeComposantesConnectHautF3(etat e){
	int nch;
	if (NombreDeComposantes(e)==2 &&  e.comppar=="{{0},{1}}")
	{ 
		nch=2;
	}
	if ((NombreDeComposantes(e)==2 &&  e.comppar=="{{0,1}}") ||  NombreDeComposantes(e)==1)
	{ 
		nch=1;
	}
	if (NombreDeComposantes(e)==0)
	{ 
		nch=0;
	}
	return nch;
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
 int NombredeComposanteConnTransML(etat e1, etat e2){
 
   int nch1,nch2,ncc;
   nch1=NombreDeComposantesConnectHautF3(e1);
   nch2=NombreDeComposantesConnectHautF3(e2);
   if (nch2==0)
   {
   	 ncc=0;
   
   }

   	
   
            
    	            int cpt=0;
                     for (int i = 0; i < e2.longueur; ++i)
                    {
       	                 cpt= cpt +BoolToInt(e1.bin[i])*BoolToInt(e2.bin[i]);
                    }
                    if (nch1==0)
                    {
                    	ncc=nch2;
                    }
                    if (nch1==1 && nch2==1 && cpt>0)
                    {
       	                ncc=0;
                    }
                    if (nch1==1 && nch2==2 && cpt>0)
                    {
       	                ncc=1;
                    }
                    if (nch1==1 && cpt==0)
                    {
       	                ncc=nch2;
                    }
                    if (nch1==2 && cpt==0)
                    {
                    	ncc=nch2;
                    }
                    if (nch1==2 && cpt==1)
                    {
                    	ncc=0;
                    }
                    if (nch1==2 && cpt==2 && BoolToInt(e2.bin[1])==1)
                    {
                    	ncc=-1;
                    }

                    if (nch1==2 && nch1==2)
                    {
                    	ncc=0;
                    }


               
    
               
    return ncc;
 }


//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

int  NombredeComposanteConnTrans32(etat e1, etat e2){

	int nch1,nch2,ncc;
	int l1,l2,l3,l4,l5;
    l1=BoolToInt(e2.bin[0]);
    l2=BoolToInt(e2.bin[1]);
    l3=BoolToInt(e1.bin[0]);
    l4=BoolToInt(e1.bin[1]);
    l5=BoolToInt(e1.bin[2]); 
   nch1=NombreDeComposantesConnectHautF3(e1);
   nch2=NombreDeComposantesConnectHautF3(e2);
   if (nch2==0)
   {
   	 ncc=0;
   }
   if (nch1==0)
   {
   	ncc=nch2;
   }
   if (nch1==2  && (l1*l3+l2*l4==1 || l1*l4+l2*l5==1))
   {
   	 ncc=0;
   }
   if (nch1==2 && ((l1*l3==0 && l2*l4==0)|| (l1*l4==0 && l2*l5==0)))
   {
   	 ncc=nch2;
   }
   if (nch1==1 &&  ((l1*l3==0 && l2*l4==0)|| (l1*l4==0 && l2*l5==0)))
   {
   	 ncc=nch2;
   }
   if (nch1==1 &&(l1*l3==1 || l1*l4==1 || l1*l4==1 || l2*l5==1))
   {
   	 ncc=0;
   }
    return ncc;
}


 //-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
int  NombredeComposanteConnTrans31(etat e1, etat e2){

	int nch1,nch2,ncc;
	int l1,l3,l4,l5;
    l1=BoolToInt(e2.bin[0]);
    l3=BoolToInt(e1.bin[0]);
    l4=BoolToInt(e1.bin[1]);
    l5=BoolToInt(e1.bin[2]); 
   nch1=NombreDeComposantesConnectHautF3(e1);
   nch2=NombreDeComposantesConnectHautF3(e2);
   if (nch2==0)
   {
   	 ncc=0;
   }
   if (nch1==0)
   {
   	 ncc= nch2;
   }
   if (nch1==2 &&  l1*l3==1 && e2.mot[0]==1)
   {
   	 ncc=0;
   }
   if (nch1==2 && l1*l3==1 && e2.mot[0]==0)
   {
   	 ncc=1;
   }
   if (nch1==1 &&  nch2==1 && e2.mot[0]==0)
   {
   	 ncc=1;
   }
   if (nch1==1 && nch2==1 && e2.mot[0]==1)
   {
   	 ncc=0;
   }
    return ncc;
}
 //-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------


int  NombredeComposanteConnTrans21(etat e1, etat e2){

	int nch1,nch2,ncc;
	int l1,l3,l4;
    l1=BoolToInt(e2.bin[0]);
    l3=BoolToInt(e1.bin[0]);
    l4=BoolToInt(e1.bin[1]);
   nch1=NombreDeComposantesConnectHautF3(e1);
   nch2=NombreDeComposantesConnectHautF3(e2);
   if (nch2==0)
   {
   	 ncc=0;
   }
   if (nch1==0)
   {
   	 ncc= nch2;
   }
   if (nch1==1 &&  nch2==1 && e2.mot[0]==0)
   {
   	 ncc=1;
   }
   if (nch1==1 && nch2==1 && e2.mot[0]==1)
   {
   	 ncc=0;
   }
    return ncc;
}


 //-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
int NombredeComposanteConnTransF3(etat e1, etat e2){
	int ncc;
	if (e1.longueur==e2.longueur)
	{
		ncc=NombredeComposanteConnTransML(e1,e2);
	}
	if (e1.longueur==3 && e2.longueur==2)
	{
		ncc=NombredeComposanteConnTrans32(e1,e2);
	}
    if (e1.longueur==3 && e2.longueur==1)
	{
		ncc=NombredeComposanteConnTrans31(e1,e2);
	}
	if (e1.longueur==2 && e2.longueur==1)
	{
		ncc=NombredeComposanteConnTrans21(e1,e2);
	}
	return ncc;
}
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
etat Creation(string str){
	etat e;
	vector<bool>binaire;
	vector<int>mot3;
	string compcomp;
	int l;
	string str1,str2,str3,str4;
	int nv1,npar,nacc1,nv2,nacc2,nacc3,nacc4,lg;
	str1=EspSpp(str);
	lg=str1.length()-1;
	str2=str1.substr(1,lg);
	nv1=str2.find(",");
	str3=str2.substr(0,nv1);
	e.longueur=str3.length();
	npar= str2.find(")");
	str4=str2.substr(nv1+1,npar-nv1-1);
    for (int i = 0; i < e.longueur; ++i)
    {
    	binaire.push_back(StringTobool(str3.substr(i,1)));
    }
    for (int i = 0; i < e.longueur; ++i)
    {
    	mot3.push_back(stringToMot(str4.substr(i,1)));
    }
    e.bin=binaire;
    e.mot=mot3;
    e.comppar=str2.substr(npar+1, str2.length()-npar-1);
	return e;

}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
vector<int> PeriTransit21(etat e1, etat e2){
	vector<int>Vp;
	int P, P1,P2;
	int l1,l3,l4;
    P=PerimetreEtat(e2.bin);
    l1=BoolToInt(e2.bin[0]);
    l3=BoolToInt(e1.bin[0]);
    l4=BoolToInt(e1.bin[1]);	
    if (l1*l3==e2.mot[0] && Extreme01(e1)==1)
    {
    	P1=P-2*l1*l3;
    	Vp.push_back(P1);
    }
    else{
    	 if (l1*l4==e2.mot[0] && Extreme10(e1)==1) {
             P2=P-2*l1*l4;
              Vp.push_back(P2);
         }
         else{

              if (Extreme11(e1)==1)
              {
              	   
                    if (l1*l3==e2.mot[0])
                    {
                       P1=P-2*l1*l3;
                       Vp.push_back(P1);
                    }
                    if (l1*l4==e2.mot[0])
                    {
                       P2=P-2*l1*l4;
                       Vp.push_back(P2);
                    }

              }

         }
    }
    return Vp;

}
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
vector<int> PeriTransit(etat e1, etat e2){
	vector<int>Vp;
	int P;
     if (e1.longueur==e2.longueur)
     {
     	P = PeriTransitMemeLongueur(e1,e2);
     	Vp.push_back(P);
     }
      if (e1.longueur==3 && e2.longueur==2)
     {
     	Vp = PeriTransit32(e1,e2);
     	
     }
      if (e1.longueur==3 && e2.longueur==1)
     {
     	Vp = PeriTransit31(e1,e2);
     	
     }
      if (e1.longueur==2 && e2.longueur==1)
     {
     	Vp = PeriTransit21(e1,e2);
     	
     }

     return Vp;

}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
int AireTransition(etat e1, etat e2){

	int aire=0;
	if (TransPossFP3(e1,e2)==1)
	{
		aire = aire + AireEtat(e2.bin);
	}
	//cout<<"*#"<<TransPossFP3(e1,e2)<<endl;
	return aire;
}
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
polytransit ComposanteMatriceF3(etat e1, etat e2){
	vector<int>Vp;
	vector<int>Vf;
	transit t;
	polytransit Pt;
	if (TransPossFP3(e1,e2)==0)
	{
		t.airx=0;
		t.periy=0;
		t.feuillez=0;
		t.compconn=0;
		t.coef=0;
        Pt.poly.push_back(t);
	}
	else{
		Vp=PeriTransit(e1,e2);
		Vf=VariationNbreFeuille(e1,e2);
		for (int i = 0; i < Vp.size(); ++i)
		{
			t.airx=AireTransition(e1,e2);
		t.periy=Vp[i];
		t.feuillez=Vf[i];
		t.compconn=NombredeComposanteConnTransF3(e1,e2);
		t.coef=1;
        Pt.poly.push_back(t);
		}
	}
	return Pt;
}
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
//--------------------facteur coefficient---------------------------------------------------------
string CoefFact(int av){

	string str;
	if (av==0)
	{
		str="0";
	}
	else{
			if (av==1)
			{
				str=" ";
			}
			else{
				str=to_string(av);
			}
		
	}
	return str;
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
string expow(int av){
	string str;
	if (av==0)
	{
		str=" ";
	}
	else{
		if (av==1)
		{
			str= "w";
		}
		else{
			str="w^"+to_string(av);
		}
	}
	return str;
}
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
string expox(int av){
	string str;
	if (av==0)
	{
		str=" ";
	}
	else{
		if (av==1)
		{
			str= "x";
		}
		else{
			str="x^"+to_string(av);
		}
	}
	return str;
}
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
string expoz(int av){
	string str;
	if (av==0)
	{
		str=" ";
	}
	else{
		if (av==1)
		{
			str= "z";
		}
		else{
			str="z^"+to_string(av);
		}
	}
	return str;
}
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
string expot(int av){
	string str;
	if (av==0)
	{
		str=" ";
	}
	else{
		if (av==1)
		{
			str= "t";
		}
		else{
			str="t^"+to_string(av);
		}
	}
	return str;
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
string Polyn(etat e1, etat e2){

	string str,str1;
	polytransit Pt, Pt1;
	Pt1=ComposanteMatriceF3(e1,e2);
	if (Pt1.poly.size()==1)
		{
			Pt=Pt1;
		}
		if (Pt1.poly.size()==2)
		{
			Pt=SommeBinaire(Pt1.poly[0],Pt1.poly[1]);
		}
		if (Pt1.poly.size()==3)
		{
			Pt=Sommetri(Pt1.poly[0],Pt1.poly[1],Pt1.poly[2]);
		}
		
		 if (Pt.poly.size()==1 && Pt.poly[0].coef!=0)
				    {

				    	str =CoefFact(Pt.poly[0].coef)+expow(Pt.poly[0].airx)+expox(Pt.poly[0].periy)+"y"+expoz(Pt.poly[0].feuillez)+expot(Pt.poly[0].compconn);
		}
		else{
			if (Pt.poly.size()==1 && Pt.poly[0].coef==0)
			{
				str="0";
			}
		}
		  if (Pt.poly.size()==2  && Pt.poly[0].coef!=0 && Pt.poly[1].coef!=0)
				    {
				    	str =CoefFact(Pt.poly[0].coef)+expow(Pt.poly[0].airx)+expox(Pt.poly[0].periy)+"y"+expoz(Pt.poly[0].feuillez)+expot(Pt.poly[0].compconn)+"+"+CoefFact(Pt.poly[1].coef)+expow(Pt.poly[1].airx)+expox(Pt.poly[1].periy)+"y"+expoz(Pt.poly[1].feuillez)+expot(Pt.poly[1].compconn);
		}
		else{
			if (Pt.poly.size()==2 && (Pt.poly[0].coef==0 || Pt.poly[1].coef==0))
			{
				str="0";
			}
		}
				    	
		
		 if (Pt.poly.size()==3  && Pt.poly[0].coef!=0 && Pt.poly[1].coef!=0 && Pt.poly[2].coef!=0)
				 {
				    	str =CoefFact(Pt.poly[0].coef)+expow(Pt.poly[0].airx)+expox(Pt.poly[0].periy)+"y"+expoz(Pt.poly[0].feuillez)+expot(Pt.poly[0].compconn)+"+"+CoefFact(Pt.poly[1].coef)+expow(Pt.poly[1].airx)+expox(Pt.poly[1].periy)+"y"+expoz(Pt.poly[1].feuillez)+expot(Pt.poly[1].compconn)+"+"+CoefFact(Pt.poly[2].coef)+expow(Pt.poly[2].airx)+expox(Pt.poly[2].periy)+"y"+expoz(Pt.poly[2].feuillez)+expot(Pt.poly[2].compconn);
				    	
				
	     }
	     else{
			if (Pt.poly.size()==3 && (Pt.poly[0].coef==0 || Pt.poly[1].coef==0 || Pt.poly[2].coef==0))
			{
				str="0";
			}
		}

	     str1=EspSpp(str);
	     return str1;

}
			
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
int main(int argc, char const *argv[])
{   

	polytransit Pt, Pt1;
	vector<etat>EtatF3;
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin>>str;
		EtatF3.push_back(Creation(str));
	}
	for (int i = 0; i < n; ++i)
	{
		int i1=i+1;
		for (int k = 0; k<n; ++k)
		{
			int k1=k+1;
		    cout<<"T_{"<<i1<<","<<k1<<"}= "<<Polyn(EtatF3[i],EtatF3[k])<<endl;
		
		}
	} 

	return 0;
}