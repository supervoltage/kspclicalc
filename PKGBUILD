# Maintainer: Andrew Kiss <ubervoltage@gmail.com>
pkgname=kspclicalc
pkgver=1.0
pkgrel=1
url="https://github.com/supervoltage/$pkgname"
pkgdesc="Kerbal Space Program calculator"
arch=('i686' 'x86_64')
license=('GPL')
groups=('libstdc++')
makedepends=('make')
options=()
source=("https://dl.dropboxusercontent.com/u/29712116/C%2B%2B/kspclicalc-1.0.tar.gz")
noextract=()
md5sums=('ec09fea777e6757383754ed273586212')

build() {
	cd $srcdir
	
	make
}

package() {
	cd $srcdir
	
	make DESTDIR="$pkgdir/" install
}