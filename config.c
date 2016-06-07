#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <libconfig.h>
#define SUCCESS 0
#define ERROR -1

#define SET_STRING_CONFIG_TYPE 0
#define GET_STRING_CONFIG_TYPE 1
#define CONFIGFILE "example.cfg"

/**
 * int childVarUtil(int varType, char *variableName, char *value)
 * 
 * @brief utility function that will get/set any variable in the CHILD section
 * of the configuration file.
 * 
 * @param int varType
 * @param char *variableName
 * @param char *value
 * @return int 0 for success, or -1 for error
 */
int childVarUtil(int varType, char *variableName, char *value)
{
        config_t cfg;
        config_setting_t *setting;
        const char *str;

        config_init(&cfg);

        /* Read the file. If there is an error, report it and exit. */
        if (!config_read_file(&cfg, CONFIGFILE)) {
                fprintf(stderr, "%s:%d - %s\n", config_error_file(&cfg),
                        config_error_line(&cfg), config_error_text(&cfg));
                config_destroy(&cfg);
        }

        switch (varType) {
        case (GET_STRING_CONFIG_TYPE):

                setting = config_lookup(&cfg, variableName);
                if (setting == NULL) {
                        config_destroy(&cfg);
                        return (ERROR);
                }
                config_lookup_string(&cfg, variableName, &str);
                printf("%s\n", str);
                config_destroy(&cfg);
                return (SUCCESS);

                break;
        case (SET_STRING_CONFIG_TYPE):

                setting = config_lookup(&cfg, variableName);
                if (setting == NULL) {
                        config_destroy(&cfg);
                        return (ERROR);
                }
                config_setting_set_string(setting, value);
                /* Write out the updated configuration. */
                if (!config_write_file(&cfg, CONFIGFILE)) {
                        fprintf(stderr, "Error while writing file.\n");
                        config_destroy(&cfg);
                        return (ERROR);
                }
                config_destroy(&cfg);
                return (SUCCESS);

                break;
        default:
                break;
        }

        config_destroy(&cfg);

        return (SUCCESS);
}

/**
 * int arrVarUtil(int varType, char *identifier, char *variableName, char *value)
 *
 * @brief utility function that will get/set any variable in the ANOTHERCHILD section
 * of the configuration file.  Notice that it is tricky when dealing with a 
 * sub-element that has a string.
 * 
 * @param int varType GET or SET
 * @param char *variableName
 * @param char * value
 * @return int 0 for success, or -1 for error
 */
int arrVarUtil(int varType, char *variableName, char *value)
{
        config_t cfg;
        config_setting_t *root, *setting;
        const char *varName;

        config_init(&cfg);

        /* Read the file. If there is an error, report it and exit. */
        if (!config_read_file(&cfg, CONFIGFILE)) {
                fprintf(stderr, "%s:%d - %s\n", config_error_file(&cfg),
                        config_error_line(&cfg), config_error_text(&cfg));
                config_destroy(&cfg);
        }

        /* DO the parent containers exist? */
        root = config_root_setting(&cfg);

        setting = config_setting_get_member(root, "rootContainer");
        if (!setting)
                setting = config_setting_add(root, "rootContainer", CONFIG_TYPE_GROUP);

        setting = config_setting_get_member(setting, "anotherChildContainer");
        if (!setting)
                setting = config_setting_add(setting, "anotherChildContainer", CONFIG_TYPE_LIST);

        /* If there is a licenses section */
        if (setting != NULL) {
                int count = config_setting_length(setting);
                int i = 0;

                for (i = 0; i < count; ++i) {
                        config_setting_t *element = config_setting_get_elem(setting, i);

                        if (!( config_setting_lookup_string(element, variableName, &varName))) {
                                continue;
                        }
                        
                        switch (varType) {
                        case (GET_STRING_CONFIG_TYPE):

                                /* Just print out the lsm info */
                                printf("%s\n", varName);
                                config_destroy(&cfg);
                                return (SUCCESS);

                                break;

                        case (SET_STRING_CONFIG_TYPE):

                                /* Notice that there is no simple update and replace */
                                config_setting_remove(element, variableName);
                                setting = config_setting_add(element, variableName, CONFIG_TYPE_STRING);
                                config_setting_set_string(setting, value);

                                /* Write out the updated configuration. */
                                if (!config_write_file(&cfg, CONFIGFILE)) {
                                        fprintf(stderr, "Error while writing file.\n");
                                        config_destroy(&cfg);
                                        return (ERROR);
                                }
                                config_destroy(&cfg);
                                return (SUCCESS);

                                break;

                        default:
                                break;
                        }

                }
                putchar('\n');
        }

        config_destroy(&cfg);

        return (SUCCESS);
}

/**
 * int main(int argc, char **argv)
 */
int main(int argc, char **argv)
{

        if (strstr(argv[0], "setChildVar") != NULL) {

                char appendStr[56] = "rootContainer.childContainer.";
                strcat(appendStr, argv[1]);
                if (childVarUtil(SET_STRING_CONFIG_TYPE, appendStr, argv[2]) != 0) {
                        return (ERROR);
                }
                return SUCCESS;

        } else if (strstr(argv[0], "setArrVar") != NULL) {

                if (arrVarUtil(SET_STRING_CONFIG_TYPE, argv[1], argv[2]) != 0) {
                        return (ERROR);
                }
                return SUCCESS;

        } else if (strstr(argv[0], "getChildVar") != NULL) {

                char appendStr[56] = "rootContainer.childContainer.";
                strcat(appendStr, argv[1]);
                if (childVarUtil(GET_STRING_CONFIG_TYPE, appendStr, NULL) != 0) {
                        return (ERROR);
                }
                return SUCCESS;

        } else if (strstr(argv[0], "getArrVar") != NULL) {

                if (arrVarUtil(GET_STRING_CONFIG_TYPE, argv[1], argv[2]) != 0) {
                        return (ERROR);
                }
                return SUCCESS;

        } else {
                fprintf(stderr, "Error");
                return (ERROR);
        }
}
