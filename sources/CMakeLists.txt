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
        TP1/modifTableauxTries.h)

add_executable(TP1 ${SOURCE_FILES_TP1})