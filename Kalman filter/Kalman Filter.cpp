#include <iostream>
#include <stdio.h>
#include <stdlib.h> //난수 생성을 위한 헤더 
#include <math.h> 
#include <time.h>
using namespace std;

double frand()
{
	return rand() / (double)RAND_MAX*1.0f;

}
int main(void)
{
	double n;
	double x_predict, x_estimate, x_last;
	double p_predict, p_estimate, p_last;
	double z_measured;
	double z_real = 1.0;
	double Q = 0.01;  //state space eq noise
	double R = 0.386; //sensor noise
	double K_gain;
	
	//srand(time(NULL));
	srand(0);
	
	x_last = z_real + frand()*0.09; //initialize last_x val
	
	double err_sum_kalman = 0;
	double err_sum_measured = 0;
		
	for(int i=0; i<30; i++)
	{
		//time update stage(prediction)
		x_predict = x_last;
		p_predict = p_last + Q;
		
		//measurement update(correction)
		K_gain = p_predict / (1.0/(p_predict + R));
		//update estimation value via z_k
		z_measured = z_real + frand()*0.09;
		x_estimate = x_predict + K_gain*(z_measured- x_predict);
		p_estimate = (1-K_gain)*p_predict;
		
		x_last = x_estimate;
		p_last = p_estimate;
		
		err_sum_measured += fabs(z_real - z_measured); 
		err_sum_kalman += fabs(z_real - x_estimate);
		
		printf("measured value: %6.3f | diff: %6.3f \n", z_measured, fabs(z_real - z_measured));
		printf("kalman value  : %6.3f | diff: %6.3f \n", x_estimate, fabs(z_real - x_estimate));
		printf("---------------------------------------------------------\n");

	}
	
	printf("\n");
	printf("total err if using raw measured : %f \n", err_sum_measured);
	printf("total err if using kalman filter : %f \n", err_sum_kalman);
		
	return 0;	
}
