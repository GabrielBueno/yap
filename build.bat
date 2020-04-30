@Echo off
SETLOCAL

SET CC=gcc
SET IPATH=./include
SET LPATH=./lib
SET SRC=./src/color.c ./src/game_object.c ./src/player.c ./src/screen.c ./src/game.c ./src/main.c
SET OUT=./bin/yap-win.exe
SET FLAGS=-Wall -Wextra -Wno-unused-variable -Wno-unused-parameter
SET LINKER_FLAGS=-lmingw32 -lSDL2main -lSDL2

@Echo on

%CC% -I%IPATH% -L%LPATH% -o %OUT% %SRC% %FLAGS% %LINKER_FLAGS%

@Echo off

ENDLOCAL