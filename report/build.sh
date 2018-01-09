#!/bin/bash

pdflatex --shell-escape main
makeindex main.idx -s StyleInd.ist
biber main
pdflatex --shell-escape main
