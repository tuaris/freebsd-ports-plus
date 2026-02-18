PORTNAME=	bfgminer
DISTVERSIONPREFIX=	v
DISTVERSION=	5.5.0
CATEGORIES=	net-p2p

MAINTAINER=	daniel@morante.net
COMMENT=	Modular ASIC/FPGA Bitcoin miner (FreeBSD fork)
WWW=		https://github.com/tuaris/fbgfminer

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	autoconf:devel/autoconf \
		automake:devel/automake \
		libtool:devel/libtool \
		${LOCALBASE}/include/uthash.h:devel/uthash
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libjansson.so:devel/jansson \
		libevent.so:devel/libevent \
		libmicrohttpd.so:www/libmicrohttpd \
		libhidapi.so:comms/hidapi

USES=		autoreconf gmake libtool ncurses pkgconfig ssl
USE_GITHUB=	yes
GH_ACCOUNT=	tuaris
GH_PROJECT=	fbgfminer
GH_TAGNAME=	b68cbca

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-libudev \
		--with-libusb \
		--enable-icarus
CONFIGURE_ENV=	CFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

INSTALL_TARGET=	install-strip

post-patch:
	@${TOUCH} ${WRKSRC}/libbase58/INSTALL

PLIST_FILES=	bin/bfgminer \
		bin/bfgminer-rpc \
		bin/start-bfgminer.sh \
		include/libbase58.h \
		include/libblkmaker-0.1/blkmaker.h \
		include/libblkmaker-0.1/blkmaker_jansson.h \
		include/libblkmaker-0.1/blktemplate.h \
		lib/libbase58.so \
		lib/libbase58.so.0 \
		lib/libbase58.so.0.0.2 \
		lib/libblkmaker-0.1.so \
		lib/libblkmaker-0.1.so.8 \
		lib/libblkmaker-0.1.so.8.0.0 \
		lib/libblkmaker_jansson-0.1.so \
		lib/libblkmaker_jansson-0.1.so.8 \
		lib/libblkmaker_jansson-0.1.so.8.0.0 \
		libdata/pkgconfig/libbase58.pc \
		libdata/pkgconfig/libblkmaker_jansson-0.1.pc \
		share/doc/fbfgminer/AUTHORS \
		share/doc/fbfgminer/COPYING \
		share/doc/fbfgminer/HACKING \
		share/doc/fbfgminer/NEWS \
		share/doc/fbfgminer/README \
		share/doc/fbfgminer/README.ASIC \
		share/doc/fbfgminer/README.FPGA \
		share/doc/fbfgminer/README.RPC \
		share/doc/fbfgminer/README.scrypt \
		share/doc/fbfgminer/example.conf \
		share/doc/fbfgminer/rpc-examples/api-example.c \
		share/doc/fbfgminer/rpc-examples/api-example.php \
		share/doc/fbfgminer/rpc-examples/api-example.py \
		share/doc/fbfgminer/rpc-examples/miner.php \
		share/doc/libbase58/AUTHORS \
		share/doc/libbase58/COPYING \
		share/doc/libbase58/INSTALL \
		share/doc/libbase58/README.md

OPTIONS_DEFINE=	SCRYPT
OPTIONS_DEFAULT=	SCRYPT

SCRYPT_DESC=		Enable scrypt algorithm support
SCRYPT_CONFIGURE_ENABLE=	scrypt

.include <bsd.port.mk>
