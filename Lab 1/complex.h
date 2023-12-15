#ifndef __COMPLEX_H__
#define __COMPLEX_H__

struct complex { 
    double re;
    double im;

    void show ();
    complex conjugate();
};

#endif 
