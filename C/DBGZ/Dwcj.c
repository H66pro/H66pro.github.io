#include <stdio.h>
#include <math.h>

int main () {
    const double En = 1.0186, L0 = 5.093, errorL = 0.001;
    double Lx1, Lx2;
    double UL0, ULx1, ULx2, UEn = 0;
    UL0 = ULx1 = ULx2 = 0.001;
    double E1, Ur1, U1, _E1, E2, Ur2, U2, _E2;

    FILE *pfr = fopen( "Data.txt", "r");
    fscanf( pfr, "Lx1 =%lf\nLx2 =%lf", &Lx1, &Lx2);
    printf("Lx1 = %g\nLx2 = %g\n", Lx1, Lx2);
    fclose(pfr);

    FILE *pfw = fopen( "Result.txt", "a");
    fprintf( pfw, "Lx1 = %g\nLx2 = %g\n\n", Lx1, Lx2);

    E1 = Lx1 * En / L0;
    Ur1 = sqrt( (UL0/L0)*(UL0/L0) + (ULx1/Lx1)*(ULx1/Lx1) + (UEn/En)*(UEn/En));
    U1 = E1 * Ur1;
    E2 = Lx2 * En / L0;
    Ur2 = sqrt( (UL0/L0)*(UL0/L0) + (ULx2/Lx2)*(ULx2/Lx2) + (UEn/En)*(UEn/En));
    U2 = E2 * Ur2;

    // printf("E1\t=\t%g\n",E1);
    // printf("Ur1\t=\t%g\n",Ur1);
    // printf("U1\t=\t%g\n",U1);
    // printf("E2\t=\t%g\n",E2);
    // printf("Ur2\t=\t%g\n",Ur2);
    // printf("U2\t=\t%g\n",U2);

    fprintf(pfw, "E1\t=\t%g\n", E1);
    fprintf(pfw, "Ur1\t=\t%g%\n", Ur1*100);
    fprintf(pfw, "U1\t=\t%g\n", U1);
    fprintf(pfw, "E2\t=\t%g\n", E2);
    fprintf(pfw, "Ur2\t=\t%g%\n", Ur2*100);
    fprintf(pfw, "U2\t=\t%g\n", U2);
    
    fclose(pfw);
    
}