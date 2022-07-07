#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<getopt.h>
#include<math.h>
#include<string.h>
#include<unistd.h>
#include"headerlib_gauss.h"


void print_usage(){
	printf("Usage: ./gauss_out -e <int expected_value> -s <int std_deviation> -a <int amount_of_values> -f name_of_file \n");
	printf("Example: ./gauss_out -e 150 -s 4 -a 100 -f gauss_out.txt\n");
	exit(2);
}

int main(int argc, char **argv) {

	int option = 0;
	char *name_of_file;
	int  exp_val, std_dev, am_values;
	while((option = getopt(argc, argv, "hvf:e:s:a:")) !=-1)
	{
		switch(option) {
			case 'h':
				printf("This programm prints gaussian distributed numbers in a file.\n");
				printf("Enter -h for help\n");
				printf("Enter -v to get versionnumber\n");
				print_usage();
				break;
			case 'v':
				printf("Version: 1.0\n");
				printf("Author: Nathan Wiebelitz\n");
				break;
			case 'f':
				name_of_file = optarg;
				break;
			case 'e':
				exp_val = atoi(optarg); //convert to int with atoi
				break;
			case 's':
				std_dev = atoi(optarg);
				break;
			case 'a':
				am_values = atoi(optarg);
				break;
		}
	}
	//transfer parameters for print_gaussian_dist
	int My = exp_val;
	int sigma = std_dev;
	int amount_of_val = am_values;
	printf("Erwartungswert: %d\n", My);
	printf("Standardabweichung: %d\n", sigma);	
	printf("Anzahl Werte: %d\n", amount_of_val);

	//necessary for random_number_creation
	time_t actual_time = time (NULL);
	srand(actual_time);

	FILE *out_stream;
	//create txt-file
	out_stream = fopen(name_of_file, "w+");
	fclose(out_stream);
	//error if file-name wasn't passed
	if (out_stream == NULL){
		printf("File not found!\n");
		exit (3);
	}
	//print gaussian_numbers into file
	out_stream = fopen(name_of_file, "a");
	print_gaussian_dist(My,sigma,amount_of_val, out_stream);

	fclose(out_stream);
	print_usage();
	return 0;
}
