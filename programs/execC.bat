@echo off
type %1 | clip
gcc %1 -o executable.exe
.\executable.exe