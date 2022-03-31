#include <iostream>
#include <string>

//lets us use inheritance based poly

class IGameObject {
public:
	virtual ~IGameObject() {}
	virtual void Update() = 0;
	virtual void Render() = 0;
};

class Plane : public IGameObject {
public: 
	Plane() {}
	void Update() {}
	void Render() {}
};

class Boat : public IGameObject {
public:
	Boat() {}
	void Update() {}
	void Render() {}
};

IGameObject* MakeGameObjectFactory(std::string type) {
       if(type =="plane") {
	       return new Plane;
       } else if(type == "boat") {
	       return new Boat;
       }
       return nullptr;
}
int main() {
//	Boat boat;
//	Plane plane;
	IGameObject* myObj = MakeGameObjectFactory("plane");
	return 0;
}
