typedef struct {
    char *ola,*olauser,*primeiraguess,*comofui,*mtalta,*proximaguess,*mtbaixa,*consegui,*tentativas,*unumero,*jogardnv,*suaguess;
} LANG;
LANG *initLang() {
    LANG *l = malloc(sizeof(LANG));
    l->ola = malloc(sizeof(char) * 100);
l->olauser = malloc(sizeof(char) * 100);
l->primeiraguess = malloc(sizeof(char) * 100);
l->comofui = malloc(sizeof(char) * 100);
l->mtalta = malloc(sizeof(char) * 100);
l->proximaguess = malloc(sizeof(char) * 100);
l->mtbaixa = malloc(sizeof(char) * 100);
l->consegui = malloc(sizeof(char) * 100);
l->tentativas = malloc(sizeof(char) * 100);
l->unumero = malloc(sizeof(char) * 100);
l->jogardnv = malloc(sizeof(char) * 100);
l->suaguess = malloc(sizeof(char) * 100);
    return l;
}
