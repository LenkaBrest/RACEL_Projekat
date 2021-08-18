#include "dialog.h"
#include "ui_dialog.h"
#include "wardrobe.h"

#define pin 7

static dht DHT;


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    wardrobe = new Wardrobe(this);
    wiringPiSetup();

    blouse.load(":/slike/bluza.jpg");
    shoes_m_s.load(":/slike/cipele_muske_svecane.png");
    shoes_w_s.load(":/slike/cizme_svecane_zenske.png");
    boots_m.load(":/slike/cizme_muske.jpg");
    shoes_m_j.load(":/slike/cipele_poslovne_muske.jpg");
    shoes_w.load(":/slike/cizme_zenske.png");
    long_sleeve_m.load(":/slike/dugacki_muski.png");
    long_sleeve_w.load(":/slike/dugacki_zenski.png");
    hoody.load(":/slike/duks_kopcanje.jpg");
    hoody2.load(":/slike/duks_navlacenje.png");
    cardigan.load(":/slike/dzemper_na_kopcanje.jpg");
    texas_jacket_m.load(":/slike/gornjak_muski.jpg");
    texas_jacket_w.load(":/slike/gornjak_zenski.jpg");
    rain_boots.load(":/slike/gumene_cizme_zenske.png");
    polo.load(":/slike/polo.png");
    heels.load(":/slike/stikle.png");
    skirt.load(":/slike/suknja.png");
    sneakers_m.load(":/slike/patike_muske.png");
    pullover_m.load(":/slike/dzemper_muski.png");
    pullover_w.load(":/slike/dzemper_zenski.jpeg");
    dress.load(":/slike/haljina.jpg");
    everyday_dress.load(":/slike/haljina_svaki_dan.jpg");
    dress_s.load(":/slike/haljina_svecana.jpg");
    hawaii.load(":/slike/havajska_kosulja.png");
    japan.load(":/slike/japanke.jpeg");
    coat_m.load(":/slike/kaput_muski.jpg");
    coat_w.load(":/slike/kaput_zenski.jpg");
    leather_m.load(":/slike/kozna_muska.jpeg");
    tie.load(":/slike/kravata.png");
    bow_tie.load(":/slike/leptir_masna.jpg");
    midi_skirt.load(":/slike/marina_suknja.jpg");
    umbrella.load(":/slike/kisobran.jpg");
    shirt_m.load(":/slike/kosulja.jpg");
    shirt_w.load(":/slike/kosulja_zenska.jpg");
    Tshirt_w.load(":/slike/kratki.jpg");
    Tshirt_m.load(":/slike/kratki_muski.jpg");
    throusers_m.load(":/slike/pantalone_muske.jpg");
    throusers_m_j.load(":/slike/pantalone_poslovne_muske.png");
    winter_dress_j.load(":/slike/poslovna_zimska_haljina.jpg");
    converse.load(":/slike/starke.jpg");
    shoes_w_j.load(":/slike/poslovne_ravne.jpg");
    a_skirt.load(":/suknja_a_kroj.jpg");
    texas_skirt.load(":/slike/teksas_suknja.jpg");
    winter_jacket_m.load(":/slike/zimska_jakna_muska.png");
    winter_jacket_w.load(":/slike/zimska_jakna_zenska.jpg");
    ski_m.load(":/slike/ski_jakna_muska.png");
    ski_w.load(":/slike/skijaska_jakna_zenska.jpg");
    throusers_w_s.load(":/slike/pantalone_svecane.jpg");
    throusers_w_j.load(":/slike/pantalone_poslovne.jpg");
    throusers_w.load(":/slike/pantalone_zenske.jpg");
    sneakers_w.load(":/slike/patike_zenske.jpg");
    jacket_m.load(":/slike/jakna_muska.jpg");
    baseball_hat.load(":/slike/kacket.png");
    cap_m.load(":/slike/kapa_muska.jpeg");
    cap_w.load(":/slike/kapa_zenska.jpeg");
    beach_hat.load(":/slike/sesir_za_plazu.jpeg");
    jacket_w.load(":/slike/sako.jpg");
    sako_w.load(":/slike/sako_zenski.jpg");
    sako_m.load(":/slike/sako_muski.jpg");
    sandals_w.load(":/slike/sandale_zenske.jpg");
    sandals_m.load(":/slike/sandale_muske.jpg");
    shortPants_m.load(":/slike/sorts_muski.jpg");
    shortPants_w.load(":/slike/sorts_zenski.jpg");
    shortPants_w_s.load(":/slike/sorts_zenski_svecani.jpg");
    bermuda.load(":/slike/bermude_muske.jpg");
    top.load(":/slike/bretele_svecane.jpeg");
    high_boots.load(":/slike/visoke_cizme.jpg");

    QTimer *myTimer = new QTimer(this);
    connect(myTimer, SIGNAL(timeout()), this, SLOT(sensor_writeOut()));
    myTimer->start(1000);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_comboBox_activated(const QString &arg1)
{
    if (arg1 == "zenski")
           sex = 1;
    else if(arg1 == "muski")
        sex = 2;
    else sex = 0;

}

void Dialog::on_comboBox_2_activated(const QString &arg1)
{
    if (arg1 == "svakodnevni")
           style = 1;
    else if(arg1 == "poslovni")
        style = 2;
    else if(arg1 == "svecani")
        style = 3;
    else
        style = 0;
}


void Dialog::on_pushButton_clicked()
{

    //wardrobe = new Wardrobe(this);
    wardrobe->show();
}


