// 构造器模式
// Created by scorpio-b on 9/6/24.
//

#include <iostream>
#include <string>
#include <optional>

// House类，表示要构建的对象
class House {
public:
    // 设置各种属性
    void setWalls(const std::string& walls) { this->walls = walls; }
    void setDoors(const std::string& doors) { this->doors = doors; }
    void setWindows(const std::string& windows) { this->windows = windows; }
    void setRoof(const std::string& roof) { this->roof = roof; }

    // 展示房屋信息
    void show() const {
        std::cout << "House with " << walls << ", " << doors << " doors, "
                  << windows << " windows and " << roof << " roof." << std::endl;
    }

private:
    std::string walls;
    std::string doors;
    std::string windows;
    std::string roof;
};

// HouseBuilder类，定义构建房屋的步骤
class HouseBuilder {
public:
    HouseBuilder& setWalls(const std::string& walls) {
        house.setWalls(walls);
        return *this;
    }

    HouseBuilder& setDoors(const std::string& doors) {
        house.setDoors(doors);
        return *this;
    }

    HouseBuilder& setWindows(const std::string& windows) {
        house.setWindows(windows);
        return *this;
    }

    HouseBuilder& setRoof(const std::string& roof) {
        house.setRoof(roof);
        return *this;
    }

    // 返回构建好的对象
    House build() { return house; }

private:
    House house;
};

// Director类，可选，负责使用HouseBuilder构建复杂对象
class Director {
public:
    // 构建一个简单的房屋
    House createSimpleHouse(HouseBuilder& builder) {
        return builder.setWalls("Wooden walls")
                      .setDoors("2")
                      .setWindows("4")
                      .setRoof("Tile roof")
                      .build();
    }

    // 构建一个豪华的房屋
    House createLuxuryHouse(HouseBuilder& builder) {
        return builder.setWalls("Brick walls")
                      .setDoors("4")
                      .setWindows("10")
                      .setRoof("Glass roof")
                      .build();
    }
};

int main() {
    // 创建一个构造器对象
    HouseBuilder builder;

    // 创建Director对象，用来管理复杂对象的创建
    Director director;

    // 构建简单的房屋
    House simpleHouse = director.createSimpleHouse(builder);
    simpleHouse.show();

    // 构建豪华的房屋
    House luxuryHouse = director.createLuxuryHouse(builder);
    luxuryHouse.show();

    return 0;
}
