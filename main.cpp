#include <aurora_engine.hpp>
#include <memory>

using namespace std;

int main () {
    AuroraEngine engine;
    engine.InitWindow();
    engine.InitUI()->withStyle();
    engine.Start();
    return 0;
}