#include"./library.cpp"
#include"./tcpconnection.cpp"
#include <SFML/Network/Packet.hpp>
#include <SFML/Network/Socket.hpp>

void data(){
	std::string s = "hello";
	sf::Packet packet;
	packet<<s;
	sf::Socket.sen
}
