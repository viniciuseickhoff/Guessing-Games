#include "includes.h"
#include "libconfig/lib/libconfig.h"
#include "constants.h"
#define EN 1
#define PT 2
#define getLanguage(a) a == 1 ? 1 : 2
int main(void) {
    int currLang = 1;
       config_t cfg;
        config_setting_t *setting;
        const char *str;

        config_init(&cfg);

        if (!config_read_file(&cfg, "game.cfg")) {
                fprintf(stderr, "%s:%d - %s\n", config_error_file(&cfg),
                        config_error_line(&cfg), config_error_text(&cfg));
                config_destroy(&cfg);
        }
         config_lookup_string(&cfg, variableName, &str);

  LANG *lang;
  
  

 return 0;



 }
