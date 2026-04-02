PORTNAME=	zetacoin
DISTVERSIONPREFIX=	v
DISTVERSION=	0.14.0-rc5
CATEGORIES=	net-p2p finance

USE_GITHUB=	yes
GH_ACCOUNT=	zetacoin-core
GH_PROJECT=	gui

MAINTAINER=	daniel@morante.net
COMMENT?=	Virtual Peer-to-Peer Currency Client (QT)
WWW=		https://github.com/zetacoin-core/gui

LICENSE=	MIT

BUILD_DEPENDS=	boost-libs>=1.74:devel/boost-libs

LIB_DEPENDS=	libcapnp.so:devel/capnproto \
		libevent.so:devel/libevent

SLAVE_PORT?=	no

USES=		cmake compiler:c++20-lang cpe pkgconfig
.if defined(SLAVE_PORT) && ${SLAVE_PORT} == "no"
USES+=		desktop-file-utils gl qt:6
USE_QT=		base tools:build
USE_GL=		opengl
.endif

CMAKE_ARGS?=	-DBUILD_GUI=ON \
		-DBUILD_BITCOIN_BIN=OFF \
		-DBUILD_CLI=OFF \
		-DBUILD_DAEMON=OFF \
		-DBUILD_SHARED_LIBS=OFF \
		-DBUILD_TX=OFF \
		-DBUILD_UTIL=OFF \
		-DBUILD_WALLET_TOOL=OFF

PLIST_FILES?=	bin/zetacoin-qt \
		libexec/zetacoin-gui \
		share/applications/zetacoin-qt.desktop \
		share/man/man1/zetacoin-qt.1.gz \
		share/pixmaps/zetacoin128.png

OPTIONS_DEFINE?=	DBUS DEBUG HARDENING QRCODES TESTS WALLET ZMQ
OPTIONS_DEFAULT?=	DBUS HARDENING QRCODES WALLET ZMQ
OPTIONS_SUB=		yes

HARDENING_DESC=	Attempt to harden binaries (PIE for ASLR, NX Stack)
QRCODES_DESC=	Display QR Codes
TESTS_DESC=	Build test binary and unit tests
WALLET_DESC=	Wallet Management Support
ZMQ_DESC=	Block and transaction broadcasting with ZeroMQ

DBUS_CMAKE_BOOL=	WITH_DBUS

DEBUG_CMAKE_ON=		-DCMAKE_BUILD_TYPE=Debug
DEBUG_CMAKE_OFF=	-DCMAKE_BUILD_TYPE=Release

HARDENING_CMAKE_BOOL=	ENABLE_HARDENING

QRCODES_LIB_DEPENDS=	libqrencode.so:graphics/libqrencode
QRCODES_CMAKE_BOOL=	WITH_QRENCODE

TESTS_CMAKE_BOOL=	BUILD_BENCH BUILD_TESTS SECP256K1_BUILD_TESTS
TESTS_PLIST_FILES=	libexec/bench_zetacoin \
			libexec/test_zetacoin
.if defined(SLAVE_PORT) && ${SLAVE_PORT} == "no"
TESTS_PLIST_FILES+=	libexec/test_zetacoin-qt
.endif

WALLET_USES=		sqlite:3
WALLET_CMAKE_ON=	-DENABLE_WALLET=ON
WALLET_CMAKE_OFF=	-DENABLE_WALLET=OFF

ZMQ_BUILD_DEPENDS=	libzmq4>0:net/libzmq4
ZMQ_RUN_DEPENDS=	libzmq4>0:net/libzmq4
ZMQ_CMAKE_BOOL=		WITH_ZMQ

.include <bsd.port.pre.mk>

.if defined(SLAVE_PORT) && ${SLAVE_PORT} == "no"

post-install:
	${INSTALL} ${FILESDIR}/zetacoin-qt.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${INSTALL} ${FILESDIR}/zetacoin128.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

.endif

.include <bsd.port.post.mk>
