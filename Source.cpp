#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

struct Individuals {
	string id;
	float fitness;
};

const int numberOfIndividuals = 10;

void sortArray(Individuals*);

int main() {
	//seed for random number
	srand(time(NULL));

	//excel file that will hold the data
	ofstream data;
	data.open("data.csv", ios::app);

	//unsorted array holding the individuals' id and fitness
	Individuals individuals[numberOfIndividuals] = { {"A", 3.2f}, {"B", 5.4f}, {"C", 1.2f}, {"D", 6.6f}, {"E", 9.1f}, {"F", 7.5f}, {"G", 4.4f}, {"H", 4.1f}, {"I", 10.0f}, {"J", 6.9f} };
	int count[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };	//number of time an individual has been chosen

	//**UNCOMMENT TO SORT ARRAY**
	//sortArray(individuals);

	//sum up all individuals' fitness
	float sum = 0;
	for (int i = 0; i < numberOfIndividuals; i++) {
		sum += individuals[i].fitness;
	}


	for (int i = 0; i < 10000; i++) {
		//generate random float number between 0 and initial sum
		float r = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / sum));

		//sum up all individuals' fitness
		float newSum = 0;
		for (int j = 0; j < numberOfIndividuals; j++) {
			newSum += individuals[j].fitness;
			//stop when the new sum is higher than the random number
			if (newSum > r){
				count[j]++;		//increase count for the chosen individual
				break;
			}
		}
	}

	//write results to console and excel file
	for (int i = 0; i < numberOfIndividuals;i++) {
		cout << individuals[i].id << " was chosen " << count[i] << " times." << endl;
		data << individuals[i].id << "," << count[i] << endl;
	}
	data << endl << endl;

	getchar();
	return 0;
}

//bubble sort function
void sortArray(Individuals *arr) {
	Individuals temp;
	for (int i = 0; i < numberOfIndividuals; i++) {
		for (int j = 0; j < numberOfIndividuals - 1; j++) {
			if (arr[j + 1].fitness > arr[j].fitness) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}