#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<math.h>

/*
Homework 3
Myles Page
Sebastian Vilanova
Computation 
Due 11/08/19
*/  

int main(int argc, char *argv[]) {
	
	int x;
	int row = 0;
	int column = 0;
	double biggest = 0;
	//Adds the sysmat1 and prodvec1
	double sysmat1[3][3] = {{6.3000, 8.2000, -7.5000},
						 {8.3000, 2.7000, -8.1000},
						 {-4.5000, 0.9000, 9.2000}
					    }; 				    
	double prodvec1[3][1] ={{-3.7},
						 {12.75},
						 {11.2}
					    };
	double matrix1[3][4];
	
	
	//Makes one big matrix by combining both sysmat1 and prodvec1
	for (column=0; column<3; column++){
        for(row=0; row<3; row++){
			matrix1[column][row] = sysmat1[row][column];	
		}
		for(row=2; row<2; row++){
			matrix1[column][row] = prodvec1[column][1];	
		}
    }
    printf("The System Matrix:\n");
    for (column=0; column<3; column++){
        	for(row=0; row<4; row++){
				printf("%.4f\t", matrix1[row][column]);
				}
            	printf("\n");
     	}
     	
    
	//Finds biggest number in column 1 to achieve pivot
	for (column=0; column < 2; column++){
		double placeholder;
		placeholder = matrix1[column][1];
        if(biggest < abs(placeholder)){
        	x++;
        	biggest = placeholder;
		} 
    }				       
	row = 0;			       
	while(row < 4){
		double placeholder;
		double placeholder1;
		placeholder = matrix1[row][0];
		placeholder1 = matrix1[row][1];
		matrix1[row][1] = placeholder;
		matrix1[row][0] = placeholder1;
		row++; 
	}
	
	//Starts the Gaussian Elimination by multiplying the correct numbers
	double a = -matrix1[0][0];
	double b = matrix1[1][1];
	double c = matrix1[0][1];
	double d = matrix1[1][0];
	matrix1[1][1] = (a*b+c*d);
	d = matrix1[2][0];
	b = matrix1[2][1];
	matrix1[2][1] = (a*b+c*d);
	d = matrix1[3][0];
	b = matrix1[3][1];
	matrix1[3][1] = (a*b+c*d);
	b = matrix1[1][2];
	c = matrix1[0][2];
	d = matrix1[1][0];
	matrix1[1][2] = (a*b+c*d);
	d = matrix1[2][0];
	b = matrix1[2][2];
	matrix1[2][2] = (a*b+c*d);
	d = matrix1[3][0];
	b = matrix1[3][2];
	matrix1[3][2] = (a*b+c*d);
	matrix1[0][1] = 0;
	matrix1[0][2] = 0;
	printf("\nColumn 1:\n");
    for (column=0; column<3; column++){
        	for(row=0; row<4; row++){
				printf("%f\t", matrix1[row][column]);
				}
            	printf("\n");
     	}
	a = abs(matrix1[1][1]);
	b = matrix1[2][2];
	c = abs(matrix1[1][2]);
	d = matrix1[2][1];
	matrix1[2][2] = (a*b+c*d);
	b = matrix1[3][2];
	d = matrix1[3][1];	
	matrix1[3][2] = (a*b+c*d);
	matrix1[1][2] = 0;
	
     	
     	
    /*for (column=0; column<4; column++){
        for(row=0; row<3; row++){
        	x = (1.0e-4)*matrix1[column][row];
			matrix1[column][row] = x;	
		}
		
    }
    */
    printf("\nColumn 2:\n");
	for (column=0; column<3; column++){
        	for(row=0; row<4; row++){
				printf("%f\t", matrix1[row][column]);
				}
            	printf("\n");
     	}	
     	
     	
    //Gets the final vectors
	double x3;
	x3 = matrix1[3][2]/matrix1[2][2];
	double x2;
	x2 = matrix1[3][1]-(matrix1[2][1]*x3); 
	x2 = x2/matrix1[1][1];
	double x1;
	x1 = matrix1[3][0]-(matrix1[2][0]*x3)-(matrix1[1][0]*x2);
	x1 = x1/matrix1[0][0];
	printf("\nSolution Vector:\n");
	printf("%.1f\n%.1f\n%.1f",x1 ,x2 ,x3);
	printf("\n__________________________________________________________________________________________________________________________________________________________________________");
	
    
    //Adds the sysmat2 and prodvec2
    double sysmat2[10][10] = {{5.00,-1.20,6.00,-7.10,-5.20,-7.80,-8.80,-1.00,-8.40,5.90},
							  {-1.00,-7.90,-1.40,7.10,-1.70,5.60,-5.30,0.90,8.60,2.90},
							  {-8.40,9.30,8.30,2.50,-9.10,-2.20,-3.00,-4.10,5.50,-2.40},
							  {-5.40,-10.00,-6.40,-3.00,8.10,-5.20,6.50,4.90,-0.30,6.30},
							  {8.30,5.50,-4.70,0.30,8.90,-1.90,-9.70,-6.30,-1.30,0.70},
							  {-7.00,6.40,-7.10,-2.00,-0.20,-8.10,-9.20,3.80,-1.10,-3.00},
							  {6.50,7.40,-7.30,-8.50,-0.20,-7.40,-6.70,-6.40,-3.90,8.80},
							  {0.80,-8.40,7.40,-5.20,-3.30,8.90,3.00,-2.60,0.20,7.60},
							  {10.00,-2.00,1.60,-7.60,8.00,9.20,4.70,2.50,0.20,1.00},
							  {10.70,-10.40,9.00,-12.80,4.70,18.10,7.70,-0.10,0.40,8.60}
							 };					 
	double prodvec2[10][1] = {{-8.33},
							  {-33.46},
							  {13.78},
							  {-36.11},
							  {-111.51},
							  {-104.61},
							  {-107.33},
							  {94.93},
							  {40.00},
							  {134.99}
							 };						 
	double matrix2[10][11];
	
	//Makes one big matrix by combining both sysmat2 and prodvec2
	for (column=0; column<10; column++){
        for(row=0; row<10; row++){
			matrix2[column][row] = sysmat2[row][column];	
		}
		for(row=2; row<2; row++){
			matrix2[column][row] = prodvec2[column][1];	
		}
    }
    printf("\n\n\nThe System Matrix:\n");
    for (column=0; column<10; column++){
        	for(row=0; row<11; row++)  {
				printf("%f\t", matrix2[row][column]);
				}
            	printf("\n");
     	}
	
	//Finds biggest number in column 1 to achieve pivot
	for (column=0; column < 10; column++){
		double placeholder;
		biggest = 0;
		placeholder = matrix2[0][column];
        if(biggest < abs(placeholder)){
        	x++;
        	biggest = placeholder;
		} 
    }
	row = 0;			       
	while(row < 11){
		double placeholder;
		double placeholder1;
		placeholder = matrix2[row][0];
		placeholder1 = matrix2[row][9];
		matrix2[row][9] = placeholder;
		matrix2[row][0] = placeholder1;
		row++; 
	}						 
    
    //Starts the Gaussian Elimination by multiplying the correct numbers
	a = -matrix2[0][0];
	b =  matrix2[1][1];
	c =  matrix2[0][1];
	d =  matrix2[1][0];
	matrix2[1][1] = a*b+c*d;
	d = matrix2[2][0];
	b = matrix2[2][1];
	matrix2[2][1] = a*b+c*d;
	d = matrix2[3][0];
	b = matrix2[3][1];
	matrix2[3][1] = a*b+c*d;
	d = matrix2[4][0];
	b = matrix2[4][1];
	matrix2[4][1] = a*b+c*d;
	d = matrix2[5][0];
	b = matrix2[5][1];
	matrix2[5][1] = a*b+c*d;
	d = matrix2[6][0];
	b = matrix2[6][1];
	matrix2[6][1] = a*b+c*d;
	d = matrix2[7][0];
	b = matrix2[7][1];
	matrix2[7][1] = a*b+c*d;
	d = matrix2[8][0];
	b = matrix2[8][1];
	matrix2[8][1] = a*b+c*d;
	d = matrix2[9][0];
	b = matrix2[9][1];
	matrix2[9][1] = a*b+c*d;
	d = matrix2[10][0];
	b = matrix2[10][1];
	matrix2[10][1] = a*b+c*d;
	c =  matrix2[0][2];
	d = matrix2[2][0];
	b = matrix2[2][2];
	matrix2[2][2] = a*b+c*d;
	d = matrix2[3][0];
	b = matrix2[3][2];
	matrix2[3][2] = a*b+c*d;
	d = matrix2[4][0];
	b = matrix2[4][2];
	matrix2[4][2] = a*b+c*d;
	d = matrix2[5][0];
	b = matrix2[5][2];
	matrix2[5][2] = a*b+c*d;
	d = matrix2[6][0];
	b = matrix2[6][2];
	matrix2[6][2] = a*b+c*d;
	d = matrix2[7][0];
	b = matrix2[7][2];
	matrix2[7][2] = a*b+c*d;
	d = matrix2[8][0];
	b = matrix2[8][2];
	matrix2[8][2] = a*b+c*d;
	d = matrix2[9][0];
	b = matrix2[9][2];
	matrix2[9][2] = a*b+c*d;
	d = matrix2[10][0];
	b = matrix2[10][2];
	matrix2[10][2] = a*b+c*d;
	c =  matrix2[0][3];
	d = matrix2[3][0];
	b = matrix2[3][3];
	matrix2[3][3] = a*b+c*d;
	d = matrix2[4][0];
	b = matrix2[4][3];
	matrix2[4][3] = a*b+c*d;
	d = matrix2[5][0];
	b = matrix2[5][3];
	matrix2[5][3] = a*b+c*d;
	d = matrix2[6][0];
	b = matrix2[6][3];
	matrix2[6][3] = a*b+c*d;
	d = matrix2[7][0];
	b = matrix2[7][3];
	matrix2[7][3] = a*b+c*d;
	d = matrix2[8][0];
	b = matrix2[8][3];
	matrix2[8][3] = a*b+c*d;
	d = matrix2[9][0];
	b = matrix2[9][3];
	matrix2[9][3] = a*b+c*d;
	d = matrix2[10][0];
	b = matrix2[10][3];
	matrix2[10][3] = a*b+c*d;
	c =  matrix2[0][4];
	d = matrix2[4][0];
	b = matrix2[4][4];
	matrix2[4][4] = a*b+c*d;
	d = matrix2[5][0];
	b = matrix2[5][4];
	matrix2[5][4] = a*b+c*d;
	d = matrix2[6][0];
	b = matrix2[6][4];
	matrix2[6][4] = a*b+c*d;
	d = matrix2[7][0];
	b = matrix2[7][4];
	matrix2[7][4] = a*b+c*d;
	d = matrix2[8][0];
	b = matrix2[8][4];
	matrix2[8][4] = a*b+c*d;
	d = matrix2[9][0];
	b = matrix2[9][4];
	matrix2[9][4] = a*b+c*d;
	d = matrix2[10][0];
	b = matrix2[10][4];
	matrix2[10][4] = a*b+c*d;
	c =  matrix2[0][5];
	d = matrix2[5][0];
	b = matrix2[5][5];
	matrix2[5][5] = a*b+c*d;
	d = matrix2[6][0];
	b = matrix2[6][5];
	matrix2[6][5] = a*b+c*d;
	d = matrix2[7][0];
	b = matrix2[7][5];
	matrix2[7][5] = a*b+c*d;
	d = matrix2[8][0];
	b = matrix2[8][5];
	matrix2[8][5] = a*b+c*d;
	d = matrix2[9][0];
	b = matrix2[9][5];
	matrix2[9][5] = a*b+c*d;
	d = matrix2[10][0];
	b = matrix2[10][5];
	matrix2[10][5] = a*b+c*d;
	c =  matrix2[0][6];
	d = matrix2[6][0];
	b = matrix2[6][6];
	matrix2[6][6] = a*b+c*d;
	d = matrix2[7][0];
	b = matrix2[7][6];
	matrix2[7][6] = a*b+c*d;
	d = matrix2[8][0];
	b = matrix2[8][6];
	matrix2[8][6] = a*b+c*d;
	d = matrix2[9][0];
	b = matrix2[9][6];
	matrix2[9][6] = a*b+c*d;
	d = matrix2[10][0];
	b = matrix2[10][6];
	matrix2[10][6] = a*b+c*d;
	c =  matrix2[0][7];
	d = matrix2[7][0];
	b = matrix2[7][7];
	matrix2[7][7] = a*b+c*d;
	d = matrix2[8][0];
	b = matrix2[8][7];
	matrix2[8][7] = a*b+c*d;
	d = matrix2[9][0];
	b = matrix2[9][7];
	matrix2[9][7] = a*b+c*d;
	d = matrix2[10][0];
	b = matrix2[10][7];
	matrix2[10][7] = a*b+c*d;
	c =  matrix2[0][8];
	d = matrix2[8][0];
	b = matrix2[8][8];
	matrix2[8][8] = a*b+c*d;
	d = matrix2[9][0];
	b = matrix2[9][8];
	matrix2[9][8] = a*b+c*d;
	d = matrix2[10][0];
	b = matrix2[10][8];
	matrix2[10][8] = a*b+c*d;
	c =  matrix2[0][9];
	d = matrix2[9][0];
	b = matrix2[9][9];
	matrix2[9][9] = a*b+c*d;
	d = matrix2[10][0];
	b = matrix2[10][9];
	matrix2[10][9] = a*b+c*d;
	c =  matrix2[0][10];
	d = matrix2[10][0];
	b = matrix2[10][10];
	matrix2[10][10] = a*b+c*d;
	
	//Zeros out the correct values in the matrix
	int y = 0;
	int times = 1;
	x = 1;
	while(y<10){
		while(x < 10){
			matrix2[y][x] = 0;
			x++;
		}
		x = 1 + times;
		times++;
		y++;
	}
	
	//Prints Column one for the 10x10 Matrix
	printf("\nColumn 1 through 10:\n");
    for (column=0; column<10; column++){
        	for(row=0; row<11; row++){
				printf("%f\t", matrix2[row][column]);
				}
            	printf("\n");
     	}
    
    //Gets final values for the 10x10 matrix
    double x10, x9, x8, x7, x6, x5, x4;				
	x10 = matrix2[10][9]/matrix2[9][9];
	x9 = matrix2[10][8]-(matrix2[9][8]*x10); 
	x9 = x9/matrix2[8][8];
	x8 = matrix2[10][7]-(matrix2[9][7]*x10)-(matrix2[8][7]*x9);
	x8 = x8/matrix2[7][7];
	x7 = matrix2[10][6]-(matrix2[9][6]*x10)-(matrix2[8][6]*x9)-(matrix2[7][6]*x8);
	x7 = x7/matrix2[6][6];
	x6 = matrix2[10][5]-(matrix2[9][5]*x10)-(matrix2[8][5]*x9)-(matrix2[7][5]*x8)-(matrix2[6][5]*x7);
	x6 = x6/matrix2[5][5];
	x5 = matrix2[10][4]-(matrix2[9][4]*x10)-(matrix2[8][4]*x9)-(matrix2[7][4]*x8)-(matrix2[6][4]*x7)-(matrix2[5][4]*x6);
	x5 = x5/matrix2[4][4];
	x4 = matrix2[10][3]-(matrix2[9][3]*x10)-(matrix2[8][3]*x9)-(matrix2[7][3]*x8)-(matrix2[6][3]*x7)-(matrix2[5][3]*x6)-(matrix2[4][3]*x5);
	x4 = x4/matrix2[3][3];
	x3 = matrix2[10][2]-(matrix2[9][2]*x10)-(matrix2[8][2]*x9)-(matrix2[7][2]*x8)-(matrix2[6][2]*x7)-(matrix2[5][2]*x6)-(matrix2[4][2]*x5)-(matrix2[3][2]*x4);
	x3 = x3/matrix2[2][2];
	x2 = matrix2[10][1]-(matrix2[9][1]*x10)-(matrix2[8][1]*x9)-(matrix2[7][1]*x8)-(matrix2[6][1]*x7)-(matrix2[5][1]*x6)-(matrix2[4][1]*x5)-(matrix2[3][1]*x4)-(matrix2[2][1]*x3);
	x2 = x2/matrix2[1][1];
	x1 = matrix2[10][0]-(matrix2[9][0]*x10)-(matrix2[8][0]*x9)-(matrix2[7][0]*x8)-(matrix2[6][0]*x7)-(matrix2[5][0]*x6)-(matrix2[4][0]*x5)-(matrix2[3][0]*x4)-(matrix2[2][0]*x3)-(matrix2[1][0]*x2);
	x1 = x1/matrix2[0][0];
	
	printf("\nSolution Vector:\n");
	printf("%.1f\n%.1f\n%.1f\n%.1f\n%.1f\n%.1f\n%.1f\n%.1f\n%.1f\n%.1f",x1 ,x2 ,x3 ,x4 ,x5 ,x6 ,x7 ,x8 ,x9 ,x10);
	
    return 0;
    
}
