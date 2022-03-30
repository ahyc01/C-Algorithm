#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

#define INF 1000000007

using namespace std;

struct info{
    int i;                          // index
    int d;                          // dist
    int s;                          // status
};

struct cmp{
    bool operator()(info &a, info &b){
        return a.d > b.d;
    }
};


unordered_map<int, int> t;          //t[노드번호] = 트랩의 순서
vector<info> v[1001][2];
int dist[1001][1024];

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    
    int a, b, s, d;
    int answer = 0;
    int flag;
    int cpush, npush;
    int nexta;
    int nextd;

    priority_queue<info, vector<info>, cmp> pq;
    
    for(int i = 0; i < traps.size(); i++)
        t[traps[i]] = i;                            

    for(int i = 0; i < roads.size(); i++){
        a = roads[i][0];
        b = roads[i][1];
        d = roads[i][2];
        v[a][0].push_back({b, d, 0});
        if((t.count(a) != 0) || (t.count(b) != 0))
            v[b][1].push_back({a, d, 0});
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < (1 << traps.size()); j++){
            dist[i][j] = INF;                           //dist[n]][j] = j의 폭탄 상태일때,. n까는 최단거리
        }
    }

    pq.push({start, 0, 0});
    dist[start][0] = 0;

    while(!pq.empty()){
        a = pq.top().i;
        d = pq.top().d;
        s = pq.top().s;
        pq.pop();
        if(a == end){
            answer = d;
            break;
        }
        cpush = 0;
        if((t.count(a) != 0) && (s & (1 << t[a])) > 0)           // 비트마스킹을 이용해서 현재 노드의 상태와 큐안에 있던 상태를 비교 
            cpush = 1;
        
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < v[a][i].size(); j++){
                nexta = v[a][i][j].i;
                nextd = v[a][i][j].d;
                npush = 0;
                if((t.count(nexta) != 0) && (s & (1 << t[nexta])) > 0)
                    npush = 1;
                flag = cpush ^ npush;                           // 지금 트랩상태와 다음노드 트랩상태를 (a,b)라고하면 (0, 0)이거나 (1, 1)이면  정방향 (0, 1), (1, 0)이면 역방향으로 이동해야함
                
                if(flag != i)
                    continue;
                
                if(dist[nexta][s] > d + nextd){
                    dist[nexta][s] = d + nextd;
                    if(t.count(nexta) != 0)
                        pq.push({nexta, d + nextd, s ^ (1 << t[nexta])});       // 다음 노드가 트랩일 경우 지금 상태에 다음 트랩의 상태를 더함
                    else
                        pq.push({nexta, d + nextd, s});
                }
            }
        }
    }

    return answer;

}

int main(){

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n = 4;
    int start = 1;
    int end = 4;
    vector<vector<int> > roads;
    vector<int> road(3);
    vector<int> traps;

    road[0] = 1;
    road[1] = 2;
    road[2] = 1;
    roads.push_back(road);
    road[0] = 3;
    road[1] = 2;
    road[2] = 1;
    roads.push_back(road);
    road[0] = 2;
    road[1] = 4;
    road[2] = 1;
    roads.push_back(road);
    traps.push_back(2);
    traps.push_back(3);

    cout << solution(n, start, end, roads, traps);

    return 0;
}
