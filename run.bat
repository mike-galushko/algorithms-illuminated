@echo off

@REM Select example
set "fileName=1.1-integer-multiply-school"

@REM Compile example
set "outputPath=./output"
set "inputPath=./part-1"
if not exist "%outputPath%/" mkdir "%outputPath"
clang++ "%inputPath%/%fileName%.cpp" -o "%outputPath%/%fileName%.exe" 

@REM Run example
@echo on
"%outputPath%/%fileName%.exe"
