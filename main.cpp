#include <iostream>
#include <cmath>

using namespace std;

class Figure {
protected:
    virtual void getSides() {}

    virtual double area_counter() { return 0; }
};

class Triangle : Figure {
private:
    float _a, _b, _c;
public:
    void getSides(float a, float b, float c) {
        _a = a;
        _b = b;
        _c = c;
    }

    double area_counter() override {
        double area;
        float half_perimeter;
        half_perimeter = (_a + _b + _c) / 2;
        area = sqrt(half_perimeter * (half_perimeter - _a) * (half_perimeter - _b) *
                    (half_perimeter - _c));
        return area;
    }
};

class Quadrangle : Figure {
private:
    float _a, _b, _c, _d, _diag;
public:
    void getSides(float a, float b, float c, float d, float diag) {
        _a = a;
        _b = b;
        _c = c;
        _d = d;
        _diag = diag;
    }

    double area_counter() override {
        double area;
        double first_quad_cos = (pow(_a, 2) + pow(_b, 2) - pow(_diag, 2)) / (2 * _a * _b);
        double second_quad_cos = (pow(_c, 2) + pow(_d, 2) - pow(_diag, 2)) / (2 * _c * _d);

        double first_quad_sin = sqrt(1 - pow(first_quad_cos, 2));
        double second_quad_sin = sqrt(1 - pow(second_quad_cos, 2));

        area = 0.5 * (_a * _b * first_quad_sin + _c * _d * second_quad_sin);
        return area;
    }
};

int main() {
    Triangle triangle;
    Quadrangle quadrangle;
    float a, b, c;
    cin >> a >> b >> c;
    triangle.getSides(a, b, c);

    float d, diag;
    cin >> a >> b >> c >> d >> diag;
    quadrangle.getSides(a, b, c, d, diag);

    cout << triangle.area_counter() << " " << quadrangle.area_counter() << endl;

    return 0;
}
