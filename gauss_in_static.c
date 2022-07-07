#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<gauss_in_static.h>

void print_gaussian_results(FILE *input_stream){

	char str[20];
	char *pEnd;
	double exp_val, std_dev, sum1 = 0, sum2 = 0;

	for (int i=0, i<100; i++){
		if(NULL != fgets(str,20,input_stream)) {
		double read_val = strtod(str, &pEnd);
		sum1 += read_val;
		sum2 += pow(read_val, 2.0);
		}
	}
	exp_val = sum1/100;
	variance = (sum2/100)-pow(exp_val, 2.0));
	std_dev = sqrt (variance);

	printf("Sum in total: %lf\n  ; expected value: %lf  ; variance:  %lf   ;  standarddeviation:   %lf\n", sum1, exp_val,variance,std_dev);

	return 0;
}




		
