/*
 * Gabriel NP
 * 2017
 * Convert image values from RGB system to XYZ system
  *C Language
 */ 

#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int main (void)
{
	float R,G,B,X,Y,Z;
	float var_R,var_G,var_B;
	

	X=0.0;
	Y=0.0;
	Z=0.0;
	var_R = 0;
    var_G = 0;
    var_B = 0;
    R=0;
    G=0;
    B=0;

	printf("Insert Red component value: ");
	scanf("%f", &R);
	printf("\nInsira Green component value: ");
	scanf("%f", &G);
	printf("\nInsert Blue component value: ");
	scanf("%f", &B);

	
   	var_R = (R / 255.0); //R from 0 to 255
    var_G = (G / 255.0); //G from 0 to 255
    var_B = (B / 255.0); //B from 0 to 255


    if (var_R > 0.04045) {
        var_R = powf(( (var_R + 0.055) / 1.055), 2.4);
    } else {
        var_R = var_R / 12.92;
    }

    if (var_G > 0.04045) {
        var_G = powf(( (var_G + 0.055) / 1.055), 2.4);
    } else {
        var_G = var_G / 12.92;
    }

    if (var_B > 0.04045) {
        var_B = powf(( (var_B + 0.055) / 1.055), 2.4);
    } else {
        var_B = var_B / 12.92;
    }

    var_R = var_R * 100;
    var_G = var_G * 100;
    var_B = var_B * 100;
	
	
    //Observer. = 2°, Illuminant = D65
    X = var_R * 0.4124 + var_G * 0.3576 + var_B * 0.1805;
    Y = var_R * 0.2126 + var_G * 0.7152 + var_B * 0.0722;
    Z = var_R * 0.0193 + var_G * 0.1192 + var_B * 0.9505;
    
    printf("\n\n\n");
 	printf("X = %f \nY = %f \nZ = %f", X, Y, Z);
	
	
	return (0);
}
