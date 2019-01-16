# try-opencv
sandbox for opencv

# run
```bash
docker pull spmallick/opencv-docker:opencv-4
sudo docker run -u root --privileged --device=/dev/video0:/dev/video0 -v ~/github/try-opencv:/home/jovyan/code -v /tmp/.X11-unix:/tmp/.X11-unix -e DISPLAY=$DISPLAY -p 5000:5000 -p 8888:8888 -it spmallick/opencv-docker:opencv-4 /bin/bash
```

# run in guest
```bash
usermod -a -G video jovyan
su - jovyan

cd code/src
mkdir build
cd build
cmake ..
cmake --build . --config Release
./version 
```


# TODO
* use dockerfile to add jovyan to video group
