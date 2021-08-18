#include "wardrobe.h"
#include "ui_wardrobe.h"

Wardrobe::Wardrobe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Wardrobe)
{
    bermuda = false; blouse = false; sako_w = false; sako_m = false; sandals_w = false; sandals_m = false; beach_hat = false; ski_m = false; ski_w = false; shortPants_w_s = false; conv = false; heels = false;
    top = false; shoes_m_s = false; shoes_m_j = false; boots_m = false; boots_w_s = false; boots_w = false; long_sleeve_m = false; long_sleeve_w = false; hoody = false; a_skirt = false; texas_skirt = false;
    hoody2 = false; sweater_m = false; cardigan = false; sweater_w = false; texas_jacket_m = false; texas_jacket_w = false; rain_boots = false; dress = false; everyday_dress = false; party_dress = false;
    hawaii = false; spring_jacket_m = false; japan = false; baseball = false; hat_m = false; hat_w = false; coat_m = false; coat_w = false; shirt_m = false; shirt_w = false; leather_m = false, tie = false;
    bow_tie = false; midi_skirt = false; jeans_m = false; throusers_w_j = false; throusers_m_j = false; throusers_w_s = false; polo = false; winter_dress_j = false; shoes_w_j = false; spring_jacket_w = false;
    high_bools = false;
    ui->setupUi(this);
}

Wardrobe::~Wardrobe()
{
    delete ui;
}


void Wardrobe::on_checkBox_stateChanged(int arg1)
{
    bermuda = !bermuda;
}

void Wardrobe::on_checkBox_2_stateChanged(int arg1)
{
    blouse = !blouse;
}

void Wardrobe::on_checkBox_3_stateChanged(int arg1)
{
    top = !top;
}

void Wardrobe::on_checkBox_4_stateChanged(int arg1)
{
    shoes_m_s = !shoes_m_s;
}

void Wardrobe::on_checkBox_5_stateChanged(int arg1)
{
    shoes_m_j = !shoes_m_j;
}

void Wardrobe::on_checkBox_6_stateChanged(int arg1)
{
    boots_m = !boots_m;
}

void Wardrobe::on_checkBox_7_stateChanged(int arg1)
{
    boots_w_s = !boots_w_s;
}

void Wardrobe::on_checkBox_8_stateChanged(int arg1)
{
    boots_w = !boots_w;
}

void Wardrobe::on_checkBox_9_stateChanged(int arg1)
{
    long_sleeve_m = !long_sleeve_m;
}

void Wardrobe::on_checkBox_10_stateChanged(int arg1)
{
    long_sleeve_w = !long_sleeve_w;
}

void Wardrobe::on_checkBox_11_stateChanged(int arg1)
{
    hoody = !hoody;
}

void Wardrobe::on_checkBox_12_stateChanged(int arg1)
{
    hoody2 = !hoody2;
}

void Wardrobe::on_checkBox_13_stateChanged(int arg1)
{
    sweater_m = !sweater_m;
}

void Wardrobe::on_checkBox_14_stateChanged(int arg1)
{
    cardigan = !cardigan;
}

void Wardrobe::on_checkBox_15_stateChanged(int arg1)
{
    sweater_w = !sweater_w;
}

void Wardrobe::on_checkBox_16_stateChanged(int arg1)
{
    texas_jacket_m = !texas_jacket_m;
}

void Wardrobe::on_checkBox_17_stateChanged(int arg1)
{
    texas_jacket_w = !texas_jacket_w;
}

void Wardrobe::on_checkBox_18_stateChanged(int arg1)
{
    rain_boots = !rain_boots;
}

void Wardrobe::on_checkBox_19_stateChanged(int arg1)
{
    dress = !dress;
}

void Wardrobe::on_checkBox_20_stateChanged(int arg1)
{
    everyday_dress = !everyday_dress;
}

void Wardrobe::on_checkBox_21_stateChanged(int arg1)
{
    party_dress = !party_dress;
}

