cmake_minimum_required(VERSION 3.8)
project(TP-Cpp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lm")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin")

set(SOURCE_FILES_LIBS
        libs/libs.h
        libs/libs.c)

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

set(SOURCE_FILES_TP2
        TP2/main.c
        TP2/factorielle.c
        TP2/factorielle.h
        TP2/harmonique.c
        TP2/harmonique.h
        TP2/piLeibniz.c
        TP2/piLeibniz.h
        )

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

add_library(mylib ${SOURCE_FILES_LIBS})

add_executable(TP1 ${SOURCE_FILES_TP1})
add_executable(TP2 ${SOURCE_FILES_TP2})
add_executable(TP3 ${SOURCE_FILES_TP3})
add_executable(TP5 ${SOURCE_FILES_TP5})

target_link_libraries(TP1 mylib)
target_link_libraries(TP2 mylib m) # 'm' for cmath lib
target_link_libraries(TP3 mylib)
target_link_libraries(TP5 mylib)

