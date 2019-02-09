# try-opencv
sandbox for opencv

# run in host 
```bash
cd dockerfiles/u1604-nvidia10-opencv4
docker build -t ct/opencv4 .
# get coffee

cd ../development/basic
docker build -t ct/opencv4-dev .
docker run --rm -h opencv-dev --device=/dev/video0:/dev/video0 -v ~/github/try-opencv/src:/home/developer/src -v /tmp/.X11-unix:/tmp/.X11-unix -e DISPLAY=$DISPLAY -p 5000:5000 -p 8888:8888 --cap-add=SYS_PTRACE --security-opt seccomp=unconfined -it ct/opencv4-dev /bin/zsh
```

# run in guest
```bash
# once to setup editor
sh /opt/clion-2018.3.4/bin/clion.sh
# setup and log in
```

# run in host before exiting guest
```bash
docker commit <container_id> ct/opencv4-dev-clion
```

# normal use
```bash
host > docker run --rm -h opencv-dev --device=/dev/video0:/dev/video0 -v ~/github/try-opencv/src:/home/developer/src -v /tmp/.X11-unix:/tmp/.X11-unix -e DISPLAY=$DISPLAY -p 5000:5000 -p 8888:8888 --cap-add=SYS_PTRACE --security-opt seccomp=unconfined -it ct/opencv4-dev-clion /bin/zsh
guest > /opt/clion-2018.3.4/bin/clion.sh &
```

# from the command line in the guest
```bash
cd src
mkdir build
cd build
cmake ..
cmake --build . --config Release
./version 
./video
```

# Handy docker scripts
```bash
docker rmi (docker images|grep none| sed 's/\s\+/ /g' | cut -d' ' -f3)
```

# TODO