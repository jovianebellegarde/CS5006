// gcc factorial.c -o factorial
// ./factorial

#include <stdio.h>

int factorial(double n){
	double tempNum = 1;
	while(n > 0) {
		tempNum = tempNum * n;
		n--;
	}
 	return tempNum;
};


int factorial_rec(int n){
	if (n < 1) {
		return 1;
	}
	return n * factorial_rec(n - 1);
}

int main(){

  printf("factorial(10) = %d\n",factorial(10));
  printf("factorial_rec(10) = %d\n",factorial_rec(10));
  printf("factorial(21) = %d\n", factorial(21));
  printf("factorial_rec(21) = %d\n", factorial_rec(21));

  return 0;
}
