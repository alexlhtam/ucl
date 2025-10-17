// write a program to input the length of the sides of a triangle
// and prints the area and length of the triangle

// if the input values do not represent a triangle then display an 
// error message instead

# include <stdio.h>
# include <math.h>


double calculate_semiperimeter(double a, double b, double c) {
    return (a + b + c) / 2;
}

double calculate_area(double a, double b, double c, double s) {
    return sqrt(s * (s-a) * (s-b) * (s-c));
}

int check_valid_triangle(double a, double b, double c) {
    if (a + b > c && a + c > b && b + c > a) {
        return 1;
    } else {
        return 0;
    }
}

int main(void) {
    double a, b, c;

    printf("Enter the lengths of the sides of the triangle: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (check_valid_triangle(a, b, c)) {
        double semiperimeter = calculate_semiperimeter(a, b, c);
        printf("Area: %f\n", calculate_area(a, b, c, semiperimeter));
    } else {
        printf("Triangle lengths provided are geometrically invalid.");
    }

    return 0;
}