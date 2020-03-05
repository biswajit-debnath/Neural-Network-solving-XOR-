#include<iostream> 
#include<time.h>
#include"mat.h"
#include<stdlib.h>
#define MAX 60000
using namespace std; 
double T_Inputs[2][2];
double Hidden[2][2];
double T_Hidden[2][2];
double T_Weight_From_Hidden[2][2];

double Weight_From_Input[2][2];
double Weight_From_Hidden[2][2];
double Hidden_Bias[2][1];
double Output_Layer_Bias[1][1];

double Prediction(double Inputs[2][2]);
void Transpose_I(double Inputs[2][2]);
void train(double Inputs[2][2],double result[1][1]);
void Transpose_H(){
	int i,j;
	for(j=0;j<2;j++){
		for(i=0;i<2;i++){
	      T_Hidden[j][i]=Hidden[i][j];		
		}
	}
}
void Transpose(){
	int i,j;
	for(j=0;j<2;j++){
		for(i=0;i<2;i++){
	      T_Weight_From_Hidden[j][i]=Weight_From_Hidden[i][j];		
		}
	}
}




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
	int i,j;
      //Create the randomize weight matrix of input-> hidden
	double x;
	  srand(time(NULL));
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			x=rand() %20 -10;
	 			x=x/10;
			Weight_From_Input[i][j]=x;
		}
	}
	//Creating hidden biases
	double z;
	for(i=0;i<2;i++){
		for(j=0;j<1;j++){
			z=rand() %20 -10;
	 			z=z/10;
			Hidden_Bias[i][j]=z;
		}
	}
	//Create the randomize weight matrix of hidden-> Output
	double y;
	for(i=0;i<1;i++){
		for(j=0;j<2;j++){
			y=rand() %20 -10;
	 			y=y/10;
			Weight_From_Hidden[i][j]=y;
		}
	}
	//bias of Output layer
   double xy;
	for(i=0;i<1;i++){
		for(j=0;j<1;j++){
			xy=rand() %20 -10;
	 			xy=xy/10;
			Output_Layer_Bias[i][j]=xy;
		}
	}
	
	double Inputs[2][2];
	struct S{
		double I[2][1];
		double Output[1][1];
	};

       struct S O[4];
	
	int k,l,m,n,r;
	
	  O[0].I[0][0]={1};
	  O[0].I[1][0]={1};
	  O[0].Output[0][0]={0};
	  
	  
	  
      O[1].I[0][0]={0};
	  O[1].I[1][0]={0};
	  O[1].Output[0][0]={0};


      O[2].I[0][0]={1};
	  O[2].I[1][0]={0};
	  O[2].Output[0][0]={1};


      O[3].I[0][0]={0};
	  O[3].I[1][0]={1};
	  O[3].Output[0][0]={1};


  		double I[2][2];
		double OT[1][1];
		
      for(i=0;i<MAX;i++){
         r=rand()%4;
        for(j=r;j==r;j++){
        	for(k=0;k<2;k++){
        		for(l=0;l<1;l++){
        			Inputs[k][l]=O[r].I[k][l];
				}
			}
			OT[0][0]=O[r].Output[0][0];
			train(Inputs,OT);
		}
}
system("CLS");
cout<<"Training is completed I'm READY \n";
double a;

	     int q;
     while(1){
     cout<<"\n            Press 1 for feeding input 1 1 \n";
     cout<<"\n            Press 2 for feeding input 0 0 \n";
     cout<<"\n            Press 3 for feeding input 1 0 \n";
     cout<<"\n            Press 4 for feeding input 0 1 \n";
     cout<<"\n            Press 5 for exit \n";
     cin>>q;
     switch(q){
     	case 1 : double I1[2][2];
     	          for(i=0;i<2;i++){
        		   for(j=0;j<1;j++) {
        		    	I1[i][j]=O[0].I[i][j];
				                    }
			                      }
						a=Prediction(I1);
     	        break;
     	        
        case 2 : double I2[2][2];
     	          for(i=0;i<2;i++){
        		   for(j=0;j<1;j++) {
        		    	I2[i][j]=O[1].I[i][j];
				                    }
			                      }
						a=Prediction(I2);
		
         	    break;
        	    
        case 3 : double I3[2][2];
     	          for(i=0;i<2;i++){
        		   for(j=0;j<1;j++) {
        		    	I3[i][j]=O[2].I[i][j];
				                    }
			                      }
						a=Prediction(I3);
        	    break;
        	    
        case 4 : double I4[2][2];
     	          for(i=0;i<2;i++){
        		   for(j=0;j<1;j++) {
        		    	I4[i][j]=O[3].I[i][j];
				                    }
			                      }
						a=Prediction(I4);
        	    break;
        	    
        case 5 : exit(0);
        	    
        	    default: cout<<"\nI didn't think you press the right choise \n";
        	    
	 }
	 if(a>90)
	 cout<<"I think the answer is 1\n";
     else
     cout<<"I think the answer is 0\n";
     char y;
     cout<<"Do you want to try again ?\n";
     cin>>y;
     if(y=='n'|y=='N')
       exit(0);
     system("CLS");
}
	    }