void Dialog::sensor_writeOut()
{

    ui->label_7->setScaledContents(true);
    ui->label_7->setGeometry(290, 60, 61, 31);
    ui->label_8->setScaledContents(true);
    ui->label_8->setGeometry(290, 0, 31, 31);
    ui->label_9->setScaledContents(true);
    ui->label_9->setGeometry(240, 100, 61, 61);
    ui->label_10->setScaledContents(true);
    ui->label_10->setGeometry(290, 170, 61, 61);
    ui->label_11->setScaledContents(true);
    ui->label_11->setGeometry(290, 240, 61, 51);
    ui->label_12->setScaledContents(true);
    ui->label_12->setGeometry(320, 100, 61, 61);

    DHT.read_dht11(pin);
    QString text2, text3, text13, text14, text15;
    text2 = QString::number(DHT.humidity);
    text3 = QString::number(DHT.temperature);
    ui->label_3->setText(text2);
    ui->label_4->setText(text3);
    //ui->label_9->setPixmap(jakna);
    //temperature
    if(DHT.temperature>30 && DHT.temperature<40)
        t = hot;
    else if(DHT.temperature>20 && DHT.temperature<30)
        t = summer;
    else if (DHT.temperature>10 && DHT.temperature<20)
        t = spring;
    else if (DHT.temperature>0 && DHT.temperature<10)
        t = winter;

    //humidity
    if(DHT.humidity>67 && DHT.humidity<100)
        h = high;
    else if(DHT.humidity>33 && DHT.humidity<67)
        h = medium;
    else if (DHT.humidity>0 && DHT.humidity<33)
        h = low;

    //text13 = QString::number(t);
    //text14 = QString::number(h);
    //text15.append("t: ");
    //text15.append(text13);
    //text15.append(" h: ");
    //text15.append(text14);
    //ui->label_13->setText(text15);

    switch(style)
    {
        case 1: switch(sex)
                {
                    case 1: switch(t)
                            {
                                case winter: switch(h)
                                             {
                                                case low: ui->label_8->setPixmap(QPixmap());
                                                          ui->label_7->setPixmap(cap_w);
                                                          ui->label_9->setPixmap(pullover_w);
                                                          ui->label_12->setPixmap(winter_jacket_w);
                                                          ui->label_10->setPixmap(throusers_w);
                                                          ui->label_11->setPixmap(shoes_w);
                                                          break;
                                                case medium:ui->label_8->setPixmap(QPixmap());
                                                            ui->label_7->setPixmap(cap_w);
                                                            ui->label_9->setPixmap(pullover_w);
                                                            ui->label_12->setPixmap(winter_jacket_w);
                                                            ui->label_10->setPixmap(throusers_w);
                                                            ui->label_11->setPixmap(shoes_w);
                                                            break;
                                                case high:ui->label_8->setPixmap(umbrella);
                                                          ui->label_7->setPixmap(cap_w);
                                                          ui->label_9->setPixmap(pullover_w);
                                                          if(wardrobe->ski_w)
                                                              ui->label_12->setPixmap(ski_w);
                                                          else
                                                            ui->label_12->setPixmap(jacket_w);
                                                          ui->label_10->setPixmap(throusers_w);
                                                          ui->label_11->setPixmap(shoes_w);
                                                          break;
                                             }
                                             break;
                                case spring: switch(h)
                                             {
                                                case low: ui->label_8->setPixmap(QPixmap());
                                                          ui->label_7->setPixmap(QPixmap());
                                                          if(wardrobe->long_sleeve_w)
                                                              ui->label_9->setPixmap(long_sleeve_w);
                                                          else
                                                            ui->label_9->setPixmap(shirt_w);
                                                          if(wardrobe->texas_jacket_w)
                                                              ui->label_12->setPixmap(texas_jacket_w);
                                                          else
                                                              ui->label_12->setPixmap(jacket_w);
                                                          ui->label_10->setPixmap(throusers_w);
                                                          if(wardrobe->conv)
                                                               ui->label_11->setPixmap(converse);
                                                          else
                                                               ui->label_11->setPixmap(sneakers_w);
                                                          break;
                                                case medium:ui->label_8->setPixmap(QPixmap());
                                                            ui->label_7->setPixmap(baseball_hat);
                                                            if(wardrobe->long_sleeve_w)
                                                                ui->label_9->setPixmap(long_sleeve_w);
                                                            else
                                                              ui->label_9->setPixmap(shirt_w);
                                                            ui->label_12->setPixmap(jacket_w);
                                                            ui->label_10->setPixmap(throusers_w);
                                                            if(wardrobe->conv)
                                                               ui->label_11->setPixmap(converse);
                                                            else
                                                               ui->label_11->setPixmap(sneakers_w);
                                                            break;
                                                case high:ui->label_8->setPixmap(umbrella);
                                                          ui->label_7->setPixmap(QPixmap());
                                                          if(wardrobe->long_sleeve_w)
                                                              ui->label_9->setPixmap(long_sleeve_w);
                                                          else
                                                            ui->label_9->setPixmap(shirt_w);
                                                          ui->label_12->setPixmap(jacket_w);
                                                          ui->label_10->setPixmap(throusers_w);
                                                          if(wardrobe->rain_boots)
                                                             ui->label_11->setPixmap(rain_boots);
                                                          else
                                                             ui->label_11->setPixmap(shoes_w);
                                                          break;
                                            }
                                            break;
                                case summer: switch(h)
                                             {
                                                case low: ui->label_8->setPixmap(QPixmap());
                                                          if(wardrobe->beach_hat)
                                                            ui->label_7->setPixmap(beach_hat);
                                                          else
                                                             ui->label_7->setPixmap(QPixmap());
                                                          ui->label_9->setPixmap(Tshirt_w);
                                                          ui->label_9->setGeometry(290, 100, 61, 61);
                                                          ui->label_12->setPixmap(QPixmap());
                                                          ui->label_12->setGeometry(360, 100, 10, 10);
                                                          if(wardrobe->a_skirt)
                                                              ui->label_10->setPixmap(a_skirt);
                                                          else if(wardrobe->texas_skirt)
                                                              ui->label_10->setPixmap(texas_skirt);
                                                          else
                                                              ui->label_10->setPixmap(shortPants_w);
                                                          if(wardrobe->japan)
                                                              ui->label_11->setPixmap(japan);
                                                          else
                                                              ui->label_11->setPixmap(sandals_w);
                                                          break;
                                                case medium:ui->label_8->setPixmap(QPixmap());
                                                            if(wardrobe->beach_hat)
                                                                ui->label_7->setPixmap(beach_hat);
                                                            else
                                                                ui->label_7->setPixmap(QPixmap());
                                                            ui->label_9->setPixmap(Tshirt_w);
                                                            ui->label_9->setGeometry(QRect(290, 100, 61, 61));
                                                            ui->label_12->setPixmap(QPixmap()); //SKINI VISE VRSTA JAKNI
                                                            ui->label_12->setGeometry(360, 100, 10, 10);
                                                            if(wardrobe->a_skirt)
                                                                ui->label_10->setPixmap(a_skirt);
                                                            else if(wardrobe->texas_skirt)
                                                                ui->label_10->setPixmap(texas_skirt);
                                                            else
                                                                ui->label_10->setPixmap(shortPants_w);
                                                            if(wardrobe->japan)
                                                                ui->label_11->setPixmap(japan);
                                                            else
                                                                ui->label_11->setPixmap(sandals_w);
                                                            break;
                                                case high:ui->label_8->setPixmap(umbrella);
                                                          if(wardrobe->beach_hat)
                                                              ui->label_7->setPixmap(beach_hat);
                                                          else
                                                              ui->label_7->setPixmap(QPixmap());
                                                            ui->label_9->setPixmap(Tshirt_w);
                                                            ui->label_9->setGeometry(290, 100, 61, 61);
                                                            ui->label_12->setPixmap(QPixmap()); //SKINI VISE VRSTA JAKNI
                                                            ui->label_12->setGeometry(360, 100, 10, 10);
                                                            if(wardrobe->a_skirt)
                                                                ui->label_10->setPixmap(a_skirt);
                                                            else if(wardrobe->texas_skirt)
                                                                ui->label_10->setPixmap(texas_skirt);
                                                            else
                                                                ui->label_10->setPixmap(shortPants_w);
                                                            ui->label_11->setPixmap(sneakers_w);
                                                            break;
                                              }
                                              break;
                                case hot: switch(h)
                                          {
                                                case low: ui->label_8->setPixmap(QPixmap());
                                                          if(wardrobe->beach_hat)
                                                              ui->label_7->setPixmap(beach_hat);
                                                          else
                                                              ui->label_7->setPixmap(QPixmap());
                                                          ui->label_9->setPixmap(Tshirt_w);
                                                          ui->label_9->setGeometry(290, 100, 61, 61);
                                                          ui->label_12->setPixmap(QPixmap());
                                                          ui->label_12->setGeometry(360, 100, 10, 10);
                                                          if(wardrobe->a_skirt)
                                                               ui->label_10->setPixmap(a_skirt);
                                                          else if(wardrobe->texas_skirt)
                                                               ui->label_10->setPixmap(texas_skirt);
                                                          else
                                                               ui->label_10->setPixmap(shortPants_w);
                                                          if(wardrobe->japan)
                                                              ui->label_11->setPixmap(japan);
                                                          else
                                                              ui->label_11->setPixmap(sandals_w);
                                                          break;
                                                case medium:ui->label_8->setPixmap(QPixmap());
                                                            if(wardrobe->beach_hat)
                                                                ui->label_7->setPixmap(beach_hat);
                                                            else
                                                                ui->label_7->setPixmap(QPixmap());
                                                            if(wardrobe->everyday_dress)
                                                            {
                                                                ui->label_9->setPixmap(everyday_dress);
                                                                ui->label_9->setGeometry(290, 100, 61, 150); 
                                                                ui->label_10->setPixmap(QPixmap());
                                                                ui->label_10->setGeometry(290, 252, 10, 10);
                                                            }
                                                            else
                                                            {
                                                                ui->label_9->setPixmap(Tshirt_w);
                                                                ui->label_9->setGeometry(290, 100, 61, 61);
                                                                 //SKINI VISE VRSTA JAKNI
                                                                if(wardrobe->a_skirt)
                                                                        ui->label_10->setPixmap(a_skirt);
                                                                else if(wardrobe->texas_skirt)
                                                                        ui->label_10->setPixmap(texas_skirt);
                                                                else
                                                                        ui->label_10->setPixmap(shortPants_w);
                                                            }
                                                            ui->label_12->setPixmap(QPixmap());
                                                            ui->label_12->setGeometry(360, 100, 10, 10);
                                                            if(wardrobe->japan)
                                                                    ui->label_11->setPixmap(japan);
                                                            else
                                                                    ui->label_11->setPixmap(sandals_w);
                                                            break;
                                            case high:ui->label_8->setPixmap(umbrella);
                                                      if(wardrobe->beach_hat)
                                                            ui->label_7->setPixmap(beach_hat);
                                                      else
                                                            ui->label_7->setPixmap(QPixmap());
                                                      ui->label_9->setPixmap(Tshirt_w);
                                                      ui->label_9->setGeometry(290, 100, 61, 61);
                                                      ui->label_12->setPixmap(QPixmap()); //SKINI VISE VRSTA JAKNI
                                                      ui->label_12->setGeometry(360, 100, 10, 10);
                                                      if(wardrobe->a_skirt)
                                                          ui->label_10->setPixmap(a_skirt);
                                                      else if(wardrobe->texas_skirt)
                                                          ui->label_10->setPixmap(texas_skirt);
                                                      else
                                                          ui->label_10->setPixmap(shortPants_w);
                                                      ui->label_11->setPixmap(sneakers_w);
                                                      break;

                                        }
                                        break;
                            }
                            break;
            case 2: switch(t)
                    {
                        case winter: switch(h)
                                     {
                                        case low: ui->label_8->setPixmap(QPixmap());
                                                  ui->label_7->setPixmap(cap_m);
                                                  if(wardrobe->hoody2)
                                                      ui->label_9->setPixmap(hoody2);
                                                  else
                                                      ui->label_9->setPixmap(pullover_m);
                                                  ui->label_12->setPixmap(winter_jacket_m);
                                                  ui->label_10->setPixmap(throusers_m);
                                                  ui->label_11->setPixmap(boots_m);
                                                  break;
                                        case medium:ui->label_8->setPixmap(QPixmap());
                                                    ui->label_7->setPixmap(cap_m);
                                                    if(wardrobe->hoody2)
                                                        ui->label_9->setPixmap(hoody2);
                                                    else
                                                        ui->label_9->setPixmap(pullover_m);
                                                    ui->label_12->setPixmap(winter_jacket_m); //SKINI VISE VRSTA JAKNI
                                                    ui->label_10->setPixmap(throusers_m);
                                                    ui->label_11->setPixmap(boots_m);
                                                    break;
                                        case high:ui->label_8->setPixmap(umbrella);
                                                  ui->label_7->setPixmap(cap_m);
                                                  if(wardrobe->hoody2)
                                                      ui->label_9->setPixmap(hoody2);
                                                  else
                                                      ui->label_9->setPixmap(pullover_m);
                                                  if(wardrobe->ski_m)
                                                      ui->label_12->setPixmap(ski_m);
                                                  else
                                                      ui->label_12->setPixmap(jacket_m);
                                                  ui->label_10->setPixmap(throusers_m);
                                                  ui->label_11->setPixmap(boots_m);
                                                  break;
                                    }
                                    break;
                        case spring: switch(h)
                                     {
                                        case low: ui->label_8->setPixmap(QPixmap());
                                                  ui->label_7->setPixmap(QPixmap());
                                                  if(wardrobe->long_sleeve_m)
                                                      ui->label_9->setPixmap(long_sleeve_m);
                                                  else
                                                      ui->label_9->setPixmap(Tshirt_m);
                                                  if(wardrobe->hoody)
                                                      ui->label_12->setPixmap(hoody);
                                                  else
                                                      ui->label_12->setPixmap(jacket_m);
                                                  ui->label_10->setPixmap(throusers_m);
                                                  if(wardrobe->conv)
                                                      ui->label_11->setPixmap(converse);
                                                  else
                                                      ui->label_11->setPixmap(sneakers_m);
                                                  break;
                                        case medium:ui->label_8->setPixmap(QPixmap());
                                                    if(wardrobe->baseball)
                                                        ui->label_7->setPixmap(baseball_hat);
                                                    else
                                                        ui->label_7->setPixmap(QPixmap());
                                                    if(wardrobe->long_sleeve_m)
                                                        ui->label_9->setPixmap(long_sleeve_m);
                                                    else
                                                        ui->label_9->setPixmap(Tshirt_m);
                                                    if(wardrobe->hoody)
                                                        ui->label_12->setPixmap(hoody);
                                                    else
                                                        ui->label_12->setPixmap(jacket_m);
                                                    ui->label_10->setPixmap(throusers_m);
                                                    if(wardrobe->conv)
                                                        ui->label_11->setPixmap(converse);
                                                    else
                                                        ui->label_11->setPixmap(sneakers_m);
                                                    break;
                                        case high:ui->label_8->setPixmap(umbrella);
                                                  if(wardrobe->baseball)
                                                        ui->label_7->setPixmap(baseball_hat);
                                                  else
                                                        ui->label_7->setPixmap(QPixmap());
                                                  if(wardrobe->long_sleeve_m)
                                                        ui->label_9->setPixmap(long_sleeve_m);
                                                  else
                                                        ui->label_9->setPixmap(Tshirt_m);
                                                  if(wardrobe->hoody)
                                                        ui->label_12->setPixmap(hoody);
                                                  else
                                                        ui->label_12->setPixmap(jacket_m);
                                                  ui->label_10->setPixmap(throusers_m);
                                                  ui->label_11->setPixmap(sneakers_m);
                                                  break;
                                    }
                                    break;
                        case summer: switch(h)
                                     {
                                        case low: ui->label_8->setPixmap(QPixmap());
                                                  if(wardrobe->baseball)
                                                         ui->label_7->setPixmap(baseball_hat);
                                                  else
                                                         ui->label_7->setPixmap(QPixmap());
                                                  if(wardrobe->hawaii)
                                                      ui->label_9->setPixmap(hawaii);
                                                  else
                                                      ui->label_9->setPixmap(Tshirt_m);
                                                  ui->label_9->setGeometry(290, 100, 61, 61);
                                                  ui->label_12->setPixmap(QPixmap());
                                                  ui->label_12->setGeometry(360, 100, 10, 10);
                                                  if(wardrobe->bermuda)
                                                      ui->label_10->setPixmap(bermuda);
                                                  else
                                                      ui->label_10->setPixmap(shortPants_m);
                                                  if(wardrobe->japan)
                                                       ui->label_11->setPixmap(japan);
                                                  else
                                                        ui->label_11->setPixmap(sandals_m);
                                                  break;
                                        case medium:ui->label_8->setPixmap(QPixmap());
                                                    if(wardrobe->baseball)
                                                        ui->label_7->setPixmap(baseball_hat);
                                                    else
                                                        ui->label_7->setPixmap(QPixmap());
                                                    if(wardrobe->hawaii)
                                                        ui->label_9->setPixmap(hawaii);
                                                    else
                                                        ui->label_9->setPixmap(Tshirt_m);
                                                    ui->label_9->setGeometry(290, 100, 61, 61);
                                                    ui->label_12->setPixmap(QPixmap());
                                                    ui->label_12->setGeometry(360, 100, 10, 10);
                                                    if(wardrobe->bermuda)
                                                        ui->label_10->setPixmap(bermuda);
                                                    else
                                                        ui->label_10->setPixmap(shortPants_m);
                                                    if(wardrobe->japan)
                                                        ui->label_11->setPixmap(japan);
                                                    else
                                                        ui->label_11->setPixmap(sandals_m);
                                                    break;
                                        case high:ui->label_8->setPixmap(umbrella);
                                                  if(wardrobe->baseball)
                                                        ui->label_7->setPixmap(baseball_hat);
                                                  else
                                                        ui->label_7->setPixmap(QPixmap());
                                                  if(wardrobe->hawaii)
                                                      ui->label_9->setPixmap(hawaii);
                                                  else
                                                      ui->label_9->setPixmap(Tshirt_m);
                                                  ui->label_9->setGeometry(290, 100, 61, 61);
                                                  ui->label_12->setPixmap(QPixmap());
                                                  ui->label_12->setGeometry(360, 100, 10, 10);
                                                  if(wardrobe->bermuda)
                                                      ui->label_10->setPixmap(bermuda);
                                                  else
                                                      ui->label_10->setPixmap(shortPants_m);
                                                  ui->label_11->setPixmap(sneakers_w);
                                                  break;
                                    }
                                    break;
                        case hot: switch(h)
                                  {
                                       case low: ui->label_8->setPixmap(QPixmap());
                                                 if(wardrobe->baseball)
                                                    ui->label_7->setPixmap(baseball_hat);
                                                 else
                                                    ui->label_7->setPixmap(QPixmap());
                                                 if(wardrobe->hawaii)
                                                    ui->label_9->setPixmap(hawaii);
                                                  else
                                                    ui->label_9->setPixmap(Tshirt_m);
                                                ui->label_9->setGeometry(290, 100, 61, 61);
                                                ui->label_12->setPixmap(QPixmap());
                                                ui->label_12->setGeometry(360, 100, 10, 10);
                                                if(wardrobe->bermuda)
                                                    ui->label_10->setPixmap(bermuda);
                                                else
                                                    ui->label_10->setPixmap(shortPants_m);
                                                if(wardrobe->japan)
                                                    ui->label_11->setPixmap(japan);
                                                else
                                                    ui->label_11->setPixmap(sandals_m);
                                                break;
                                    case medium:ui->label_8->setPixmap(QPixmap());
                                                if(wardrobe->baseball)
                                                    ui->label_7->setPixmap(baseball_hat);
                                                else
                                                    ui->label_7->setPixmap(QPixmap());
                                                if(wardrobe->hawaii)
                                                    ui->label_9->setPixmap(hawaii);
                                                else
                                                    ui->label_9->setPixmap(Tshirt_m);
                                                ui->label_9->setGeometry(290, 100, 61, 61);
                                                ui->label_12->setPixmap(QPixmap());
                                                ui->label_12->setGeometry(360, 100, 10, 10);
                                                if(wardrobe->bermuda)
                                                    ui->label_10->setPixmap(bermuda);
                                                else
                                                    ui->label_10->setPixmap(shortPants_m);
                                                if(wardrobe->japan)
                                                    ui->label_11->setPixmap(japan);
                                                else
                                                    ui->label_11->setPixmap(sandals_m);
                                                break;
                                   case high:ui->label_8->setPixmap(umbrella);
                                             if(wardrobe->baseball)
                                                ui->label_7->setPixmap(baseball_hat);
                                             else
                                                ui->label_7->setPixmap(QPixmap());
                                             if(wardrobe->hawaii)
                                                ui->label_9->setPixmap(hawaii);
                                             else
                                                ui->label_9->setPixmap(Tshirt_m);
                                            ui->label_9->setGeometry(290, 100, 61, 61);
                                            ui->label_12->setPixmap(QPixmap());
                                            ui->label_12->setGeometry(360, 100, 10, 10);
                                            if(wardrobe->bermuda)
                                                ui->label_10->setPixmap(bermuda);
                                            else
                                                ui->label_10->setPixmap(shortPants_m);
                                            ui->label_11->setPixmap(sneakers_w);
                                            break;
                                }
                                break;
                    }
                    break;
           }
           break;
    case 2: switch(sex)
            {
                case 1: switch(t)
                        {
                        case winter: switch(h)
                                     {
                                        case low: ui->label_8->setPixmap(QPixmap());
                                                  if(wardrobe->winter_dress_j)
                                                  {
                                                      ui->label_7->setPixmap(QPixmap());
                                                      ui->label_9->setPixmap(winter_dress_j);
                                                      ui->label_9->setGeometry(290, 100, 61, 101);
                                                      ui->label_10->setPixmap(QPixmap());
                                                      ui->label_10->setGeometry(290, 202, 10, 10);
                                                  }
                                                  else
                                                  {
                                                      ui->label_7->setPixmap(shirt_w);
                                                      ui->label_7->setGeometry(290, 30, 61, 61);
                                                      ui->label_9->setPixmap(sako_w);
                                                       ui->label_10->setPixmap(throusers_w_j);
                                                 }
                                                 if(wardrobe->coat_w)
                                                     ui->label_12->setPixmap(coat_w);
                                                 else
                                                        ui->label_12->setPixmap(winter_jacket_w);
                                                 if(wardrobe->boots_w_s)
                                                    ui->label_11->setPixmap(shoes_w_s);
                                                 else
                                                    ui->label_11->setPixmap(shoes_w);
                                                  break;
                                        case medium:ui->label_8->setPixmap(QPixmap());
                                                    if(wardrobe->winter_dress_j)
                                                    {
                                                        ui->label_7->setPixmap(QPixmap());
                                                        ui->label_9->setPixmap(winter_dress_j);
                                                        ui->label_9->setGeometry(290, 100, 61, 101);
                                                        ui->label_10->setPixmap(QPixmap());
                                                        ui->label_10->setGeometry(290, 202, 10, 10);
                                                    }
                                                    else
                                                    {
                                                        ui->label_7->setPixmap(shirt_w);
                                                        ui->label_7->setGeometry(290, 30, 61, 61);
                                                        ui->label_9->setPixmap(sako_w);
                                                        ui->label_10->setPixmap(throusers_w_j);
                                                    }
                                                    if(wardrobe->coat_w)
                                                        ui->label_12->setPixmap(coat_w);
                                                    else
                                                        ui->label_12->setPixmap(winter_jacket_w);
                                                    if(wardrobe->boots_w_s)
                                                        ui->label_11->setPixmap(shoes_w_s);
                                                    else
                                                        ui->label_11->setPixmap(shoes_w);
                                                    break;
                                        case high:ui->label_8->setPixmap(umbrella);
                                                  ui->label_7->setPixmap(shirt_w);
                                                  ui->label_9->setPixmap(sako_w);
                                                  if(wardrobe->coat_w)
                                                        ui->label_12->setPixmap(coat_w);
                                                  else
                                                         ui->label_12->setPixmap(winter_jacket_w);
                                                  ui->label_10->setPixmap(throusers_w_j);
                                                  ui->label_11->setPixmap(shoes_w);
                                                  break;
                                     }
                                     break;
                        case spring: switch(h)
                                     {
                                        case low: ui->label_8->setPixmap(QPixmap());
                                                  ui->label_7->setPixmap(QPixmap());
                                                  if(wardrobe->blouse)
                                                        ui->label_9->setPixmap(blouse);
                                                  else
                                                        ui->label_9->setPixmap(shirt_w);
                                                  ui->label_12->setPixmap(sako_w);
                                                  if(wardrobe->a_skirt)
                                                        ui->label_10->setPixmap(a_skirt);
                                                  else
                                                        ui->label_10->setPixmap(throusers_w_j);
                                                  if(wardrobe->shoes_w_j)
                                                        ui->label_11->setPixmap(shoes_w_j);
                                                  else
                                                        ui->label_11->setPixmap(heels);
                                                  break;
                                        case medium:ui->label_8->setPixmap(QPixmap());
                                                    ui->label_7->setPixmap(QPixmap());
                                                    if(wardrobe->blouse)
                                                        ui->label_9->setPixmap(blouse);
                                                    else
                                                        ui->label_9->setPixmap(shirt_w);
                                                    ui->label_12->setPixmap(sako_w);
                                                    if(wardrobe->a_skirt)
                                                        ui->label_10->setPixmap(a_skirt);
                                                    else
                                                        ui->label_10->setPixmap(throusers_w_j);
                                                    if(wardrobe->shoes_w_j)
                                                        ui->label_11->setPixmap(shoes_w_j);
                                                    else
                                                        ui->label_11->setPixmap(heels);
                                                    break;
                                        case high:ui->label_8->setPixmap(umbrella);
                                                  ui->label_7->setPixmap(QPixmap());
                                                  if(wardrobe->blouse)
                                                      ui->label_9->setPixmap(blouse);
                                                  else
                                                      ui->label_9->setPixmap(shirt_w);
                                                  ui->label_12->setPixmap(jacket_w);
                                                  ui->label_10->setPixmap(throusers_w_j);
                                                  if(wardrobe->rain_boots)
                                                      ui->label_11->setPixmap(rain_boots);
                                                  else
                                                      ui->label_11->setPixmap(shoes_w);
                                                  break;
                                    }
                                    break;
                        case summer: switch(h)
                                     {
                                        case low: ui->label_8->setPixmap(QPixmap());
                                                  ui->label_7->setPixmap(QPixmap());
                                                  if(wardrobe->party_dress)
                                                      ui->label_9->setPixmap(dress_s);
                                                  else
                                                        ui->label_9->setPixmap(dress);
                                                  ui->label_9->setGeometry(290, 100, 61, 101);
                                                  ui->label_12->setPixmap(QPixmap());
                                                  ui->label_12->setGeometry(360, 100, 10, 10);
                                                  ui->label_10->setPixmap(QPixmap());
                                                  ui->label_10->setGeometry(290, 202, 10, 10);
                                                  if(wardrobe->shoes_w_j)
                                                      ui->label_11->setPixmap(shoes_w_j);
                                                  else
                                                      ui->label_11->setPixmap(sandals_w);
                                                  break;
                                        case medium:ui->label_8->setPixmap(QPixmap());
                                                    ui->label_7->setPixmap(QPixmap());
                                                    if(wardrobe->party_dress)
                                                        ui->label_9->setPixmap(dress_s);
                                                    else
                                                          ui->label_9->setPixmap(dress);
                                                    ui->label_9->setGeometry(290, 100, 61, 101);
                                                    ui->label_12->setPixmap(QPixmap()); //SKINI VISE VRSTA JAKNI
                                                    ui->label_12->setGeometry(360, 100, 10, 10);
                                                    ui->label_10->setPixmap(QPixmap());
                                                    ui->label_10->setGeometry(290, 202, 10, 10);
                                                    if(wardrobe->shoes_w_j)
                                                        ui->label_11->setPixmap(shoes_w_j);
                                                    else
                                                        ui->label_11->setPixmap(sandals_w);
                                                    break;
                                        case high:ui->label_8->setPixmap(umbrella);
                                                    ui->label_7->setPixmap(QPixmap());
                                                    if(wardrobe->party_dress)
                                                        ui->label_9->setPixmap(dress_s);
                                                    else
                                                          ui->label_9->setPixmap(dress);
                                                    ui->label_9->setGeometry(290, 100, 61, 101);
                                                    ui->label_12->setPixmap(QPixmap()); //SKINI VISE VRSTA JAKNI
                                                    ui->label_12->setGeometry(360, 100, 10, 10);
                                                    ui->label_10->setPixmap(QPixmap());
                                                    ui->label_10->setGeometry(290, 202, 10, 10);
                                                    ui->label_11->setPixmap(heels);
                                                    break;
                                      }
                                      break;
                        case hot: switch(h)
                                  {
                                        case low: ui->label_8->setPixmap(QPixmap());
                                                  ui->label_7->setPixmap(QPixmap());
                                                  if(wardrobe->party_dress)
                                                      ui->label_9->setPixmap(dress_s);
                                                  else
                                                        ui->label_9->setPixmap(dress);
                                                  ui->label_9->setGeometry(290, 100, 61, 101);
                                                  ui->label_12->setPixmap(QPixmap());
                                                  ui->label_12->setGeometry(360, 100, 10, 10);
                                                  ui->label_10->setPixmap(QPixmap());
                                                  ui->label_10->setGeometry(290, 202, 10, 10);
                                                  ui->label_11->setPixmap(sandals_w);
                                                  break;
                                        case medium:ui->label_8->setPixmap(QPixmap());
                                                    ui->label_7->setPixmap(QPixmap());
                                                    if(wardrobe->party_dress)
                                                        ui->label_9->setPixmap(dress_s);
                                                    else
                                                          ui->label_9->setPixmap(dress);
                                                    ui->label_9->setGeometry(290, 100, 61, 101);
                                                    ui->label_12->setPixmap(QPixmap()); //SKINI VISE VRSTA JAKNI
                                                    ui->label_12->setGeometry(360, 100, 10, 10);
                                                    ui->label_10->setPixmap(QPixmap());
                                                    ui->label_10->setGeometry(290, 202, 10, 10);
                                                    ui->label_11->setPixmap(sandals_w);
                                                    break;
                                        case high:ui->label_8->setPixmap(umbrella);
                                                  ui->label_7->setPixmap(QPixmap());
                                                  if(wardrobe->party_dress)
                                                      ui->label_9->setPixmap(dress_s);
                                                  else
                                                        ui->label_9->setPixmap(dress);
                                                  ui->label_9->setGeometry(290, 100, 61, 101);
                                                  ui->label_12->setPixmap(QPixmap()); //SKINI VISE VRSTA JAKNI
                                                  ui->label_12->setGeometry(360, 100, 10, 10);
                                                  ui->label_10->setPixmap(QPixmap());
                                                  ui->label_10->setGeometry(290, 202, 10, 10);
                                                  ui->label_11->setPixmap(heels);
                                                  break;
                                }
                                break;
                    }
                    break;

        case 2: switch(t)
                {
                case winter: switch(h)
                             {
                                case low: if(wardrobe->tie)
                                               ui->label_8->setPixmap(tie);
                                          else
                                                ui->label_8->setPixmap(QPixmap());
                                          ui->label_8->setGeometry(290, 0, 31, 31);
                                          ui->label_7->setPixmap(shirt_m);
                                          ui->label_7->setGeometry(290, 32, 61, 61);
                                          ui->label_9->setPixmap(pullover_m);
                                          if(wardrobe->coat_m)
                                              ui->label_12->setPixmap(coat_m);
                                          else
                                                ui->label_12->setPixmap(winter_jacket_m);
                                          ui->label_10->setPixmap(throusers_m_j);
                                          if(wardrobe->shoes_m_j)
                                              ui->label_11->setPixmap(shoes_m_j);
                                          else
                                              ui->label_11->setPixmap(shoes_m_s);
                                          break;
                                case medium:if(wardrobe->tie)
                                                ui->label_8->setPixmap(tie);
                                            else
                                                ui->label_8->setPixmap(QPixmap());
                                            ui->label_8->setGeometry(290, 0, 31, 31);
                                            ui->label_7->setPixmap(shirt_m);
                                            ui->label_7->setGeometry(290, 32, 61, 61);
                                            ui->label_9->setPixmap(pullover_m);
                                            if(wardrobe->coat_m)
                                                ui->label_12->setPixmap(coat_m);
                                            else
                                                  ui->label_12->setPixmap(winter_jacket_m);
                                            ui->label_10->setPixmap(throusers_m_j);
                                            if(wardrobe->shoes_m_j)
                                                ui->label_11->setPixmap(shoes_m_j);
                                            else
                                                ui->label_11->setPixmap(shoes_m_s);
                                            break;
                                case high:ui->label_8->setPixmap(umbrella);
                                          ui->label_8->setGeometry(290, 0, 31, 31);
                                          ui->label_7->setPixmap(shirt_m);
                                          ui->label_7->setGeometry(290, 32, 61, 61);
                                          ui->label_9->setPixmap(sako_m);
                                          if(wardrobe->coat_m)
                                              ui->label_12->setPixmap(coat_m);
                                          else
                                                ui->label_12->setPixmap(winter_jacket_m);
                                          ui->label_10->setPixmap(throusers_m_j);
                                          ui->label_11->setPixmap(boots_m);
                                          break;
                            }
                            break;
                case spring: switch(h)
                             {
                                case low: if(wardrobe->tie)
                                              ui->label_8->setPixmap(tie);
                                          else
                                              ui->label_8->setPixmap(QPixmap());
                                          ui->label_7->setPixmap(QPixmap());
                                          ui->label_9->setPixmap(shirt_m);
                                          if(wardrobe->sako_m)
                                              ui->label_12->setPixmap(sako_m);
                                          else
                                              ui->label_12->setPixmap(jacket_m);
                                          ui->label_10->setPixmap(throusers_m_j);
                                          if(wardrobe->shoes_m_j)
                                              ui->label_11->setPixmap(shoes_m_j);
                                          else
                                              ui->label_11->setPixmap(shoes_m_s);
                                          break;
                                case medium:if(wardrobe->tie)
                                                ui->label_8->setPixmap(tie);
                                             else
                                                ui->label_8->setPixmap(QPixmap());
                                            ui->label_7->setPixmap(QPixmap());
                                            ui->label_9->setPixmap(shirt_m);
                                            if(wardrobe->sako_m)
                                                ui->label_12->setPixmap(sako_m);
                                            else
                                                ui->label_12->setPixmap(jacket_m);
                                            ui->label_10->setPixmap(throusers_m_j);
                                            if(wardrobe->shoes_m_j)
                                                ui->label_11->setPixmap(shoes_m_j);
                                            else
                                                ui->label_11->setPixmap(shoes_m_s);
                                            break;
                                case high:ui->label_8->setPixmap(umbrella);
                                          ui->label_8->setGeometry(290, 0, 31, 31);
                                          if(wardrobe->tie)
                                               ui->label_7->setPixmap(tie);
                                          else
                                               ui->label_7->setPixmap(QPixmap());
                                          ui->label_7->setGeometry(290, 32, 61, 61);
                                          ui->label_9->setPixmap(shirt_m);
                                          ui->label_12->setPixmap(jacket_m);
                                          ui->label_10->setPixmap(throusers_m_j);
                                          if(wardrobe->shoes_m_j)
                                              ui->label_11->setPixmap(shoes_m_j);
                                          else
                                              ui->label_11->setPixmap(shoes_m_s);
                                          break;
                            }
                            break;
                case summer: switch(h)
                             {
                                case low: ui->label_8->setPixmap(QPixmap());
                                          ui->label_7->setPixmap(QPixmap());
                                          if(wardrobe->polo)
                                                ui->label_9->setPixmap(polo);
                                          else
                                                ui->label_9->setPixmap(shirt_m);
                                          ui->label_9->setGeometry(290, 100, 61, 61);
                                          ui->label_12->setPixmap(QPixmap());
                                          ui->label_12->setGeometry(360, 100, 10, 10);
                                          ui->label_10->setPixmap(throusers_m_j);
                                          if(wardrobe->shoes_m_j)
                                              ui->label_11->setPixmap(shoes_m_j);
                                          else
                                              ui->label_11->setPixmap(shoes_m_s);
                                          break;
                                case medium:ui->label_8->setPixmap(QPixmap());
                                            ui->label_7->setPixmap(QPixmap());                                           
                                            if(wardrobe->polo)
                                                  ui->label_9->setPixmap(polo);
                                            else
                                                  ui->label_9->setPixmap(shirt_m);
                                            ui->label_9->setGeometry(290, 100, 61, 61);
                                            ui->label_12->setPixmap(QPixmap()); //SKINI VISE VRSTA JAKNI
                                            ui->label_12->setGeometry(360, 100, 10, 10);
                                            ui->label_10->setPixmap(throusers_m);
                                            if(wardrobe->shoes_m_j)
                                                ui->label_11->setPixmap(shoes_m_j);
                                            else
                                                ui->label_11->setPixmap(shoes_m_s);
                                            break;
                                case high:ui->label_8->setPixmap(umbrella);
                                          ui->label_7->setPixmap(QPixmap());                                         
                                          if(wardrobe->polo)
                                              ui->label_9->setPixmap(polo);
                                          else
                                              ui->label_9->setPixmap(shirt_m);
                                          ui->label_9->setGeometry(290, 100, 61, 61);
                                          ui->label_12->setPixmap(QPixmap()); //SKINI VISE VRSTA JAKNI
                                          ui->label_12->setGeometry(360, 100, 10, 10);
                                          ui->label_10->setPixmap(throusers_m);
                                          if(wardrobe->shoes_m_j)
                                              ui->label_11->setPixmap(shoes_m_j);
                                          else
                                              ui->label_11->setPixmap(shoes_m_s);
                                          break;
                            }
                            break;
                case hot: switch(h)
                          {
                                case low: ui->label_8->setPixmap(QPixmap());
                                          ui->label_7->setPixmap(QPixmap());
                                          if(wardrobe->polo)
                                              ui->label_9->setPixmap(polo);
                                          else
                                              ui->label_9->setPixmap(shirt_m);
                                          ui->label_9->setGeometry(290, 100, 61, 61);
                                          ui->label_12->setPixmap(QPixmap());
                                          ui->label_12->setGeometry(360, 100, 10, 10);
                                          ui->label_10->setPixmap(throusers_m_j);
                                          if(wardrobe->shoes_m_j)
                                                ui->label_11->setPixmap(shoes_m_j);
                                          else
                                                ui->label_11->setPixmap(shoes_m_s);
                                          break;
                                case medium:ui->label_8->setPixmap(QPixmap());
                                            ui->label_7->setPixmap(QPixmap());                                           
                                            if(wardrobe->polo)
                                                ui->label_9->setPixmap(polo);
                                            else
                                                ui->label_9->setPixmap(shirt_m);
                                            ui->label_9->setGeometry(290, 100, 61, 61);
                                            ui->label_12->setPixmap(QPixmap()); //SKINI VISE VRSTA JAKNI
                                            ui->label_12->setGeometry(360, 100, 10, 10);
                                            ui->label_10->setPixmap(throusers_m_j);
                                            if(wardrobe->shoes_m_j)
                                                ui->label_11->setPixmap(shoes_m_j);
                                            else
                                                ui->label_11->setPixmap(shoes_m_s);
                                            break;
                              case high:ui->label_8->setPixmap(umbrella);
                                        ui->label_7->setPixmap(QPixmap());                                       
                                        if(wardrobe->polo)
                                            ui->label_9->setPixmap(polo);
                                        else
                                            ui->label_9->setPixmap(shirt_m);
                                        ui->label_9->setGeometry(290, 100, 61, 61);
                                        ui->label_12->setPixmap(QPixmap()); //SKINI VISE VRSTA JAKNI
                                        ui->label_12->setGeometry(360, 100, 10, 10);
                                        ui->label_10->setPixmap(throusers_m);
                                        if(wardrobe->shoes_m_j)
                                            ui->label_11->setPixmap(shoes_m_j);
                                        else
                                            ui->label_11->setPixmap(shoes_m_s);
                                        break;
                            }
                            break;
            }
            break;
        }
        break;
    case 3: switch(sex)
                {
                    case 1: switch(t)
                            {
                                case winter: switch(h)
                                            {
                                                case low: ui->label_8->setPixmap(QPixmap());
                                                          ui->label_8->setGeometry(360, 0, 1, 1);
                                                          if(wardrobe->party_dress)
                                                          {
                                                                ui->label_7->setPixmap(dress_s);
                                                                ui->label_7->setGeometry(290, 1, 61, 101);
                                                          }
                                                          else
                                                          {
                                                                ui->label_7->setPixmap(shirt_w);
                                                                ui->label_7->setGeometry(290, 30, 61, 61);
                                                                if(wardrobe->midi_skirt)
                                                                        ui->label_10->setPixmap(midi_skirt);
                                                                else
                                                                        ui->label_10->setPixmap(throusers_w_s);
                                                          }
                                                          ui->label_9->setPixmap(sako_w);
                                                          if(wardrobe->coat_w)
                                                              ui->label_12->setPixmap(coat_w);
                                                          else
                                                              ui->label_12->setPixmap(winter_jacket_w);
                                                          if(wardrobe->boots_w_s)
                                                              ui->label_11->setPixmap(shoes_w_s);
                                                          else
                                                              ui->label_11->setPixmap(high_boots);
                                                          break;
                                                case medium:ui->label_8->setPixmap(QPixmap());
                                                            ui->label_8->setGeometry(360, 0, 1, 1);
                                                            if(wardrobe->party_dress)
                                                            {
                                                                  ui->label_7->setPixmap(dress_s);
                                                                  ui->label_7->setGeometry(290, 1, 61, 101);
                                                            }
                                                            else
                                                            {
                                                                ui->label_7->setPixmap(shirt_w);
                                                                ui->label_7->setGeometry(290, 30, 61, 61);
                                                                if(wardrobe->midi_skirt)
                                                                    ui->label_10->setPixmap(midi_skirt);
                                                                else
                                                                    ui->label_10->setPixmap(throusers_w_s);
                                                            }
                                                            ui->label_9->setPixmap(sako_w);
                                                            if(wardrobe->coat_w)
                                                                ui->label_12->setPixmap(coat_w);
                                                            else
                                                                ui->label_12->setPixmap(winter_jacket_w);
                                                            if(wardrobe->boots_w_s)
                                                                ui->label_11->setPixmap(shoes_w_s);
                                                            else
                                                                ui->label_11->setPixmap(high_boots);
                                                            break;
                                                case high:ui->label_8->setPixmap(umbrella);
                                                          ui->label_7->setPixmap(shirt_w);
                                                          ui->label_7->setGeometry(290, 30, 61, 61);
                                                          if(wardrobe->midi_skirt)
                                                              ui->label_10->setPixmap(midi_skirt);
                                                          else
                                                              ui->label_10->setPixmap(throusers_w_s);
                                                          ui->label_9->setPixmap(sako_w);
                                                          if(wardrobe->coat_w)
                                                              ui->label_12->setPixmap(coat_w);
                                                          else
                                                              ui->label_12->setPixmap(winter_jacket_w);
                                                          ui->label_11->setPixmap(high_boots);
                                                          break;
                                            }
                                            break;
                                case spring: switch(h)
                                             {
                                                case low: ui->label_8->setPixmap(QPixmap());
                                                          ui->label_7->setPixmap(QPixmap());
                                                          ui->label_9->setPixmap(blouse);
                                                          ui->label_12->setPixmap(sako_w);
                                                          if(wardrobe->a_skirt)
                                                              ui->label_10->setPixmap(a_skirt);
                                                          else
                                                              ui->label_10->setPixmap(skirt);
                                                          if(wardrobe->shoes_w_j)
                                                              ui->label_11->setPixmap(shoes_w_j);
                                                          else
                                                              ui->label_11->setPixmap(heels);
                                                          break;
                                                case medium:ui->label_8->setPixmap(QPixmap());
                                                            ui->label_7->setPixmap(QPixmap());
                                                            ui->label_9->setPixmap(blouse);
                                                            ui->label_12->setPixmap(jacket_w);
                                                            if(wardrobe->a_skirt)
                                                                ui->label_10->setPixmap(a_skirt);
                                                            else
                                                                ui->label_10->setPixmap(skirt);
                                                            if(wardrobe->shoes_w_j)
                                                                ui->label_11->setPixmap(shoes_w_j);
                                                            else
                                                                ui->label_11->setPixmap(heels);
                                                            break;
                                                case high:ui->label_8->setPixmap(umbrella);
                                                          ui->label_7->setPixmap(QPixmap());
                                                          ui->label_9->setPixmap(blouse);
                                                          ui->label_12->setPixmap(jacket_w);
                                                          ui->label_10->setPixmap(throusers_w_s);
                                                          ui->label_11->setPixmap(shoes_w);
                                                          break;
                                        }
                                        break;
                                case summer: switch(h)
                                             {
                                                case low: ui->label_8->setPixmap(QPixmap());
                                                          ui->label_7->setPixmap(QPixmap());
                                                          if(wardrobe->dress)
                                                          {
                                                              ui->label_9->setPixmap(dress);
                                                              ui->label_9->setGeometry(290, 100, 61, 101);
                                                              ui->label_10->setPixmap(QPixmap());
                                                              ui->label_10->setGeometry(360, 202, 10, 10);
                                                          }
                                                          else
                                                          {
                                                              ui->label_9->setPixmap(blouse);
                                                              ui->label_9->setGeometry(290, 100, 61, 61);
                                                              if(wardrobe->shortPants_w_s)
                                                                  ui->label_10->setPixmap(shortPants_w_s);
                                                              else
                                                                  ui->label_10->setPixmap(a_skirt);
                                                          }
                                                          ui->label_12->setPixmap(QPixmap());
                                                          ui->label_12->setGeometry(360, 100, 10, 10);
                                                          if(wardrobe->sandals_w)
                                                                ui->label_11->setPixmap(sandals_w);
                                                          else
                                                                ui->label_11->setPixmap(heels);
                                                          break;
                                                case medium:ui->label_8->setPixmap(QPixmap());
                                                            ui->label_7->setPixmap(QPixmap());
                                                            if(wardrobe->dress)
                                                            {
                                                                ui->label_9->setPixmap(dress);
                                                                ui->label_9->setGeometry(290, 100, 61, 101);
                                                                ui->label_10->setPixmap(QPixmap());
                                                                ui->label_10->setGeometry(360, 202, 10, 10);
                                                            }
                                                            else
                                                            {
                                                                ui->label_9->setPixmap(blouse);
                                                                ui->label_9->setGeometry(290, 100, 61, 61);
                                                                if(wardrobe->shortPants_w_s)
                                                                    ui->label_10->setPixmap(shortPants_w_s);
                                                                else
                                                                    ui->label_10->setPixmap(a_skirt);
                                                            }
                                                            ui->label_12->setPixmap(QPixmap());
                                                            ui->label_12->setGeometry(360, 100, 10, 10);
                                                            if(wardrobe->sandals_w)
                                                                ui->label_11->setPixmap(sandals_w);
                                                            else
                                                                ui->label_11->setPixmap(heels);
                                                            break;
                                                case high:ui->label_8->setPixmap(umbrella);
                                                          ui->label_7->setPixmap(QPixmap());
                                                          ui->label_9->setPixmap(blouse);
                                                          ui->label_9->setGeometry(290, 100, 61, 61);
                                                          if(wardrobe->shortPants_w_s)
                                                              ui->label_10->setPixmap(shortPants_w_s);
                                                          else
                                                              ui->label_10->setPixmap(a_skirt);
                                                          ui->label_12->setPixmap(QPixmap());
                                                          ui->label_12->setGeometry(360, 100, 10, 10);
                                                          ui->label_11->setPixmap(heels);
                                                          break;
                                            }
                                            break;
                                case hot: switch(h)
                                          {
                                                case low: ui->label_8->setPixmap(QPixmap());
                                                          ui->label_7->setPixmap(QPixmap());
                                                          if(wardrobe->dress)
                                                          {
                                                              ui->label_9->setPixmap(dress);
                                                              ui->label_9->setGeometry(290, 100, 61, 101);
                                                              ui->label_10->setPixmap(QPixmap());
                                                              ui->label_10->setGeometry(360, 202, 10, 10);
                                                          }
                                                          else
                                                          {
                                                               ui->label_9->setPixmap(blouse);
                                                               ui->label_9->setGeometry(290, 100, 61, 61);
                                                              if(wardrobe->shortPants_w_s)
                                                                  ui->label_10->setPixmap(shortPants_w_s);
                                                              else
                                                                  ui->label_10->setPixmap(a_skirt);
                                                          }
                                                          ui->label_12->setPixmap(QPixmap());
                                                          ui->label_12->setGeometry(360, 100, 10, 10);
                                                          if(wardrobe->sandals_w)
                                                                ui->label_11->setPixmap(sandals_w);
                                                          else
                                                                ui->label_11->setPixmap(heels);
                                                          break;
                                                case medium:ui->label_8->setPixmap(QPixmap());
                                                            ui->label_7->setPixmap(QPixmap());
                                                            if(wardrobe->dress)
                                                            {
                                                                ui->label_9->setPixmap(dress);
                                                                ui->label_9->setGeometry(290, 100, 61, 101);
                                                                ui->label_10->setPixmap(QPixmap());
                                                                ui->label_10->setGeometry(360, 202, 10, 10);
                                                            }
                                                            else
                                                            {
                                                                ui->label_9->setPixmap(blouse);
                                                                ui->label_9->setGeometry(290, 100, 61, 61);
                                                                if(wardrobe->shortPants_w_s)
                                                                    ui->label_10->setPixmap(shortPants_w_s);
                                                                else
                                                                    ui->label_10->setPixmap(a_skirt);
                                                                ui->label_10->setGeometry(290, 170, 61, 61);
                                                            }
                                                            ui->label_12->setPixmap(QPixmap());
                                                            ui->label_12->setGeometry(360, 100, 10, 10);
                                                            if(wardrobe->sandals_w)
                                                                ui->label_11->setPixmap(sandals_w);
                                                            else
                                                                ui->label_11->setPixmap(heels);
                                                            break;
                                            case high:ui->label_8->setPixmap(umbrella);
                                                      ui->label_7->setPixmap(QPixmap());
                                                      ui->label_9->setPixmap(blouse);
                                                      ui->label_9->setGeometry(290, 100, 61, 61);
                                                      if(wardrobe->shortPants_w_s)
                                                          ui->label_10->setPixmap(shortPants_w_s);
                                                      else
                                                          ui->label_10->setPixmap(a_skirt);
                                                      ui->label_12->setPixmap(QPixmap());
                                                      ui->label_12->setGeometry(360, 100, 10, 10);
                                                      ui->label_11->setPixmap(heels);
                                                      break;
                                        }
                                        break;
                            }
                            break;
     case 2: switch(t)
            {
            case winter: switch(h)
                         {
                            case low: if(wardrobe->bow_tie)
                                           ui->label_8->setPixmap(bow_tie);
                                      else
                                            ui->label_8->setPixmap(QPixmap());
                                      ui->label_8->setGeometry(290, 0, 93, 31);
                                      ui->label_7->setPixmap(shirt_m);
                                      ui->label_7->setGeometry(290, 32, 61, 61);
                                      ui->label_9->setPixmap(pullover_m);
                                      if(wardrobe->coat_m)
                                          ui->label_12->setPixmap(coat_m);
                                      else
                                            ui->label_12->setPixmap(winter_jacket_m);
                                      ui->label_10->setPixmap(throusers_m_j);
                                      if(wardrobe->shoes_m_j)
                                          ui->label_11->setPixmap(shoes_m_j);
                                      else
                                          ui->label_11->setPixmap(shoes_m_s);
                                      break;
                            case medium:if(wardrobe->bow_tie)
                                            ui->label_8->setPixmap(bow_tie);
                                        else
                                            ui->label_8->setPixmap(QPixmap());
                                        ui->label_8->setGeometry(290, 0, 93, 31);
                                        ui->label_7->setPixmap(shirt_m);
                                        ui->label_7->setGeometry(290, 32, 61, 61);
                                        ui->label_9->setPixmap(pullover_m);
                                        if(wardrobe->coat_m)
                                            ui->label_12->setPixmap(coat_m);
                                        else
                                              ui->label_12->setPixmap(winter_jacket_m);
                                        ui->label_10->setPixmap(throusers_m_j);
                                        if(wardrobe->shoes_m_j)
                                            ui->label_11->setPixmap(shoes_m_j);
                                        else
                                            ui->label_11->setPixmap(shoes_m_s);
                                        break;
                            case high:ui->label_8->setPixmap(umbrella);
                                      ui->label_7->setGeometry(290, 0, 31, 31);
                                      ui->label_7->setPixmap(shirt_m);
                                      ui->label_7->setGeometry(290, 32, 61, 61);
                                      ui->label_9->setPixmap(sako_m);
                                      if(wardrobe->coat_m)
                                          ui->label_12->setPixmap(coat_m);
                                      else
                                            ui->label_12->setPixmap(winter_jacket_m);
                                      ui->label_10->setPixmap(throusers_m_j);
                                      ui->label_11->setPixmap(boots_m);
                                      break;
                        }
                        break;
            case spring: switch(h)
                         {
                            case low: if(wardrobe->bow_tie)
                                          ui->label_8->setPixmap(bow_tie);
                                      else
                                          ui->label_8->setPixmap(QPixmap());
                                      ui->label_8->setGeometry(290, 0, 93, 31);
                                      ui->label_7->setPixmap(QPixmap());
                                      ui->label_9->setPixmap(shirt_m);
                                      if(wardrobe->sako_m)
                                          ui->label_12->setPixmap(sako_m);
                                      else
                                          ui->label_12->setPixmap(jacket_m);
                                      ui->label_10->setPixmap(throusers_m_j);
                                      if(wardrobe->shoes_m_j)
                                          ui->label_11->setPixmap(shoes_m_j);
                                      else
                                          ui->label_11->setPixmap(shoes_m_s);
                                      break;
                            case medium:if(wardrobe->bow_tie)
                                            ui->label_8->setPixmap(bow_tie);
                                         else
                                            ui->label_8->setPixmap(QPixmap());
                                        ui->label_8->setGeometry(290, 0, 93, 31);
                                        ui->label_7->setPixmap(QPixmap());
                                        ui->label_9->setPixmap(shirt_m);
                                        if(wardrobe->sako_m)
                                            ui->label_12->setPixmap(sako_m);
                                        else
                                            ui->label_12->setPixmap(jacket_m);
                                        ui->label_10->setPixmap(throusers_m_j);
                                        if(wardrobe->shoes_m_j)
                                            ui->label_11->setPixmap(shoes_m_j);
                                        else
                                            ui->label_11->setPixmap(shoes_m_s);
                                        break;
                            case high:ui->label_8->setPixmap(umbrella);
                                      ui->label_8->setGeometry(290, 0, 31, 31);
                                      if(wardrobe->bow_tie)
                                           ui->label_7->setPixmap(bow_tie);
                                      else
                                           ui->label_7->setPixmap(QPixmap());
                                      ui->label_7->setGeometry(290, 32, 93, 31);
                                      ui->label_9->setPixmap(shirt_m);
                                      ui->label_12->setPixmap(jacket_m);
                                      ui->label_10->setPixmap(throusers_m_j);
                                      if(wardrobe->shoes_m_j)
                                          ui->label_11->setPixmap(shoes_m_j);
                                      else
                                          ui->label_11->setPixmap(shoes_m_s);
                                      break;
                        }
                        break;
            case summer: switch(h)
                         {
                            case low: ui->label_8->setPixmap(QPixmap());
                                      ui->label_7->setPixmap(QPixmap());
                                      if(wardrobe->polo)
                                            ui->label_9->setPixmap(polo);
                                      else
                                            ui->label_9->setPixmap(shirt_m);
                                      ui->label_9->setGeometry(290, 100, 61, 61);
                                      ui->label_12->setPixmap(QPixmap());
                                      ui->label_12->setGeometry(360, 100, 10, 10);
                                      ui->label_10->setPixmap(throusers_m_j);
                                      if(wardrobe->shoes_m_j)
                                          ui->label_11->setPixmap(shoes_m_j);
                                      else
                                          ui->label_11->setPixmap(shoes_m_s);
                                      break;
                            case medium:ui->label_8->setPixmap(QPixmap());
                                        ui->label_7->setPixmap(QPixmap());                                       
                                        if(wardrobe->polo)
                                              ui->label_9->setPixmap(polo);
                                        else
                                              ui->label_9->setPixmap(shirt_m);
                                        ui->label_9->setGeometry(290, 100, 61, 61);
                                        ui->label_12->setPixmap(QPixmap()); //SKINI VISE VRSTA JAKNI
                                        ui->label_12->setGeometry(360, 100, 10, 10);
                                        ui->label_10->setPixmap(throusers_m);
                                        if(wardrobe->shoes_m_j)
                                            ui->label_11->setPixmap(shoes_m_j);
                                        else
                                            ui->label_11->setPixmap(shoes_m_s);
                                        break;
                            case high:ui->label_8->setPixmap(umbrella);
                                      ui->label_7->setPixmap(QPixmap());                                      
                                      if(wardrobe->polo)
                                          ui->label_9->setPixmap(polo);
                                      else
                                          ui->label_9->setPixmap(shirt_m);
                                      ui->label_9->setGeometry(290, 100, 61, 61);
                                      ui->label_12->setPixmap(QPixmap()); //SKINI VISE VRSTA JAKNI
                                      ui->label_12->setGeometry(360, 100, 10, 10);
                                      ui->label_10->setPixmap(throusers_m_j);
                                      if(wardrobe->shoes_m_j)
                                          ui->label_11->setPixmap(shoes_m_j);
                                      else
                                          ui->label_11->setPixmap(shoes_m_s);
                                      break;
                        }
                        break;
            case hot: switch(h)
                      {
                            case low: ui->label_8->setPixmap(QPixmap());
                                      ui->label_7->setPixmap(QPixmap());
                                      if(wardrobe->polo)
                                          ui->label_9->setPixmap(polo);
                                      else
                                          ui->label_9->setPixmap(shirt_m);
                                      ui->label_9->setGeometry(290, 100, 61, 61);
                                      ui->label_12->setPixmap(QPixmap());
                                      ui->label_12->setGeometry(360, 100, 10, 10);
                                      ui->label_10->setPixmap(throusers_m_j);
                                      if(wardrobe->shoes_m_j)
                                            ui->label_11->setPixmap(shoes_m_j);
                                      else
                                            ui->label_11->setPixmap(shoes_m_s);
                                      break;
                            case medium:ui->label_8->setPixmap(QPixmap());
                                        ui->label_7->setPixmap(QPixmap());                                        
                                        if(wardrobe->polo)
                                            ui->label_9->setPixmap(polo);
                                        else
                                            ui->label_9->setPixmap(shirt_m);
                                        ui->label_9->setGeometry(290, 100, 61, 61);
                                        ui->label_12->setPixmap(QPixmap()); //SKINI VISE VRSTA JAKNI
                                        ui->label_12->setGeometry(360, 100, 10, 10);
                                        ui->label_10->setPixmap(throusers_m_j);
                                        if(wardrobe->shoes_m_j)
                                            ui->label_11->setPixmap(shoes_m_j);
                                        else
                                            ui->label_11->setPixmap(shoes_m_s);
                                        break;
                          case high:ui->label_8->setPixmap(umbrella);
                                    ui->label_7->setPixmap(QPixmap());                                  
                                    if(wardrobe->polo)
                                        ui->label_9->setPixmap(polo);
                                    else
                                        ui->label_9->setPixmap(shirt_m);
                                    ui->label_9->setGeometry(290, 100, 61, 61);
                                    ui->label_12->setPixmap(QPixmap()); //SKINI VISE VRSTA JAKNI
                                    ui->label_12->setGeometry(360, 100, 10, 10);
                                    ui->label_10->setPixmap(throusers_m);
                                    if(wardrobe->shoes_m_j)
                                        ui->label_11->setPixmap(shoes_m_j);
                                    else
                                        ui->label_11->setPixmap(shoes_m_s);
                                    break;
                                        }
                                        break;
                    }
                    break;
        }
        break;
  }
}






