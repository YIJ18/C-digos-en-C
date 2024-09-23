// Declaraciones de funciones de euler predictor
double derivada(double x, double y);
double Euler_predictor_corrector(double x, double y, double h, double *y_predictor);
double y_exacto(double x, double y);
void imprimir_tabla(double x, double y, double y_predictor);
void resolver_edo(double x0, double y0, double h, double x_fin);

/**** ----------------PM-------------*****/
void euler_metodo(double (*funcion_derivada)(double, double), double x_inicial, double y_inicial, double x_final, double h);
double derivada2(double x, double y);
double eulerPuntoMedio(double x, double y, double h);
double f_pm(double x, double y);
double error(double y_real, double y_aprox);