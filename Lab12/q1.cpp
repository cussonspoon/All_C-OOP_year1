#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

class Pokemon
{
private:
    std::string name;
    std::string sound;
    std::string type;
    int power;
    int speed;

public:
    Pokemon(std::string n, std::string s, std::string t, int p, int spd) : name(n), sound(s), type(t), power(p), speed(spd) {}

    std::string getName() const
    {
        return name;
    }

    std::string getSound() const
    {
        return sound;
    }

    std::string getType() const
    {
        return type;
    }

    int getPower() const
    {
        return power;
    }

    int getSpeed() const
    {
        return speed;
    }
};

class WildPokemon : public Pokemon
{
private:
    int catchRate;

public:
    WildPokemon(int cr, std::string n, std::string s, std::string t, int p, int spd)
        : Pokemon(n, s, t, p, spd), catchRate(cr) {}

    int getcatchRate() const
    {
        return catchRate;
    }
    void attemptEscape()
    {
        std::cout << "Escaping"
                  << "\n";
    }
};

class PalPokemon : public Pokemon
{
public:
    PalPokemon(const std::string &n, const std::string &s, const std::string &t, int p, int spd)
        : Pokemon(n, s, t, p, spd)
    {
    }
};

class Pokeball
{
private:
    std::string name;
    int efficiency;

public:
    Pokeball(std::string n, int eff) : name(n), efficiency(eff) {}
    std::string getname()
    const {
        return name;
    }
    int geteff() const
    {
        return efficiency;
    }
    void catchPokemon(const WildPokemon &pokemon)
    {
        if (efficiency >= pokemon.getcatchRate())
        {
            std::cout << "Caught!!"
                      << "\n";
        }
    }
};

class Berry
{
private:
    std::string name;
    int effectiveness;

public:
    Berry(std::string n = "", int eff = 0) : name(n), effectiveness(eff) {}
    std::string getname() const
    {
        return name;
    }
    int geteff() const
    {
        return effectiveness;
    }
};

class World
{
private:
    std::vector<WildPokemon> encounter;

public:
    void addWildPokemon(const WildPokemon &pokemon)
    {
        encounter.push_back(pokemon);
    }
    WildPokemon getrandomEncounter() const
    {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        int randomIndex = std::rand() % encounter.size();
        return encounter[randomIndex];
    }
};
class Player
{
private:
    std::vector<Pokeball> pokeball_inventory;
    std::vector<Berry> berry_bag;
    std::vector<PalPokemon> pokemon_inventory;

public:
    Player(std::vector<Pokeball> inv = {}, std::vector<Berry> ber = {}, std::vector<PalPokemon> bag = {}) : pokeball_inventory(inv), berry_bag(ber), pokemon_inventory(bag) {}
    void addPokeball()
    {
        for (int i = 0; i < 5; ++i)
        {
            int type = rand() % 2 + 1;
            int effectiveness = (type == 1) ? 70 : 30;
            std::string name = (type == 1) ? "Ultra" : "Normal";
            Pokeball ball(name, effectiveness);
            pokeball_inventory.push_back(ball);
        }
        std::cout << "5 Balls added"
                  << "\n";
    }
    void catchPokemon(const WildPokemon &pokemon, const Pokeball pokeball, const Berry &berry = Berry(""))
    {
        if (pokeball.geteff() + berry.geteff() >= pokemon.getcatchRate())
        {
            std::cout << "Caught!!"
                      << "\n";
            PalPokemon newPokemon(
                pokemon.getName(),
                pokemon.getSound(),
                pokemon.getType(),
                pokemon.getPower(),
                pokemon.getSpeed());
            pokemon_inventory.push_back(newPokemon);
        }
        else
        {
            std::cout << "The pokemon has run away!"
                      << "\n";
        }
    }
void Walk(const World& world)  {
    bool encounter = (rand() % 2 == 0);
    if (encounter) {
        WildPokemon wildPokemon = world.getrandomEncounter();
        std::cout << "A wild " << wildPokemon.getName() << " appears!\n";
        std::cout << wildPokemon.getSound() << "\n";
        int choice_catch;
        while (true) {
            std::cout << "Do you want to catch it (1. Yes / 2. No): ";
            std::cin >> choice_catch;
            if (choice_catch == 1) {
                int choice_ball;
                int index = 1;
                std::cout << "Available Pokeballs:\n";
                for (auto it = pokeball_inventory.begin(); it != pokeball_inventory.end(); ++it) {
                    std::cout << index << ". " << it->getname() << " Pokeball (Efficiency: " << it->geteff() << ")\n";
                    index++;
                }
                std::cout << "Which ball do you want to use? ";
                std::cin >> choice_ball;
                if (choice_ball > 0 && choice_ball <= pokeball_inventory.size()) {
                    if (pokeball_inventory[choice_ball - 1].geteff() >= wildPokemon.getcatchRate()) {
                        std::cout << "Caught!!\n";
                        PalPokemon newPokemon(
                            wildPokemon.getName(),
                            wildPokemon.getSound(),
                            wildPokemon.getType(),
                            wildPokemon.getPower(),
                            wildPokemon.getSpeed());
                        pokemon_inventory.push_back(newPokemon);
                    } else {
                        std::cout << "The Pokemon broke free!\n";
                    }
                    pokeball_inventory.erase(pokeball_inventory.begin() + choice_ball - 1);
                    break;
                } else {
                    std::cout << "Invalid Pokeball choice.\n";
                }
            } else if (choice_catch == 2) {
                std::cout << "You decided not to catch it.\n";
                break;
            } else {
                std::cout << "Invalid input.\n";
            }
        }
    } else {
        std::cout << "You didn't encounter any wild Pokemon during your walk.\n";
    }
}

