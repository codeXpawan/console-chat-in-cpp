#include"./tcpconnection.cpp"
#include"./classes.cpp"

int main(){
	//connection();
	char connectiontype;
	cout<<"'s' for server and 'c' for client: ";
	cin>>connectiontype;
	if(connectiontype == 's' || connectiontype == 'S'){
		Server server;
		while(true){
			sf::Thread sen(&Server::Send, &server);
			sf::Thread rec(&Server::Receive, &server);
			sen.launch();
			rec.launch();
		}

	}
	else if(connectiontype == 'c' || connectiontype == 'C'){
		Client client;
		while(true){
			sf::Thread rec(&Client::Receive, &client);
			sf::Thread sen(&Client::Send, &client);
			rec.launch();
			sen.launch();
		}
	}
	else{
		cout<<"Wrong input.";
		main();
	}
	return 0;
}
