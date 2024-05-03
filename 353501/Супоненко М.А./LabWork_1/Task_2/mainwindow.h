#pragma once

#include <QMainWindow>
#include <QTimer>
#include <QResizeEvent>

#include "paintscene.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    PaintScene *scene;  // Объявляем кастомную графическую сцену
    QTimer *timer;      /* Определяем таймер для подготовки актуальных размеров
                         * графической сцены
                         * */
private:
    /* Переопределяем событие изменения размера окна
     * для пересчёта размеров графической сцены
     * */
    void resizeEvent(QResizeEvent * event);

private slots:
    // Таймер для изменения размеров сцены при изменении размеров Окна приложения
    void slotTimer();
    void on_pushButton_clicked();       // Включаем отрисовку Ромба
    void on_pushButton_2_clicked();     // Включаем отрисовку Прямоугольника
    void on_pushButton_3_clicked();     // Включаем отрисовку Треугольника
    void on_pushButton_4_clicked();     // Включаем отрисовку Круга
    void on_pushButton_5_clicked();     // Включаем отрисовку Квадрата
    void on_pushButton_6_clicked();     // Включаем отрисовку Звезда 5
    void on_pushButton_7_clicked();     // Включаем отрисовку Шестиугольник
    void on_pushButton_8_clicked();     // Включаем отрисовку Звезда 6
    void on_pushButton_9_clicked();     // Включаем отрисовку Звезда 8
    void on_pushButton_10_clicked();    // Включаем отрисовку другой фигуры
    void on_pushButton_11_clicked();    // Включаем отрисовку рисунка

    void on_spinBox_valueChanged(int x);  // угол
    void on_spinBox_2_valueChanged(int x);
    void on_spinBox_3_valueChanged(int x);
    void on_doubleSpinBox_valueChanged(qreal x);   // масштаб

};

