#include "includes.h"
#include "libconfig/lib/libconfig.h"
#include "constants.h"
#define EN 0
#define PT 1
#define getLanguage(a) a == 0 ? en-us : pt-br
config_t cfg;
int main(void) {
    int currLang = 1;
    char *la;
    char *dummy;
    int gameMode;
 config_setting_t *setting;
        const char *str;
  LANG *lang;
        config_init(&cfg);

        if (!config_read_file(&cfg, "game.cfg")) {
                fprintf(stderr, "%s:%d - %s\n", config_error_file(&cfg),
                        config_error_line(&cfg), config_error_text(&cfg));
                config_destroy(&cfg);
        }
         config_lookup_string(&cfg, "lang.welcome", &str);
         printf("%s",str);
         scanf("%d", &currLang);
         sprintf(dummy,"lang.%s.gamemode",getLanguage(currLang));
         printf("%s",dummy);
         scanf("%d",gameMode);
         config_destroy(&cfg);
         config_init(&cfg);
        if (!config_read_file(&cfg, currLang == 0 ? "en-us.cfg" : "pt-br.cfg")) {
                fprintf(stderr, "%s:%d - %s\n", config_error_file(&cfg),
                        config_error_line(&cfg), config_error_text(&cfg));
                config_destroy(&cfg);
        }
         config_lookup_string(&cfg,"lang.ola",Lang->ola);
	 config_lookup_string(&cfg,"lang.olauser",Lang->olauser);	
	 config_lookup_string(&cfg,"lang.primeiraguess",Lang->primeiraguess);	
	 config_lookup_string(&cfg,"lang.comofui",Lang->comofui);	
	 config_lookup_string(&cfg,"lang.mtalta",Lang->mtalta);	
	 config_lookup_string(&cfg,"lang.proximaguess",Lang->proximaguess);	
	 config_lookup_string(&cfg,"lang.mtbaixa",Lang->mtbaixa);	
	 config_lookup_string(&cfg,"lang.consegui",Lang->consegui);	
	 config_lookup_string(&cfg,"lang.tentativas",Lang->tentativas);	
	 config_lookup_string(&cfg,"lang.unumero",Lang->unumero);	
	 config_lookup_string(&cfg,"lang.jogardnv",Lang->jogardnv);	
         if(gameMode == 0) {
           initGameModeZero();
   }
        if(gameMode == 1) {
	initGameMode();
 }
        if(gameMOde == 2) {
                initCustomGameMode();
         }   
         
         
         

;
  
  

 return 0;



 }
char *getChar(const char *str) {
  char *s;
  config_lookup_string(&cfg,str,s);
  return s;
}
void display(char *string) {
 printf("%s",getChar(string));
}


