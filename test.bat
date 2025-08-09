@echo off
echo Testing compiled executables...
echo.
echo Testing RenderTest.exe:
if exist RenderTest.exe (
    echo RenderTest.exe exists
    RenderTest.exe
) else (
    echo RenderTest.exe NOT found
)
echo.
echo Testing Game.exe:
if exist Game.exe (
    echo Game.exe exists
    echo Ready to run Game.exe
) else (
    echo Game.exe NOT found
)
pause
