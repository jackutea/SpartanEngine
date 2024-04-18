@echo off

if not exist bin mkdir bin
if not exist build mkdir build

@REM Engine
setlocal enabledelayedexpansion
set "engineCPP="
for /R .\src\Engine %%F in (*.cpp) do (
    set "engineCPP=!engineCPP! "%%F""
)
g++ %engineCPP% .\lib\raylib.dll -shared -o .\build\SpartanEngine.dll
g++ .\src\main.cpp -c -o .\build\main.o

@REM User
setlocal enabledelayedexpansion
set "userCPP="
for /R .\src\User %%F in (*.cpp) do (
    set "userCPP=!userCPP! "%%F""
)
g++ %userCPP% .\lib\raylib.dll .\build\SpartanEngine.dll -shared -o .\build\User.dll

@REM Link
g++ .\build\main.o .\lib\raylib.dll .\build\User.dll .\build\SpartanEngine.dll -o .\bin\game

copy .\lib\raylib.dll .\bin
copy .\build\SpartanEngine.dll .\bin
copy .\build\User.dll .\bin
xcopy .\assets .\bin\assets /E /I /Y

@echo on