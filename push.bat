@echo off
cd /d "%~dp0"

echo.
set /p msg=Enter commit message: 

git add .

git commit -m "%msg%"

git push

echo.
echo ===============================
echo       Push Completed!
echo ===============================
pause