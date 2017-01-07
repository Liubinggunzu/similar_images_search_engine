#ifndef IMAGESWINDOW_H
#define IMAGESWINDOW_H

#include <QMainWindow>
#include <QThread>
#include "src/Workers/QueryWorker.hpp"

namespace Ui {
class ImagesWindow;
}

class ImagesWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ImagesWindow(BOW * b, QString selectedImage, int nImgs, QWidget *parent = 0);
    ~ImagesWindow();

private slots:
    void getData(QList<QString>);

private:
    Ui::ImagesWindow *ui;
    BOW * bow;
};

#endif // IMAGESWINDOW_H
