/**
 * Simple C++ class to communicate with Minetest/Minecraft server using API and socket
 * @author David SALLÉ
 * @date 02/08/2021 
 */

#include "minecraft.hpp"


Minecraft::Minecraft() {
    // Socket creation for TCP
	m_sd = socket(AF_INET, SOCK_STREAM, 0);
}



Minecraft::~Minecraft() {
    // Socket close
    close(m_sd);
}


void Minecraft::connect_to(string ip_address, unsigned short tcp_port) {
	// Socket configuration
	m_address.sin_family = AF_INET;
	m_address.sin_port = htons(tcp_port);
	m_address.sin_addr.s_addr = inet_addr(ip_address.c_str());

	// Socket connexion
	connect(m_sd, (struct sockaddr *)&m_address, sizeof(struct sockaddr));
}


void Minecraft::send_command(string command) {
    // Send command to server with socket
    send(m_sd, command.c_str(), command.length(), 0);
}


string Minecraft::read_answer() {
    return "";
}


void Minecraft::chat_post(string message) {
    ostringstream request;
    request << "chat.post(" << message << ")\n";
    send_command(request.str());    
}

