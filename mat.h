#ifndef mat_H
#define mat_H
#include<iostream>
//#include"Neural_network.h"
 using namespace std;
   
   
   double** Matrix_multiply(double M2[2][2],double M3[2][2],int row1,int col1,int row2,int col2)
   {
       //int M1[2][2],M2[2][2];
       /*cout<<"Enter elements of the first matrix\n";
       for(i=0;i<M;i++){
         for(j=0;j<N;j++){
              cin>>M1[i][j];}}
       cout<<"Enter elements of the second matrix\n";
       for(i=0;i<M;i++){
         for(j=0;j<N;j++){
              cin>>M2[i][j];}}*/
////////////////////////////////////////////     
    int i,j,k;
    double Result[row1][col2],sum=0;
           


       for(i=0;i<row1;i++){
         for(j=0;j<col2;j++){
           for(k=0;k<row2;k++){
            sum=sum+(M2[i][k]*M3[k][j]);
         }
            Result[i][j]=sum;
            sum=0;  
            }}
            
        double **R= new double*[col2];
		 for(i=0;i<col2;i++){
		 	R[i]= new double[row1];
		 	 for(j=0;j<row1;j++){
		 	 	R[i][j]=Result[j][i];
			  }
		 }
		      
            
/*        cout<<"The result Matrix is \n";
        for(i=0;i<row1;i++){
         for(j=0;j<col2;j++){
              cout<<Result[i][j]<<" ";}cout<<endl;}*/
           return R;
          } 
          
          
          
          
          
          
          
////////////////////////////////////////////////////////          
          
		  
 //Defination of sigmoid fn
double sigmoid(double x){
	
	 int acc=30;
	 double ans=1;
	 double temp=1;
	 int i;
	 for(i=1;i<=acc;i++){
	 	temp=(temp*(-x))/i;
	 	ans=ans+temp;
	 }
	      ans=ans+1;
		ans=1/ans;
	//	cout<<ans<<endl;
		return ans;
}
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
////////////////////////////////////////        
           
 // Matrix subtraction Result=Output-Guess
 
double** Matrix_subtraction(double M1[20][20],double M2[20][20],int row1,int col1,int row2,int col2)
   {
   	  int i,j;
   	  double Result[row1][col1];
   	  
   	     for(i=0;i<row1;i++){
   	     	for(j=0;j<col1;j++){
   	     		Result[i][j]=M1[i][j]-M2[i][j];
				}
			}
			
			double** R= new double*[col1];
			for(i=0;i<col1;i++){
			  R[i]= new double[row1];
				for(j=0;j<row1;j++){
				     R[i][j]=Result[i][j];	
				}
			} 
        return R;
    }
    #endif
