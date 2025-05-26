#include <vector>
#include <string>
#include <memory>
#include <functional>
#include "IGame.h"

class GameRegistry {
public:
    using GameFactory = std::function<std::unique_ptr<IGame>()>;

    static void registerGame(const std::string& name, GameFactory factory) {
        getRegistry().emplace_back(name, std::move(factory));
    }

    static const std::vector<std::pair<std::string, GameFactory>>& getGames() {
        return getRegistry();
    }

private:
    static std::vector<std::pair<std::string, GameFactory>>& getRegistry() {
        static std::vector<std::pair<std::string, GameFactory>> registry;
        return registry;
    }
};
