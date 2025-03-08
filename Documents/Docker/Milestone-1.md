# Milestone #1: Dev Container de base

# 📌 Prérequis

1. Installer Docker : Docker Desktop
2. Installer Visual Studio Code : VS Code
3. Installer l’extension Dev Containers :
   * Ouvrir VS Code
   * Aller dans l’onglet Extensions (Ctrl + Shift + X)
   * Rechercher Dev Containers et l’installer

# 🏗 Étape 1 : Création du projet

Dans un terminal, crée un dossier pour ton projet :

```
mkdir DevContainer
cd DevContainer
```

Ajoute un fichier source simple :

```
mkdir src
echo '#include <stdio.h>\nint main() { printf("Hello, Dev Container!\\n"); return 0; }' > src/main.c
```

# 🛠 Étape 3 : Création du Dev Container

Dans le dossier DevContainer, crée un sous-dossier .devcontainer :

```
mkdir .devcontainer
```

Crée ensuite un fichier Dockerfile dans .devcontainer/ :
```
# Image Alpine minimale
FROM alpine:latest

# Installer uniquement les outils nécessaires
RUN apk add --no-cache gcc musl-dev make gdb

# Définir le dossier de travail
WORKDIR /workspace

# Commande par défaut
CMD ["/bin/sh"]

```
Crée ensuite un fichier devcontainer.json dans .devcontainer/ :

```
{
  "name": "Minimal C Dev Container",
  "build": {
    "dockerfile": "Dockerfile"
  },
  "customizations": {
    "vscode": {
      "extensions": ["ms-vscode.cpptools"]
    }
  },
  "workspaceFolder": "/workspace",
  "mounts": [
    "source=${localWorkspaceFolder}/src,target=/workspace,type=bind"
  ],
  "runArgs": ["--cap-add=SYS_PTRACE", "--security-opt", "seccomp=unconfined"]
}
```

# 📦 Étape 4 : Lancer le Dev Container

Ouvre le dossier DevContainer dans VS Code.
Appuie sur Ctrl + Shift + P et cherche Dev Containers: Reopen in Container.
VS Code va construire et ouvrir le container.

# 🔧 Étape 5 : Compiler et Exécuter le code

Dans le terminal de VS Code (ou via bash dans le container) :

```
cd /workspace
gcc main.c -o main
./main
```

Tu devrais voir :

```
Hello, Dev Container!
```
