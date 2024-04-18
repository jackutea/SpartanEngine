@echo off

if not exist bin mkdir bin
if not exist build mkdir build

g++ .\src\main.cpp -c -o .\build\main.o 
g++ .\src\User\UserMain.cpp -c -o .\build\UserMain.o

g++ .\build\main.o .\build\UserMain.o .\lib\raylib.dll -o .\bin\game

copy .\lib\raylib.dll .\bin
xcopy .\assets .\bin\assets /E /I /Y

@echo on