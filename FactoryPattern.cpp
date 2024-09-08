// 工厂模式
// Created by scorpio-b on 9/8/24.
//


#include <iostream>
#include <memory>
#include <string>
#include <variant>

// 抽象基类: Shape
class Shape {
public:
    virtual ~Shape() = default;
    virtual void draw() const = 0; // 纯虚函数，子类必须实现
};

// 具体类: Circle
class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a Circle\n";
    }
};

// 具体类: Rectangle
class Rectangle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a Rectangle\n";
    }
};

// 工厂类: ShapeFactory
class ShapeFactory {
public:
    enum class ShapeType { Circle, Rectangle };

    // 工厂方法，返回 std::unique_ptr<Shape>
    static std::unique_ptr<Shape> createShape(ShapeType type) {
        switch (type) {
            case ShapeType::Circle:
                return std::make_unique<Circle>();
            case ShapeType::Rectangle:
                return std::make_unique<Rectangle>();
            default:
                return nullptr;
        }
    }
};

// 使用 C++20 的 std::variant 来存储不同的形状类型
using ShapeVariant = std::variant<Circle, Rectangle>;

int main() {
    // 使用工厂创建形状对象
    auto circle = ShapeFactory::createShape(ShapeFactory::ShapeType::Circle);
    auto rectangle = ShapeFactory::createShape(ShapeFactory::ShapeType::Rectangle);

    // 调用 draw() 方法
    if (circle) {
        circle->draw();
    }
    if (rectangle) {
        rectangle->draw();
    }

    // 使用 std::variant 处理不同的形状类型
    ShapeVariant shapeCircle = Circle{}; // 可以存储 Circle 或 Rectangle
    ShapeVariant shapeRectangle = Rectangle{};

    // 通过 std::visit 调用具体形状的 draw()
    std::visit([](auto &&shape) { shape.draw(); }, shapeCircle);
    std::visit([](auto &&shape) { shape.draw(); }, shapeRectangle);

    return 0;
}
