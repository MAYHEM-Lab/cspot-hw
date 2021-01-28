#include "hw.h"
#include <woofc.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define ARGS "W:"
const char* Usage = "hw -W woof_name\n";

int main(int argc, char** argv) {
    char Wname[4096];

    int c;
    while ((c = getopt(argc, argv, ARGS)) != EOF) {
        switch (c) {
        case 'W':
            strncpy(Wname, optarg, sizeof(Wname));
            break;
        default:
            fprintf(stderr, "unrecognized command %c\n", (char)c);
            fprintf(stderr, "%s", Usage);
            return 1;
        }
    }

    if (Wname[0] == 0) {
        fprintf(stderr, "must specify woof name\n");
        fprintf(stderr, "%s", Usage);
        return 1;
    }

    WooFInit();

    int err = WooFCreate(Wname, sizeof(hw_el_stc), 5);
    if (err < 0) {
        fprintf(stderr, "couldn't create woof from %s\n", Wname);
        return 1;
    }

    hw_el_stc el;
    strncpy(el.str, "my first bark", sizeof(el.str));

    unsigned long ndx = WooFPut(Wname, "hw", &el);

    if (WooFInvalid(ndx)) {
        fprintf(stderr, "first WooFPut failed for %s\n", Wname);
        return 1;
    }
}
