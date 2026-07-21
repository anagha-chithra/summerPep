@echo off
cd /d "%~dp0"

echo =====================================
echo         DSA GitHub Auto Push
echo =====================================
echo.

git status

git diff --quiet
if %errorlevel%==0 (
    git diff --cached --quiet
    if %errorlevel%==0 (
        echo.
        echo No changes to commit.
        pause
        exit
    )
)

echo.
set /p msg=Enter commit message:

if "%msg%"=="" (
    echo Commit message cannot be empty.
    pause
    exit
)

git add .
git commit -m "%msg%"

echo.
echo Syncing with GitHub...
git pull --rebase origin main

if errorlevel 1 (
    echo Rebase failed. Resolve conflicts and run:
    echo git rebase --continue
    pause
    exit
)

echo.
echo Pushing to GitHub...
git push

echo.
echo =====================================
echo Successfully pushed to GitHub!
echo =====================================
pause