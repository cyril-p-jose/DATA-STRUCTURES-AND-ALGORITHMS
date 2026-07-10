
#include<stdio.h>
struct polynomial{
int coeff;
int expo;
};


int main(){
struct polynomial x1[50],x2[50],x3[100];
int i=0,j=0,k=0;
int m,n;

    
// Read first polynomial
printf("enter the number of terms of first polynomial:");
scanf("%d",&m);

printf("enter the coefficient and exponents of first polynomial in the decreasing order of exponent\n");
for(i=0;i<m;i++){
printf("term %d:",i+1);
scanf("%d%d",&x1[i].coeff,&x1[i].expo);
}
    
// Read second polynomial
printf("enter the number of terms of second polynomial:");
scanf("%d",&n);

printf("enter the coefficient and exponents of second polynomial in the decreasing order of exponent\n");
for(j=0;j<n;j++){
printf("term %d:",j+1);
scanf("%d%d",&x2[j].coeff,&x2[j].expo);
}
    
// Initialize indices
i=0;
j=0;
k=0;
// Polynomial addition    
while(i<m && i<n){
if(x1[i].expo==x2[j].expo){
x3[k].coeff=x1[i].coeff + x2[k].coeff;
x3[k].expo=x1[i].expo;
i++;
j++;
k++;
}

else if (x1[i].expo>x2[j].expo){
x3[k].coeff=x1[i].coeff;
x3[k].expo=x1[i].expo;
i++;
k++;
}

else{
x3[k].coeff=x2[j].coeff;
x3[k].expo=x2[j].expo;
j++;
k++;
}
}
// Copy remaining terms of first polynomial
while(i<m){
x3[k].coeff=x1[i].coeff;
x3[k].expo=x1[i].expo;
i++;
k++;
}
// Copy remaining terms of second polynomial
while(j<n){
x3[k].coeff=x2[j].coeff;
x3[k].expo=x2[j].expo;
j++;
k++;
}

    // Display first polynomial
printf("\n\nfirst Polynomial\n");

for(i=0;i<m;i++){
printf("%dx^%d",x1[i].coeff,x1[i].expo);
if(i!=m-1){
printf("+");
}
}
        // Display second polynomial
printf("\n\nsecond Polynomial\n");

for(i=0;i<n;i++){
printf("%dx^%d",x2[i].coeff,x2[i].expo);
if(i!=n-1){
printf("+");
}
}
        // Display Resultant polynomial
printf("\n\nResultant Polynomial\n");

for(i=0;i<k;i++){
printf("%dx^%d",x3[i].coeff,x3[i].expo);
if(i!=k-1){
printf("+");
}

}

printf("\n");


return 0;
}
