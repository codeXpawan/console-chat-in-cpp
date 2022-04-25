//program to talk with another person from local network using sfml(simple and fast multimedia library)
#include <SFML/Network/IpAddress.hpp>
#include <SFML/Network/TcpListener.hpp>
#include <cstddef>
#include<iostream>
#include"./SFML/include/SFML/Network.hpp"
#include"./SFML/include/SFML/System.hpp"
using namespace std;

int main(){
	sf::IpAddress ip = sf::IpAddress::getLocalAddress();
	sf::TcpSocket socket;
	sf::Packet data;
	char buffer[2000];
	size_t received;
	string text = "Connected to: ";
	char connectionType, mode, ans = 'n';

	cout<<"Enter the connection type(s for server and c for client): ";
	cin>>connectionType;
	/*void receiveMsg(){
		socket.receive(buffer, sizeof(buffer),received);
		cout<<buffer<<endl;
	}*/

	if(connectionType == 's'){
		sf::TcpListener listner;
		listner.listen(2000);
		listner.accept(socket);
		text += "Server";
		data<<text;
		tcpSocket.send(data);
		tcpSocket.receive(data);
		data>>text;
		cout<<endl;
		while(ans != 'y'){
			//sf::Thread thread;
			//thread.launch();
			cout<<"Enter the message:";
			cin>>text;
			data<<text;
			//sf::Thread thread(sf::Socket(socket.send,text.c_str(),text.length()+1));
			socket.send(data);
			//thread.launch();
			socket.receive(data);
			data>>text;
			cout<<endl;
			cout<<"Do you want to end the chat(y/n): ";
			cin>>ans;
		}
	}
	else if(connectionType == 'c'){
		socket.connect(ip, 2000);
		text += "Client";
		data<<text;
		socket.send(data);
		socket.receive(data);
		data>>text;
		cout<<endl;
		while(ans != 'y'){
			//sf::Thread thread(&receiveMsg);
			//thread.launch();
			cout<<"Enter the message:";
			cin>>text;
			data<<text;
			socket.send(data);
			socket.receive(data);
			data>>text;
			cout<<endl;
			cout<<"Do you want to end the chat(y/n): ";
			cin>>ans;
		}
	}
	//socket.send(text.c_str(),text.length()+1);
	//socket.receive(buffer, sizeof(buffer),received);
	//cout<<buffer<<endl;
	system("pause");
	return 0;
}
