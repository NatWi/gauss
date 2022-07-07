
double randomize_between_zero_and_one(){
	int random_number_temp = rand()%32767;	//scale to value between 1 and 32767
	double random_number = random_number_temp/32767.0; //scale to value between 0 and 1
	return random_number;
}

double return_box_muller_number(double random1, double random2){

	double gaussian_number = sqrt(-2 * log(random1)) * cos(2 * M_PI * random2);	//Box-Muller transformation
	return gaussian_number;
}

void print_gaussian_dist(int expected_value, int std_deviation, int amount_of_values, FILE *output_stream){

	for (int i=0;i<amount_of_values;i++){
		//calculate gaussian distributed number
		double gaussian_dist = return_box_muller_number(randomize_between_zero_and_one(),randomize_between_zero_and_one()) * std_deviation + expected_value;
		fprintf(output_stream,"Zufallszahl: %lf \n", gaussian_dist);
	}
}


