#include <bits/stdc++.h>
using namespace std;

struct student {
    string name;
    int korean;
    int english;
    int math;
};

bool cmp(student A, student B) {
    if (A.korean != B.korean) {
        return A.korean > B.korean;
    } else if (A.english != B.english) {
        return A.english < B.english;
    } else if (A.math != B.math) {
        return A.math > B.math;
    } else {
        return A.name < B.name;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    vector<student> students;

    for (int i=0; i<N; i++) {
        student person; 
        cin >> person.name >> person.korean >> person.english >> person.math;
        students.push_back(person);
    }

    sort(students.begin(), students.end(), cmp);

    for (auto it : students) {
        cout << it.name << "\n";
    }
}