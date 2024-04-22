@REM Get Arguments, 0 is the script name, 1 is the build type
set "buildType=%1"
set "define_editor=-D SPARTAN_RUNTIME_ONLY"
set "link_editor="
set "dll_raylib=.\lib\raylib.dll"
set "dll_engine=.\build\SpartanEngine.dll"
set "dll_user=.\build\SpartanUser.dll"
set "dll_editor=.\build\SpartanEditor.dll"
@echo buildType: %buildType%
@echo off

if not exist bin mkdir bin
if not exist build mkdir build

@REM Engine
setlocal enabledelayedexpansion
set "engineCPP="
for /R .\src\Engine %%F in (*.cpp) do (
    set "engineCPP=!engineCPP! "%%F""
)
g++ %engineCPP% %dll_raylib% -shared -o %dll_engine%
@echo on
@echo Built SpartanEngine Runtime.
@echo off
setlocal disabledelayedexpansion

@REM Editor
setlocal enabledelayedexpansion
set "editorCPP="
for /R .\src\Editor %%F in (*.cpp) do (
    set "editorCPP=!editorCPP! "%%F""
)
setlocal disabledelayedexpansion
if "%buildType%" equ "--editor" (
    g++ %define_editor% %editorCPP% %dll_raylib% %dll_engine% -shared -o %dll_editor%
    set "link_editor=%dll_editor%"
    set "define_editor="
    @echo Built SpartanEngine Editor.
)

@REM User
setlocal enabledelayedexpansion
set "userCPP="
for /R .\src\User %%F in (*.cpp) do (
    set "userCPP=!userCPP! "%%F""
)
g++ %userCPP% %dll_raylib% %dll_engine% -shared -o %dll_user%
@echo on
@echo Built User.
@echo off
setlocal disabledelayedexpansion

@REM Main
g++ %define_editor% .\src\main.cpp -c -o .\build\main.o

@REM Link
g++ %define_editor% .\build\main.o %link_editor% %dll_raylib% %dll_user% %dll_engine% -o .\bin\game
@echo on
@echo Linked Raylib, User and SpartanEngine.
@echo off

copy %dll_raylib% .\bin
copy %dll_engine% .\bin
copy %dll_user% .\bin
if "%buildType%" neq "--runtime" (
    copy %dll_editor% .\bin
)

xcopy .\assets .\bin\assets /E /I /Y /Q
@echo on
@echo Copied assets directory to bin
@echo off

@echo on