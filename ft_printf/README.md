
# ft_printf

**ft_printf** est une fonction personnalisée codée en C, qui recrée une version simplifiée de la fonction `printf` de la bibliothèque standard. Elle permet d'afficher des chaînes de caractères et de gérer divers types de données avec les spécificateurs `%s`, `%d`, `%x`, `%X`, `%u`, `%p`, `%c`.

## Installation et Compilation

1. Clonez ce dépôt :

   ```bash
   git clone https://github.com/JBmader/ft_printf
   cd ft_printf
   ```

2. Compilez la bibliothèque avec le Makefile fourni :

   ```bash
   make
   ```

   Cela générera le fichier `libftprintf.a` à la racine du projet.

3. Pour nettoyer les fichiers objets :

   ```bash
   make clean
   ```

4. Pour nettoyer tout (y compris `libftprintf.a`) :

   ```bash
   make fclean
   ```

5. Pour tout recompiler depuis zéro :

   ```bash
   make re
   ```

## Exemple d'utilisation

```c
#include "ft_printf.h"

int main() {
    int count;

    count = ft_printf("Voici un entier: %d
", 42);
    printf("ft_printf a écrit %d caractères.
", count);

    return 0;
}
```
Projet réalisé par JBmader.
