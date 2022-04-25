#include"./library.cpp"
#include <SFML/Network/IpAddress.hpp>
#include <SFML/Network/TcpListener.hpp>
#include <SFML/Network/TcpSocket.hpp>
void connection(){
	sf::Packet packet;
	char ConnectionType;
	cout<<"Enter the character ('s' for Server and 'c' for client): ";
	cin>>ConnectionType;
	if(ConnectionType == 's' || ConnectionType == 'S'){
		//sf::IpAddress ip = sf::IpAddress::getLocalAddress(); //server is local host that is 127.0.0.1 which means only works in same computer in different terminal
		sf::TcpListener listener; //to listen port
		if (listener.listen(53000) != sf::Socket::Done)
		{
    			cout<<"Waiting for connection...";
		}

	// accept a new connection
		sf::TcpSocket client;
		if (listener.accept(client) != sf::Socket::Done)
		{
    			cout<<"Client connected!";
		}
		client.receive(packet);
		std::string s;
		packet>>s;
		cout<<s;
		s = "dkc";
		packet<<s;
		client.send(packet);
	}
	else if(ConnectionType == 'c'|| ConnectionType == 'C'){
		sf::IpAddress ipaddr;
		cout<<"Enter the server name or ip you want to connect: ";
		cin>>ipaddr;
		sf::TcpSocket socket;
		sf::Socket::Status status = socket.connect(ipaddr, 53000);
		if (status != sf::Socket::Done)
		{
		    cout<<"Connection failed";
		}
		std::string s = "hello";
		packet<<s;
		socket.send(packet);
		socket.receive(packet);
		packet>>s;
		cout<<s;
	}
}
