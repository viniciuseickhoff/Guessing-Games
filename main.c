#include "includes.h"
#include "libconfig.h"

int main(void) {
    config_t cfg, *cf;
    const config_setting_t *retries;
    const char *base = NULL;
    int count, n, enabled;

    cf = &cfg;
    config_init(cf);

    if (!config_read_file(cf, "game.cfg")) {
        fprintf(stderr, "%s:%d - %s\n",
            config_error_file(cf),
            config_error_line(cf),
            config_error_text(cf));
        config_destroy(cf);
        return -1;
 }

 return 0;



 }
