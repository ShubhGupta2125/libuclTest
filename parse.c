#include <ucl.h>
#include<stdio.h>

int main () {

    char inbuf[8192];
    struct ucl_parser *parser = NULL;
    int ret = 0, r = 0;
    ucl_object_t *top = NULL;
    FILE *in;

    in = fopen("FreeBSD.conf","r");
    parser = ucl_parser_new (0);
    while (!feof (in) && r < (int)sizeof (inbuf)) {
            r += fread (inbuf + r, 1, sizeof (inbuf) - r, in);
    }
    ucl_parser_add_chunk (parser, inbuf, r);
    fclose (in);

    if (ucl_parser_get_error (parser)) {
            printf ("Error occurred: %s\n", ucl_parser_get_error (parser));
    }
    else {
            top = ucl_parser_get_object (parser);
    }

    ucl_object_iter_t it = NULL, it_obj = NULL, it_objj = NULL;
    const ucl_object_t *cur, *obj, *objj

    /* Iterate over the object */
    while ((obj = ucl_iterate_object (top, &it, false))) {
                /* Iterate over the values of a key */
                while ((cur = ucl_iterate_object (obj, &it_obj, false))) {
                            printf ("key: \"%s\"\n", ucl_object_tostring_forced (cur));
                            while ((objj = ucl_iterate_object (cur, &it_objj, false))) {
                                    printf ("key: \"%s\"\n", ucl_object_tostring_forced (objj));
                                    }
                                }
    }

    if (parser != NULL) {
            ucl_parser_free (parser);
    }
/*    if (obj != NULL) {
            ucl_object_unref (obj);
    }*/
    return 0;
}
