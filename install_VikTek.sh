
git clone https://github.com/gmonacho/Build_Vik_Wrap.git
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
	sudo apt-get install libsdl2-dev
	sudo apt-get install libsdl-image2-dev
	sudo apt-get install libsdl-ttf2.0-dev
	sudo apt-get install cmake
	cp ./Build_Vik_Wrap/lib/libVik_Wrap.a /usr/local/lib
	cp ./Build_Vik_Wrap/lib/libVik_Wrap.so /usr/local/lib
	cp ./Build_Vik_Wrap/include/VRA/*.h /usr/local/include
	sudo echo "/usr/local/lib" >> /etc/ld.so.conf
	sudo ldconfig
	rm -rf ./Build_Vik_Wrap
	;;
	*)
	;;
esac
	echo "SUCCESS (MAYBE)"

