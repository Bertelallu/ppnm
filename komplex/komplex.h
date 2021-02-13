typedef struct {double re,im;} komplex;

void    komplex_print    (char* s, komplex z); /* print string s and the komplex number z */
void    komplex_set      (komplex* z, double x, double y);   /* z is set to x+i*y */
komplex komplex_new      (double x, double y);   /* returns x+i*y */
komplex komplex_add      (komplex a, komplex b); /* returns a+b */
komplex komplex_sub      (komplex a, komplex b); /* returns a-b */
