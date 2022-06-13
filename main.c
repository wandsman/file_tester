#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *f_file, *s_file;
    int dif_char = 0;
    char f_ch, s_ch;

#if debug
    for (int i = 0; i < argc; ++i) {
        printf("%d arg - %s\n", i, argv[i]);
    }
#endif
    f_file = fopen(argv[1], "r");
    s_file = fopen(argv[2], "r");
    if (f_file == NULL || s_file == NULL) {
        return 1;
    }

    f_ch = fgetc(f_file);
    s_ch = fgetc(s_file);
    while ((f_ch != EOF) || (s_ch != EOF)) {
        if (f_ch != s_ch) {
            dif_char++;
        }
        f_ch = fgetc(f_file);
        s_ch = fgetc(s_file);
    }

    if (dif_char > 0) {
        printf("file are different\n");
    } else {
        printf("file are equal\n");
    }

    fclose(f_file);
    fclose(s_file);

    return 0;
}
