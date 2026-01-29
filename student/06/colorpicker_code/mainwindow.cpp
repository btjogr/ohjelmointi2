#include "mainwindow.hh"
#include <QLabel>
#include <QSlider>
#include <QGridLayout>
#include <QPixmap>
#include <QColor>

#define LEFT_MARGIN 10
#define TOP_MARGIN 10
#define BUTTON_WIDTH 100
#define BUTTON_HEIGHT 40
#define RGB_VALUE_MAX 255

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    colorLabel = new QLabel(this);
    colorLabel->setFixedSize(64, 64);

    // Luodaan central-widget ja layout
    QWidget* central = new QWidget(this);
    QGridLayout* gLayout = new QGridLayout(central);

    // --- RED ---
    horizontalSliderRed = new QSlider(Qt::Horizontal, this);
    horizontalSliderRed->setRange(0, RGB_VALUE_MAX);
    horizontalSliderRed->setValue(0);

    spinBoxRed = new QSpinBox(this);
    spinBoxRed->setRange(0, RGB_VALUE_MAX);
    spinBoxRed->setValue(0);

    connect(horizontalSliderRed, &QSlider::valueChanged, spinBoxRed, &QSpinBox::setValue);
    connect(spinBoxRed, QOverload<int>::of(&QSpinBox::valueChanged), horizontalSliderRed, &QSlider::setValue);
    connect(horizontalSliderRed, &QSlider::valueChanged, this, &MainWindow::onColorChanged);

    QHBoxLayout* redLayout = new QHBoxLayout;
    redLayout->addWidget(horizontalSliderRed);
    redLayout->addWidget(spinBoxRed);

    // --- GREEN ---
    horizontalSliderGreen = new QSlider(Qt::Horizontal, this);
    horizontalSliderGreen->setRange(0, RGB_VALUE_MAX);
    horizontalSliderGreen->setValue(0);

    spinBoxGreen = new QSpinBox(this);
    spinBoxGreen->setRange(0, RGB_VALUE_MAX);
    spinBoxGreen->setValue(0);

    connect(horizontalSliderGreen, &QSlider::valueChanged, spinBoxGreen, &QSpinBox::setValue);
    connect(spinBoxGreen, QOverload<int>::of(&QSpinBox::valueChanged), horizontalSliderGreen, &QSlider::setValue);
    connect(horizontalSliderGreen, &QSlider::valueChanged, this, &MainWindow::onColorChanged);

    QHBoxLayout* greenLayout = new QHBoxLayout;
    greenLayout->addWidget(horizontalSliderGreen);
    greenLayout->addWidget(spinBoxGreen);

    // --- BLUE ---
    horizontalSliderBlue = new QSlider(Qt::Horizontal, this);
    horizontalSliderBlue->setRange(0, RGB_VALUE_MAX);
    horizontalSliderBlue->setValue(0);

    spinBoxBlue = new QSpinBox(this);
    spinBoxBlue->setRange(0, RGB_VALUE_MAX);
    spinBoxBlue->setValue(0);

    connect(horizontalSliderBlue, &QSlider::valueChanged, spinBoxBlue, &QSpinBox::setValue);
    connect(spinBoxBlue, QOverload<int>::of(&QSpinBox::valueChanged), horizontalSliderBlue, &QSlider::setValue);
    connect(horizontalSliderBlue, &QSlider::valueChanged, this, &MainWindow::onColorChanged);

    QHBoxLayout* blueLayout = new QHBoxLayout;
    blueLayout->addWidget(horizontalSliderBlue);
    blueLayout->addWidget(spinBoxBlue);

    spinBoxRed->setObjectName("spinBoxRed");
    spinBoxGreen->setObjectName("spinBoxGreen");
    spinBoxBlue->setObjectName("spinBoxBlue");
    horizontalSliderRed->setObjectName("horizontalSliderRed");
    horizontalSliderGreen->setObjectName("horizontalSliderGreen");
    horizontalSliderBlue->setObjectName("horizontalSliderBlue");

    // --- Layout ---
    gLayout->addWidget(colorLabel, 0, 0);
    gLayout->addLayout(redLayout, 1, 0);
    gLayout->addLayout(greenLayout, 2, 0);
    gLayout->addLayout(blueLayout, 3, 0);

    setCentralWidget(central);
}


MainWindow::~MainWindow()
{
    // Tarvittaessa voisi poistaa luodut widgetit, mutta Qt hoitaa tämän itse
}

void MainWindow::onColorChanged()
{
    // Saadaan liukusäätimistä väriarvot
    int red = horizontalSliderRed->value();
    int green = horizontalSliderGreen->value();
    int blue = horizontalSliderBlue->value();

    // Luodaan uusi väri valituista arvosta
    QColor selectedColor(red, green, blue);

    // Luodaan pixmap ja täytetään se valitulla värillä
    QPixmap colorMap(64, 64);
    colorMap.fill(selectedColor);

    // Asetetaan pixmap QLabel:iin, jotta väri näkyy
    colorLabel->setPixmap(colorMap);
}
