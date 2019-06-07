# get os 
os=`uname -a`
case $os in 
	Darwin*)
	git clone https://github.com/kube/42homebrew.git
	sh ./42homebrew/install.sh
	source ~/.zshrc
	brew install sdl2
	brew install sdl2_image
	brew install sdl2_ttf
	brew install cmake
	;;
	Linux*)
	sudo -i apt-get install libsdl2-dev
	sudo -i apt-get install libsdl2-image2.0 libsdl2-image2-dev
	sudo -i apt-get install libsdl2-ttf2.0 libsdl2-ttf2-dev
	sudo -i apt-get install cmake
	;;
	*)
	;;
esac
	git clone https://github.com/gmonacho/Build_Vik_Wrap.git

