
#include "QOpenCVWidget.h"

// Constructor
QOpenCVWidget::QOpenCVWidget(QWidget *parent) : QWidget(parent)
{


    layout = new QVBoxLayout;
    imagelabel = new QLabel;
    QImage dummy(100,100,QImage::Format_RGB32);
    image = dummy;
    layout->addWidget(imagelabel);
    for (int x = 0; x < 100; x ++) {
        for (int y =0; y < 100; y++) {
            image.setPixel(x,y,qRgb(x, y, y));
        }
    }
    imagelabel->setPixmap(QPixmap::fromImage(image));

    setLayout(layout);

#ifdef _TEST_
    initBuffer();
    initServer();
    Connection();
#endif

}

QOpenCVWidget::~QOpenCVWidget(void) {
    
}

void QOpenCVWidget::putImage(IplImage *cvimage,int flag) {
    int cvIndex, cvLineStart;
    // switch between bit depths
    switch (cvimage->depth) {
        case IPL_DEPTH_8U:
            switch (cvimage->nChannels) {
                case 3:
                    if ( (cvimage->width != image.width()) || (cvimage->height != image.height()) ) {
                        QImage temp(cvimage->width, cvimage->height, QImage::Format_RGB32);
                        image = temp;
                    }
                    cvIndex = 0; cvLineStart = 0;
                    for (int y = 0; y < cvimage->height; y++) { //高
                        unsigned char red,green,blue;
                        cvIndex = cvLineStart;
                        for (int x = 0; x < cvimage->width; x++) {
                            // DO it
                            red = cvimage->imageData[cvIndex+2];
                            green = cvimage->imageData[cvIndex+1];
                            blue = cvimage->imageData[cvIndex+0];
                            
                            image.setPixel(x,y,qRgb(red, green, blue));
                            cvIndex += 3;
                        }
                        cvLineStart += cvimage->widthStep;                        
                    }
                    break;
                default:
                    printf("This number of channels is not supported\n");
                    break;
            }
            break;
        default:
            printf("This type of IplImage is not implemented in QOpenCVWidget\n");
            break;
    }

//qDebug() << "init image" <<image.size()<<image_data.size();
//qDebug() << image.data_ptr();

//    QBuffer buf(&image_data);
//    buf.open(QIODevice::WriteOnly);
//    image.save(&buf);

   // imagelabel->setPixmap(QPixmap::fromImage(image));
#ifdef _TEST_
    image_data.clear();
    image_data.append((const char *)image.bits(),image.byteCount());

    qDebug() << "init image" <<image.byteCount() <<image_data.size();




    writed =-1;
    filesize=0;
    emit imageReady((qint64)image_data.size());
#else

    if(flag) image.save("/tmp/timage.png","PNG");

#endif
    //if(flag) initImage();


}

void QOpenCVWidget::initImage()
{

    //QByteArray image_data;
    image_data.clear();
    QBuffer buf(&image_data);
    buf.open(QIODevice::WriteOnly);

    if ( image.save(&buf) )
    {
     qDebug() << "init image" << image_data.size();
     emit imageReady((qint64)sizeof(qint64));
    }
}

void QOpenCVWidget::initBuffer()
{
//    buf.setBuffer(&image_data);
//    buf.open(QIODevice::WriteOnly);
}

void QOpenCVWidget::initServer()
{

//    this->setWindowTitle(tr("ImageShow_send"));
//    connect(&tcp_client,SIGNAL(connected()),this,SLOT(openimage()));
    connect(this,SIGNAL(imageReady(qint64)),this,SLOT(SendData(qint64)));
    connect(&tcp_client,SIGNAL(bytesWritten(qint64)),this,SLOT(SendData(qint64)));

}
void QOpenCVWidget::Connection()
{
        tcp_client.connectToHost(QHostAddress::LocalHost,3333);
}


void QOpenCVWidget::SendData(qint64 towrite)
{
        if(writed==-1)
        {
                filesize = image_data.size();
                tcp_client.write((char *)&filesize,sizeof(int));
                writed=0;
                QString size;
                size.setNum(filesize);
               // QMessageBox::about(this,tr("错误"),size);
                return;

        }
        if(writed<filesize)
        {
                towrite = 65536;
                if((writed+65536)>filesize) towrite=filesize-writed;
                writed += (int)tcp_client.write((image_data.data()+writed),towrite);
                if(writed>=filesize)
                {
                                QString size;
                                size.setNum(writed);
                                QMessageBox::about(this,tr("错误"),size);
                }
        }
}

