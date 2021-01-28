#include <woofc.h>
#include "hw.h"
#include <stdio.h>

int hw(WOOF* wf, unsigned long seq_no, void* ptr) {
    hw_el_stc* el = (hw_el_stc*)ptr;
    printf("hello world\n");
    printf("at %lu with string: %s\n", seq_no, el->str);
    return 1;
}

