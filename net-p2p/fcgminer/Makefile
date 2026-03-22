PORTNAME=	fcgminer
DISTVERSIONPREFIX=	v
DISTVERSION=	4.8.1-freebsd
CATEGORIES=	net-p2p

MAINTAINER=	daniel@morante.net
COMMENT=	Modular ASIC miner with Scrypt/Zeus/GridSeed support (FreeBSD fork)
WWW=		https://github.com/tuaris/fcgminer

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		autoreconf gmake libtool pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	tuaris
GH_TAGNAME=	e2f1356

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-curses \
		--enable-scrypt \
		--enable-zeus
CONFIGURE_ENV=	CFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/cgminer

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/include/jansson.h \
		${STAGEDIR}${PREFIX}/include/jansson_config.h \
		${STAGEDIR}${PREFIX}/include/libusb-1.0 \
		${STAGEDIR}${PREFIX}/lib/libjansson* \
		${STAGEDIR}${PREFIX}/lib/libusb-1.0* \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/jansson.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/libusb-1.0.pc

.include <bsd.port.mk>
