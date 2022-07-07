#include<stdio.h>
#include<stdlib.h>
#include<getopt.h>
#include<math.h>
#include<string.h>
#include<unistd.h>
#include<gauss_in_static.h>

void print_usage(){
	printf("Usage: ./gauss_in -...-\n");
	printf("Example: ./gauss_in -...-\n");
}

int main (int argc, char **argv) {
	int option = 0;
	char *name_of_file;
	int placeholder;
	while((option = getopt(argc,argv,"hvf:")) !=-1) {
		switch(option) {
			case 'h':
				printf("This programm reads 100 values out of a stream and calculates the gaussian expected value and the standarddeviation.\n");
				printf("The result will be printed in the console.\n");
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
		}
	}
	FILE *in_stream;
	in_stream = fopen(name_of_file, "r");
	//Errormessage if file doesn't exist
	if (NULL == in_stream){
		perror("File wasn't found!\n");
		exit(3);
	}
	print_gaussian_results(in_stream);
	fclose(in_stream);
	print_usage();
	return 0;
}

		
