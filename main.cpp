#include <memory>
#include "../src/Main.h"
#include "../src/simple/Triangle.h"

int main() {

    std::unique_ptr<Main> main = std::make_unique<Triangle>();
    main->createWindow(600, 600, "test");
    main->draw();
    return 0;
}
