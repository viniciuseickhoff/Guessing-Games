#include "libconfig/lib/libconfig.h"
#include "constants.h"
#include "GuessGame.c"
#include "modocpu.c"
#include "main.h"
#include "string.h"
#define EN 0
#define PT 1
#define ARR_SIZE(arr) (sizeof ((arr)) / sizeof((arr[0])) )
void display(char *string) {
    printf("%s",string);
}
char **split(char frase[], char separador)
{
    int i, j, k, contsep = 0;

    for(i=0,contsep=0; i<strlen(frase); i++)
        if(frase[i] == separador)
            contsep++;

    char  aux[contsep][20];
    char **result = (char**)malloc(contsep*sizeof(char));

    if(contsep)
    {
        for(i=0; i<=contsep; i++ )
            *(result + i) = (char*)malloc(40*sizeof(char));

        for(i=0,k=0,j=0; i < strlen(frase); i++)
            if(frase[i] != separador)
            {
                aux[k][j] = frase[i];
                j++;
            }
            else
            {
                aux[k][j] = 0;
                k++;
                j=0;
            }
        aux[k][j] = 0;

        for(i=0; i<=contsep; i++)
            *(result+i) = strcpy(*(result+i), aux[i]);

        return result;
    }
    else
        printf("error");
}
config_t cfg;
int main(void) {
    LANG *Lang = initLang();
    int currLang = 1;
    char *la;
    const char *dummy;
    int gameMode;
    config_setting_t *setting;
    const char *str;

    config_init(&cfg);

    if (!config_read_file(&cfg, "game.cfg")) {
        fprintf(stderr, "%s:%d - %s\n", config_error_file(&cfg),
                config_error_line(&cfg), config_error_text(&cfg));
        config_destroy(&cfg);
    }
    config_lookup_string(&cfg, "lang.welcome", &str);
    printf("%s",str);
    scanf("%d", &currLang);
    config_destroy(&cfg);
    config_init(&cfg);
    if (!config_read_file(&cfg, currLang == EN ? "en.cfg" : "pt.cfg")) {
        fprintf(stderr, "%s:%d - %s\n", config_error_file(&cfg),
                config_error_line(&cfg), config_error_text(&cfg));
        config_destroy(&cfg);
    }
    config_lookup_string(&cfg,"lang.gamemode",&dummy);
    printf("%s",dummy);
    scanf("%d",&gameMode);
    config_lookup_string(&cfg,"lang.ola",&(Lang->ola));
    config_lookup_string(&cfg,"lang.olauser",&(Lang->olauser));
    config_lookup_string(&cfg,"lang.primeiraguess",&(Lang->primeiraguess));
    config_lookup_string(&cfg,"lang.comofui",&(Lang->comofui));
    config_lookup_string(&cfg,"lang.mtalta",&(Lang->mtalta));
    config_lookup_string(&cfg,"lang.proximaguess",&(Lang->proximaguess));
    config_lookup_string(&cfg,"lang.mtbaixa",&(Lang->mtbaixa));
    config_lookup_string(&cfg,"lang.consegui",&(Lang->consegui));
    config_lookup_string(&cfg,"lang.tentativas",&(Lang->tentativas));
    config_lookup_string(&cfg,"lang.unumero",&(Lang->unumero));
    config_lookup_string(&cfg,"lang.jogardnv",&(Lang->jogardnv));
    config_lookup_string(&cfg,"lang.suaguess",&(Lang->suaguess));

    if(gameMode == 0) {
        initGameModeZero(Lang);
    }
    if(gameMode == 1) {
        srand(time(NULL));
        int x = rand()%100 + 1;
        int resp;
        display((Lang->ola));
        display(Lang->suaguess);
        while(true) {
            scanf("%d", &resp);
            if (resp == x)
            {
                display(Lang->consegui);
                break;
            }
            display(Lang->guesserrada);
        }
    }
    if(gameMode == 2) {
        config_destroy(&cfg);
        config_init(&cfg);
        if (!config_read_file(&cfg, "game.cfg")) {
            fprintf(stderr, "%s:%d - %s\n", config_error_file(&cfg),
                    config_error_line(&cfg), config_error_text(&cfg));
            config_destroy(&cfg);
        }
        int qtd = 0;
        char *modos;
        config_lookup_int(&cfg,"modes.quantity",&qtd);
        config_lookup_string(&cfg,"modes.names",&modos);
        char** mds;
        mds = split(modos,',');
        free(modos);
        display(Lang->foramachados);
        printf("%d%s",qtd," modos:\n");
        for(int i = 0; i < qtd; i++) {
            printf("%d%s%s%s",i,"-",mds[i],"\n");

        }
        int mod;
        int qtmod;
        scanf("%d",&mod);
        const char *cmod;
        const char *vmod;
        cmod = mds[mod];
        free(mds);
        setting =  config_lookup(&cfg,"modes");
        setting = config_lookup(&setting,cmod);
        free(cmod);
        config_lookup_int(&setting,"size",&qtmod);
        config_lookup_string(&setting,"values",&vmod);
        mds = split(vmod,',');

        srand(time(NULL));
        *modos = mds[0];
        while(1) {
//display(Lang->suaguess);
            char *cr;
            scanf("%s",&cr);
            //   if(!strstr(rs,cr)) {
            //  display(Lang->consegui);
            break;
//}
        }



    }




    ;



    return 0;



}



