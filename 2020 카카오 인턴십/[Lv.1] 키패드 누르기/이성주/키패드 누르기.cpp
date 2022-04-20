#include <string>
#include <vector>

using namespace std;

int distance(int point, int hand_point){
    int distance = 0;
    
    distance = (abs(point-hand_point) / 3) + (abs(point-hand_point) % 3);

    return distance;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left = 10, right = 12;
    
    for(int i=0; i<numbers.size(); i++){
        if(numbers[i]==1 || numbers[i]==4 || numbers[i]==7){
            answer += "L";
            left = numbers[i];
        }
        else if(numbers[i]==3 || numbers[i]==6 || numbers[i]==9){
            answer += "R";
            right = numbers[i];
        }
        else{
            if(numbers[i]==0){
                numbers[i] = 11;
            }

            int distance_l = distance(numbers[i], left);
            int distance_r = distance(numbers[i], right);
            
            if(distance_l == distance_r && hand == "left"){
                answer += "L";
                left = numbers[i];
            }
            else if(distance_l == distance_r && hand == "right"){
                answer += "R";
                right = numbers[i];
            }
            else if(distance_l > distance_r){
                answer += "R";
                right = numbers[i];
            }
            else{
                answer += "L";
                left = numbers[i];
            }
        }
    }
    
    return answer;
}
