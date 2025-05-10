#include <iostream>
#include <set>
#include <map>
using namespace std;
int main() {
    set<int> myset = {1, 2, 4, 5, 6};
    map<int, string> mymap = {{1, "one"}, {2, "two"}, {4, "four"}, {5, "five"}};

    auto it = myset.find(2);
    cout << (it == myset.end());



    // Set에서 lower_bound와 upper_bound 사용
    auto set_lower = myset.lower_bound(3);
    auto set_upper = myset.upper_bound(4);
    cout << "set lower_bound(3): " << *set_lower << "\n";
    cout << "set upper_bound(4): " << *set_upper << "\n";

    // Map에서 lower_bound와 upper_bound 사용
    auto map_lower = mymap.lower_bound(3);
    auto map_upper = mymap.upper_bound(4);
    if (map_lower != mymap.end()) {
        cout << "map lower_bound(3): " << map_lower->first << " -> " << map_lower->second << endl;
    }
    if (map_upper != mymap.end()) {
        cout << "map upper_bound(4): " << map_upper->first << " -> " << map_upper->second << endl;
    }

    return 0;
}
