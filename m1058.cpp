#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <math.h>
#include <algorithm>

double minimizeError(std::vector<double>& prices, int target) {
	struct {
		bool operator()(double a, double b) const
		{
			return a - floor(a) < b - floor(b);
		}
	} customLess;

	std::sort(prices.begin(), prices.end(), customLess);
	int bottom = 0;
	int effectiveSize = prices.size();
	for (auto price : prices) {
		std::cout << price << std::endl;
		bottom += floor(price);
		if (price == floor(price)) {
			effectiveSize--;
		}
	}

	if (bottom + effectiveSize < target || bottom > target) {
		return -1;
	} 
	int numCeil = target - bottom;
	double ret = 0;
	for (int i = 0; i < numCeil; i++) {
		double temp = prices[prices.size() - 1 - i];
		ret += ceil(temp) - temp;
	}
	for (int i = 0; i < prices.size() - numCeil; i++) {
		double temp = prices[i];
		if (temp == floor(temp)) {
			continue;
		}
		ret += temp - floor(temp);
	}
	return ret;
}

int main (int argc, char** argv) {
	std::vector<double> prices;
	prices.push_back(3.000);
	prices.push_back(0.000);
	prices.push_back(0.001);
	prices.push_back(5.000);
	std::cout << minimizeError(prices, 9) << std::endl;
}