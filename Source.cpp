// B13
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

struct FactHistory {
    int arg;
    double result;
};

double y(double&);
double s(double&, const double&);
double fact(int);

const double A = -1.5;
const double B = 1.5;
const double EPS = 1e-4;

int main() {
    double h = (B - A) / 10;

    int precision = abs(log10(EPS));
    int columnWidth = 2 * precision;
    cout << setw(columnWidth) << 'x' << setw(columnWidth + 1) << "y(x)" << setw(columnWidth + 1) << "s(x)" << endl;
    for (double x = A; x < B + h / 2; x += h) {
        cout << setw(columnWidth) << x << " | " << setw(columnWidth) << setprecision(precision)
            << y(x) << " | " << s(x, EPS) / 4 << endl;
    }

    return 0;
}

double y(double& x) {
    return pow(cos(x), 3);
}

double s(double& x, const double& eps) {
    double summand;
    double result = 0;
    for (int n = 0; n == 0 || fabs(summand) > eps; n++) {
        summand = pow(-1, n) * (3 + pow(9, n)) * pow(x, 2 * n) / fact(2 * n);
        result += summand;
    }
    return result;
}

double fact(int n) {
    static FactHistory savedCall = { 0, 1 };
    if (n == 0 || n == 1) return 1;
    if (n != savedCall.arg) {
        savedCall = { n, n * fact(n - 1) };
    }
    return savedCall.result;
}
