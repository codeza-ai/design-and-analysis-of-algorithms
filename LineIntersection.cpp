#include <iostream>
#include <limits>

using namespace std;

#define pdd pair<double, double>

void displayPoint(pdd P) {
    cout << "(" << P.first << ", " << P.second << ")" << endl;
}

pdd lineLineIntersection(pdd A, pdd B, pdd C, pdd D) {
    double a1 = B.second - A.second;
    double b1 = A.first - B.first;
    double c1 = a1 * (A.first) + b1 * (A.second);

    double a2 = D.second - C.second;
    double b2 = C.first - D.first;
    double c2 = a2 * (C.first) + b2 * (C.second);

    double determinant = a1 * b2 - a2 * b1;

    if (determinant == 0) {
        return make_pair(numeric_limits<double>::infinity(), numeric_limits<double>::infinity());
    } else {
        double x = (b2 * c1 - b1 * c2) / determinant;
        double y = (a1 * c2 - a2 * c1) / determinant;
        return make_pair(x, y);
    }
}

int main() {
    int coords[8];
    for(int i = 0;i< 8;i++) {
        cin>>coords[i];
    }
    pdd A = make_pair(coords[0], coords[1]);
    pdd B = make_pair(coords[2], coords[3]);
    pdd C = make_pair(coords[4], coords[5]);
    pdd D = make_pair(coords[6], coords[7]);

    pdd intersection = lineLineIntersection(A, B, C, D);

    if (intersection.first == numeric_limits<double>::infinity() &&
        intersection.second == numeric_limits<double>::infinity()) {
        cout << "The given lines AB and CD are parallel.\n";
    } else {
        displayPoint(intersection);
    }
    return 0;
}
