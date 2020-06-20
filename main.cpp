// ConsoleApplication4.cpp : Defines the entry point for the console application.
//
//THESE CODE IS LICENCED BY BIRUK ABERE
//@ Copyright Wed 18 March 2020
//#include "stdafx.h"
#include<iostream>
using namespace std;
void knapsack(int n, float weight[], float profit[], int capacity);
int main() {
	int num;
	float weight[20], profit[20], capacity;
	float ratio[20], temp;
	cout << "please enter the number of objects" << endl;
	cin >> num;
	cout << "please enter the value weights and profits" << endl;
	for (int i = 0; i < num; i++) {
		cout << "Enter weight and profit " << i + 1 << " ";
		cin >> weight[i];
		cin >> profit[i];
	}
	cout << " please enter the capacity of the Bag" << endl;
	cin >> capacity;
	for (int i = 0;i < num; i++) {
		ratio[i] = profit[i] / weight[i];
	}
	for (int i = 0; i < num; i++) {
		for (int j = i + 1; j < num; j++) {
			if (ratio[i] < ratio[j]) {
				//these will exchange positions of elements with the high profit
				int temp = ratio[j];
				ratio[j] = ratio[i];
				ratio[i] = temp;

				//these will exchange elements with the high weight
				temp = weight[j];
				weight[j] = weight[i];
				weight[i] = temp;

				//these will exchange elements with the highest profit
				temp = profit[j];
				profit[j] = profit[i];
				profit[i] = temp;



			}
		}
	}
	knapsack(num, weight, profit, capacity);
}

void knapsack(int n, float weight[], float profit[], int capacity) {
	float x[20],u,i;
	int tp = 0;
	u = capacity;
	for (int i=0; i < n; i++)
		x[i] = 0.0;
	for (int i = 0; i < n; i++) {
		if (weight[i] > u)
			break;
		else {
			x[i] = 1.0;
			tp = tp + profit[i];
			u = u - weight[i];
		}

	}

    /*
       if(i<n){
       x[i] = u/weight[i];
       }
       tp = tp + (x[i] * profit[i]);
       cout << "the vectors are " << " ";
	for (int i = 0; i < n; i++) {
		 cout <<x[i] << " ";

		 cout << "Maximum profit is" <<  tp ;

	}
	cout << "the maximum profit is " << tp << " ";
*/
       for(int i=0; i<n; i++){
        tp=tp+(x[i]+profit[i]);
        }
        cout <<" profit is " << tp << " ";
}
