@echo off
echo ===============================
echo      Git Auto Push
echo ===============================

git add .

set /p msg=Enter commit message:

git commit -m "%msg%"

echo.
echo Pulling latest changes...
git pull --rebase origin main

if errorlevel 1 (
    echo.
    echo Rebase failed. Resolve the issue and try again.
    pause
    exit /b
)

echo.
echo Pushing to GitHub...
git push origin main

echo.
echo ===============================
echo      Done!
echo ===============================
pause