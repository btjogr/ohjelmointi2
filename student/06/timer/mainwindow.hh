#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    // Normally this member should be in private part of the
    // class, but due to the automated tests it must be more
    // accessible.
    QTimer* timer_;

private slots:
    // Add your slots here

    void timer_slot();
    void on_stopButton_clicked();

    void on_startButton_clicked();

    void on_resetButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    int second=0;
    int minute=0;

    // Add other necessary members here
};

#endif // MAINWINDOW_HH
