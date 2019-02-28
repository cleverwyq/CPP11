// Statistics.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class Statistics {
public:
	double Mean(double inputs[], int num) {
		//Todo: be another invalid value
		double mean = 0;
		if (num <= 0) {
			return mean;
		}

		double sum = 0.0;
		for (int i = 0; i < num; i++) {
			sum += inputs[i];
		}
		return sum / num;
	}

	double Variance(double inputs[], int num) {
		double variance = -1.0;
		if (num <= 0) {
			return variance;
		}

		double mean = this->Mean(inputs, num);
		double total = 0.0;
		for (int i = 0; i < num; i++) {
			double diff = inputs[i] - mean;
			total += diff * diff;
		}

		return total / num;
	}

	double Covariance(double x[], double y[], int num) {
		//Todo: be another invalid value
		double covariance = 0.0f;
		if (num <= 0) {
			return covariance;
		}

		double x_mean = this->Mean(x, num);
		double y_mean = this->Mean(y, num);
		double total = 0.0;
		for (int i = 0; i < num; i++) {
			total += (x[i] - x_mean) * (y[i] - y_mean);
		}
		return total / num;
	}

	double NormalizedCovariance() {
		//???
	}

};

int _tmain(int argc, _TCHAR* argv[])
{
	Statistics st;

	return 0;
}

