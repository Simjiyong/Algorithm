#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    string str;
    int n;
    bool check = true;
    for (int i = 0; i < skill_trees.size(); i++) {
        str = skill_trees[i];
        int n = 0;
        check = true;
        for (int j = 0; j < str.size(); j++) {
            for (int k = 0; k < skill.size(); k++) {
                if (str[j] == skill[k] && n >= k) {
                    n++;
                    break;
                }
                else if (str[j] == skill[k]) {
                    check = false;
                    break;
                }
            }
            if (!check)
                break;
        }
        if (check)
            answer++;
    }
    return answer;
}