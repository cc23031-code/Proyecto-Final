@echo off
echo ========================================
echo   Compilando Biblioteca Matematica
echo ========================================
echo.

REM Paso 1: Compilar la biblioteca a objeto (.o)
echo [1/4] Compilando MathLibrary.cpp...
g++ -c MathLibrary/MathLibrary.cpp -o MathLibrary/MathLibrary.o
if %errorlevel% neq 0 (
    echo ERROR: Fallo al compilar MathLibrary.cpp
    pause
    exit /b 1
)
echo OK: MathLibrary.o creado

REM Paso 2: Crear biblioteca estática (.a)
echo.
echo [2/4] Creando biblioteca estatica MathLibrary.a...
ar rcs MathLibrary/libMathLibrary.a MathLibrary/MathLibrary.o
if %errorlevel% neq 0 (
    echo ERROR: Fallo al crear la biblioteca estatica
    pause
    exit /b 1
)
echo OK: libMathLibrary.a creada

REM Paso 3: Compilar el cliente
echo.
echo [3/4] Compilando MathClient.cpp...
g++ -c MathClient/MathClient.cpp -I MathLibrary -o MathClient/MathClient.o
if %errorlevel% neq 0 (
    echo ERROR: Fallo al compilar MathClient.cpp
    pause
    exit /b 1
)
echo OK: MathClient.o creado

REM Paso 4: Enlazar el cliente con la biblioteca
echo.
echo [4/4] Enlazando MathClient con libMathLibrary...
g++ MathClient/MathClient.o -L MathLibrary -lMathLibrary -o MathClient.exe
if %errorlevel% neq 0 (
    echo ERROR: Fallo al enlazar el ejecutable
    pause
    exit /b 1
)

echo.
echo ========================================
echo   Compilacion EXITOSA!
echo ========================================
echo.
echo Ejecutando MathClient.exe...
echo.
MathClient.exe

echo.
pause