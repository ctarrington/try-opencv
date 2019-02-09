FROM ct/opencv4

RUN apt-get update && apt-get install -y tree curl wget vim git-core gnome-terminal
RUN apt-get install -y zsh

RUN cd /tmp && \
    wget https://download.jetbrains.com/cpp/CLion-2018.3.4.tar.gz && \
    tar xvzf CLion-2018.3.4.tar.gz -C /opt/

# user setup
RUN useradd -m -d /home/developer \
    -s /usr/bin/zsh \
    -G sudo,video \
    -u 1000 \
    -p "$(openssl passwd -1 developer)" \
    developer

RUN echo "HISTFILE=~/.histfile" >> /home/developer/.zshrc && \
    echo "HISTSIZE=1000" >> /home/developer/.zshrc && \
    echo "SAVEHIST=1000" >> /home/developer/.zshrc && \
    echo "zstyle :compinstall filename '/home/developer/.zshrc'" >> /home/developer/.zshrc && \
    echo "autoload -Uz compinit" >> /home/developer/.zshrc && \
    echo "compinit" >> /home/developer/.zshrc && \
    echo "export PROMPT='%m %/ >'" >> /home/developer/.zshrc && \
    chown developer /home/developer/.zshrc

USER developer
WORKDIR /home/developer
