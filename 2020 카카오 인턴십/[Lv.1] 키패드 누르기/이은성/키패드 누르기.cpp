#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

int calcdist(pair<int, int> &a, pair<int, int> &b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    unordered_map<int, pair<int, int>> key={
        {1, {0, 0}},
        {2, {0, 1}},
        {3, {0, 2}},
        {4, {1, 0}},
        {5, {1, 1}},
        {6, {1, 2}},
        {7, {2, 0}},
        {8, {2, 1}},
        {9, {2, 2}},
        {0, {3, 1}},
    };
    pair<int, int> left, right;
    int dl, dr;
    left = {3, 0};
    right = {3, 2};
    for(auto i : numbers){
        if(i == 1 || i == 4 || i == 7){
            answer.append("L");
            left = key[i];
        }
        else if(i == 3 || i == 6 || i == 9){
            answer.append("R");
            right = key[i];
        }
        else{
            dl = calcdist(left, key[i]);
            dr = calcdist(right, key[i]);

            if(dl < dr){
                answer.append("L");
                left = key[i];
            }
            else if(dr < dl){
                answer.append("R");
                right = key[i];
            }
            else{
                if(hand == "left"){
                    answer.append("L");
                    left = key[i];
                }
                if(hand == "right"){
                    answer.append("R");
                    right = key[i];       
                }
            }
        }
    }

    return answer;
}

int main(){
    vector<int> numbers={1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5};
    string hand = "right";

    solution(numbers, hand);
}
