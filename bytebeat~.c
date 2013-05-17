// megrimm 2011

#include "m_pd.h"
#include "bytebeat~.h"
#include <math.h>

static t_class *bytebeat_class;

typedef struct _bytebeat {
    t_object x_obj;
    t_float x_f;
} t_bytebeat;

static void *bytebeat_new(void) {
    t_bytebeat *x = (t_bytebeat *)pd_new(bytebeat_class);
    outlet_new(&x->x_obj, gensym("signal"));
    x->x_f = 0;
    return (x);
}

static t_int *bytebeat_perform(t_int *w) {
	t_float *in = (t_float *)(w[2]);
    t_float *out = (t_float *)(w[3]);
    t_int n = (t_int)(w[4]);
    int t;
    while (n--) {
    t = *in++;
    //*out++ = (((v&0xff)^0x80)-128)/128; //putchar, conversion 2 unsigned char
    *out++ = v000;
    }
    return (w+5);
}

void bytebeat_dsp(t_bytebeat *x, t_signal **sp) {
    dsp_add(bytebeat_perform, 4, x, sp[0]->s_vec, sp[1]->s_vec, sp[0]->s_n);
}

void bytebeat_tilde_setup(void) {
    bytebeat_class = class_new(gensym("bytebeat~"), (t_newmethod)bytebeat_new, 0,
    	sizeof(t_bytebeat), 0, A_DEFFLOAT, 0);
    CLASS_MAINSIGNALIN(bytebeat_class, t_bytebeat, x_f);
    class_addmethod(bytebeat_class, (t_method)bytebeat_dsp, gensym("dsp"), 0);
    post("bytebeat~ v0.1 megrimm 2011");
}