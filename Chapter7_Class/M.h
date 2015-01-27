#ifndef M_H
#define M_H
#include "N.h"
class M {
    public:
        friend void N::test();
        void test();
    private:
        int x;
};
#endif
