FROM ct/opencv4

RUN apt-get update && apt-get install -y tree curl wget vim git-core gnome-terminal
RUN apt-get install -y zsh

RUN cd /tmp && \
    wget https://download.jetbrains.com/cpp/CLion-2018.3.4.tar.gz && \
    tar xzf CLion-2018.3.4.tar.gz -C /opt/

# user setup
RUN useradd -m -d /home/developer \
    -s /bin/bash \
    -G sudo,video \
    -u 1000 \
    -p "$(openssl passwd -1 developer)" \
    developer


USER developer
WORKDIR /home/developer

RUN echo "developer" | sh -c "$(wget https://raw.githubusercontent.com/robbyrussell/oh-my-zsh/master/tools/install.sh -O -)"
RUN git clone https://github.com/zsh-users/zsh-history-substring-search ${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/plugins/zsh-history-substring-search

RUN sed -i 's/plugins=(git)/plugins=(git history-substring-search)/' .zshrc
RUN sed -i 's/ZSH_THEME="robbyrussell"/ZSH_THEME="kphoen"/' .zshrc

RUN echo "setopt rmstarsilent" >> .zshrc
RUN echo "export PATH=$PATH:/opt/clion-2018.3.4/bin/gdb/linux/bin" >> .zshrc

