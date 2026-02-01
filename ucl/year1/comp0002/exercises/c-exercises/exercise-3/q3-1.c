// Write a program to input the length of the sides of a triangle, and prints the area and length of
// the perimeter of the triangle. If the input values do not represent a triangle then display an error
// message instead.

# include <stdio.h>
# include <math.h>

double calc_sp(double a, double b, double c) {
    return 0.5 * (a + b + c);
}

double calc_a(double a, double b, double c, double s) {
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int verify_tri(double a, double b, double c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

int main(void) {
    double a, b, c;
    
    printf("Enter 3 sides of a triangle: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (!verify_tri(a, b, c)) {
        printf("Invalid triangle\n");
    } else {
        double sp = calc_sp(a, b, c);
        double p = sp * 2;
        double area = calc_a(a, b, c, sp);

        printf("Perimeter: %lf\n", p);
        printf("Area: %lf\n", area);
    }

    return 0;
}