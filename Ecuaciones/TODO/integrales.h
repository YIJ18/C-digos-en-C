// Declaraciones de funciones de simpson
double simpson_3_8_intervalos(double a, double b, int n);
double f(double x);
double simpson_1_3(double a, double b);
double simpson_3_8(double a, double b);
double simpson_compuesta(double a, double b, int n);
void error_r_p(double valor_aprox, double *error_relativo, double *error_porcentual);
void imprimir_resultados(double a, double b, int n);

// Declaraciones de funciones de taylor
double factorial(int n);
double F(double x);
double n_derivada_central(double x, int n, double h);
double Maclaurin(double a, double x, double h);

// Runge
double derivada_runge(double x, double y);
double runge_kutta(double (*derivada_runge)(double, double), double x, double y, double h);
void resolver(double (*derivada_runge)(double, double), double x_inicial, double y_inicial, double x_final, double h);
void llamar_runge();
