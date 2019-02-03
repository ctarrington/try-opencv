# try-opencv
sandbox for opencv

# run in host 
```bash
cd dockerfiles/u1604-nvidia10-opencv4
docker build -t ct/opencv4 .
# get coffee
cd ../development/basic
docker build -t ct/opencv4-dev
docker run --device=/dev/video0:/dev/video0 -v ~/github/try-opencv/src:/home/developer/src -v /tmp/.X11-unix:/tmp/.X11-unix -e DISPLAY=$DISPLAY -p 5000:5000 -p 8888:8888 -it ct/opencv4-dev /bin/bash
```

# run in guest
```bash
cd src
mkdir build
cd build
cmake ..
cmake --build . --config Release
./version 
./video
```


# TODO
* use dockerfile to add jovyan to video group
