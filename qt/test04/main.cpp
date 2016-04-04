#include <QCoreApplication>
#include <iostream>
#include <cstdio>
#include <QDebug>
#include <vector>
#include <string>
using namespace std;

void test(int digit)
{
    vector<string> v {"one", "two", "three",
                       "four", "five", "six",
                        "seven", "eight", "nine"};

    for (int i=1; i<10; ++i) {
        if (digit==i) {
            cout << v[i];
        }
    }

    if (digit>9 && digit%2==0) {
        cout << "even";
    } else {
        cout << "odd";
    }
}

void test2(int d1, int d2)
{
    vector<string> v {"one", "two", "three",
                       "four", "five", "six",
                        "seven", "eight", "nine"};


    for (int i=d1; i<=d2; ++i){
        if (i<10) {
            cout << v[i-1] << endl;
            if (d1==d2) cout << v[i-1] << endl;
        } else {
            if (i%2==0) cout << "even" << endl;
            else cout << "odd" << endl;
        }

    }

}

int max_of_four(int a, int b, int c, int d)
{
    int array[4] = {a, b, c, d};
    int max = array[0];
    for (int i=1; i<4; ++i){
        if (array[i] > max) {
            max = array[i];
        }
    }

    return max;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int b;
    int c;
    cin >> b;
    cin >> c;
    //cout << b;
    //qDebug() << b;
    //qDebug() << c;

    //test2(b,c);
    qDebug() << max_of_four(3,5,1,33);
    return a.exec();
}
