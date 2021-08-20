#include 
#include 
using namespace std;
 
 
// 既にその頂点を使っているかどうか管理する配列
vector used;
 
// 接続状況を格納する配列
vector connect;
 
int N, M;
 
// パスを全探索する関数
// now: 今見ている頂点
// depth: 今まで列挙した頂点数
 
int dfs(int now, int depth) {
    // 使用済みであれば return
    if (used[now]) return 0;
 
    // depthがNなら有効なパスなので、1 を返す
    if (depth == N) return 1;
 
    // 使用済みフラグを立てる
    used[now] = 1;
 
    int ans = 0;
 
    // 全部の遷移先をチェックする
    for (int i = 0; i < N; i++)
    {
        //nowから繋がっている頂点であれば、遷移を試す
        if (connect[now][i]) ans += dfs(i, depth + 1);
    }
 
    // 使用済みフラグを折る
    used[now] = 0;
 
    return ans;
}
 
int main() {
    // 入力を受け取る
    cin >> N >> M;
    vector a(M), b(M);
    for (int i = 0; i < M; i++)
    {
        cin >> a[i] >> b[i];
        // 1から始まると使いづらいので、1引いた値を格納する
        a[i]--; b[i]--;
    }
 
    // 配列の初期化
    used = vector(N, 0);
    connect = vector(N, vector(N, 0));
 
    for (int i = 0; i < M; i++)
    {
        // 配列に反映させる
        connect[a[i]][b[i]] = connect[b[i]][a[i]] = 1;
    }
 
    // 0番から始まるパスの種類を列挙し、出力する
    cout << dfs(0, 1) << endl;
}