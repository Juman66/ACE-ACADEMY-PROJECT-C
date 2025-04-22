#include <stdio.h>
#include <math.h>

// Define M_PI if it's not defined
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Function Prototypes
float area_circle(float radius);
float circumference_circle(float radius);
float area_rectangle(float length, float width);
float perimeter_rectangle(float length, float width);
float area_triangle(float base, float height);
float perimeter_triangle(float a, float b, float c);
void clear_input_buffer();

int main() {
    int choice;
    float a, b, c;

    while (1) {
        printf("\n--- Mensuration Calculator ---\n");
        printf("1. Circle\n");
        printf("2. Rectangle\n");
        printf("3. Triangle\n");
        printf("4. Exit\n");
        printf("Choose a shape: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clear_input_buffer();
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter radius of the circle: ");
                if (scanf("%f", &a) != 1 || a <= 0) {
                    printf("Invalid input. Radius must be a positive number.\n");
                    clear_input_buffer();
                    break;
                }
                printf("Area of Circle = %.2f\n", area_circle(a));
                printf("Circumference of Circle = %.2f\n", circumference_circle(a));
                break;

            case 2:
                printf("Enter length and width of the rectangle: ");
                if (scanf("%f %f", &a, &b) != 2 || a <= 0 || b <= 0) {
                    printf("Invalid input. Dimensions must be positive numbers.\n");
                    clear_input_buffer();
                    break;
                }
                printf("Area of Rectangle = %.2f\n", area_rectangle(a, b));
                printf("Perimeter of Rectangle = %.2f\n", perimeter_rectangle(a, b));
                break;

            case 3:
                printf("Enter the three sides of the triangle: ");
                if (scanf("%f %f %f", &a, &b, &c) != 3 || a <= 0 || b <= 0 || c <= 0 ||
                    (a + b <= c || a + c <= b || b + c <= a)) {
                    printf("Invalid triangle sides. Please enter valid lengths.\n");
                    clear_input_buffer();
                    break;
                }
                float height;
                printf("Enter height of the triangle for area calculation: ");
                if (scanf("%f", &height) != 1 || height <= 0) {
                    printf("Invalid height. Must be a positive number.\n");
                    clear_input_buffer();
                    break;
                }
                printf("Area of Triangle = %.2f\n", area_triangle(a, height));
                printf("Perimeter of Triangle = %.2f\n", perimeter_triangle(a, b, c));
                break;

            case 4:
                printf("Exiting the calculator \n");
                return 0;

            default:
                printf("Invalid choice. Please select from 1 to 4.\n");
        }
    }

    return 0;
}

// Function Definitions

float area_circle(float radius) {
    return M_PI * radius * radius;
}

float circumference_circle(float radius) {
    return 2 * M_PI * radius;
}

float area_rectangle(float length, float width) {
    return length * width;
}

float perimeter_rectangle(float length, float width) {
    return 2 * (length + width);
}

float area_triangle(float base, float height) {
    return 0.5f * base * height;
}

float perimeter_triangle(float a, float b, float c) {
    return a + b + c;
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}


