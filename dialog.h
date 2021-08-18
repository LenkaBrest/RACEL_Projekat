#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTimer>
#include "dht11.h"
#include "wardrobe.h"



enum temperature{winter=0, spring, summer, hot};
enum humidity{low, medium, high};


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    enum temperature t;
    enum humidity h;
    int sex;
    int style;
    QPixmap blouse;
        QPixmap shoes_m_s;
        QPixmap shoes_w_s;
        QPixmap boots_m;
        QPixmap shoes_m_j;
        QPixmap shoes_w;
        QPixmap long_sleeve_m;
        QPixmap long_sleeve_w;
        QPixmap hoody;
        QPixmap hoody2;
        QPixmap cardigan;
        QPixmap texas_jacket_m;
        QPixmap texas_jacket_w;
        QPixmap rain_boots;
        QPixmap polo;
        QPixmap heels;
        QPixmap skirt;
        QPixmap sneakers_m;
        QPixmap pullover_m;
        QPixmap pullover_w;
        QPixmap dress;
        QPixmap everyday_dress;
        QPixmap dress_s;
        QPixmap hawaii;
        QPixmap japan;
        QPixmap coat_m;
        QPixmap coat_w;
        QPixmap leather_m;
        QPixmap tie;
        QPixmap bow_tie;
        QPixmap midi_skirt;
        QPixmap umbrella;
        QPixmap shirt_m;
        QPixmap shirt_w;
        QPixmap Tshirt_w;
        QPixmap Tshirt_m;
        QPixmap throusers_m;
        QPixmap throusers_m_j;
        QPixmap winter_dress_j;
        QPixmap converse;
        QPixmap shoes_w_j;
        QPixmap a_skirt;
        QPixmap texas_skirt;
        QPixmap winter_jacket_m;
        QPixmap winter_jacket_w;
        QPixmap ski_m;
        QPixmap ski_w;
        QPixmap throusers_w_s;
        QPixmap throusers_w_j;
        QPixmap throusers_w;
        QPixmap sneakers_w;
        QPixmap jacket_m;
        QPixmap baseball_hat;
        QPixmap cap_m;
        QPixmap cap_w;
        QPixmap beach_hat;
        QPixmap jacket_w;
        QPixmap sako_w;
        QPixmap sako_m;
        QPixmap sandals_w;
        QPixmap sandals_m;
        QPixmap shortPants_m;
        QPixmap shortPants_w;
        QPixmap shortPants_w_s;
        QPixmap bermuda;
        QPixmap top;
        QPixmap high_boots;
   /* QString bluza=":/slike/bluza.jpg";
    QPixmap blouse(QString &filename);*/

private slots:
    void on_comboBox_activated(const QString &arg1);

    void on_comboBox_2_activated(const QString &arg1);

    void sensor_writeOut();

    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
    Wardrobe *wardrobe;

};

#endif // DIALOG_H
