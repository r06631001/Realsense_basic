#include "realsense.hpp"
#include "ui_realsense.h"

Realsense::Realsense(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Realsense)
{
    ui->setupUi(this);
}

Realsense::~Realsense()
{
    delete ui;
}

void Realsense::on_pushButton_clicked()
{

    // Create a Pipeline, which serves as a top-level API for streaming and processing frames
    rs2::pipeline p;
    //Create a configuration for configuring the pipeline with a non default profile
    rs2::config cfg;
    cfg.enable_stream(RS2_STREAM_COLOR, 1280, 720, RS2_FORMAT_BGR8, 30);
    cfg.enable_stream(RS2_STREAM_INFRARED, 1280, 720, RS2_FORMAT_Y8, 30);
    cfg.enable_stream(RS2_STREAM_DEPTH, 1280, 720, RS2_FORMAT_Z16, 30);
    qDebug() << "finish enable";


    p.start(cfg);
    rs2::align align_to(RS2_STREAM_COLOR);

    cv::VideoWriter video_writer_rgb, video_writer_depth, video_writer_scale_depth;
    video_writer_rgb.open("video/video_RGB.avi", CV_FOURCC('M', 'J', 'P', 'G'), 30, cv::Size(1280, 720));
    video_writer_depth.open("video/video_depth.avi", CV_FOURCC('M', 'J', 'P', 'G'), 30, cv::Size(1280, 720));
    video_writer_scale_depth.open("video/video_scale_depth.avi", CV_FOURCC('M', 'J', 'P', 'G'), 30, cv::Size(1280, 720));

    while (1)
    {
        auto data = p.wait_for_frames();
        data = align_to.process(data);
        auto color_frame = data.get_color_frame();
        rs2::depth_frame depth_frame = data.get_depth_frame();
        cv::Mat color(cv::Size(1280, 720), CV_8UC3, (void*)color_frame.get_data(), cv::Mat::AUTO_STEP);
        cv::Mat depth(cv::Size(1280, 720), CV_16SC1, (void*)depth_frame.get_data(), cv::Mat::AUTO_STEP);


        qDebug() << depth.at<ushort>(640, 360);
        qDebug() << depth_frame.get_distance(640, 360);

        cv::Mat scale_mat;
        depth.convertTo( scale_mat, CV_8U, -255.0 / 10000.0, 255.0 ); // 0-10000 -> 255(white)-0(black)
        applyColorMap(scale_mat, scale_mat, cv::COLORMAP_JET );

        cv::imshow("Color Image", color);
        cv::imshow("Depth Image", scale_mat);

        video_writer_rgb.write(color);
        video_writer_scale_depth.write(scale_mat);
        cv::imwrite("depth.jpg", depth);

        cv::waitKey(33);
    }
    p.stop();
}

void Realsense::on_actionExit_triggered()
{
    exit(1);
}