///////////////////////////////////////////////////////////////////////////////////////////////////////


double Prediction(double Inputs[2][2]){
	double Guess[1][1];
	
	int i,j;	
	
 //Hidden= (Weight Inputs->Hidden) * Inputs
	    double **H=Matrix_multiply(Weight_From_Input,Inputs,2,2,2,1);
       for(i=0;i<2;i++){
         for(j=0;j<1;j++){
              Hidden[i][j]=H[j][i];}}
              
              
 //Adding Bias of hidden layer with Hidden layer
	
	for(i=0;i<2;i++){
		for(j=0;j<1;j++){
	    Hidden[i][j]=Hidden[i][j]+Hidden_Bias[i][j];
	}
}
   //Passing throuh sigmoid
       for(i=0;i<2;i++){
         for(j=0;j<1;j++){
	     	 Hidden[i][j]=sigmoid(Hidden[i][j]);
					}
					}


//Creating output layer =(Weight Hidden->Output) * Hidden layer
	    double **O=Matrix_multiply(Weight_From_Hidden,Hidden,1,2,2,1);
   // cout<<"Output\n";
       for(i=0;i<1;i++){
         for(j=0;j<1;j++){
              Guess[i][j]=O[j][i];}}
//Adding Biases of output layer with output layer 	
	for(i=0;i<1;i++){
		for(j=0;j<1;j++){
	    Guess[i][j]=Guess[i][j]+Output_Layer_Bias[i][j];
	}
}

   //Passing through sigmoid
       for(i=0;i<1;i++){
         for(j=0;j<1;j++){
	     	 Guess[i][j]=sigmoid(Guess[i][j]);
					}
					}
double t,w;
t=Guess[0][0]*100;
if(t>90)
cout<<t<<"% accurate..........\n";
else{
	w=100-t;
	cout<<w<<"% accurate..........\n";
}
//Output[i][j]=Outputs[i][j];}}
return t;
	
}


/////////////////////////////////////////////////////////////////


