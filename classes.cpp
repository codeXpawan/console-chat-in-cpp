#include"./library.cpp"
#include <SFML/Network/IpAddress.hpp>
#include <SFML/Network/Packet.hpp>
#include <SFML/Network/Socket.hpp>
#include <SFML/Network/TcpListener.hpp>
#include <SFML/Network/TcpSocket.hpp>

class Server{
	private:
		sf::TcpListener listener;
		sf::TcpSocket socket;
		sf::Packet packet;
		std::string message;
	public:
		Server(){
			listener.listen(55001);
			listener.accept(socket);
			cout<<"New client connected: "<<socket.getRemoteAddress()<<endl;
		}
		void Send(){
			cout<<"Enter the message: ";
			cin>>message;
			cout<<endl;
			packet<<message;
			socket.send(packet);
			packet.clear();
		}
		void Receive(){
			socket.receive(packet);
			packet>>message;
			cout<<"from "<<socket.getRemoteAddress()<<": "<<message<<endl;
			packet.clear();
		}
};
class Client{
	private:
		sf::IpAddress ipaddress;
		sf::TcpSocket socket;
		std::string message;
		sf::Packet packet;
	public:
		Client(){
			cout<<"Enter the ip address: ";
			cin>>ipaddress;
			socket.connect(ipaddress, 55001);
			cout<<"Connected to the server."<<endl;
		}
		void Send(){
			cout<<"Enter the message: ";
			getline(cin, message);
			cout<<endl;
			packet<<message;
			socket.send(packet);
			packet.clear();
		}
		void Receive(){
			socket.receive(packet);
			packet>>message;
			cout<<"from "<<socket.getRemoteAddress()<<": "<<message<<endl;
			packet.clear();
		}
};
