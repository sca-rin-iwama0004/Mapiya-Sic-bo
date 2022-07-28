#include <iostream>
#include <random>
using namespace std;

void judgement();
int main() {

  int money = 100;
  int betmoney;
  int a;
  int b;
  int c;
  int d;
  int e;
  string y;
  string k;

  
  cout << "丁半では、偶数を丁、奇数を半と呼びます" << endl;
  cout << "振られた二つのサイコロの出目と、出目の和が丁か半かを予想して賭けてく"
          "ださい"
       << endl;
  cout << "出目が二つとも当たっていれば掛け金の2倍、";
  cout << "丁か半か当たっていれば掛け金の1倍が払い戻されます" << endl;

  while(money >= 0){
  cout << "あなたの所持金は" << money << "です" << endl;
  cout << "掛け金を入力してください" << endl;

  while (cin >> betmoney, money < betmoney) {
    cout << money << "以下にしてください" << endl;
  }

  cout << "1つめのサイコロの出目を予想してください" << endl;
  while (cin >> a, a < 0 || a > 6) {
    cout << "1以上6以下にしてください" << endl;
  }
  cout << "2つめのサイコロの出目を予想してください" << endl;
  while (cin >> b, b < 0 || b > 6) {
    cout << "1以上6以下にしてください" << endl;
  }

  if ((a + b) % 2 == 0) {
    y = "丁";
  } else {
    y = "半";
  }
  cout << "あなたの予想は" << a << "と" << b << "の" << y << "です" << endl;

  random_device rnd;
  random_device rnd2;

  c = rnd() % 6 + 1;
  d = rnd2() % 6 + 1;

  if ((c + d) % 2 == 0) {
    k = "丁";
  } else {
    k = "半";
  }
  cout << "結果は" << c << "と" << d << "の" << k << "です" << endl;

  if (a == c && b == d) {
    judgement();
    money += betmoney * 2;
  } else if (a == d && b == c) {
    judgement();
    money += betmoney * 2;
  } else {
    if (y == k) {
      cout << "やりましたね！丁か半かがあってます" << endl;
      money += betmoney;
    } else {
      cout << "残念でした！" << endl;
      money -= betmoney;
    }
  }
    
    cout << "終わりますか？1で終わる、2で続ける" << endl;
    cin >> e;
    if(e == 1){
      break;
    }
  }
  cout << "あなたの所持金は" << money << "でした！" <<endl;
}
void judgement() {
  cout << "おめでとうございます！出目がどちらもあってます" << endl;
}
