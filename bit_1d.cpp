#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll n, x;
string s;

ll character[100005], BIT[100005];

ll get_sum(ll index) {
  ll sum = 0;

  while (index > 0) {
    sum += BIT[index];
    index -= index & (-index);
  }

  cout << sum << '\n';
}

void update(int index, int val) {
  index = index + 1;

  while (index <= n) {
    BIT[index] += val;
    index += index & (-index);
  }
}

void new_BIT() {
  for (int i = 1; i <= n; i++)
    BIT[i] = 0;

  for (int i = 0; i < n; i++)
    update(i, character[i]);
}

main() {
  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> character[i];

  new_BIT();

  while (cin >> s >> x) {
    --x;

    if (s == 'a')
      update(x, -character[x]);
    else
      get_sum(x);
  }
}
