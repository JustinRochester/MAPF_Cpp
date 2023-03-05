#include <iostream>
#include "MapReader.h"
using namespace std;

int main() {
    try {
        MapReader m;
        cout << "Hello, World!" << std::endl;
        m.load_scenario("random-32-32-20", "random", 1, 10);

        cout << m.get_height() << " " << m.get_width() << "\n";
        for (auto &e: m.get_maps()) {
            for (auto c: e)
                cout << c;
            cout << "\n";
        }

        vector<Position> start_positions = m.get_start_positions();
        vector<Position> goal_positions = m.get_goal_positions();
        for (int i = 0; i < 10; ++i)
            cout << start_positions[i] << " " << goal_positions[i] << "\n";
        return 0;
    }
    catch(const char *msg) {
        cerr<<msg<<"\n";
        exit(1);
    }
}
