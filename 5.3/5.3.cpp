#include <iostream>
#include <iomanip> 
#include <cmath>

using namespace std;

double p(const double x) {
    if (abs(x) >= 1) {
        return (sin(x) + cos(x)) / (pow(sin(x), 2) + exp(x));
    }
    else {
        double sum = 0;
        double term = 1; 
        for (int j = 0; j <= 4; ++j) {
            sum += pow(-1, j) * pow(x, 2 * j) / tgamma(2 * j + 1);
        }
        return 1 / cos(x) * sum;
    }
}

int main() {
    double gp, gk;
    int n;

    cout << "gp = "; cin >> gp;
    cout << "gk = "; cin >> gk;
    cout << "n = "; cin >> n;

    double dg = (gk - gp) / n;  
    double g = gp;

    cout << setw(10) << "g" << setw(20) << "z" << endl;
    cout << "------------------------------" << endl;

    while (g <= gk) {
        double z = p(2 * g + 1) + pow(p(pow(g, 2) - 1), 2) + sqrt(p(1));
        cout << fixed << setprecision(6) << setw(10) << g << setw(20) << z << endl;
        g += dg;
    }

    return 0;
}
