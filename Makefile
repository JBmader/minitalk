# Nom de l'exécutable
TARGET_CLIENT = client
TARGET_SERVER = server

# Compilateur
CC = gcc

# Options de compilation
CFLAGS = -Wall -Wextra -Werror -D_DEFAULT_SOURCE

# Répertoires
SRCDIR = src
OBJDIR = obj
BINDIR = bin
INCDIR = include

# Répertoire de ft_printf
FT_PRINTF_DIR = ./ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

# Fichiers sources et objets
SRC_CLIENT = $(SRCDIR)/client.c $(SRCDIR)/utils.c
SRC_SERVER = $(SRCDIR)/server.c $(SRCDIR)/utils.c
OBJ_CLIENT = $(SRC_CLIENT:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
OBJ_SERVER = $(SRC_SERVER:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Fichiers d'en-tête
HEADERS = $(INCDIR)/minitalk.h

# Règle par défaut
all: $(FT_PRINTF_LIB) $(BINDIR)/$(TARGET_CLIENT) $(BINDIR)/$(TARGET_SERVER)

# Inclure le Makefile de ft_printf
$(FT_PRINTF_LIB):
	$(MAKE) -C $(FT_PRINTF_DIR)

# Règle pour créer l'exécutable client
$(BINDIR)/$(TARGET_CLIENT): $(OBJ_CLIENT) $(FT_PRINTF_LIB)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -o $@ $^ -L$(FT_PRINTF_DIR) -lftprintf -I$(INCDIR)

# Règle pour créer l'exécutable serveur
$(BINDIR)/$(TARGET_SERVER): $(OBJ_SERVER) $(FT_PRINTF_LIB)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -o $@ $^ -L$(FT_PRINTF_DIR) -lftprintf -I$(INCDIR)

# Règle pour créer les fichiers objets
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS)
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $< -I$(INCDIR)

# Règle pour nettoyer les fichiers générés
clean:
	rm -rf $(OBJDIR) $(BINDIR)
	$(MAKE) -C $(FT_PRINTF_DIR) clean

# Règle pour nettoyer tout
fclean: clean
	rm -f $(BINDIR)/$(TARGET_CLIENT) $(BINDIR)/$(TARGET_SERVER)
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

# Règle pour recompiler
re: fclean all

.PHONY: all clean fclean re
