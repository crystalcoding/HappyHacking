#ifndef BCDGUI_H
#define BCDGUI_H

#include <QMainWindow>
#include <vector>
#include <string>
#include <bitset>
#include <algorithm>
#include <QDebug>

using namespace std;

namespace Ui {
class BCDGUI;
}

class BCDGUI : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit BCDGUI(QWidget *parent = 0);
    ~BCDGUI();
    
private slots:
    void on_dec_edit1_textEdited(const QString &arg1);

    void on_dec_edit2_textEdited(const QString &arg1);

private:
    Ui::BCDGUI *ui;
    string input_1, intput_2;
    vector<int> v1;
    vector<int> v2;
    vector<int>::iterator it1;
    vector<int>::iterator it2;
    vector<bitset<4>> vb1;
    vector<bitset<4>> vb2;

    vector<int> get_sum();
    vector<int> carry_sum();

    QString get_bcd(vector<int>);
    QString get_bcd(string s);
};

#endif // BCDGUI_H