void Wardrobe::on_checkBox_22_stateChanged(int arg1)
{
    hawaii = !hawaii;
}

void Wardrobe::on_checkBox_23_stateChanged(int arg1)
{
    spring_jacket_m = !spring_jacket_m;
}

void Wardrobe::on_checkBox_24_stateChanged(int arg1)
{
    japan = !japan;
}

void Wardrobe::on_checkBox_25_stateChanged(int arg1)
{
    baseball = !baseball;
}

void Wardrobe::on_checkBox_26_stateChanged(int arg1)
{
    hat_m = !hat_m;
}

void Wardrobe::on_checkBox_27_stateChanged(int arg1)
{
    hat_w = !hat_w;
}

void Wardrobe::on_checkBox_28_stateChanged(int arg1)
{
    coat_m = !coat_m;
}

void Wardrobe::on_checkBox_29_stateChanged(int arg1)
{
    coat_w = !coat_w;
}

void Wardrobe::on_checkBox_30_stateChanged(int arg1)
{
    shirt_m = !shirt_m;
}

void Wardrobe::on_checkBox_31_stateChanged(int arg1)
{
    shirt_w = !shirt_w;
}

void Wardrobe::on_checkBox_32_stateChanged(int arg1)
{
    leather_m = !leather_m;
}

void Wardrobe::on_checkBox_33_stateChanged(int arg1)
{
    tie = !tie;
}

void Wardrobe::on_checkBox_34_stateChanged(int arg1)
{
    bow_tie = !bow_tie;
}

void Wardrobe::on_checkBox_35_stateChanged(int arg1)
{
    midi_skirt = !midi_skirt;
}

void Wardrobe::on_checkBox_36_stateChanged(int arg1)
{
    throusers_w_j = !throusers_w_j;
}

void Wardrobe::on_checkBox_37_stateChanged(int arg1)
{
    throusers_m_j = !throusers_m_j;
}

void Wardrobe::on_checkBox_38_stateChanged(int arg1)
{
    throusers_w_s = !throusers_w_s;
}

void Wardrobe::on_checkBox_39_stateChanged(int arg1)
{
    polo = !polo;
}

void Wardrobe::on_checkBox_40_stateChanged(int arg1)
{
    winter_dress_j = !winter_dress_j;
}

void Wardrobe::on_checkBox_41_stateChanged(int arg1)
{
    shoes_w_j = !shoes_w_j;
}

void Wardrobe::on_checkBox_42_stateChanged(int arg1)
{
    spring_jacket_w = !spring_jacket_w;
}

void Wardrobe::on_checkBox_43_stateChanged(int arg1)
{
    sako_m = !sako_m;
}

void Wardrobe::on_checkBox_44_stateChanged(int arg1)
{
    sako_w = !sako_w;
}

void Wardrobe::on_checkBox_45_stateChanged(int arg1)
{
    sandals_m = !sandals_m;
}

void Wardrobe::on_checkBox_46_stateChanged(int arg1)
{
    sandals_w = !sandals_w;
}

void Wardrobe::on_checkBox_47_stateChanged(int arg1)
{
    beach_hat = !beach_hat;
}

void Wardrobe::on_checkBox_48_stateChanged(int arg1)
{
    ski_m = !ski_m;
}

void Wardrobe::on_checkBox_49_stateChanged(int arg1)
{
    ski_w = !ski_w;
}

void Wardrobe::on_checkBox_50_stateChanged(int arg1)
{
    shortPants_w_s = !shortPants_w_s;
}

void Wardrobe::on_checkBox_51_stateChanged(int arg1)
{
    conv = !conv;
}

void Wardrobe::on_checkBox_52_stateChanged(int arg1)
{
    heels = !heels;
}

void Wardrobe::on_checkBox_53_stateChanged(int arg1)
{
    a_skirt = !a_skirt;
}

void Wardrobe::on_checkBox_54_stateChanged(int arg1)
{
    texas_skirt = !texas_skirt;
}
