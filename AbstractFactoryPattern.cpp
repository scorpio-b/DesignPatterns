//
// Created by scorpio-b on 9/8/24.
//

#include <iostream>
#include <memory>

// 抽象产品: Button
class Button {
public:
    virtual ~Button() = default;
    virtual void paint() const = 0;
};

// 具体产品: Windows Button
class WindowsButton : public Button {
public:
    void paint() const override {
        std::cout << "Rendering a Windows Button\n";
    }
};

// 具体产品: Mac Button
class MacButton : public Button {
public:
    void paint() const override {
        std::cout << "Rendering a Mac Button\n";
    }
};

// 抽象产品: Checkbox
class Checkbox {
public:
    virtual ~Checkbox() = default;
    virtual void paint() const = 0;
};

// 具体产品: Windows Checkbox
class WindowsCheckbox : public Checkbox {
public:
    void paint() const override {
        std::cout << "Rendering a Windows Checkbox\n";
    }
};

// 具体产品: Mac Checkbox
class MacCheckbox : public Checkbox {
public:
    void paint() const override {
        std::cout << "Rendering a Mac Checkbox\n";
    }
};

// 抽象工厂: GUIFactory
class GUIFactory {
public:
    virtual ~GUIFactory() = default;
    virtual std::unique_ptr<Button> createButton() const = 0;
    virtual std::unique_ptr<Checkbox> createCheckbox() const = 0;
};

// 具体工厂: WindowsFactory
class WindowsFactory : public GUIFactory {
public:
    std::unique_ptr<Button> createButton() const override {
        return std::make_unique<WindowsButton>();
    }
    std::unique_ptr<Checkbox> createCheckbox() const override {
        return std::make_unique<WindowsCheckbox>();
    }
};

// 具体工厂: MacFactory
class MacFactory : public GUIFactory {
public:
    std::unique_ptr<Button> createButton() const override {
        return std::make_unique<MacButton>();
    }
    std::unique_ptr<Checkbox> createCheckbox() const override {
        return std::make_unique<MacCheckbox>();
    }
};

// 客户端代码
void clientCode(const GUIFactory& factory) {
    auto button = factory.createButton();
    auto checkbox = factory.createCheckbox();
    button->paint();
    checkbox->paint();
}

int main() {
    // 客户端选择使用 Windows 工厂或 Mac 工厂
    std::unique_ptr<GUIFactory> factory;

    // Windows 环境下
    factory = std::make_unique<WindowsFactory>();
    std::cout << "Client: Testing Windows GUI Factory:\n";
    clientCode(*factory);

    std::cout << "\n";

    // Mac 环境下
    factory = std::make_unique<MacFactory>();
    std::cout << "Client: Testing Mac GUI Factory:\n";
    clientCode(*factory);

    return 0;
}
