#include <iostream>
#include <vector>

// Base class
class SpaceObject {
public:
    virtual void draw() const {
        std::cout << "Drawing a generic space object.\n";
    }
    virtual ~SpaceObject() {}
};

// Derived classes
class Martian : public SpaceObject {
public:
    void draw() const override {
        std::cout << "Drawing a Martian with green antennas\n";
    }
};

class Venutian : public SpaceObject {
public:
    void draw() const override {
        std::cout << "Drawing a Venutian with a shiny, silver surface\n";
    }
};

class Plutonian : public SpaceObject {
public:
    void draw() const override {
        std::cout << "Drawing a Plutonian with a cold, blue glow.\n";
    }
};

class Spaceship : public SpaceObject {
public:
    void draw() const override {
        std::cout << "Drawing a Spaceship with sleek, aerodynamic wings.\n";
    }
};

class Laserbeam : public SpaceObject {
public:
    void draw() const override {
        std::cout << "Drawing a LaserBeam with a bright, red streak.\n";
    }
};

class Mercurian : public SpaceObject {
public:
    void draw() const override {
        std::cout << "Drawing a Mercurian with a swift, silver shadow.\n";
    }
};

class ScreenManager {
    std::vector<SpaceObject*> objects;

public:
    void addObject(SpaceObject* obj) {
        objects.push_back(obj);
    }

    void refreshScreen() {
        for (const auto& obj : objects) {
            obj->draw();
        }
    }
};


int main() {
    ScreenManager manager;
    manager.addObject(new Martian());
    manager.addObject(new Venutian());
    manager.addObject(new Plutonian());
    manager.addObject(new Spaceship());
    manager.addObject(new Laserbeam());
    manager.addObject(new Mercurian());

    manager.refreshScreen();

    return 0;
}
