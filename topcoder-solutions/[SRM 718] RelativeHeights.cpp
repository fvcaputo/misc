#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

class RelativeHeights {
public:
    int countWays(vector<int> h) {
        set<vector<int> > uniqueHeightProfile;
        vector<int> idx(h.size()-1, 0); // array of indexes filled with 0, already considering one removed val
        for (int i = 0; i < idx.size(); ++i) {
            idx[i] = i;
        }

        for (int i = 0; i < h.size(); ++i) {
            vector<int> aux = h;
            vector<int> auxIdx = idx;
            aux.erase(aux.begin()+i);

            // Sort the array of indexes but using the actual data
            auto customComparator = [&](const int& a, const int& b) { return aux[a] > aux[b]; };
            sort(auxIdx.begin(), auxIdx.end(), customComparator );

            uniqueHeightProfile.insert(auxIdx);
        }

        return uniqueHeightProfile.size();
    }
};

int main(void) {
    RelativeHeights rh;
    vector<int> v = {4,2,1,3};
    cout << rh.countWays(v);
}
