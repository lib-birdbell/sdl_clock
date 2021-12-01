# sdl_clock
sdl 1.2 clock for linux

- dependencies
"SDL 1.2"

export  NM="arm-linux-gnueabihf-nm"
export  LD="arm-linux-gnueabihf-ld"
export  CC="arm-linux-gnueabihf-gcc" 
export  CXX="arm-linux-gnueabihf-g++"    
export  RANLIB="arm-linux-gnueabihf-ranlib"
export  AR="arm-linux-gnueabihf-ar"
export  STRIP="arm-linux-gnueabihf-strip"
./configure --build=i386-linux --host=arm-linux \
--prefix=$directory$/output \
--disable-debug --disable-joystick --disable-cdrom --disable-diskaudio --disable-mintaudio --disable-esd \
--disable-nasm --disable-dga --disable-video-x11-dgamouse --disable-video-x11-xv --disable-video-x11-xinerama \
--disable-video-x11-xme --disable-video-dga --disable-video-photon --disable-video-ps2gs --disable-video-xbios \
--disable-video-gem --disable-video-opengl --enable-input-events --disable-stdio-redirect --disable-directx --disable-atari-ldgmake --disable-video-x11
clean ; make

"SDL ttf 2.0.11"

export  NM="arm-linux-gnueabihf-nm"
export  LD="arm-linux-gnueabihf-ld"
export  CC="arm-linux-gnueabihf-gcc" 
export  CXX="arm-linux-gnueabihf-g++"    
export  RANLIB="arm-linux-gnueabihf-ranlib"
export  AR="arm-linux-gnueabihf-ar"
export  CFLAGS+="-I$directory$/freetype-2.11.0/include "
export  CFLAGS+="-I$directory$/SDL-1.2.15/include "
export  LDFLAGS+="-L$directory$/SDL-1.2.15/build/.libs "
export  LDFLAGS+="-L$directory$/freetype-2.11.0/objs/.libs "
export  LIBS+="-lfreetype "
#export SDL_CONFIG="$directory$/SDL-1.2.15/bin/sdl-config"
./configure --build=i386-linux --host=arm-linux \
--prefix=$directory$/output \
--with-sdl-prefix=$directory$/SDL-1.2.15 \
--without-x \
--includedir=$directory$/freetype-2.11.0/include \
--with-freetype-prefix=$directory$/freetype-2.11.0
make

"freetype-2.11.0"

export  NM="arm-linux-gnueabihf-nm"
export  LD="arm-linux-gnueabihf-ld"
export  CC="arm-linux-gnueabihf-gcc" 
export  CXX="arm-linux-gnueabihf-g++"    
export  RANLIB="arm-linux-gnueabihf-ranlib"
export  AR="arm-linux-gnueabihf-ar"
./configure --build=i386-linux --host=arm-linux \
--enable-shared \
--prefix=$directory$/output
make clean
make
