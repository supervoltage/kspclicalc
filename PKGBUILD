# Maintainer: Andrew Kiss <ubervoltage@gmail.com>
pkgname=kspclicalc
pkgver=1.5
pkgrel=7
url="https://github.com/supervoltage/$pkgname"
pkgdesc="Kerbal Space Program calculator"
arch=('i686' 'x86_64')
license=('GPL')
groups=('libstdc++')
makedepends=('make')
options=()
source=("https://dl.dropboxusercontent.com/u/29712116/C%2B%2B/kspclicalc.tar.gz")
noextract=()
md5sums=('2ebd9ea9b29c8c2ca9c9709d875544f1')

build() {
	cd $srcdir
	
	make
}

package() {
	cd $srcdir
	
	make DESTDIR="$pkgdir/" install
}