#include <Application/Application.h>
#include <Utils/Config.h>

int main()
{
    srand(time(NULL));

    Application game("DuckHunt");

    game.mainLoop();

    return 0;
}