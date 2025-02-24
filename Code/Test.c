#include <stdio.h>
#include "c:/c_compilator/libraries/include/Objects.h"

int
main(void){
    Object* a,* b;
    a = Init_obj("a", TYPE_STRING, (Value){0, .string_value = "hello"});

    float a_res = Get_value_obj(a);
    printf("%lf\n", a_res);
}