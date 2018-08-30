#ifndef REALSENSE_HPP
#define REALSENSE_HPP

#include <QMainWindow>
#include <librealsense2/rs.hpp>
#include <opencv.hpp>

#include <QDebug>

namespace Ui {
class Realsense;
}

class Realsense : public QMainWindow
{
    Q_OBJECT

public:
    explicit Realsense(QWidget *parent = 0);
    ~Realsense();

private slots:
    void on_pushButton_clicked();

    void on_actionExit_triggered();

private:
    Ui::Realsense *ui;
    cv::Mat kk;
};

#endif // REALSENSE_HPP