void train(double Inputs[2][2],double result[1][1]){
	
	double Guess[1][1];
	
	int i,j;


    /////////////////////////////////////////////////////////////////////////////////
	 //Hidden= (Weight Inputs->Hidden) * Inputs
	
	    double **H=Matrix_multiply(Weight_From_Input,Inputs,2,2,2,1);
       for(i=0;i<2;i++){
         for(j=0;j<1;j++){
              Hidden[i][j]=H[j][i];}}
              
  //Adding Bias of hidden layer with Hidden layer
	
	for(i=0;i<2;i++){
		for(j=0;j<1;j++){
	    Hidden[i][j]=Hidden[i][j]+Hidden_Bias[i][j];
	}
}
   //Passing throuh sigmoid
       for(i=0;i<2;i++){
         for(j=0;j<1;j++){
	     	 Hidden[i][j]=sigmoid(Hidden[i][j]);
					}
					}

//Creating output layer =(Weight Hidden->Output) * Hidden layer
//cout<<"Creating output layer=(Weight Hidden->Output)*Hidden\n";
	    double **O=Matrix_multiply(Weight_From_Hidden,Hidden,1,2,2,1);
       for(i=0;i<1;i++){
         for(j=0;j<1;j++){
              Guess[i][j]=O[j][i];}}
              

//Adding Biases of output layer with output layer 	
	for(i=0;i<1;i++){
		for(j=0;j<1;j++){
	    Guess[i][j]=Guess[i][j]+Output_Layer_Bias[i][j];
	}
}

   //Passing through sigmoid
       for(i=0;i<1;i++){
         for(j=0;j<1;j++){
	     	 Guess[i][j]=sigmoid(Guess[i][j]);
					}
					}

///////////////////////////////////////////////////////////////////////////
//Output Error=result-prediction
 double Output_Layer_Error[2][2];
  for(i=0;i<1;i++){
  	for(j=0;j<1;j++){
  		Output_Layer_Error[i][j]=result[i][j]-Guess[i][j];
	  }
  }	

//Hidden Error=T_Weight_From_Hidden x Output_Error
   double Hidden_Error[2][2];
   Transpose();
   
   double **H_E=Matrix_multiply(T_Weight_From_Hidden,Output_Layer_Error,2,1,1,1);
       for(i=0;i<2;i++){
         for(j=0;j<1;j++){
              Hidden_Error[i][j]=H_E[j][i];}}
    
    ////////////////////Gradient Decent///////////////////////////////
    
    //From Hidden To Output
    Transpose_H();
    
	double lr=0.08;
	
	double Delta_Weight_From_Hidden[1][2],Temp[2][2];       
   	double Output_Layer_Gradient;
   	
   	Output_Layer_Gradient=Guess[0][0]*(1-Guess[0][0]);
//   	cout<<"1 Output layer gradient Guess[1][1]*(1-Guess[1][1])\n";
  // 	cout<<Output_Layer_Gradient<<endl;
   	
   	Temp[0][0]=Output_Layer_Gradient*Output_Layer_Error[0][0];
   	Temp[0][0]=Temp[0][0]*lr;
  // 	cout<<"Final output layer gradient...............";
   //	cout<<Temp[0][0]<<endl;  
	   	
   	 
   	   double **D_W_H=Matrix_multiply(Temp,T_Hidden,1,1,1,2);
   			for(i=0;i<1;i++){
         		for(j=0;j<2;j++){
              		Delta_Weight_From_Hidden[i][j]=D_W_H[j][i];}}
              		
//Creating Gradiet for Ouput layer biases
  double Delta_Output_Layer_Bias[1][1];
 	Delta_Output_Layer_Bias[0][0]=Temp[0][0];


   	//Updating Weights from hidden to output
   for(i=0;i<1;i++){
         for(j=0;j<2;j++){
         	Weight_From_Hidden[i][j]=Weight_From_Hidden[i][j]+Delta_Weight_From_Hidden[i][j];
  }}
  
  //Updating Baises for Output Layer
              	Output_Layer_Bias[0][0]=Output_Layer_Bias[0][0]+Delta_Output_Layer_Bias[0][0];
      	
   	//From Input To Hidden
   	Transpose_I(Inputs);
   	
	   double Delta_Weight_From_Input[2][2],Temp_2[2][2];       
   	double Hidden_Gradient[2][2];
   	for(i=0;i<2;i++){
   		for(j=0;j<1;j++){
   			Hidden_Gradient[i][j]=Hidden[i][j]*(1-Hidden[i][j]);
   		   }
	   }
//	cout<<"Hidden Gradient = Hidden x (1-Hidden)\n";
   	  //Elements wise multiplicaion 
   	           for(i=0;i<2;i++){
         		for(j=0;j<1;j++){
              		Temp_2[i][j]=Hidden_Gradient[i][j]*Hidden_Error[i][j];
					  Temp_2[i][j]=Temp_2[i][j]*lr;}}
 
//Creating Gradient for biases for hidden layer
 double Delta_Hidden_Bias[2][1];
  for(i=0;i<2;i++){
         for(j=0;j<1;j++){
         	Delta_Hidden_Bias[i][j]=Temp_2[i][j];}}
     
  
 //Multiplying Hidden Gradient and T_Inputs 
   	   double **D_W_I=Matrix_multiply(Temp_2,T_Inputs,2,1,1,2);
   			for(i=0;i<2;i++){
         		for(j=0;j<2;j++){
              		Delta_Weight_From_Input[i][j]=D_W_I[j][i];}}
 
   	//Updating Weights from Input to Hidden
 for(i=0;i<2;i++){
         for(j=0;j<2;j++){
         	Weight_From_Input[i][j]=Weight_From_Input[i][j]+Delta_Weight_From_Input[i][j];
     }}
   //Updating baises for hidden layer
  for(i=0;i<2;i++){
         for(j=0;j<1;j++){
         	Hidden_Bias[i][j]=Hidden_Bias[i][j]+Delta_Hidden_Bias[i][j];}}  
}

void Transpose_I(double Inputs[2][2]){
	int i,j;
	for(j=0;j<2;j++){
		for(i=0;i<2;i++){
	      T_Inputs[j][i]=Inputs[i][j];		
		}
	}
}
