#include <iostream>
#include <vector>
#include <string>

using namespace std;

int hashFun(int size, long key);
void insert();

int main()
{
    insert();
}

int hashFun(int size, long key) {
    int index;
    index = key % size;
    return index;
};

void insert() {
    vector<vector<pair<long, string>>> tab;
    
    string command, data;
    long key;
    int cases;

    cin >> cases;

    for (int i = 0; i < cases; i++) {
        tab.clear();
        while (true) {
            cin >> command;
            if (command == "size") {
                cin >> key;
                tab.resize(key);
            }
            else if (command == "add") {
                cin >> key;
                cin >> data;

                long tmp = key;
                bool check = false;

                while (!check) {
                    int index = hashFun(tab.size(), tmp);

                    if (!tab[index].empty()) {
                        tmp++;
                    }
                    else {
                        tab[index].push_back(make_pair(key, data));
                        check = true;
                    }
                }
            }
            else if (command == "print") {
                cout << endl;
                for (int i = 0; i < tab.size(); i++) {
                    if (!tab[i].empty()) {
                        cout << i << " " << tab[i][0].first << " " << tab[i][0].second << endl;
                    }
                }
                cout << endl;
            }
            else if (command == "delete") {
                cin >> key;

                bool check = false;
                int tmp = key;

                while (!check) {
                    int index = hashFun(tab.size(), key);

                    if (key == tab[index][0].first) {
                        tab[index].clear();
                        check = true;
                    }
                    else {
                        tmp++;
                    }
                }
            }
            else if (command == "stop") {
                break;
            }
        }

    }
};
