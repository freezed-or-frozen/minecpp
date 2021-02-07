/**
 * Simple C++ class to communicate with Minetest/Minecraft server using API and socket
 * @author David SALLÉ
 * @date 02/08/2021 
 */

#include "minecraft.hpp"

int main() {
    Minecraft mc;
    mc.connect_to("127.0.0.1", 4711);
    mc.chat_post("Hello from minecpp !");
    return 0;
}
