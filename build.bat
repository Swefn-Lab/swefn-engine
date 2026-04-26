@echo off

if not exist build mkdir build

pushd build

cl /nologo /I..\ext\SDL\include ..\src\main.c /link /LIBPATH:..\lib /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup SDL3.lib
copy ..\lib\SDL3.dll .\SDL3.dll

popd
