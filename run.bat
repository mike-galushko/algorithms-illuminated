@echo off 
set "fileName=1.1-integer-multiply-school.cpp"
set "outputPath=./output"
set "inputPath=./Part1-basics"
if not exist "%outputPath%/" mkdir "%outputPath"

@echo on
clang++ "%inputPath%/%fileName%" -o "%outputPath%/%fileName%" 
