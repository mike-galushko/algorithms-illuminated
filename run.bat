@echo off

@REM Select example
@REM set "fileName=1.2.3-school-multiplication"
set "fileName=1.3.1-recursive-multiplication"

@REM Compile example
set "outputPath=./output"
set "inputPath=./part-1"
if not exist "%outputPath%/" mkdir "%outputPath"
clang++ "%inputPath%/%fileName%.cpp" -o "%outputPath%/%fileName%.exe" 

@REM Run example
@echo on
"%outputPath%/%fileName%.exe"
