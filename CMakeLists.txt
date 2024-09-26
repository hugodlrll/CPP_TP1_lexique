# Version minimum de CMake requise
cmake_minimum_required(VERSION 3.10)

# Nom du projet
project(Lexique)

# Spécification du standard C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Ajout des fichiers sources
set(SOURCES
    main.cpp
    Utilitaire.cpp
    Lexique.cpp
)

# Création de l'exécutable
add_executable(Lexique ${SOURCES})