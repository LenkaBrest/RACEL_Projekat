#ifndef WARDROBE_H
#define WARDROBE_H

#include <QDialog>

namespace Ui {
class Wardrobe;
}

class Wardrobe : public QDialog
{
    Q_OBJECT

public:
    explicit Wardrobe(QWidget *parent = nullptr);
    ~Wardrobe();
    bool bermuda, blouse, sako_w, sako_m, sandals_w, sandals_m, beach_hat, ski_m, ski_w, shortPants_w_s, conv, heels;
    bool top, shoes_m_s, shoes_m_j, boots_m, boots_w_s, boots_w, long_sleeve_m, long_sleeve_w, hoody, a_skirt, texas_skirt;
    bool hoody2, sweater_m, cardigan, sweater_w, texas_jacket_m, texas_jacket_w, rain_boots, dress, everyday_dress, party_dress;
    bool hawaii, spring_jacket_m, japan, baseball, hat_m, hat_w, coat_m, coat_w, shirt_m, shirt_w, leather_m, tie;
    bool bow_tie, midi_skirt, jeans_m, throusers_w_j, throusers_m_j, throusers_w_s, polo, winter_dress_j, shoes_w_j, spring_jacket_w;
    bool high_bools;

private slots:


    void on_checkBox_stateChanged(int arg1);

    void on_checkBox_2_stateChanged(int arg1);

    void on_checkBox_3_stateChanged(int arg1);

    void on_checkBox_4_stateChanged(int arg1);

    void on_checkBox_5_stateChanged(int arg1);

    void on_checkBox_6_stateChanged(int arg1);

    void on_checkBox_7_stateChanged(int arg1);

    void on_checkBox_8_stateChanged(int arg1);

    void on_checkBox_9_stateChanged(int arg1);

    void on_checkBox_10_stateChanged(int arg1);

    void on_checkBox_11_stateChanged(int arg1);

    void on_checkBox_12_stateChanged(int arg1);

    void on_checkBox_13_stateChanged(int arg1);

    void on_checkBox_14_stateChanged(int arg1);

    void on_checkBox_15_stateChanged(int arg1);

    void on_checkBox_16_stateChanged(int arg1);

    void on_checkBox_17_stateChanged(int arg1);

    void on_checkBox_18_stateChanged(int arg1);

    void on_checkBox_19_stateChanged(int arg1);

    void on_checkBox_20_stateChanged(int arg1);

    void on_checkBox_21_stateChanged(int arg1);

    void on_checkBox_22_stateChanged(int arg1);

    void on_checkBox_23_stateChanged(int arg1);

    void on_checkBox_24_stateChanged(int arg1);

    void on_checkBox_25_stateChanged(int arg1);

    void on_checkBox_26_stateChanged(int arg1);

    void on_checkBox_27_stateChanged(int arg1);

    void on_checkBox_28_stateChanged(int arg1);

    void on_checkBox_29_stateChanged(int arg1);

    void on_checkBox_30_stateChanged(int arg1);

    void on_checkBox_31_stateChanged(int arg1);

    void on_checkBox_32_stateChanged(int arg1);

    void on_checkBox_33_stateChanged(int arg1);

    void on_checkBox_34_stateChanged(int arg1);

    void on_checkBox_35_stateChanged(int arg1);

    void on_checkBox_36_stateChanged(int arg1);

    void on_checkBox_37_stateChanged(int arg1);

    void on_checkBox_38_stateChanged(int arg1);

    void on_checkBox_39_stateChanged(int arg1);

    void on_checkBox_40_stateChanged(int arg1);

    void on_checkBox_41_stateChanged(int arg1);

    void on_checkBox_42_stateChanged(int arg1);

    void on_checkBox_43_stateChanged(int arg1);

    void on_checkBox_44_stateChanged(int arg1);

    void on_checkBox_45_stateChanged(int arg1);

    void on_checkBox_46_stateChanged(int arg1);

    void on_checkBox_47_stateChanged(int arg1);

    void on_checkBox_48_stateChanged(int arg1);

    void on_checkBox_49_stateChanged(int arg1);

    void on_checkBox_50_stateChanged(int arg1);

    void on_checkBox_51_stateChanged(int arg1);

    void on_checkBox_52_stateChanged(int arg1);

    void on_checkBox_53_stateChanged(int arg1);

    void on_checkBox_54_stateChanged(int arg1);

private:
    Ui::Wardrobe *ui;
};

#endif // WARDROBE_H
