#include <iostream>
#include <random>
#include <ctime>
#include <fstream>

using namespace std;

void simulate(int trial_students, int total_values)
{
	int test_iterations = 100000;
	int favourable_count=0;

	for(int iter = 1; iter<=test_iterations; iter++)
	{
		int test[total_values];
		memset(test, 0, sizeof(test));	

		for(int student = 1; student<=trial_students; student++)
		{
			int index = rand()%total_values;
			if(test[index]==1)
			{
				favourable_count++;
				break;
			}
			else
			{
				test[index]++;
			}
		}
	}

	double prob = (double)favourable_count/((double)test_iterations);

	if(trial_students%10 == 0)
	{
		cout<<"\tTrial Students = "<<trial_students<<endl;
		cout<<"\tProbability of Collision = "<<prob<<endl;
		cout<<endl;
	}

	 // For graph plotting 
	// ofstream fout;
	// string name = "data.txt";
	// fout.open(name, ios_base::app);
	
	// fout<<trial_students<<"\t"<<prob<<endl;
	// fout.close(); 
	
}

int main(int argc, char const *argv[])
{
	srand(time(NULL));

	int total_values = 365;
	cout<<"Total Values = 365"<<endl<<endl;
	for(int trial_students = 2;trial_students<=100;trial_students++)
	{
		simulate(trial_students, total_values);
	}
	return 0;
}