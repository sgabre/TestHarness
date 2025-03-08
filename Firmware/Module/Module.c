
#include <ctype.h>

#include <string.h>

#include "Module.h"


static int8_t Module_PrivateFunction(int8_t a, int8_t b, int8_t c)
{
    return (int8_t)(((int16_t)a + (int16_t)b + (int16_t)c) / 3);
}

int8_t Module_Function(int8_t a, int8_t b, int8_t c)
{
    return (int8_t)(((int16_t)a + (int16_t)b + (int16_t)c) / 3);
}

bool Module_IsPalindrome(const char *str) 
{
    if (str == NULL) 
        return false;  // Vérification de sécurité
    
    const char *debut = str;  
    const char *fin = str + strlen(str) - 1;
    
    while (debut < fin) 
        {
            // Ignorer les espaces et caractères non alphanumériques
            while (debut < fin && !isalnum((unsigned char)*debut)) 
                debut++;
            while (debut < fin && !isalnum((unsigned char)*fin)) 
                fin--;
            
            // Comparaison insensible à la casse
            if (tolower((unsigned char)*debut) != tolower((unsigned char)*fin)) 
                {
                    return false;  // Pas un palindrome
                }
            
            debut++;
            fin--;
        }
    
    return true;  // C'est un palindrome
}
