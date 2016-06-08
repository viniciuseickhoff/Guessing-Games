#include "includes.h"
#include "libconfig/lib/libconfig.h"
#include "constants.h"
#define EN 1
#define PT 2
#define getLanguage(a) a == 1 ? EN : PT
int main(void) {
    int l = 0;
    printf("Choose your Language | Escolha sua Lingua");
    printf("\n1- English (USA)\n");
    printf("2- Portugues (BR)");
    scanf("%d",&l);
    #define CURR_LANG getLanguage(l)
    config_t cfg, *cf;
    const config_setting_t *retries;
    const char *base = NULL;
    int count, n, enabled;
    
    cf = &cfg;
    config_init(cf);

    if (!config_read_file(cf, "lang.cfg")) {
        fprintf(stderr, "%s:%d - %s\n",
            config_error_file(cf),
            config_error_line(cf),
            config_error_text(cf));
        config_destroy(cf);
        return -1;
 }
  LANG *lang;
  
  

 return 0;



 }
