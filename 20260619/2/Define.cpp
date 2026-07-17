struct Define
{
    static const int SIZE = 100;
    static const int MAX = 10000;
    static const int MIN = 1000;
    static const int current = 1;
};
// static(変数・定数)は、他のブロックからでも参照できるようにする
// constで定数化したものをこのファイルに集めることで、あっちはint main()から始めることができる
// Difine 定数