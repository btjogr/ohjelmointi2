#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QSlider>
#include <QGridLayout>
#include <QPixmap>
#include <QColor>
#include <QSpinBox>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


    const int LEFT_MARGIN = 20;
    const int TOP_MARGIN = 20;
    const int BUTTON_WIDTH = 50;
    const int BUTTON_HEIGTH = 30;





private slots:
    void onColorChanged();

private:
    QSlider* horizontalSliderRed;
    QSlider* horizontalSliderGreen;
    QSlider* horizontalSliderBlue;
    QLabel* colorLabel;
    const int RGB_VALUE_MAX = 255;


    QSpinBox* spinBoxRed;
    QSpinBox* spinBoxGreen;
    QSpinBox* spinBoxBlue;


};

#endif // MAINWINDOW_HH
