cmake_minimum_required(VERSION 3.8)
project(Cpp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES_TP1
        TP1/algosTri.c
        TP1/algosTri.h
        TP1/generationTableaux.c
        TP1/generationTableaux.h
        TP1/main.c
        TP1/manipTableauxNonTries.c
        TP1/manipTableauxNonTries.h
        TP1/manipTableauxTries.c
        TP1/manipTableauxTries.h
        TP1/modifTableauxNonTries.c
        TP1/modifTableauxNonTries.h
        TP1/modifTableauxTries.c
        TP1/modifTableauxTries.h TP5/main.c)

set(SOURCE_FILES_TP3
        TP3/main.c
        TP3/arbresBasiques.c
        TP3/arbresBasiques.h
        TP3/arbresFctRecursives.c
        TP3/arbresFctRecursives.h
        TP3/modifArbres.c
        TP3/modifArbres.h)

set(SOURCE_FILES_TP5
        TP5/main.c)

add_executable(TP1 ${SOURCE_FILES_TP1})
add_executable(TP3 ${SOURCE_FILES_TP3})
add_executable(TP5 ${SOURCE_FILES_TP5})
