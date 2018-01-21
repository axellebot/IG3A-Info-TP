cmake_minimum_required(VERSION 3.8)
project(TP-Cpp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lm")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin")

set(SOURCE_FILES_LIBS
        libs/libs.h
        libs/libs.c)

set(SOURCE_FILES_TP1-2
        TP1-2/algosTri.c
        TP1-2/algosTri.h
        TP1-2/generationTableaux.c
        TP1-2/generationTableaux.h
        TP1-2/main.c
        TP1-2/manipTableauxNonTries.c
        TP1-2/manipTableauxNonTries.h
        TP1-2/manipTableauxTries.c
        TP1-2/manipTableauxTries.h
        TP1-2/modifTableauxNonTries.c
        TP1-2/modifTableauxNonTries.h
        TP1-2/modifTableauxTries.c
        TP1-2/modifTableauxTries.h
        TP1-2/factorielle.c
        TP1-2/factorielle.h
        TP1-2/harmonique.c
        TP1-2/harmonique.h
        TP1-2/piLeibniz.c
        TP1-2/piLeibniz.h
        TP1-2/bubbleBreaker.c
        TP1-2/bubbleBreaker.h)

set(SOURCE_FILES_TP3-4
        TP3-4/main.c
        TP3-4/arbresBasiques.c
        TP3-4/arbresBasiques.h
        TP3-4/arbresFctRecursives.c
        TP3-4/arbresFctRecursives.h
        TP3-4/modifArbres.c
        TP3-4/modifArbres.h
        TP3-4/parcoursArbres.c
        TP3-4/parcoursArbres.h)

set(SOURCE_FILES_TP3-4-stat
        TP3-4/mainExostats.c
        TP3-4/arbresBasiques.c
        TP3-4/arbresBasiques.h
        TP3-4/arbresFctRecursives.c
        TP3-4/arbresFctRecursives.h
        TP3-4/modifArbres.c
        TP3-4/modifArbres.h
        TP3-4/parcoursArbres.c
        TP3-4/parcoursArbres.h)

set(SOURCE_FILES_TP9-10
        TP9-10/main.cpp
        TP9-10/Mage.cpp
        TP9-10/Mage.h
        TP9-10/MageGuerrier.cpp
        TP9-10/MageGuerrier.h
        TP9-10/Personne.cpp
        TP9-10/Personne.h
        TP9-10/Guerrier.cpp
        TP9-10/Guerrier.h
        )

add_library(mylib ${SOURCE_FILES_LIBS})

add_executable(TP1-2 ${SOURCE_FILES_TP1-2})
add_executable(TP3-4 ${SOURCE_FILES_TP3-4})
add_executable(TP3-4-Stat ${SOURCE_FILES_TP3-4-stat})
add_executable(TP7-8-UDP_Client TP7-8/clientUDP.c)
add_executable(TP7-8-UDP_Server TP7-8/serveurUDP.c)
add_executable(TP7-8-TCP_Server TP7-8/serveurTCP.c)
add_executable(TP7-8-GetHostByName TP7-8/getHostByName.c)
add_executable(TP9-10 ${SOURCE_FILES_TP9-10})

# 'm' for cmath lib
target_link_libraries(TP1-2 mylib m)
target_link_libraries(TP3-4 mylib)
target_link_libraries(TP9-10 mylib m)

