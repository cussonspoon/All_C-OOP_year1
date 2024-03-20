#include <iostream>
#include <vector>
#include <algorithm> 
#include <cmath>  
#include <iomanip>

using namespace std;

int main() {
    vector<double> numbers;
    double input;

    cout << "Enter numbers (end with a non-numeric character): ";
    while (cin >> input) {
        numbers.push_back(input);
    }

    double sum = 0.0;
    for (double num : numbers) {
        sum += num;
    }
    double mean = sum / numbers.size();

    sort(numbers.begin(), numbers.end());
    double median = numbers.size() % 2 == 0
                        ? (numbers[numbers.size() / 2 - 1] + numbers[numbers.size() / 2]) / 2.0
                        : numbers[numbers.size() / 2];

    double squared_deviations_sum = 0.0;
    for (double num : numbers) {
        squared_deviations_sum += pow(num - mean, 2);
    }
    double standard_deviation = sqrt(squared_deviations_sum / numbers.size());

    double minimum = *min_element(numbers.begin(), numbers.end());
    double maximum = *max_element(numbers.begin(), numbers.end());

    cout << fixed << setprecision(2); 
    cout << "\nMean: " << mean << endl;
    cout << "Median: " << median << endl;
    cout << "Standard Deviation: " << standard_deviation << endl;
    cout << "Minimum: " << minimum << endl;
    cout << "Maximum: " << maximum << endl;

    return 0;
}