    std::vector<Pokeball> getBallInven(){
        return pokeball_inventory;
    }
    std::vector<PalPokemon> getPokemonInven(){
        return pokemon_inventory;
    }
};




class GameTester
{
public:
    static void testCatchPokemon(Player &player, const WildPokemon &pokemon, const Pokeball &pokeball, const Berry &berry = Berry(""))
    {
        player.catchPokemon(pokemon, pokeball, berry);
    }

    static void testPlayerWorldInteraction(Player &player, const World &world)
    {
        player.Walk(world);
    }
};

int main()
{
    Player player1;
    World world;
    world.addWildPokemon(WildPokemon(50, "Pikachu", "Pika!!", "Electric", 100, 80));
    world.addWildPokemon(WildPokemon(40, "Charmander", "Charrr!", "Fire", 90, 70));
    world.addWildPokemon(WildPokemon(45, "Bulbasaur", "Bulba?", "Grass", 95, 75));
    world.addWildPokemon(WildPokemon(55, "Squirtle", "*Sqirt*", "Water", 85, 65));
    while (true)
    {
        int choice;
        std::cout << "Choose an action:\n1. Add Pokeballs to stock\n2. Walk\n3. List Pokeballs\n4. List caught Pokemon\n5. Exit";
        std::cin >> choice;
        if (choice == 1)
        {
            player1.addPokeball();
        }
        else if (choice == 2)
        {
            player1.Walk(world);
        }
        else if (choice == 3)
        {
            int index = 1;
            for (const Pokeball& ball : player1.getBallInven()) {
                std::cout << index << ". " << ball.getname() << " Pokeball (Efficiency: " << ball.geteff() << ")\n";
                index++;
            }
        }
        else if (choice == 4)
        {
            for (PalPokemon pokemon : player1.getPokemonInven()){
                std::cout << pokemon.getName() << "\n";
            }
        }
        else if (choice == 5)
        {
            std::cout << "Exiting game. . ."
                      << "\n";
            break;
        }
        else
        {
            std::cout << "Invalid input"
                      << "\n";
        }
    }
}
