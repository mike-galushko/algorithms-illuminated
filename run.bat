@echo off

@REM Select example
@REM set "fileName=1.2.3-school-multiplication"
@REM set "fileName=1.3.1-recursive-multiplication"
@REM set "fileName=3.2-count-inversions-brute-force"
set "fileName=3.2-count-inversions"
set "dataFile=3.2-count-inversions.txt"

@REM Compile example
set "outputPath=./output"
set "inputPath=./part-1"
if not exist "%outputPath%/" mkdir "%outputPath"
clang++ "%inputPath%/%fileName%.cpp" -o "%outputPath%/%fileName%.exe" -std=c++20

@REM Run example
@echo on
@cd "%outputPath%
@"%fileName%.exe" /C "../%inputPath%/%dataFile%"
@cd ..
