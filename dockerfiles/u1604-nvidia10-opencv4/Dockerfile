# Goals
# opencv 4 installed with python
# developer user with sudo
# expose x11
# expose video

FROM nvidia/cuda:10.0-devel-ubuntu16.04

RUN apt-get update && \
    apt-get install -y sudo

# opencv 4
RUN apt-get -y remove x264 libx264-dev

## Install dependencies
RUN apt-get -y install build-essential checkinstall cmake pkg-config yasm && \
    apt-get -y install git gfortran && \
    apt-get -y install libjpeg8-dev libjasper-dev libpng12-dev

RUN apt-get -y install libtiff5-dev && \
    apt-get -y install libtiff-dev

RUN apt-get -y install libavcodec-dev libavformat-dev libswscale-dev libdc1394-22-dev && \
    apt-get -y install libxine2-dev libv4l-dev

RUN cd /usr/include/linux && \
    ln -s -f ../libv4l1-videodev.h videodev.h
RUN cd /

RUN apt-get -y install libgstreamer0.10-dev libgstreamer-plugins-base0.10-dev && \
    apt-get -y install libgtk2.0-dev libtbb-dev qt5-default && \
    apt-get -y install libatlas-base-dev && \
    apt-get -y install libfaac-dev libmp3lame-dev libtheora-dev && \
    apt-get -y install libvorbis-dev libxvidcore-dev && \
    apt-get -y install libopencore-amrnb-dev libopencore-amrwb-dev && \
    apt-get -y install libavresample-dev && \
    apt-get -y install x264 v4l-utils

# Optional dependencies
RUN apt-get -y install libprotobuf-dev protobuf-compiler && \
    apt-get -y install libgoogle-glog-dev libgflags-dev && \
    apt-get -y install libgphoto2-dev libeigen3-dev libhdf5-dev doxygen

# python
RUN apt-get -y install python3-dev python3-pip  && \
    pip3 install -U pip numpy  && \
    apt-get -y install python3-testresources

# fetch sources
RUN mkdir /github && \
    cd /github && \
    git clone https://github.com/opencv/opencv.git && \
    cd /github/opencv && \
    git checkout master

RUN cd /github && \
    git clone https://github.com/opencv/opencv_contrib.git && \
    cd /github/opencv_contrib && \
    git checkout master


# build them
RUN cd /github/opencv && mkdir build && cd /github/opencv/build && cmake \
            -D CMAKE_BUILD_TYPE=RELEASE \
            -D CMAKE_INSTALL_PREFIX=/usr/local \
            -D INSTALL_C_EXAMPLES=ON \
            -D INSTALL_PYTHON_EXAMPLES=ON \
            -D WITH_TBB=ON \
            -D WITH_V4L=ON \
            -D OPENCV_PYTHON3_INSTALL_PATH=/OpenCV-master-py3/lib/python3.5/site-packages \
            -D WITH_QT=ON \
            -D WITH_OPENGL=ON \
            -D OPENCV_EXTRA_MODULES_PATH=/github/opencv_contrib/modules \
            -D BUILD_EXAMPLES=ON \
            /github/opencv


RUN cd /github/opencv/build && make -j4 && make install

# dlib
RUN apt-get -y install libopenblas-dev liblapack-dev && \
    apt-get -y install libx11-dev libgtk-3-dev

RUN cd /github && \
    git clone https://github.com/davisking/dlib.git && \
    cd dlib && \
    mkdir build && \
    cd build  && \
    cmake .. -DUSE_AVX_INSTRUCTIONS=ON && \
    cmake --build . --config Release && \
    make -j4 && \
    make install && \
    ldconfig



