#include <string>
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>


struct Character{
	int x;
	int y;
	std::string name;
	Character (std::string _name) : name(_name) {}
	void move(int _x,int _y){
		x = _x;
		y = _y;
	}

};

//commmand pattern
class Command {
public:
	virtual ~Command() {}
	virtual void execute(Character &c) = 0; //pure virtual function -> must be implemented in the child classes
	virtual void undo(Character &c) = 0;
};


//Move is a Command
class Move : public Command {
public:
	void execute(Character &c) {
		int randomx = rand() % 4;
		int randomy = rand() % 4;
		c.move(randomx, randomy);
		x = randomx;
		y = randomy;
		std::cout << c.name << " moved" << x << "," << y << "\n";
	}

	void undo(Character &c) {
		c.move(-x,-y);
		std::cout << "undo" << -x << "," << -y << "\n";
	}
private:
	int x,y;

};

int main() {
	srand(time(NULL));
	Character saad("Saad");
	std::vector<Command*> commandQueue;
	Move* m1 = new Move();
	commandQueue.push_back(m1);
	Move* m2 = new Move();
	commandQueue.push_back(m2);
	Move* m3 = new Move();
	commandQueue.push_back(m3);
	Move* m4 = new Move();
	commandQueue.push_back(m4);
	for(int i =0; i < commandQueue.size(); i++) {
		commandQueue[i]->execute(saad);
	}

	for(int i = commandQueue.size() -1; i > -1; i--) {
		commandQueue[i]->undo(saad);
	}
	return 0;
}

