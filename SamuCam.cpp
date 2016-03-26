/**
 * @brief Samu has learnt the rules of Conway's Game of Life
 *
 * @file GameOfLife.h
 * @author  Norbert Bátfai <nbatfai@gmail.com>
 * @version 0.0.1
 *
 * @section LICENSE
 *
 * Copyright (C) 2015, 2016 Norbert Bátfai, batfai.norbert@inf.unideb.hu
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @section DESCRIPTION
 *
 * SamuBrain, exp. 4, cognitive mental organs: MPU (Mental Processing Unit), Q-- lerning, acquiring higher-order knowledge
 *
 * This is an example of the paper entitled "Samu in his prenatal development".
 *
 * Previous experiments
 *
 * Samu (Nahshon)
 * http://arxiv.org/abs/1511.02889
 * https://github.com/nbatfai/nahshon
 *
 * SamuLife
 * https://github.com/nbatfai/SamuLife
 * https://youtu.be/b60m__3I-UM
 *
 * SamuMovie
 * https://github.com/nbatfai/SamuMovie
 * https://youtu.be/XOPORbI1hz4
 *
 * SamuStroop
 * https://github.com/nbatfai/SamuStroop
 * https://youtu.be/6elIla_bIrw
 * https://youtu.be/VujHHeYuzIk
 */


#include "SamuCam.h"

SamuCam::SamuCam ( std::string videoStream, int width = 176, int height = 144 )
  : videoStream ( videoStream ), width ( width ), height ( height )
{
  openVideoStream();
}

SamuCam::~SamuCam ()
{
}

void SamuCam::openVideoStream()
{
  videoCapture.open ( videoStream );

  videoCapture.set ( CV_CAP_PROP_FRAME_WIDTH, width );
  videoCapture.set ( CV_CAP_PROP_FRAME_HEIGHT, height );
  videoCapture.set ( CV_CAP_PROP_FPS, 10 );
}

void SamuCam::run()
{

  cv::CascadeClassifier faceClassifier;

  std::string faceXML = "lbpcascade_frontalface.xml"; // https://github.com/Itseez/opencv/tree/master/data/lbpcascades

  if ( !faceClassifier.load ( faceXML ) )
    {
      qDebug() << "error: cannot found" << faceXML.c_str();
      return;
    }

  cv::Mat frame;

  while ( videoCapture.isOpened() )
    {

      QThread::msleep ( 50 );
      while ( videoCapture.read ( frame ) )
        {

          if ( !frame.empty() )
            {

              cv::resize ( frame, frame, cv::Size ( 176, 144 ), 0, 0, cv::INTER_CUBIC );

              std::vector<cv::Rect> faces;
              cv::Mat grayFrame;

              cv::cvtColor ( frame, grayFrame, cv::COLOR_BGR2GRAY );
              cv::equalizeHist ( grayFrame, grayFrame );

              faceClassifier.detectMultiScale ( grayFrame, faces, 1.1, 3, 0, cv::Size ( 60, 60 ) );

              if ( faces.size() > 0 )
                {

                  cv::Mat onlyFace = frame ( faces[0] ).clone();

                  QImage* face = new QImage ( onlyFace.data,
                                              onlyFace.cols,
                                              onlyFace.rows,
                                              onlyFace.step,
                                              QImage::Format_RGB888 );

                  cv::Point x ( faces[0].x-1, faces[0].y-1 );
                  cv::Point y ( faces[0].x + faces[0].width+2, faces[0].y + faces[0].height+2 );
                  cv::rectangle ( frame, x, y, cv::Scalar ( 240, 230, 200 ) );


                  emit  faceChanged ( face );
                }

              QImage*  webcam = new QImage ( frame.data,
                                             frame.cols,
                                             frame.rows,
                                             frame.step,
                                             QImage::Format_RGB888 );

              emit  webcamChanged ( webcam );

            }

          QThread::msleep ( 80 );

        }

      if ( ! videoCapture.isOpened() )
        {
          openVideoStream();
        }

    }

}