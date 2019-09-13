//UnionFind
class UnionFind {
public:
  //親の番号を格納する。親だった場合は-(その集合のサイズ)
  vector<int> Parent;

  UnionFind(int N) {
    Parent = vector<int>(N, -1);
  }

  //Aがどのグループに属しているか調べる
  int root(int A) {
    if (Parent[A] < 0) return A;
    return Parent[A] = root(Parent[A]);
  }

  //自分のいるグループの頂点数を調べる
  int size(int A) {
    return -Parent[root(A)];
  }

  //AとBをくっ付ける
  bool connect(int A, int B) {
    
    A = root(A);
    B = root(B);
    if (A == B) {
      
      return false;
    }
    if (size(A) < size(B)) swap(A, B);
    
    Parent[A] += Parent[B];
    Parent[B] = A;

    return true;
  }
};
