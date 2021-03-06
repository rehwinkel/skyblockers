#pragma once

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

#include "../util/util.hpp"
#include "../resource/resource_manager.hpp"
#include "../gui/gui_handler.hpp"
#include "chunk.hpp"
#include "input_handler.hpp"

class World {
    private:
        std::vector<Chunk> chunks;
        std::unique_ptr<InputHandler> inputHandler;

        void loadChunkFiles();
        bool doesChunkExist(int x, int y);
        int toChunkPos(int blockPos);

    public:
        World(KeyboardHandler* keyboardHandler, GUIHandler* guiHandler);
        void saveAll();
        void setBlock(int x, int y, Blocks blockId);
        void renderChunks(sf::RenderWindow& window, ResourceManager& resourceManager);
};