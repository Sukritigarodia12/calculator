/*
Anudish Jinturkar
H-27
Subject: Network Security (Lab)
Lab10: Implementation of ECC Algorithm
*/


#include <bits/stdc++.h>
#include <cmath>
#define gc getchar_unlocked

using namespace std;

int Px,Py,Qx,Qy,Xg,Xr,Yg,Yr;
int Pa_x,Pa_y,Pb_x,Pb_y,key_a_x,key_a_y,key_b_x,key_b_y;
int P,a,b,i,j,s,t;
int Na,Nb,lmd;

int main(int argc,char **argv)
{
    cout<<"Enter prime number (p), a and b : "<<endl;
    cin>>P>>a>>b;
    cout<<"\nEp(a,b) = E"<<P<<"("<<a<<","<<b<<")"<<endl;
    cout<<"\nEnter point P (Px,Py) : "<<endl;
    cin>>Px>>Py;

    if((( Py* Py ) % P ) == (( Px * Px * Px ) + ( a * Px ) + b ) % P )
        cout<<"\nPoint lies on Elliptic Curve"<<endl;
    else
        cout<<"Point doesn't lie on Elliptic Curve"<<endl;

    cout<<"\nEnter point Q (Qx,Qy) : "<<endl;
    cin>>Qx>>Qy;

    if((( Qy*Qy) % P ) == (( Qx * Qx * Qx ) + ( a * Qx ) + b ) % P)
    {
        cout<<"\nPoint lies on the Elliptic Curve "<<endl;
    }
    else
    {
        cout<<"Point doesn't lie on the Elliptic Curve"<<endl;
    }

    if( Px == Qx && Py == Qy )
    {
        cout<<"Points are same\n"<<endl;
    }
    else
    {
        cout<<"Points are not same\n"<<endl;
    }

    cout<<"Diffie Hellman application on ECC : "<<endl;
    cout<<"Enter Xg,Yg : "<<endl;
    cin>>Xg>>Yg;

    cout<<"G = ("<<Xg<<","<<Yg<<")"<<endl;
    cout<<"Enter Na and Nb : "<<endl;
    cin>>Na>>Nb;
    cout<<"\n Na and Nb are :\n"<<Na<<"\n"<<Nb<<endl;

    //public key generation Pa

    Xr=Xg;
    Yr=Yg;

    for(i=0;i<Na-1;i++)
    {
        if(Xg==Xr&&Yg==Yr)
        {
            lmd=(((3*(Xg*Xg))+a))/(2*Yg);
        }

        else
        {
            lmd=((Yr-Yg))/(Xr-Xg);
        }

        Xr=((lmd*lmd)-Xg-Xr) % P;
        Yr=(lmd*(Xg-Xr)-Yg) % P;

    }

    Pa_x=Xr;
    Pa_y=Yr;

    cout<<"\nPublic Key for User A : Pa ("<<Pa_x<<","<<Pa_y<<")"<<endl;


    //public generation Pb

    Xr=Xg;
    Yr=Yg;

    for(j=0;j<Nb-1;j++)
    {
        if(Xg==Xr&&Yg==Yr)
        {
            lmd=(((3*(Xg*Xg))+a))/(2*Yg);
        }

        else
        {
            lmd=((Yr-Yg))/(Xr-Xg);
        }

        Xr=((lmd*lmd)-Xg-Xr) % P;
        Yr=(lmd*(Xg-Xr)-Yg) % P;
    }

    Pb_x=Xr;
    Pb_y=Yr;

    cout<<"\nPublic Key for User B : Pb ("<<Pb_x<<","<<Pb_y<<")\n";

    //Secret Key Generation Ka

    Xr=Pb_x;
    Yr=Pb_y;

    for(s=1;s<Na;s++)
    {
        if(Xg==Xr&&Yg==Yr)
        {
            lmd=(((3*(Xg*Xg))+a))/(2*Yg);
        }

        else
        {
            lmd=((Yr-Yg))/(Xr-Xg);
        }

        Xr = ((lmd*lmd)-Xg-Xr) % P;
        Yr = (lmd*(Xg-Xr)-Yg) % P;

    }

    key_a_x=Xr;
    key_a_y=Yr;

    cout<<"\nSecret Key for User A : Ka ("<<key_a_x<<","<<key_a_y<<")\n";

    //Secret key Generation for Kb

    Xr=Pa_x;
    Yr=Pa_y;

    for(t=1;t<Nb;t++)
    {
        if(Xg==Xr&&Yg==Yr)
        {
            lmd=(((3*(Xg*Xg))+a))/(2*Yg);
        }

        else
        {
            lmd=((Yr-Yg))/(Xr-Xg);
        }

        Xr = ((lmd*lmd)-Xg-Xr) % P;
        Yr = (lmd*(Xg-Xr)-Yg) % P;

    }

    key_b_x=Xr;
    key_b_y=Yr;

    cout<<"\nSecret Key for User B : Kb ("<<key_b_x<<","<<key_b_y<<")\n";

    if(key_a_x == key_b_x && key_a_y == key_b_y)
    {
        cout<<"\n"<<"Secret Keys of User A and User B are same "<<endl;
    }

    else
    {
        cout<<"\n"<<"Secret Keys of User A and User B are different "<<endl;
    }

    return 0;

}




/*

Output:

Enter prime number (p), a and b :
13
2
4

Ep(a,b) = E13(2,4)

Enter point P (Px,Py) :
2
4

Point lies on Elliptic Curve

Enter point Q (Qx,Qy) :
18
37
Point doesn't lie on the Elliptic Curve
Points are not same

Diffie Hellman application on ECC :
Enter Xg,Yg :
3
6
G = (3,6)
Enter Na and Nb :
13
18

 Na and Nb are :
13
18

Public Key for User A : Pa (6,6)

Public Key for User B : Pb (7,-10)

Secret Key for User A : Ka (7,-10)

Secret Key for User B : Kb (7,-10)

Secret Keys of User A and User B are same

*/
