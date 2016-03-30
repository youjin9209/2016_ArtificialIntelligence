#include <stdio.h>

int n; //정점의 총 개수
int map[30][30], visit[30]; // map[][]: 인접 행렬 visit[] : 방문 여부 배열


void DFS(int v)
{
    int i;
    
    visit[v] = 1; //정점 v를 방문했다고 표시
    for(i=1; i<=n; i++)
    {
        if (map[v][i] == 1 && !visit[i]) //정점 v 와 정점 i가 연결되었고, 정점i를 방문하지 않았다면
        {
            printf("(%d, %d)\n", v, i); //v에서 i로 이동
            DFS(i); //i에서 시작
        }
    }
}
//8 1
//1 2 1 3 2 4 2 5 4 8 5 8 3 6 3 7 6 8 7 8 -1 -1

int main()
{
    int start; //시작 정점
    int v1, v2;
    FILE *fp = NULL;
    
    fp = fopen("/Users/scarlett/Documents/input/graph2.txt", "r");
    
    fscanf(fp, "%d %d", &n, &start);
    
    //인접행렬 map[][]
    while (1)
    {
        fscanf(fp, "%d %d", &v1, &v2);
        if (v1 == -1 && v2 == -1)
            break;
        map[v1][v2] = map[v2][v1] = 1; //정점 v1과 정점 v2가 연결되었다고 인접행렬에 표시
    }
    
    DFS(start);
    fclose(fp);
    return 0;
}