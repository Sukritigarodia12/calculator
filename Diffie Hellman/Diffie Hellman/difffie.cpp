/*
Anudish Jinturkar
H-27
Subject: Network Security (Lab)
Lab9: Implementation of Diffie Hellman Key Exchange Algorithm
*/


#include <bits/stdc++.h>
#include <cmath>
#define gc getchar_unlocked

using namespace std;

int q,xA,xB,alpha,k1,k2,yA,yB,rslt,rslt_1,rslt_2,rslt_3;

int userA(int,int);
int userB(int,int);

int userA(int alpha,int q)
{

	rslt = alpha % q;
	rslt_1 =1;
	for(int i=0;i<xA;i++){

			rslt_1 *= rslt;
			rslt_1 = rslt_1 % q;
	}

	 return rslt_1;


}

int userB(int alpha,int q)
{
    rslt_2 = alpha % q;
	rslt_3 =1;
	for(int i=0;i<xB;i++){

			rslt_3 *= rslt_2;
			rslt_3 = rslt_3 % q;
	}

	return rslt_3;
}

int main(int argc,char **argv)
{

    cout<<"Enter the values of alpha and prime number Q : "<<endl;
    cin>>alpha>>q;
    cout<<"Enter xA and xB :"<<endl;
    cin>>xA>>xB;

	yA=userA(alpha,q);
	cout<<endl<<"Ya is: "<<yA;

    yB = userB(alpha,q);
    cout<<endl<<"Yb is: "<<yB;

	 k1 = userA(yB,q);
     cout<<endl<<"k1 is: "<<k1;

	 k2 = userB(yA,q);
	cout<<endl<<"k2 is: "<<k2;
    return 0;
}



/*

Output:

Enter the values of alpha and prime number Q :
3
353
Enter xA and xB :
97
233

Ya is: 40
Yb is: 248
k1 is: 160
k2 is: 160

*/
