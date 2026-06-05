#include <stdio.h>
#include <stdlib.h>
/*Написать программу подсчитывающая количество битов, выставленных в единицу у числа типа long и double. Сами значения чисел вводятся с клавиатуры.*/ 

int num_bits_long(unsigned long n)
{
    if (n==0){
		return 0;
	}
    return (n%2)+num_bits_long(n/2);
}    
int num_bits_double(double n)
{
    unsigned char* doubytes = (unsigned char*) &n;
    int k = 0;
    int i;
    for (i=0; i<sizeof(double); i++){
    	unsigned char lonbytes = doubytes[i];
    	while(lonbytes){
    		k += lonbytes & 1;
    		lonbytes >>= 1;
		}
	}
	return k;
}
int main(int argc, char *argv[])
{
  long n;
  printf("long=");
  scanf("%ld",&n);
  printf("number of bits n long=%d\n",num_bits_long(n)); 
  
  double d;
  printf("double=");
  scanf("%lf",&d);
  printf("number of bits n long=%d\n",num_bits_double(d)); 
  return 0;
}