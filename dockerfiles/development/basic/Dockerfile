FROM ct/opencv4

# user setup
RUN useradd -m -d /home/developer \
    -s /bin/bash \
    -G sudo,video \
    -u 1000 \
    -p "$(openssl passwd -1 developer)" \
    developer

USER developer
WORKDIR /home/developer