#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double dFirstx(double x[]);
double dSecondx(double x[]);

//x1에 대해 미분한 도함수식
double dFirstx(double x[]) {
    double dx1Return = 0.0;
    dx1Return = 3*pow(x[0], 2) + 2*x[1] - 2*x[0]*pow(x[1], 2);
    return dx1Return;
}
//x2에 대해 미분한 도함수식
double dSecondx(double x[]) {
    double dx2Return = 0.0;
    dx2Return = pow(x[0], 3) + 2*x[0] - 2*pow(x[0], 2)*x[1];
    
    return dx2Return;
}

int main() {
    double x[2] = {1,1};
    double g[2] = {0};
    int xIndex;
    double r = 0.02;
    
    printf("0번째 ");
    for(xIndex = 0; xIndex < 2; xIndex++) {
        printf("%f ", x[xIndex]);
    }
    printf("\n");
    
    //while문 r*g[0] < 0 || r*g[1] < 0 일때 멈춰
    int count = 0;
    
    while (1) {
        count++;
        g[0] = dFirstx(x);
        g[1] = dSecondx(x);
        
        //x1 = x0 - rg(0)계산
        x[0] = x[0] - r*g[0];
        x[1] = x[1] - r*g[1];
        
        printf("%d번째 ", count);
        for(xIndex = 0; xIndex < 2; xIndex++) {
            printf("%f ", x[xIndex]);
        }
        printf("\n");
        
        if(r*g[0] < 0 || r*g[1] < 0)
            break;
    }
    
    return 0;
}
