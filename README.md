##1. Potrzebne zależności
[compiler]
```bash
sudo apt-get install build-essential
```

[required]
```bash
sudo apt-get install cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
```

[optional]
```bash
sudo apt-get install python-dev python-numpy libtbb2 libtbb-dev libjpeg-dev libpng-dev libtiff-dev libjasper-dev libdc1394-22-dev
```

##2. Klonowanie repo
```bash
git clone https://github.com/Itseez/opencv.git
git clone https://github.com/Itseez/opencv_contrib.git
```

##3. Folder na build
```bash
cd ~/opencv
mkdir build
cd build
```

##4. Użycie cmake

```bash
cmake -D CMAKE_BUILD_TYPE=Release -D CMAKE_INSTALL_PREFIX=/usr/local ..
cmake -DOPENCV_EXTRA_MODULES_PATH=../../opencv_contrib/modules ..
make -j5
```

##5. Instalacja
```bash
sudo make install
```

##6.BOOST
Pobranie i dwie komendy:
```bash
sudo ./bootstrap.sh --prefix=/usr/local
sudo ./b2 install
```

niezbędne linie w cmake:
```bash
find_package( OpenCV REQUIRED )
find_package( Boost REQUIRED COMPONENTS system filesystem)
target_link_libraries( BagOfWords ${OpenCV_LIBS} )
target_link_libraries( BagOfWords ${Boost_LIBRARIES} )
```