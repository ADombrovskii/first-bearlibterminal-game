#include <BearLibTerminal.h>
#include <string>

class Room
{
public:
    std::string map[5] = {"*****",
                          "*   *",
                          "*   *",
                          "*   *",
                          "*****"
    };
    /*void print_map()
    {
        for (int i = 0; i < 5; i++) {
            terminal_print(0, i, map[i])
        }
    }*/
};

class Player
{
private:
    bool collision(Room room)
    {
        if (room.map[1][2] != ' ')
        {
            return true;
        }
        else
        {
            return false;
        }
    }

public:
    int x;
    int y;

    Player(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

int main()
{
    terminal_open();

    // Выводим текст
    // terminal_printf(1, 1, "Hello, world!   β   √ Привет мир  Ш");

    Player player(0, 0);

    terminal_print(player.x, player.y, "@");

    terminal_refresh();

    terminal_clear();

    // Ждем, пока пользователь не закроет окно
    while (terminal_read() != TK_CLOSE);

    terminal_close();
}