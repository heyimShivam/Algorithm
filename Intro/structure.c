#include <stdio.h>

struct cube
{
    int lenght;
    int breadth;
    int height;
};

void main(){

    struct cube cubes[10] = {{10,5,90},{20,50,10}};
    int i;
    scanf("Enter the cube you wanna know volume of 0-10 : %d", &i);
    printf("The volume of %d cube is %d",i,cubes[i].lenght*cubes[i].breadth*cubes[i].height);

}