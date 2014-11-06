#include "bcdgui.h"
#include "ui_bcdgui.h"

BCDGUI::BCDGUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BCDGUI)
{
    ui->setupUi(this);
    v1.push_back(0);
    v2.push_back(0);
}

BCDGUI::~BCDGUI()
{
    delete ui;
}

QString BCDGUI::get_bcd(vector<int> v)
{
    string ret;
    for (auto i: v){
        ret += bitset<4>(i).to_string();
        ret += " ";
    }
    return QString(ret.c_str());
}

QString BCDGUI::get_bcd(string s)
{
    string ret;
    for (auto i: s) {
        string ss(1, i);
        ret += bitset<4>(stoi(ss)).to_string();
        ret += " ";
    }
    return QString(ret.c_str());
}

vector<int> BCDGUI::get_sum()
{
    vector<int> sum;

    vector<int> v11 = v1;
    vector<int> v22 = v2;

    reverse(v11.begin(), v11.end());
    reverse(v22.begin(), v22.end());
    it1 = v11.begin();
    it2 = v22.begin();

    if (v11.empty()){
        it1 = v11.end();
    }
    if (v22.empty()){
        it2 = v22.end();
    }

    while(true){
        int first = 0;
        int second = 0;

        if (it1 != v11.end()){
            first = *it1;
            ++it1;
        }

        if (it2 != v22.end()){
            second = *it2;
            ++it2;
        }

        sum.push_back(first+second);
        if (it1 == v11.end() && it2 ==v22.end()){
            break;
        }
    }

    reverse(sum.begin(),  sum.end());
    qDebug() << "sum is: ";
    for (auto i: sum){
        qDebug() << i;
    }
    return sum;
}

vector<int> BCDGUI::carry_sum()
{
    vector<int> sum = get_sum();
    reverse(sum.begin(), sum.end());
    vector<int> new_sum;
    bool carry = false;

    for (auto i: sum){
        if (carry) {
          i = i + 1;
        }
        if (i > 9){
          i = i - 10;
          carry = true;
        } else {
          carry = false;
        }
        new_sum.push_back(i);
      }

      if (carry){
        //vector<int>::iterator it = new_sum.begin();
        //new_sum.insert(it, 1);
          new_sum.push_back(1);
      }

      reverse(new_sum.begin(), new_sum.end());
      return new_sum;
}

void BCDGUI::on_dec_edit1_textEdited(const QString &arg1)
{
    qDebug() << arg1;
    v1.clear();
    for (auto s: arg1) {
        string ss(QString(s).toStdString());
        v1.push_back(stoi(ss));
    }

    vector<int> sum = carry_sum();
    string answer;
    for(auto i: sum){
        answer += QString::number(i).toStdString();
    }
    qDebug() << answer.c_str();
    ui->dec_sum->setText(answer.c_str());

    ui->bcd1->setText(get_bcd(v1));
    ui->bcd_sum->setText(get_bcd(answer));
}

void BCDGUI::on_dec_edit2_textEdited(const QString &arg1)
{
    qDebug() << arg1;
    v2.clear();
    for (auto s: arg1) {
        string ss(QString(s).toStdString());
        v2.push_back(stoi(ss));
    }

    vector<int> sum = carry_sum();
    string answer;
    for(auto i: sum){
        answer += QString::number(i).toStdString();
    }
    qDebug() << answer.c_str();
    ui->dec_sum->setText(answer.c_str());

    ui->bcd2->setText(get_bcd(v2));
    ui->bcd_sum->setText(get_bcd(answer));
}
